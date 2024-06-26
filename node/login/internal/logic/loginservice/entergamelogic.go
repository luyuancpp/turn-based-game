package loginservicelogic

import (
	"context"
	"github.com/golang/protobuf/proto"
	"login/data"
	"strconv"

	"login/internal/svc"
	"login/pb/game"

	"github.com/zeromicro/go-zero/core/logx"
)

type EnterGameLogic struct {
	ctx    context.Context
	svcCtx *svc.ServiceContext
	logx.Logger
}

func NewEnterGameLogic(ctx context.Context, svcCtx *svc.ServiceContext) *EnterGameLogic {
	return &EnterGameLogic{
		ctx:    ctx,
		svcCtx: svcCtx,
		Logger: logx.WithContext(ctx),
	}
}

func (l *EnterGameLogic) EnterGame(in *game.EnterGameC2LRequest) (*game.EnterGameC2LResponse, error) {
	sessionId := strconv.FormatUint(in.SessionInfo.SessionId, 10)
	defer data.SessionList.Remove(sessionId)
	playerIdStr := strconv.FormatUint(in.ClientMsgBody.PlayerId, 10)
	_, ok := data.SessionList.Get(sessionId)
	resp := &game.EnterGameC2LResponse{
		ClientMsgBody: &game.EnterGameResponse{Error: &game.Tip{}},
		SessionInfo:   in.SessionInfo}
	if !ok {
		resp.ClientMsgBody.Error = &game.Tip{Id: 1005}
		return resp, nil
	}

	reflection := proto.MessageReflect(&game.PlayerDatabase{})
	key := string(reflection.Descriptor().FullName()) + playerIdStr
	cmd := l.svcCtx.Redis.Get(l.ctx, key)
	if len(cmd.Val()) == 0 {
		_, err := l.svcCtx.DBPlayerService.Load2Redis(l.ctx, &game.LoadPlayerRequest{PlayerId: in.ClientMsgBody.PlayerId})
		if err != nil {
			resp.ClientMsgBody.Error = &game.Tip{Id: 1005}
			return resp, err
		}
	}

	centreEnterGame := &game.EnterGameL2Ctr{ClientMsgBody: in.ClientMsgBody, SessionInfo: in.SessionInfo}
	l.svcCtx.CentreClient.Send(centreEnterGame, 54)
	return resp, nil
}
