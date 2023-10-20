#include <bits/stdc++.h>
#include "worldmodel.h"

void WorldModel::setWorldModelInfomation(std::string serverMessage, std::vector<std::string> parsedMessage) {

    if(serverMessage.substr(1, 4) == "init"){
        // set initial info
        char playerSide = parsedMessage[1][0];
        int playerUnum = stoi(parsedMessage[2]);
        setSide(playerSide);
        setUnum(playerUnum);
        setGamemode("before_kick_off");
    }

    if(serverMessage.substr(1, 4) == "hear") {
        // playmode change
        setGamemode(parsedMessage[3]);
    }

    if(serverMessage.substr(1, 3) == "see") {
        // update info about world objects
        int size = parsedMessage.size();

        for(int i = 0;i < size;i++) {
            if(parsedMessage[i] == "ball") {
                double ballPosX = stod(parsedMessage[i + 1]) - 52.5;
                double ballPosY = stod(parsedMessage[i + 2]);
                std::pair<double, double> ballPos = std::make_pair(ballPosX, ballPosY);
                setBallPosition(ballPos);
            }
        }
    }

} 