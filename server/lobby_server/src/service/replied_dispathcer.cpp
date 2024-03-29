#include "replied_dispathcer.h"

#include "src/network/codec/dispatcher.h"

#include "deploy_service_replied.h"

extern ProtobufDispatcher g_response_dispatcher;

void InitRepliedCallback()
{
    g_response_dispatcher.registerMessageCallback<LobbyServerResponse>(std::bind(&OnLobbyServerReplied, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    g_response_dispatcher.registerMessageCallback<SceneSqueueResponese>(std::bind(&SceneSequenceNodeIdReplied, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
          
}

