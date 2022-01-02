#include "message_sys.hpp"

#include "muduo/base/Logging.h"

#include "src/common_type/common_type.h"
#include "src/game_logic/comp/gs_scene_comp.hpp"
#include "src/game_logic/game_registry.h"
#include "src/server_common/server_component.h"

using namespace common;

namespace master
{
    void Send2GS(const google::protobuf::Message& message,
        const std::string& service,
        const std::string& stub,
        entt::entity player_entity)
{
    auto ptr_gse = reg.try_get<GSEntity>(player_entity);
    if (nullptr == ptr_gse)
    {
        LOG_ERROR << "player send message empty server:" << reg.get<Guid>(player_entity)
            << "message:" << message.GetTypeName();
        return;
    }
    auto& gs = reg.get<RpcServerConnection>(ptr_gse->server_entity());
    gs.Send(message, service, stub);
}

}//namespace master