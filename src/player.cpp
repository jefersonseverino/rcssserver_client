#include "player.h"

void Player::sendMessage(const char * message) {
    this->client.sendMessageToServer(message);
}
