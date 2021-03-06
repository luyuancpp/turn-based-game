#include <memory>
#include <unordered_map>
#include "player_service.h"
#include "logic_proto/team_server_player.pb.h"
#include "src/service/logic/msteam_server_player.h"
#include "logic_proto/scene_server_player.pb.h"
#include "src/service/logic/msscene_server_player.h"
#include "logic_proto/common_server_player.pb.h"
#include "src/service/logic/mscommon_server_player.h"
std::unordered_map<std::string, std::unique_ptr<PlayerService>> g_player_services;
std::unordered_set<std::string> g_open_player_services;
class ServerPlayerTeamServiceOpenImpl : public ServerPlayerTeamService{};
class ServerPlayerSceneServiceOpenImpl : public ServerPlayerSceneService{};
class ServerPlayerLoginServiceOpenImpl : public ServerPlayerLoginService{};
void InitPlayerServcie()
{
    g_player_services.emplace("ServerPlayerTeamService", std::make_unique<ServerPlayerTeamServiceImpl>(new ServerPlayerTeamServiceOpenImpl));
    g_player_services.emplace("ServerPlayerSceneService", std::make_unique<ServerPlayerSceneServiceImpl>(new ServerPlayerSceneServiceOpenImpl));
    g_player_services.emplace("ServerPlayerLoginService", std::make_unique<ServerPlayerLoginServiceImpl>(new ServerPlayerLoginServiceOpenImpl));
}
