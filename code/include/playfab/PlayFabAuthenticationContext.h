#pragma once

#include <string>

namespace PlayFab
{
    /// <summary>
    /// Container for PlayFab authentication credentials data.
    /// </summary>
    class PlayFabAuthenticationContext
    {
    public:
#ifndef DISABLE_PLAYFABCLIENT_API
        std::string clientSessionTicket; // Client session ticket that is used as an authentication token in many PlayFab API methods.
        std::string playFabId; // Master player Id for the logged in client.

        std::string advertisingIdType; // Set this to the appropriate AD_TYPE_X constant (defined in PlayFabSettings)
        std::string advertisingIdValue; // Set this to corresponding device value

        // DisableAdvertising is provided for completeness, but changing it is not suggested
        // Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
        bool disableAdvertising;
#endif
#ifndef DISABLE_PLAYFABENTITY_API
        std::string entityToken; // Active entity token. Entity tokens are required by all Entity API methods.
        std::string entityId; // Describes the Entity Id for the active entity. For clients, this is the title player ID, for servers, this is the title Id.
        std::string entityType; // Describes the type of entity identified in entityId.
#endif

        PlayFabAuthenticationContext();
        PlayFabAuthenticationContext(std::string clientSessionTicket, std::string entityToken, std::string playFabId, std::string entityId, std::string entityType);

        bool IsClientLoggedIn();
        bool IsEntityLoggedIn();

        void ForgetAllCredentials();
        void CopyFrom(std::shared_ptr<PlayFabAuthenticationContext> other);
    };
}
