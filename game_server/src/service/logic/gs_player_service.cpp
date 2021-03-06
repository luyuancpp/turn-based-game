#include <memory>
#include <unordered_map>
#include "player_service.h"
#include "logic_proto/common_client_player.pb.h"
#include "src/service/logic/gscommon_client_player.h"
#include "logic_proto/scene_client_player.pb.h"
#include "src/service/logic/gsscene_client_player.h"
#include "logic_proto/team_client_player.pb.h"
#include "src/service/logic/gsteam_client_player.h"
#include "logic_proto/team_server_player.pb.h"
#include "src/service/logic/gsteam_server_player.h"
#include "logic_proto/scene_server_player.pb.h"
#include "src/service/logic/gsscene_server_player.h"
#include "logic_proto/common_server_player.pb.h"
#include "src/service/logic/gscommon_server_player.h"
std::unordered_map<std::string, std::unique_ptr<PlayerService>> g_player_services;
std::unordered_set<std::string> g_open_player_services;
class ClientPlayerCommonServiceOpenImpl : public ClientPlayerCommonService{};
class ClientPlayerSceneServiceOpenImpl : public ClientPlayerSceneService{};
class ClientPlayerTeamServiceOpenImpl : public ClientPlayerTeamService{};
class ServerPlayerTeamServiceOpenImpl : public ServerPlayerTeamService{};
class ServerPlayerSceneServiceOpenImpl : public ServerPlayerSceneService{};
class ServerPlayerLoginServiceOpenImpl : public ServerPlayerLoginService{};
void InitPlayerServcie()
{
    g_player_services.emplace("ClientPlayerCommonService", std::make_unique<ClientPlayerCommonServiceImpl>(new ClientPlayerCommonServiceOpenImpl));
    g_player_services.emplace("ClientPlayerSceneService", std::make_unique<ClientPlayerSceneServiceImpl>(new ClientPlayerSceneServiceOpenImpl));
    g_player_services.emplace("ClientPlayerTeamService", std::make_unique<ClientPlayerTeamServiceImpl>(new ClientPlayerTeamServiceOpenImpl));
    g_player_services.emplace("ServerPlayerTeamService", std::make_unique<ServerPlayerTeamServiceImpl>(new ServerPlayerTeamServiceOpenImpl));
    g_player_services.emplace("ServerPlayerSceneService", std::make_unique<ServerPlayerSceneServiceImpl>(new ServerPlayerSceneServiceOpenImpl));
    g_player_services.emplace("ServerPlayerLoginService", std::make_unique<ServerPlayerLoginServiceImpl>(new ServerPlayerLoginServiceOpenImpl));
    g_open_player_services.emplace("ClientPlayerCommonService");
    g_open_player_services.emplace("ClientPlayerSceneService");
    g_open_player_services.emplace("ClientPlayerTeamService");
}
