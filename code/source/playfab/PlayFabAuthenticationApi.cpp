#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabAuthenticationApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#pragma warning (disable: 4100) // formal parameters are part of a public interface

namespace PlayFab
{
    using namespace AuthenticationModels;

    size_t PlayFabAuthenticationAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabAuthenticationAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabAuthentication APIs

    void PlayFabAuthenticationAPI::GetEntityToken(
        GetEntityTokenRequest& request,
        ProcessApiCallback<GetEntityTokenResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {
        std::string authKey, authValue;
        auto callSettings = PlayFabSettings::staticSettings;
        auto callContext = request.authenticationContext == nullptr ? PlayFabSettings::staticPlayer : request.authenticationContext;

        if (callContext->entityToken.length() > 0) {
            authKey = "X-EntityToken"; authValue = request.authenticationContext->entityToken;
        }
        else if (callContext->clientSessionTicket.length() > 0) {
            authKey = "X-Authorization"; authValue = request.authenticationContext->clientSessionTicket;
        }
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
        else if (callSettings->developerSecretKey.length() > 0) {
            authKey = "X-SecretKey"; authValue = callSettings->developerSecretKey;
        }
#endif

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace(authKey, authValue);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Authentication/GetEntityToken",
            headers,
            jsonAsString,
            OnGetEntityTokenResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetEntityTokenResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("None", request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabAuthenticationAPI::OnGetEntityTokenResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetEntityTokenResponse outResult;
        if (ValidateResult(outResult, container))
        {
            if (outResult.EntityToken.length() > 0)            {
                PlayFabSettings::staticPlayer->entityToken = outResult.EntityToken;
                PlayFabSettings::staticPlayer->entityId = outResult.Entity->Id;
                PlayFabSettings::staticPlayer->entityType = outResult.Entity->Type;
            }

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetEntityTokenResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabAuthenticationAPI::ValidateEntityToken(
        ValidateEntityTokenRequest& request,
        ProcessApiCallback<ValidateEntityTokenResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        auto callContext = request.authenticationContext == nullptr ? PlayFabSettings::staticPlayer : request.authenticationContext; headers.emplace("X-EntityToken", callContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Authentication/ValidateEntityToken",
            headers,
            jsonAsString,
            OnValidateEntityTokenResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<ValidateEntityTokenResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("EntityToken", request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabAuthenticationAPI::OnValidateEntityTokenResult(int httpCode, std::string result, std::unique_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        ValidateEntityTokenResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<ValidateEntityTokenResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabAuthenticationAPI::ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container)
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

#pragma warning (enable: 4100) // formal parameters are part of a public interface
