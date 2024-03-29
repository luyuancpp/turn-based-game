#pragma once

#include "common_proto/common.pb.h"
#include "common_proto/deploy_config.pb.h"

class LobbyConfig
{
public:
	const LobbyConfigInfo& config_info() const { return config_info_; }

	static LobbyConfig& GetSingleton() {
		static LobbyConfig singleton;
		return singleton;
	}

	void Load(const std::string& filename);
private:
	LobbyConfigInfo config_info_;
};

