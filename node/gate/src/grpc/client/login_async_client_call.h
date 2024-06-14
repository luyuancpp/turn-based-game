#pragma once

#include <grpcpp/grpcpp.h>

#include "common_proto/login_service.pb.h"
#include "common_proto/login_service.grpc.pb.h"

using grpc::ClientContext;
using grpc::Status;
using grpc::ClientAsyncResponseReader;

class LoginC2LAsyncClientCall
{
public:
    ClientContext context;
    Status status;

    LoginC2LResponse reply;
    std::unique_ptr<ClientAsyncResponseReader<LoginC2LResponse>> response_reader;
};

class CreatePlayerC2LAsyncClientCall
{
public:
    ClientContext context;
    Status status;

    CreatePlayerC2LResponse reply;
    std::unique_ptr<ClientAsyncResponseReader<CreatePlayerC2LResponse>> response_reader;
};