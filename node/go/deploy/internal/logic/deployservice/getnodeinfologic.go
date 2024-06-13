package deployservicelogic

import (
	"context"
	"deploy/pkg"
	"strconv"

	"deploy/internal/svc"
	"deploy/pb/game"

	"github.com/zeromicro/go-zero/core/logx"
)

type GetNodeInfoLogic struct {
	ctx    context.Context
	svcCtx *svc.ServiceContext
	logx.Logger
}

func NewGetNodeInfoLogic(ctx context.Context, svcCtx *svc.ServiceContext) *GetNodeInfoLogic {
	return &GetNodeInfoLogic{
		ctx:    ctx,
		svcCtx: svcCtx,
		Logger: logx.WithContext(ctx),
	}
}

func (l *GetNodeInfoLogic) GetNodeInfo(in *game.NodeInfoRequest) (*game.NodeInfoResponse, error) {
	response := &game.NodeInfoResponse{
		Info: &game.ServersInfoData{
			DatabaseInfo: &game.DatabaseServerDb{},
			LoginInfo:    []*game.LoginServerDb{},
			CentreInfo:   []*game.CentreServerDb{},
			GateInfo:     []*game.GateServerDb{},
			GameInfo:     []*game.GameServerDb{},
			RedisInfo:    []*game.RedisServerDb{},
		},
	}

	zoneId := strconv.FormatUint(uint64(in.GetZoneId()), 10)
	pkg.PbDb.LoadListByWhereCase(response.Info.GetDatabaseInfo(), "where zone_id="+zoneId)
	pkg.PbDb.LoadListByWhereCase(response.Info.GetLoginInfo(), "where zone_id="+zoneId)
	pkg.PbDb.LoadListByWhereCase(response.Info.GetCentreInfo(), "where zone_id="+zoneId)
	pkg.PbDb.LoadListByWhereCase(response.Info.GetGameInfo(), "where zone_id="+zoneId)
	pkg.PbDb.LoadListByWhereCase(response.Info.GetGateInfo(), "where zone_id="+zoneId)
	pkg.PbDb.LoadListByWhereCase(response.Info.GetRedisInfo(), "where zone_id="+zoneId)

	return response, nil
}
