#include <bits/stdc++.h>

class ServerMessageParser {
    public:
        ServerMessageParser() = default;
        ~ServerMessageParser() = default;
        std::vector<std::string> splitServerMessage(std::string message);
        std::string removeBrackets(std::string message);
};
