#include <stdafx.h>

#include <playfab/PlayFabSettings.h>

#pragma warning (disable: 4100) // formal parameters are part of a public interface

namespace PlayFab
{
    const std::string PlayFabSettings::sdkVersion = "3.11.190520";
    const std::string PlayFabSettings::buildIdentifier = "jbuild_xplatcppsdk__sdk-genericslave-1_2";
    const std::string PlayFabSettings::versionString = "XPlatCppSdk-3.11.190520";
    const std::string PlayFabSettings::verticalName = "";

    const std::map<std::string, std::string> PlayFabSettings::requestGetParams = {
        { "sdk", PlayFabSettings::versionString }
    };

    bool PlayFabSettings::useDevelopmentEnvironment = false;
    std::string PlayFabSettings::developmentEnvironmentURL = ".playfabsandbox.com";
    std::string PlayFabSettings::productionEnvironmentURL = ".playfabapi.com";
    std::string PlayFabSettings::titleId; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
    ErrorCallback PlayFabSettings::globalErrorHandler = nullptr;

    // Control whether all callbacks are threaded or whether the user manually controlls callback timing from their main-thread
    bool PlayFabSettings::threadedCallbacks = false;

    std::string PlayFabSettings::entityToken; // This is set by entity GetEntityToken method, and is required by all other Entity API methods
#if defined(ENABLE_PLAYFABSERVER_API) || defined(ENABLE_PLAYFABADMIN_API)
    std::string PlayFabSettings::developerSecretKey; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
#endif

#ifndef DISABLE_PLAYFABCLIENT_API
    std::string PlayFabSettings::clientSessionTicket; // This is set by any Client Login method, and is required for all other Client API methods
    std::string PlayFabSettings::advertisingIdType = ""; // Set this to the appropriate AD_TYPE_X constant below
    std::string PlayFabSettings::advertisingIdValue = ""; // Set this to corresponding device value

    bool PlayFabSettings::disableAdvertising = false;
    const std::string PlayFabSettings::AD_TYPE_IDFA = "Idfa";
    const std::string PlayFabSettings::AD_TYPE_ANDROID_ID = "Adid";
#endif

    void PlayFabSettings::ForgetAllCredentials()
    {
        entityToken.clear();
        clientSessionTicket.clear();
    }

    std::string PlayFabSettings::GetUrl(const std::string& urlPath, const std::map<std::string, std::string>& getParams)
    {
        std::string fullUrl;
        fullUrl.reserve(1000);

        fullUrl += "https://";

        if(PlayFabSettings::verticalName.length() > 0)
        {
            fullUrl += PlayFabSettings::verticalName;
        }
        else
        {
            fullUrl += titleId;
        }

        fullUrl += useDevelopmentEnvironment ? developmentEnvironmentURL : productionEnvironmentURL;
        fullUrl += urlPath;

        bool firstParam = true;
        for (auto const& paramPair : getParams)
        {
            if (firstParam) {
                fullUrl += "?";
                firstParam = false;
            } else {
                fullUrl += "&";
            }
            fullUrl += paramPair.first;
            fullUrl += "=";
            fullUrl += paramPair.second;
        }
        
        return fullUrl;
    }

    bool PlayFabSettings::ValidateSettings(const std::string& apiAuth, const std::shared_ptr<PlayFabAuthenticationContext> authenticationContext, const std::shared_ptr<PlayFabApiSettings> apiSettings, CallRequestContainer& container)
    {
        bool valid = true;
        if (PlayFabSettings::titleId.empty())
        {
            container.errorWrapper.HttpCode = 0;
            container.errorWrapper.HttpStatus = "Client-side validation failure";
            container.errorWrapper.ErrorCode = PlayFabErrorCode::PlayFabErrorInvalidParams;
            container.errorWrapper.ErrorName = container.errorWrapper.HttpStatus;
            container.errorWrapper.ErrorMessage = "PlayFabSettings::titleId has not been set properly. It must not be empty.";
            valid = false;
        }

        if (valid)
            return true;

        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(container.errorWrapper, container.GetCustomData());
        if (container.errorCallback != nullptr)
            container.errorCallback(container.errorWrapper, container.GetCustomData());

        return false;
    }
}

#pragma warning (default: 4100) // formal parameters are part of a public interface
