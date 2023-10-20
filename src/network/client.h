#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <bits/stdc++.h>

class Client {
    public:
        Client() = default;
        ~Client() = default;

        void createSocket();
        void sendMessageToServer(const char * message);
        std::string receiveMessageFromServer();

        const char * getGoalieInitMessage() {
            return goalieInitMessage;
        }

        const char * getPlayerInitMessage() {
            return playerInitMessage;
        }

        int getSocketFileDescriptor() {
            return M_socket_fd;
        }

        struct addrinfo* getAddressInfo() {
            return p;
        }

        struct addrinfo* getServerInfo() {
            return serverinfo;
        }

    private:
        int M_socket_fd;
        struct addrinfo hints, *serverinfo, *p;
        const char * PORT = "6000";
        const char * goalieInitMessage = "(init RoboCIn (goalie))";
        const char * playerInitMessage = "(init RoboCIn)";

};