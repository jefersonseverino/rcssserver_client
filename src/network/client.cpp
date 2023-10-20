#include "client.h"

void Client::createSocket() {

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    int info = getaddrinfo(
        "localhost",
        PORT,
        &hints,
        &serverinfo
    );

    for(p = serverinfo; p != NULL; p = p->ai_next) {
        if((M_socket_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket error");
            continue;
        }
        break;
    }

    if(p == NULL) {
        perror("Failed to create socket");
        return ;
    }

}

void Client::sendMessageToServer(const char * message) {
    int n = sendto(M_socket_fd, message, strlen(message), 0, p->ai_addr, p->ai_addrlen);
}

std::string Client::receiveMessageFromServer(){
    static char receivedMessage[8192];
    std::string message;

    int bytesRead = recvfrom(
        M_socket_fd,
        receivedMessage,
        sizeof(receivedMessage),
        0,
        serverinfo->ai_addr,
        &serverinfo->ai_addrlen
    );

    if(bytesRead > 0) {
        if(receivedMessage[bytesRead - 1] == '\0') {
            message.assign(receivedMessage, bytesRead - 1);
        }else{
            message.assign(receivedMessage, bytesRead);
        }
    }

    return message;
}
