// Code generated by goctl. DO NOT EDIT.
// Source: deploy_service.proto

package deployservice

import (
	"context"

	"deploy/pb/game"

	"github.com/zeromicro/go-zero/zrpc"
	"google.golang.org/grpc"
)

type (
	CentreNodeDb            = game.CentreNodeDb
	CentreNodeListDb        = game.CentreNodeListDb
	DatabaseNodeDb          = game.DatabaseNodeDb
	GameNodeDb              = game.GameNodeDb
	GameNodeListDb          = game.GameNodeListDb
	GateNodeDb              = game.GateNodeDb
	GateNodeListDb          = game.GateNodeListDb
	GetGameNodeInfoRequest  = game.GetGameNodeInfoRequest
	GetGameNodeInfoResponse = game.GetGameNodeInfoResponse
	LobbyNodeDb             = game.LobbyNodeDb
	LoginNodeDb             = game.LoginNodeDb
	LoginNodeListDb         = game.LoginNodeListDb
	NewGameNodeRequest      = game.NewGameNodeRequest
	NewGameNodeResponse     = game.NewGameNodeResponse
	NodeInfoRequest         = game.NodeInfoRequest
	NodeInfoResponse        = game.NodeInfoResponse
	NodesInfoData           = game.NodesInfoData
	RedisNodeDb             = game.RedisNodeDb
	RedisNodeListDb         = game.RedisNodeListDb

	DeployService interface {
		GetNodeInfo(ctx context.Context, in *NodeInfoRequest, opts ...grpc.CallOption) (*NodeInfoResponse, error)
	}

	defaultDeployService struct {
		cli zrpc.Client
	}
)

func NewDeployService(cli zrpc.Client) DeployService {
	return &defaultDeployService{
		cli: cli,
	}
}

func (m *defaultDeployService) GetNodeInfo(ctx context.Context, in *NodeInfoRequest, opts ...grpc.CallOption) (*NodeInfoResponse, error) {
	client := game.NewDeployServiceClient(m.cli.Conn())
	return client.GetNodeInfo(ctx, in, opts...)
}
