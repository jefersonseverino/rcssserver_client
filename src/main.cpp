#include <unistd.h>
#include <chrono>
#include <thread>
#include <bits/stdc++.h>

#include "player.h"

void sendAction(Player * player) {
    // main loop (actions)
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if(player->wm.getGamemode() == "before_kick_off") {
            std::string message = player->formationParser.readBeforeKickOffFormation(player->wm.getUnum());
            const char * position = message.c_str();
            player->sendMessage(position);
        }else if(player->wm.getGamemode() == "kick_off_l") {
            if(player->wm.getUnum() == 11) {
                const char * firstKick = "(kick 40 0)";
                player->sendMessage(firstKick);
            }
        }else if(player->wm.getGamemode() == "play_on") {
            if(player->wm.getUnum() == 11) {
                const char * goToBallPosition = "(dash 100)";
                player->sendMessage(goToBallPosition);
            }
        }
    }
}

int main(int argc, char * argv[]) {

    Player player;
    player.client.createSocket();
    int socketfd = player.client.getSocketFileDescriptor();

    // Connection message
    if(argc == 2) {
        player.sendMessage(player.client.getGoalieInitMessage());
    }else{
        player.sendMessage(player.client.getPlayerInitMessage());
    }

    std::thread actionThread(sendAction, &player);

    // main loop (listening)
    while(true) {
        std::string message = player.client.receiveMessageFromServer();
        std::vector<std::string> messageParsed = player.parser.splitServerMessage(message);
        player.wm.setWorldModelInfomation(message, messageParsed);
    }

    actionThread.join();
    freeaddrinfo(player.client.getServerInfo());
    close(socketfd);
    return 0;
}
