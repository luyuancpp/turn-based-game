#ifndef COMMON_SRC_RETURN_CODE_Return_Notice_Code
#define COMMON_SRC_RETURN_CODE_Return_Notice_Code

#include <cstdint>
#include <string>
#include <vector>

namespace common
{
    enum  EnumCode : uint32_t
    {
        RET_OK = 1,

        //login server 
        RET_LOGIN_CNAT_FIND_ACCOUNT = 1000,
        RET_LOGIN_MAX_PLAYER_SIZE = 1001,
        RET_LOGIN_CREATE_PLAYER_DONOT_LOAD_ACCOUNT = 1002,
        RET_LOGIN_CREATE_PLAYER_CONNECTION_HAS_NOT_ACCOUNT = 1003,

        //TeamRet
        RET_TEAM_NOT_IN_APPLICANTS = 5000,
        RET_TEAM_PLAEYR_ID = 5001,
        RET_TEAM_MEMBERS_FULL = 5002,
        RET_TEAM_MEMBER_IN_TEAM = 5003,
        RET_TEAM_MEMBER_NOT_IN_TEAM = 5004,
        RET_TEAM_KICK_SELF = 5005,
        RET_TEAM_KICK_NOT_LEADER = 5006,
        RET_TEAM_APPOINT_SELF = 5007,
        RET_TEAM_APPOINT_LEADER_NOT_LEADER = 5008,
        RET_TEAM_TEAM_FULL = 5009,
        RET_TEAM_IN_APPLICANT_LIEST = 5010,
        RET_TEAM_NOT_IN_APPLICANT_LIEST = 5011,
        RET_TEAM_TEAM_LIST_MAX = 5012,
        RET_TEAM_HAS_NOT_TEAM_ID = 5013,
        RET_TEAM_DISMISS_NOT_LEADER = 5014,
    };
}//namespace common

#define RET_CHECK_RET(f)\
{\
ReturnValue ret = (f);\
if (ret != ReturnValue(RET_OK))\
{\
    return  ret;\
}\
}

#define  ReturnCloseureError(f)\
response->mutable_error()->set_error_no(f);\
done->Run();\
return;


#endif // !COMMON_SRC_RETURN_CODE_Return_Notice_Code
