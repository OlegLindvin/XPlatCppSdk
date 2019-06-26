#include <stdafx.h>

#include <playfab/PlayFabSettings.h>

#pragma warning (disable: 4100) // formal parameters are part of a public interface

namespace PlayFab
{
    const std::string PlayFabSettings::sdkVersion = "3.11.190520";
    const std::string PlayFabSettings::buildIdentifier = "default_manual_build";
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

    std::shared_ptr<PlayFabAuthenticationContext> PlayFabSettings::staticPlayer = std::make_shared<PlayFabAuthenticationContext>();
    std::shared_ptr<PlayFabApiSettings> PlayFabSettings::staticSettings = std::make_shared<PlayFabApiSettings>();
    const std::string PlayFabSettings::AD_TYPE_IDFA = "Idfa";
    const std::string PlayFabSettings::AD_TYPE_ANDROID_ID = "Adid";

    void PlayFabSettings::ForgetAllCredentials()
    {
        staticPlayer->ForgetAllCredentials();
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

#pragma warning (enable: 4100) // formal parameters are part of a public interface
