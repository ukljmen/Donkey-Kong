
#ifndef DK_DKBOARD_H
#define DK_DKBOARD_H

#include "Mario.h"
#include <iostream>>
#include <vector>

enum GameState {
    RUNNING, FINISHED_WON, FINISHED_LOST
};

class DKBoard {

    Mario luigi;
    int time;
    GameState state;
    int boardHeight = 510;
    std::vector<std::pair<int, int>> barrelVector;


public:
    DKBoard();

    void goLeft();

    void goRight();

    void Jump();

    void endJumpLadder();

    void goUP();

    void goDown();

    void ladderStart();

    GameState getGameState();

    void setGameStateLost();

    void setGameStateWon();

    int getBoardHeight();

    int getMarioX() const;

    int getMarioY() const;

    MarioState getMarioState() const;

    std::vector<std::pair<int, int>> getBarrelVec();

    void barrelGoDown(int n);

    void barrelGoLeft(int n);

    void barrelGoRight(int n);

    void createBarrel();

    void eraseBarrel();

    void addTime();

    int getTime() const;


};


#endif //DK_DKBOARD_H
