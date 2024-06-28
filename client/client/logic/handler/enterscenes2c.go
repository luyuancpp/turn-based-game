package handler

import (
	"client/logic"
	"client/pb/game"
	"client/pkg"
	"log"
)

func EnterSceneS2CHandler(client *pkg.GameClient, response *game.EnterSceneS2C) {
	log.Println(response)
	logic.GMainPlayer.SceneId = response.SceneInfo.Guid
	logic.GMainPlayer.Send(&game.SceneInfoRequest{}, 23)
}