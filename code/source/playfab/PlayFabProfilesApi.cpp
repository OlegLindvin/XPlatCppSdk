#include <stdafx.h>

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabProfilesApi.h>
#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabSettings.h>
#include <playfab/PlayFabError.h>
#include <memory>

#pragma warning (disable: 4100) // formal parameters are part of a public interface

namespace PlayFab
{
    using namespace ProfilesModels;

    size_t PlayFabProfilesAPI::Update()
    {
        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        return http.Update();
    }

    void PlayFabProfilesAPI::ForgetAllCredentials()
    {
        return PlayFabSettings::ForgetAllCredentials();
    }

    // PlayFabProfiles APIs

    void PlayFabProfilesAPI::GetGlobalPolicy(
        GetGlobalPolicyRequest& request,
        ProcessApiCallback<GetGlobalPolicyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Profile/GetGlobalPolicy",
            headers,
            jsonAsString,
            OnGetGlobalPolicyResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetGlobalPolicyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("EntityToken", request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabProfilesAPI::OnGetGlobalPolicyResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetGlobalPolicyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetGlobalPolicyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabProfilesAPI::GetProfile(
        GetEntityProfileRequest& request,
        ProcessApiCallback<GetEntityProfileResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Profile/GetProfile",
            headers,
            jsonAsString,
            OnGetProfileResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetEntityProfileResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("EntityToken", request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabProfilesAPI::OnGetProfileResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetEntityProfileResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetEntityProfileResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabProfilesAPI::GetProfiles(
        GetEntityProfilesRequest& request,
        ProcessApiCallback<GetEntityProfilesResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Profile/GetProfiles",
            headers,
            jsonAsString,
            OnGetProfilesResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetEntityProfilesResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("EntityToken", request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabProfilesAPI::OnGetProfilesResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetEntityProfilesResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetEntityProfilesResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabProfilesAPI::GetTitlePlayersFromMasterPlayerAccountIds(
        GetTitlePlayersFromMasterPlayerAccountIdsRequest& request,
        ProcessApiCallback<GetTitlePlayersFromMasterPlayerAccountIdsResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Profile/GetTitlePlayersFromMasterPlayerAccountIds",
            headers,
            jsonAsString,
            OnGetTitlePlayersFromMasterPlayerAccountIdsResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<GetTitlePlayersFromMasterPlayerAccountIdsResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("EntityToken", request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabProfilesAPI::OnGetTitlePlayersFromMasterPlayerAccountIdsResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        GetTitlePlayersFromMasterPlayerAccountIdsResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<GetTitlePlayersFromMasterPlayerAccountIdsResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabProfilesAPI::SetGlobalPolicy(
        SetGlobalPolicyRequest& request,
        ProcessApiCallback<SetGlobalPolicyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Profile/SetGlobalPolicy",
            headers,
            jsonAsString,
            OnSetGlobalPolicyResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetGlobalPolicyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("EntityToken", request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabProfilesAPI::OnSetGlobalPolicyResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SetGlobalPolicyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetGlobalPolicyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabProfilesAPI::SetProfileLanguage(
        SetProfileLanguageRequest& request,
        ProcessApiCallback<SetProfileLanguageResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Profile/SetProfileLanguage",
            headers,
            jsonAsString,
            OnSetProfileLanguageResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetProfileLanguageResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("EntityToken", request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabProfilesAPI::OnSetProfileLanguageResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SetProfileLanguageResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetProfileLanguageResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    void PlayFabProfilesAPI::SetProfilePolicy(
        SetEntityProfilePolicyRequest& request,
        ProcessApiCallback<SetEntityProfilePolicyResponse> callback,
        ErrorCallback errorCallback,
        void* customData
    )
    {

        IPlayFabHttpPlugin& http = *PlayFabPluginManager::GetPlugin<IPlayFabHttpPlugin>(PlayFabPluginContract::PlayFab_Transport);
        const auto requestJson = request.ToJson();

        Json::FastWriter writer;
        std::string jsonAsString = writer.write(requestJson);

        std::unordered_map<std::string, std::string> headers;
        headers.emplace("X-EntityToken", request.authenticationContext == nullptr ? PlayFabSettings::entityToken : request.authenticationContext->entityToken);

        auto reqContainer = std::unique_ptr<CallRequestContainer>(new CallRequestContainer(
            "/Profile/SetProfilePolicy",
            headers,
            jsonAsString,
            OnSetProfilePolicyResult,
            customData));

        reqContainer->successCallback = std::shared_ptr<void>((callback == nullptr) ? nullptr : new ProcessApiCallback<SetEntityProfilePolicyResponse>(callback));
        reqContainer->errorCallback = errorCallback;

        if (PlayFabSettings::ValidateSettings("EntityToken", request.authenticationContext, nullptr, *reqContainer))
        {
            http.MakePostRequest(std::unique_ptr<CallRequestContainerBase>(static_cast<CallRequestContainerBase*>(reqContainer.release())));
        }
    }

    void PlayFabProfilesAPI::OnSetProfilePolicyResult(int httpCode, std::string result, std::shared_ptr<CallRequestContainerBase> reqContainer)
    {
        CallRequestContainer& container = static_cast<CallRequestContainer&>(*reqContainer);

        SetEntityProfilePolicyResponse outResult;
        if (ValidateResult(outResult, container))
        {

            const auto internalPtr = container.successCallback.get();
            if (internalPtr != nullptr)
            {
                const auto callback = (*static_cast<ProcessApiCallback<SetEntityProfilePolicyResponse> *>(internalPtr));
                callback(outResult, container.GetCustomData());
            }
        }
    }

    bool PlayFabProfilesAPI::ValidateResult(PlayFabResultCommon& resultCommon, CallRequestContainer& container)
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

#pragma warning (default: 4100) // formal parameters are part of a public interface
