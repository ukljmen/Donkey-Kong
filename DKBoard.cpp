
#include "DKBoard.h"

DKBoard::DKBoard() {
    state = RUNNING;
    time = 0;

    luigi.x = 50;
    luigi.y = getBoardHeight() - 45;
    luigi.mstate = WALK;
    createBarrel();


}

void DKBoard::goLeft() {
    luigi.x -= 4;
}

void DKBoard::goRight() {
    luigi.x += 4;
}

void DKBoard::Jump() {
    luigi.mstate = JUMP;
}

void DKBoard::endJumpLadder() {
    luigi.mstate = WALK;
}

void DKBoard::goUP() {
    luigi.y -= 5;
}

void DKBoard::goDown() {
    luigi.y += 5;
}

void DKBoard::ladderStart() {
    luigi.mstate = LADDERING;
}


GameState DKBoard::getGameState() {
    return this->state;
}

void DKBoard::setGameStateLost() {
    state = FINISHED_LOST;
}

void DKBoard::setGameStateWon() {
    state = FINISHED_WON;
}

int DKBoard::getBoardHeight() {
    return this->boardHeight;
}


int DKBoard::getMarioX() const {
    return luigi.x;
}

int DKBoard::getMarioY() const {
    return luigi.y;
}

MarioState DKBoard::getMarioState() const {
    return luigi.mstate;
}

std::vector<std::pair<int, int>> DKBoard::getBarrelVec() {
    return barrelVector;
}

void DKBoard::barrelGoDown(int n) {
    barrelVector[n].second += 5;
}

void DKBoard::barrelGoLeft(int n) {
    barrelVector[n].first -= 5;
}

void DKBoard::barrelGoRight(int n) {
    barrelVector[n].first += 5;
}

void DKBoard::createBarrel() {
    barrelVector.push_back(std::make_pair(35, 110));
}

void DKBoard::eraseBarrel() {
    barrelVector.erase(barrelVector.begin());
}

void DKBoard::addTime() {
    this->time++;
}

int DKBoard::getTime() const {
    return this->time;
}











