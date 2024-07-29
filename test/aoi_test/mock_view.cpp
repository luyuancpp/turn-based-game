#include "system/scene/view.h"

#include "type_define/type_define.h"
#include "thread_local/storage.h"

extern EntityUnorderedMap entitiesToNotifyEntry;
extern EntityUnorderedMap entitiesToNotifyExit;

bool ViewSystem::CheckSendNpcEnterMessage(entt::entity observer, entt::entity entity) {
    return true; // Mock behavior
}

bool ViewSystem::CheckSendPlayerEnterMessage(entt::entity observer, entt::entity entity) {
    
    return true; // Mock behavior
}

void ViewSystem::FillActorCreateS2CInfo(entt::entity observer, entt::entity entity, ActorCreateS2C& actorCreateMessage) {
    entitiesToNotifyEntry.emplace(observer, entity);
}

void ViewSystem::HandlerPlayerLeaveMessage(entt::entity observer, entt::entity leaver)
{
    entitiesToNotifyExit.emplace(observer, leaver);
}