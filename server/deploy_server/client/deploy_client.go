package client

import (
	"deploy_server/client/deployservice"
	"flag"
	"fmt"
	"github.com/zeromicro/zero-examples/rpc/remote/unary"
	"time"
)

package main

import (
"context"
"flag"
"fmt"
"time"

"github.com/zeromicro/go-zero/core/conf"
"github.com/zeromicro/go-zero/zrpc"
"github.com/zeromicro/zero-examples/rpc/remote/unary"
)

var configFile = flag.String("f", "config.json", "the config file")

func main() {
	flag.Parse()

	var c zrpc.RpcClientConf
	conf.MustLoad(*configFile, &c)
	client := zrpc.MustNewClient(c)
	ticker := time.NewTicker(time.Millisecond * 500)
	defer ticker.Stop()
	for {
		select {
		case <-ticker.C:
			deploy := deployservice.NewDeployService(client)
			resp, err := deploy.StartGs(context.Background(), &unary.Request{
				Name: "kevin",
			})
			if err != nil {
				fmt.Println("X", err.Error())
			} else {
				fmt.Println("=>", resp.Greet)
			}
			break
		}
	}
}
