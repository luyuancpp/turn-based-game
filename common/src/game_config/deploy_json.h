#pragma once

#include "common.pb.h"


class GameConfig
{
public:
    const GameConfigInfo& config_info() const { return config_info_; }

    static GameConfig& GetSingleton() {
        thread_local GameConfig singleton;
        return singleton;
    }

    void Load(const std::string& filename);
private:
    GameConfigInfo config_info_;
};

class DeployConfig
{
public:
    enum ConnectionDeployEnum
    {
        SERVER_DATABASE = 0,
        SERVER_DEPLOY = 1,
    };
    const ConnetionParam& database_param() { return connetion_param_.data(SERVER_DATABASE); }
    const ConnetionParam& deploy_info() { return connetion_param_.data(SERVER_DEPLOY); }

    static DeployConfig& GetSingleton() {
        thread_local DeployConfig singleton;
        return singleton;
    }

    void Load(const std::string& filename);

private:
    ConnetionParamJsonFormat connetion_param_;
};


