#include "server_message_parser.h"

std::vector<std::string> ServerMessageParser::splitServerMessage(std::string message) {
    message = removeBrackets(message);
    std::vector<std::string> splitedMessage;
    std::string info;
    std::stringstream ss(message);
    while( getline(ss, info, ' ') ) {
        info = removeBrackets(info);
        splitedMessage.push_back(info);
    }
    return splitedMessage;
}

std::string ServerMessageParser::removeBrackets(std::string message) {

    while(!message.empty() && (message[0] == '(' || message[0] == ')')) {
        message = message.substr(1);
    }
    
    while(!message.empty() && (message.back() == '(' || message.back() == ')')) {
        message = message.substr(0, message.size() - 1);
    }

    return message;
}
