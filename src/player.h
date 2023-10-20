#include <bits/stdc++.h>
#include "worldmodel/worldmodel.h"
#include "network/client.h"
#include "parser/server_message_parser.h"
#include "parser/formation_parser.h"

class Player {
    public:
        Player() = default;
        ~Player() = default;

        WorldModel wm;
        ServerMessageParser parser;
        FormationParser formationParser;
        Client client;

        void sendMessage(const char * message);
};
