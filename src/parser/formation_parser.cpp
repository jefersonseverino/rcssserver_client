#include "formation_parser.h"

std::string FormationParser::readBeforeKickOffFormation(int playerUnum) {
    // Read before kick off formation
    std::ifstream inputFile("formations/kick_off_formation.txt");
    std::string line;
    std::vector<std::string> info;

    while( getline(inputFile, line) ) {
        std::string number;
        std::stringstream ss(line);
        while(ss >> number) {
            info.push_back(number);
        }
        if(info[0] == std::to_string(playerUnum) ) {
            break;
        }
        info.clear();
    }

    std::string message = "(move " + info[1] + " " + info[2] +  ")";
    return message;
}