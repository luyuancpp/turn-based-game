// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//
// This is a public header file, it must only include public header files.

#ifndef COMMON_SRC_GAME_RPC_GAME_RPC_SERVER_H_
#define COMMON_SRC_GAME_RPC_GAME_RPC_SERVER_H_

#include "muduo/net/TcpServer.h"

namespace google {
namespace protobuf {

class Service;

}  // namespace protobuf
}  // namespace google

namespace common
{

class GameRpcServer
{
 public:
  GameRpcServer(muduo::net::EventLoop* loop,
            const muduo::net::InetAddress& listenAddr);

  void setThreadNum(int numThreads)
  {
    server_.setThreadNum(numThreads);
  }

  void registerService(::google::protobuf::Service*);
  void start();

 private:
  void onConnection(const muduo::net::TcpConnectionPtr& conn);

  // void onMessage(const TcpConnectionPtr& conn,
  //                Buffer* buf,
  //                Timestamp time);

  muduo::net::TcpServer server_;
  std::map<std::string, ::google::protobuf::Service*> services_;
};

}  // namespace common


#endif  // COMMON_SRC_GAME_RPC_GAME_RPC_SERVER_H_
