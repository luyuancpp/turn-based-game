#include "game_player_replied_handler.h"
#include "network/codec/dispatcher.h"

extern ProtobufDispatcher g_response_dispatcher;

///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE

void InitGamePlayerServiceCentre2GsLoginRepliedHandler()
{
	g_response_dispatcher.registerMessageCallback<google::protobuf::Empty>(std::bind(&OnGamePlayerServiceCentre2GsLoginRepliedHandler, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void OnGamePlayerServiceCentre2GsLoginRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<google::protobuf::Empty>& replied, Timestamp timestamp)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}

