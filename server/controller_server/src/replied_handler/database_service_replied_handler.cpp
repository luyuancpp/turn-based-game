#include "database_service_replied_handler.h"
#include "src/network/codec/dispatcher.h"

///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
extern ProtobufDispatcher g_response_dispatcher;


void InitAccountDBServiceLoad2RedisRepliedHandler()
{
	g_response_dispatcher.registerMessageCallback<LoadAccountResponse>(std::bind(&OnAccountDBServiceLoad2RedisRepliedHandler, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	g_response_dispatcher.registerMessageCallback<SaveAccountResponse>(std::bind(&OnAccountDBServiceSave2RedisRepliedHandler, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void OnAccountDBServiceLoad2RedisRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<LoadAccountResponse>& replied, Timestamp timestamp)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}

void OnAccountDBServiceSave2RedisRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<SaveAccountResponse>& replied, Timestamp timestamp)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}

///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
