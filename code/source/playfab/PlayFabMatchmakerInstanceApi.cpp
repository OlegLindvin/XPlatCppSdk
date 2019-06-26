#include <stdafx.h>

#ifndef PLAYFAB_PLATFORM_PLAYSTATION // Issue 32699
#ifdef ENABLE_PLAYFABSERVER_API

#include <playfab/PlayFabMatchmakerInstanceApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#pragma warning (disable: 4100) // formal parameters are part of a public interface

namespace PlayFab
{
    using namespace MatchmakerModels;

    PlayFabMatchmakerInstanceAPI::PlayFabMatchmakerInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings)
    {
        this->settings = std::move(apiSettings);
    }

    PlayFabMatchmakerInstanceAPI::PlayFabMatchmakerInstanceAPI(std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        if (authenticationContext == nullptr) throw std::runtime_error("Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.GetAuthenticationContext");
        this->context = std::move(authenticationContext);
    }

    PlayFabMatchmakerInstanceAPI::PlayFabMatchmakerInstanceAPI(std::shared_ptr<PlayFabApiSettings> apiSettings, std::shared_ptr<PlayFabAuthenticationContext> authenticationContext)
    {
        if (authenticationContext == nullptr) throw std::runtime_error("Context cannot be null, create a PlayFabAuthenticationContext for each player in advance, or get <PlayFabClientInstanceAPI>.GetAuthenticationContext");
        this->settings = std::move(apiSettings);
        this->context = std::move(authenticationContext);
    }

    PlayFabMatchmakerInstanceAPI::~PlayFabMatchmakerInstanceAPI()
    {
    }

    std::shared_ptr<PlayFabApiSettings> PlayFabMatchmakerInstanceAPI::GetSettings() const
    {
        return this->settings;
    }

    void PlayFabMatchmakerInstanceAPI::SetSettings(std::shared_ptr<PlayFabApiSettings> apiSettings)
    {
        this->settings = std::move(apiSettings);
    }

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabMatchmakerInstanceAPI::GetAuthenticationContext() const
    {
        return this->context;
    }

    size_t PlayFabMatchmakerInstanceAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabMatchmakerInstanceAPI::ForgetAllCredentials()
    {
        if (this->context == nullptr)
            return;

        this->context->ForgetAllCredentials();
    }

    // PlayFabMatchmaker instance APIs

    void PlayFabMatchmakerInstanceAPI::AuthUser(
        AuthUserRequest& request,
        ProcessApiCallback<AuthUserResponse> callback,
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
        headers.emplace("X-SecretKey", PlayFabSettings::staticSettings->developerSecretKey);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Matchmaker/AuthUser",
            headers,
            jsonAsString,
            std::bind(&PlayFabMatchmakerInstanceAPI::OnAuthUserResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            callSettings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<AuthUserResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("SecretKey", callContext, callSettings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabMatchmakerInstanceAPI::OnAuthUserResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        AuthUserResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<AuthUserResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabMatchmakerInstanceAPI::PlayerJoined(
        PlayerJoinedRequest& request,
        ProcessApiCallback<PlayerJoinedResponse> callback,
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
        headers.emplace("X-SecretKey", PlayFabSettings::staticSettings->developerSecretKey);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Matchmaker/PlayerJoined",
            headers,
            jsonAsString,
            std::bind(&PlayFabMatchmakerInstanceAPI::OnPlayerJoinedResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            callSettings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PlayerJoinedResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("SecretKey", callContext, callSettings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabMatchmakerInstanceAPI::OnPlayerJoinedResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        PlayerJoinedResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PlayerJoinedResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabMatchmakerInstanceAPI::PlayerLeft(
        PlayerLeftRequest& request,
        ProcessApiCallback<PlayerLeftResponse> callback,
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
        headers.emplace("X-SecretKey", PlayFabSettings::staticSettings->developerSecretKey);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Matchmaker/PlayerLeft",
            headers,
            jsonAsString,
            std::bind(&PlayFabMatchmakerInstanceAPI::OnPlayerLeftResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            callSettings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<PlayerLeftResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("SecretKey", callContext, callSettings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabMatchmakerInstanceAPI::OnPlayerLeftResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        PlayerLeftResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<PlayerLeftResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabMatchmakerInstanceAPI::StartGame(
        StartGameRequest& request,
        ProcessApiCallback<StartGameResponse> callback,
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
        headers.emplace("X-SecretKey", PlayFabSettings::staticSettings->developerSecretKey);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Matchmaker/StartGame",
            headers,
            jsonAsString,
            std::bind(&PlayFabMatchmakerInstanceAPI::OnStartGameResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            callSettings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<StartGameResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("SecretKey", callContext, callSettings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabMatchmakerInstanceAPI::OnStartGameResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        StartGameResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<StartGameResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabMatchmakerInstanceAPI::UserInfo(
        UserInfoRequest& request,
        ProcessApiCallback<UserInfoResponse> callback,
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
        headers.emplace("X-SecretKey", PlayFabSettings::staticSettings->developerSecretKey);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Matchmaker/UserInfo",
            headers,
            jsonAsString,
            std::bind(&PlayFabMatchmakerInstanceAPI::OnUserInfoResult, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
            customData,
            callSettings));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<UserInfoResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("SecretKey", callContext, callSettings, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabMatchmakerInstanceAPI::OnUserInfoResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        UserInfoResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<UserInfoResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabMatchmakerInstanceAPI::ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container)
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
