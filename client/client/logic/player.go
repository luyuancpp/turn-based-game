package logic

import (
	"client/pb/game"
	"client/pkg"
	"log"
)

type Player struct {
	PlayerId uint64
	Client   *pkg.GameClient
}

func NewPlayer(playerId uint64, client *pkg.GameClient) *Player {
	return &Player{PlayerId: playerId, Client: client}
}

func (player *Player) EnterGame() {
	rq := &game.EnterGameRequest{PlayerId: player.PlayerId}
	player.Client.Send(rq, 52)
	msg := <-player.Client.Client.Conn.InMsgList
	log.Println(msg)
	msg = <-player.Client.Client.Conn.InMsgList
}