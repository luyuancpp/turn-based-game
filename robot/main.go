package main

import (
	"client/config"
	"client/logic/handler"
	"client/pb/game"
	"client/pkg"
	"go.uber.org/zap"
	"go.uber.org/zap/zapcore"
	"strconv"

	"github.com/luyuancpp/muduoclient/muduo"
	"sync"
)

func main() {
	// 初始化日志记录器
	logger, err := zap.NewProduction()
	if err != nil {
		panic(err)
	}
	defer logger.Sync()
	zap.ReplaceGlobals(logger)

	// 配置日志级别
	lvl := zap.NewAtomicLevel()
	lvl.SetLevel(zapcore.Level(config.AppConfig.LogLevel)) // 根据需要调整日志级别

	var wg sync.WaitGroup

	for i := 0; i < config.AppConfig.Robots.Count; i++ {
		wg.Add(1)
		go func(i int) {
			defer wg.Done()

			client, err := muduo.NewClient(config.AppConfig.Server.IP, config.AppConfig.Server.Port, &muduo.TcpCodec{})
			if err != nil {
				zap.L().Error("Failed to create client", zap.Error(err))
				return
			}
			gameClient := pkg.NewGameClient(client)
			defer gameClient.Close()

			// 登录请求
			rq := &game.LoginRequest{Account: "luhailong" + strconv.Itoa(i), Password: "luhailong"}
			gameClient.Send(rq, game.LoginServiceLoginMessageId)

			// 处理消息
			for {
				msg := <-gameClient.Client.Conn.InMsgList
				d := muduo.GetDescriptor(&msg)
				switch d.Name() {
				case "LoginResponse":
					resp := msg.(*game.LoginResponse)
					handler.LoginHandler(gameClient, resp)
				case "CreatePlayerResponse":
					resp := msg.(*game.CreatePlayerResponse)
					handler.CreatePlayerHandler(gameClient, resp)
				case "MessageBody":
					resp := msg.(*game.MessageBody)
					handler.MessageBodyHandler(gameClient, resp)
				default:
					zap.L().Warn("Unhandled message type", zap.String("message_type", string(d.Name())))
				}

				gameClient.TickBehaviorTree()
			}
		}(i)
	}

	// 等待所有 goroutine 完成
	wg.Wait()
}
