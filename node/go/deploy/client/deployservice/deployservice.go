// Code generated by goctl. DO NOT EDIT.
// Source: deploy_service.proto

package deployservice

import (
	"context"

	"deploy_server/pb/game"

	"github.com/zeromicro/go-zero/zrpc"
	"google.golang.org/grpc"
)

type (
	CentreServerDb          = game.CentreServerDb
	DatabaseServerDb        = game.DatabaseServerDb
	GameServerDb            = game.GameServerDb
	GateServerDb            = game.GateServerDb
	GetGameNodeInfoRequest  = game.GetGameNodeInfoRequest
	GetGameNodeInfoResponse = game.GetGameNodeInfoResponse
	LobbyServerDb           = game.LobbyServerDb
	LoginServerDb           = game.LoginServerDb
	NewGameNodeRequest      = game.NewGameNodeRequest
	NewGameNodeResponse     = game.NewGameNodeResponse
	NodeInfoRequest         = game.NodeInfoRequest
	NodeInfoResponse        = game.NodeInfoResponse
	RedisServerDb           = game.RedisServerDb
	ServersInfoData         = game.ServersInfoData

	DeployService interface {
		GetNodeInfo(ctx context.Context, in *NodeInfoRequest, opts ...grpc.CallOption) (*NodeInfoResponse, error)
		NewGameNode(ctx context.Context, in *NewGameNodeRequest, opts ...grpc.CallOption) (*NewGameNodeResponse, error)
		GetGameNodeInfo(ctx context.Context, in *GetGameNodeInfoRequest, opts ...grpc.CallOption) (*GetGameNodeInfoResponse, error)
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

func (m *defaultDeployService) NewGameNode(ctx context.Context, in *NewGameNodeRequest, opts ...grpc.CallOption) (*NewGameNodeResponse, error) {
	client := game.NewDeployServiceClient(m.cli.Conn())
	return client.NewGameNode(ctx, in, opts...)
}

func (m *defaultDeployService) GetGameNodeInfo(ctx context.Context, in *GetGameNodeInfoRequest, opts ...grpc.CallOption) (*GetGameNodeInfoResponse, error) {
	client := game.NewDeployServiceClient(m.cli.Conn())
	return client.GetGameNodeInfo(ctx, in, opts...)
}
