#include "service_l2ms.h"

#include "muduo/base/Logging.h"

#include "src/common_type/common_type.h"
#include "src/game_logic/comp/player.hpp"
#include "src/game_logic/game_registry.h"
#include "src/game/game_client.h"
#include "src/master_player/master_player_list.h"
#include "src/master_server.h"
#include "src/server_common/closure_auto_done.h"


#include "ms2gw.pb.h"

using namespace master;
using namespace common;

namespace l2ms
{
    void l2ms::LoginServiceImpl::EnterGame(::google::protobuf::RpcController* controller,
        const ::l2ms::EnterGameRequest* request,
        ::l2ms::EnterGameResponese* response,
        ::google::protobuf::Closure* done)
    {
        ClosurePtr cp(done);
        auto guid = request->guid();   
        auto connection_id = request->connection_id();
        auto e = reg().create();
        reg().emplace<GameGuid>(e, guid);
        reg().emplace<SharedAccountString>(e, std::make_shared<std::string>(request->account()));
        reg().emplace<GatewayConnectionId>(e, connection_id);
        MasterPlayerList::GetSingleton().EnterGame(guid, e);

        ms2gw::PlayerEnterGameServerRequest gw_request;
        gw_request.set_connection_id(connection_id);
        for (auto e : GameClient::GetSingleton()->view<uint32_t>())
        {
            response->set_game_server_id(GameClient::GetSingleton()->get<uint32_t>(e));
            break;
        }
    }

    void LoginServiceImpl::LeaveGame(::google::protobuf::RpcController* controller, 
        const ::l2ms::LeaveGameRequest* request, 
        ::google::protobuf::Empty* response,
        ::google::protobuf::Closure* done)
    {
        ClosurePtr cp(done);
        auto guid = request->guid();
        auto e = MasterPlayerList::GetSingleton().GetPlayer(guid);
        assert(reg().get<GameGuid>(e) == guid);
        reg().destroy(e);
        MasterPlayerList::GetSingleton().LeaveGame(guid);  
        assert(!MasterPlayerList::GetSingleton().HasPlayer(guid));
        assert(MasterPlayerList::GetSingleton().GetPlayer(guid) == entt::null); 
    }

    void LoginServiceImpl::Disconect(::google::protobuf::RpcController* controller, 
        const ::l2ms::DisconnectRequest* request,
        ::google::protobuf::Empty* response,
        ::google::protobuf::Closure* done)
    {
        ClosurePtr cp(done);
        auto guid = request->guid();
        auto e = MasterPlayerList::GetSingleton().GetPlayer(guid);
        if (entt::null  == e)
        {
            return;
        }
        assert(reg().get<GameGuid>(e) == guid);
        reg().destroy(e);
        MasterPlayerList::GetSingleton().LeaveGame(guid);
        assert(!MasterPlayerList::GetSingleton().HasPlayer(guid));
        assert(MasterPlayerList::GetSingleton().GetPlayer(guid) == entt::null);
    }

}//namespace master



