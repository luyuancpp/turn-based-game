#include "src/client.h"

#include "google/protobuf/util/json_util.h"

#include "src/util/file2string.h"
#include "src/thread_local/thread_local_storage.h"
#include "src/luacpp/lua_module.h"
#include "service/service.h"


int main(int argc, char* argv[])
{
    LOG_INFO << "pid = " << getpid();

    if (argc > 0)
    {
        InitMessageInfo();

        void InitPlayerService();
        InitPlayerService();

        
        void InitServiceLua();
   
        int32_t nClients = 1;

        if (argc > 1)
        {
            nClients = atoi(argv[1]);
        }
        EventLoop loop;

        loop.runInLoop(InitLua);
        loop.runInLoop(InitServiceLua);

        
        gAllFinish = tls.registry.create();
        tls.registry.emplace<uint32_t>(gAllFinish, nClients);

        auto contents = File2String("client.json");
        absl::string_view sv(contents.data(), contents.size());
        ConnetionParamJsonFormat connetion_param_;
        auto result =  google::protobuf::util::JsonStringToMessage(sv, &connetion_param_);
		if (!result.ok()) {
			LOG_FATAL << result.message().data();
		}
        InetAddress serverAddr(connetion_param_.data(0).ip(), connetion_param_.data(0).port());
  
        muduo::Logger::setLogLevel(muduo::Logger::WARN);
        std::vector<std::unique_ptr<PlayerClient>> clients;
        for (int i = 0; i < nClients; ++i)
        {
            clients.emplace_back(new PlayerClient(&loop,
                serverAddr));
            clients.back()->connect();
        }
        Timestamp start(Timestamp::now());
        muduo::Logger::setLogLevel(muduo::Logger::INFO);
        loop.loop();
        Timestamp end(Timestamp::now());
        double seconds = timeDifference(end, start);
        LOG_INFO << seconds << "seconds\n";
        muduo::Logger::setLogLevel(muduo::Logger::WARN);
    }
    else
    {
        printf("Usage: %s host_ip numClients [numThreads]\n", argv[0]);
    }
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}

