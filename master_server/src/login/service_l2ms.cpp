#include "service_l2ms.h"

#include "src/common_type/common_type.h"
#include "src/game_logic/comp/player.hpp"
#include "src/game_logic/game_registry.h"
#include "src/master_player/master_player_list.h"
#include "src/master_server.h"
#include "src/server_common/closure_auto_done.h"
#include "src/game/game_client.h"

#include "ms2gw.pb.h"

using namespace master;
using namespace common;

namespace l2ms
{
    void l2ms::LoginServiceImpl::EnterGame(::google::protobuf::RpcController* controller,
        const ::l2ms::EnterGameRequest* request,
        ::l2ms::EnterGameResponse* response,
        ::google::protobuf::Closure* done)
    {
        ClosurePtr cp(done);
        auto player_id = request->player_id();   
        auto connection_id = request->connection_id();
        auto e = reg().create();
        reg().emplace<GameGuid>(e, player_id);
        reg().emplace<SharedAccountString>(e, std::make_shared<std::string>(request->account()));
        reg().emplace<GatewayConnectionId>(e, connection_id);
        MasterPlayerList::GetSingleton().EnterGame(player_id, e);

        ms2gw::PlayerEnterGameServerRequest gw_request;
        gw_request.set_connection_id(connection_id);
        gw_request.set_player_id(player_id);
        for (auto e : GameClient::GetSingleton()->view<uint32_t>())
        {
            gw_request.set_server_id(GameClient::GetSingleton()->get<uint32_t>(e));
            break;
        }
        
        g_master_server->gate_client()->Send(gw_request, "ms2gw.Ms2gwService", "PlayerEnterGameServer");
    }

    void LoginServiceImpl::LeaveGame(::google::protobuf::RpcController* controller, 
        const ::l2ms::LeaveGameRequest* request, 
        ::l2ms::LeaveGameResponse* response,
        ::google::protobuf::Closure* done)
    {
        ClosurePtr cp(done);
        auto player_id = request->player_id();
        auto e = MasterPlayerList::GetSingleton().GetPlayer(player_id);
        if (e != entt::null)
        {
            assert(reg().get<GameGuid>(e) == player_id);
            reg().destroy(e);
        }
        MasterPlayerList::GetSingleton().LeaveGame(player_id);
        assert(!MasterPlayerList::GetSingleton().HasPlayer(player_id));
        assert(MasterPlayerList::GetSingleton().GetPlayer(player_id) == entt::null);        
    }

    void LoginServiceImpl::Disconect(::google::protobuf::RpcController* controller, 
        const ::l2ms::DisconectRequest* request,
        ::l2ms::DisconectResponse* response,
        ::google::protobuf::Closure* done)
    {
        ClosurePtr cp(done);
    }

}//namespace master



