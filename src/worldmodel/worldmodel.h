#include <iostream>

class WorldModel {
    private:
        int M_unum;
        char M_side;
        std::string M_gamemode;
        std::pair<double, double> ballPosition;
    
    public:
        WorldModel() = default;
        ~WorldModel() = default;

        void setWorldModelInfomation(std::string serverMessage, std::vector<std::string> parsedMessage);

        void setUnum(int unum) {
            M_unum = unum;
        }

        void setSide(char side) {
            M_side = side;
        }

        void setGamemode(std::string gamemode) {
            M_gamemode = gamemode;
        }

        void setBallPosition(std::pair<double, double> ballPos) {
            ballPosition = ballPos;
        }

        int getUnum() {
            return M_unum;
        }

        char getSide() {
            return M_side;
        }

        std::string getGamemode() {
            return M_gamemode;
        }

        std::pair<double, double> getBallPosition() {
            return ballPosition;
        }

};