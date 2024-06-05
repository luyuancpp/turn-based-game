#include "logic_proto/lobby_scene.pb.h"
#include "muduo/net/TcpConnection.h"
using namespace muduo;
using namespace muduo::net;

void OnLobbyServiceStartCrossGsRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<StartCrossGsResponse>& replied, Timestamp timestamp);

void OnLobbyServiceStartControllerNodeRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<Empty>& replied, Timestamp timestamp);

void OnLobbyServiceEnterCrossMainSceneRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<EnterCrossMainSceneResponese>& replied, Timestamp timestamp);

void OnLobbyServiceEnterCrossMainSceneWeightRoundRobinRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<EnterCrossRoomSceneSceneWeightRoundRobinResponse>& replied, Timestamp timestamp);

void OnLobbyServiceLeaveCrossMainSceneRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<Empty>& replied, Timestamp timestamp);

void OnLobbyServiceGameConnectToControllerRepliedHandler(const TcpConnectionPtr& conn, const std::shared_ptr<Empty>& replied, Timestamp timestamp);

