ps -ef | grep deploy_server | grep -v grep | awk '{print $2}' | xargs kill -9
ps -ef | grep lobby_server | grep -v grep | awk '{print $2}' | xargs kill -9
ps -ef | grep database_server | grep -v grep | awk '{print $2}' | xargs kill -9
ps -ef | grep controller_server | grep -v grep | awk '{print $2}' | xargs kill -9
ps -ef | grep login_server | grep -v grep | awk '{print $2}' | xargs kill -9
ps -ef | grep game_server | grep -v grep | awk '{print $2}' | xargs kill -9
ps -ef | grep gate_server | grep -v grep | awk '{print $2}' | xargs kill -9
