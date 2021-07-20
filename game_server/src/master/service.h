#ifndef GAME_SERVER_MASTER_SERVICE_SERVICE_H_
#define GAME_SERVER_MASTER_SERVICE_SERVICE_H_

#include "ms2g.pb.h"

namespace ms2g
{
    class Ms2gServiceImpl : public Ms2gService
    {
    public:
        void Login(::google::protobuf::RpcController* controller,
            const ::ms2g::LoginRequest* request,
            ::ms2g::LoginResponse* response,
            ::google::protobuf::Closure* done)override;
    private:

    };
}//namespace ms2g

#endif//GAME_SERVER_MASTER_SERVICE_SERVICE_H_
