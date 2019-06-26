#include <stdafx.h>

#ifndef PLAYFAB_PLATFORM_PLAYSTATION // Issue 32699
#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabEventsInstanceApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#pragma warning (disable: 4100) // formal parameters are part of a public interface

namespace PlayFab
{
    using namespace EventsModels;

    PlayFabEventsInstanceAPI::PlayFabEventsInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings)
    {
        this->settings = std::move(apiSettings);
    }

    PlayFabEventsInstanceAPI::PlayFabEventsInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        if (authenticationContext == nullptr) throw std::runtime_error("Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.GetAuthenticationContext");
        this->context = std::move(authenticationContext);
    }

    PlayFabEventsInstanceAPI::PlayFabEventsInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        if (authenticationContext == nullptr) throw std::runtime_error("Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.GetAuthenticationContext");
        this->settings = std::move(apiSettings);
        this->context = std::move(authenticationContext);
    }

    PlayFabEventsInstanceAPI::~PlayFabEventsInstanceAPI()
    {
    }

    std::shared_ptr<PlayFabApiSettings> PlayFabEventsInstanceAPI::GetSettings() const
    {
        return this->settings;
    }

    void PlayFabEventsInstanceAPI::SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings)
    {
        this->settings = std::move(apiSettings);
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabEventsInstanceAPI::GetAuthenticationContext() const
    {
        return this->context;
    }

    size_t PlayFabEventsInstanceAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabEventsInstanceAPI::ForgetAllCredentials()
    {
        if (this->context == nullptr)
            return;

        this->context->ForgetAllCredentials();
    }

    bool PlayFabEventsInstanceAPI::IsEntityLoggedIn()
    {
        return this->context == nullptr ? false : this->context->IsEntityLoggedIn();
    }

    // PlayFabEvents instance APIs

    void PlayFabEventsInstanceAPI::WriteEvents(
        WriteEventsRequest& request,
        ProcessApiCallback<WriteEventsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        auto callContext = request.authenticationContext == nullptr ? this->context : request.authenticationContext; auto callSettings = this->settings == nullptr ? PlayFabSettings::staticSettings : this->settings;
        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? this->context->entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Event/WriteEvents",
            headers,
            jsonAsString,
            std::bind(&PlayFabEventsInstanceAPI::OnWriteEventsResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            callSettings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<WriteEventsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("EntityToken", callContext, callSettings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabEventsInstanceAPI::OnWriteEventsResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        WriteEventsResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<WriteEventsResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabEventsInstanceAPI::ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container)
    {
        if (container.errorWrapper.HttpCode == 200)
        {
            resultCommon.FromJson(container.errorWrapper.Data);
            resultCommon.Request = container.errorWrapper.Request;
            return true;
        }
        else // Process the error case
        {
            if (PlayFabSettings::globalErrorHandler != nullptr)
                PlayFabSettings::globalErrorHandler(container.errorWrapper, container.GetCustomData());
            if (container.errorCallback != nullptr)
                container.errorCallback(container.errorWrapper, container.GetCustomData());
            return false;
        }
    }
}

#endif
#endif

#pragma warning (enable: 4100) // formal parameters are part of a public interface
