#include <stdafx.h>

#include <playfab/PlayFabAuthenticationContext.h>
#include <playfab/PlayFabSettings.h>

namespace PlayFab
{
    PlayFabAuthenticationContext::PlayFabAuthenticationContext()
    {
    }

    PlayFabAuthenticationContext::PlayFabAuthenticationContext(std::string clientSessionTicket, std::string entityToken, std::string playFabId, std::string entityId, std::string entityType)
    {
    }

    void PlayFabAuthenticationContext::ForgetAllCredentials()
    {
#ifndef DISABLE_PLAYFABCLIENT_API
        clientSessionTicket.clear();
        playFabId.clear();
#endif
#ifndef DISABLE_PLAYFABENTITY_API
        entityToken.clear();
        entityId.clear();
        entityType.clear();
#endif
    }

    bool PlayFabAuthenticationContext::IsClientLoggedIn()
    {
        return clientSessionTicket.length();
    }

    bool PlayFabAuthenticationContext::IsEntityLoggedIn()
    {
        return entityToken.length();
    }

    void PlayFabAuthenticationContext::CopyFrom(std::shared_ptr<PlayFabAuthenticationContext> other)
    {
#ifndef DISABLE_PLAYFABCLIENT_API
        clientSessionTicket = other->clientSessionTicket;
        playFabId = other->playFabId;
#endif
#ifndef DISABLE_PLAYFABENTITY_API
        entityToken = other->entityToken;
        entityId = other->entityId;
        entityType = other->entityType;
#endif
    }
}
