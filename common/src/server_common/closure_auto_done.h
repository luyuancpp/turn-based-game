#ifndef COMMON_SRC_server_common_CLOSURE_AUTO_DONE_H_
#define COMMON_SRC_server_common_CLOSURE_AUTO_DONE_H_

#include <memory>

#include "google/protobuf/stubs/callback.h"

namespace common
{
    class ClosureDeleter {
    public:
        void operator()(::google::protobuf::Closure* done) { done->Run(); }
    };

    using AutoRecycleClosure = std::unique_ptr<::google::protobuf::Closure, ClosureDeleter>;

}//namespace common

#endif//COMMON_SRC_server_common_CLOSURE_AUTO_DONE_H_