#include <array>
#include <memory>
#include <google/protobuf/message.h>

#include "scene.h"
#include "team.h"
std::array<std::unique_ptr<::google::protobuf::Service>, 2> g_server_service{
std::unique_ptr<::google::protobuf::Service>(new ServerSceneServiceImpl),
std::unique_ptr<::google::protobuf::Service>(new S2STeamServiceImpl)};