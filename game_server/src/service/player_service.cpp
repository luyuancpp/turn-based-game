#include <memory>
#include <unordered_map>
#include "player_service.h"
#include "logic_proto/ms2gs_scene.pb.h"
#include "ms2gs_scene_player.h"
#include "logic_proto/player_team.pb.h"
#include "player_team_player.h"
#include "logic_proto/player_scene.pb.h"
#include "player_scene_player.h"
namespace game
{
std::unordered_map<std::string, std::unique_ptr<PlayerService>> g_player_services;
class C2GsServiceImpl : public ms2gs::C2GsService{};
class PlayerTeamServiceImpl : public playerservice::PlayerTeamService{};
class PlayerSceneServiceImpl : public playerservice::PlayerSceneService{};
void InitPlayerServcie()
{
    g_player_services.emplace("ms2gs.C2GsService", std::make_unique<ms2gs::PlayerC2GsServiceImpl>(new C2GsServiceImpl));
    g_player_services.emplace("playerservice.PlayerTeamService", std::make_unique<playerservice::PlayerPlayerTeamServiceImpl>(new PlayerTeamServiceImpl));
    g_player_services.emplace("playerservice.PlayerSceneService", std::make_unique<playerservice::PlayerPlayerSceneServiceImpl>(new PlayerSceneServiceImpl));
}
}//namespace game
