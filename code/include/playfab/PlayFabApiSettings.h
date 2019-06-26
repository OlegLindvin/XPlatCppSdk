#pragma once

#include <string>
#include <map>

namespace PlayFab
{
    /// <summary>
    /// The settings that can be used (optionally) by instance versions of PlayFab APIs.
    /// </summary>
    class PlayFabApiSettings
    {
    public:
        std::string verticalName; // The name of a PlayFab service vertical
        std::string baseServiceHost; // The base for a PlayFab service host
        std::string titleId; // You must set this value for PlayFabSdk to work properly (found in the Game Manager for your title, at the PlayFab Website)
        std::string developerSecretKey; // Developer secret key. These keys can be used in development environments.

        PlayFabApiSettings();
        std::string GetUrl(const std::string& urlPath, const std::map<std::string, std::string>& getParams);
    };
}
