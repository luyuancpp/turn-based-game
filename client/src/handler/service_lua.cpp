#include <sol/sol.hpp>
#include "muduo/base/Logging.h"
#include "src/util/file2string.h"
#include "src/game_logic/thread_local/thread_local_storage_lua.h"
void LoadLuaScript()
{
	std::string contents;
	contents = File2String("script/lua/service/client.lua");
	{
		auto r = tls_lua_state.script(contents);
		if (!r.valid())
		{
			sol::error err = r;
			LOG_FATAL << err.what();
		}
	}
	contents = File2String("script/lua/service/common_client_player.lua");
	{
		auto r = tls_lua_state.script(contents);
		if (!r.valid())
		{
			sol::error err = r;
			LOG_FATAL << err.what();
		}
	}
	contents = File2String("script/lua/service/scene_client_player.lua");
	{
		auto r = tls_lua_state.script(contents);
		if (!r.valid())
		{
			sol::error err = r;
			LOG_FATAL << err.what();
		}
	}
	contents = File2String("script/lua/service/team_client_player.lua");
	{
		auto r = tls_lua_state.script(contents);
		if (!r.valid())
		{
			sol::error err = r;
			LOG_FATAL << err.what();
		}
	}

}
