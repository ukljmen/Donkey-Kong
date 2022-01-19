
#ifndef DK_ENDSCREEN_H
#define DK_ENDSCREEN_H

#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include "DKBoard.h"


class EndScreen {

private:
    DKBoard &bordend;
    sf::Text txtLose, txtWon, hScores, pos, finalTime;
    sf::Font fontey;

public:
    explicit EndScreen(DKBoard &o);

    void displayWin(sf::RenderWindow &win);

    void displayLose(sf::RenderWindow &win);

    void saveTime();


};


#endif //DK_ENDSCREEN_H
