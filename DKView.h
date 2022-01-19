
#ifndef DK_DKVIEW_H
#define DK_DKVIEW_H

#include "SFML/Graphics.hpp"
#include "DKBoard.h"

class DKView {

    DKBoard &brd;
    sf::ConvexShape crown, platformBig, platformSmall, player, ladder;
    sf::ConvexShape cannon;
    sf::CircleShape barrel;
    std::vector<std::pair<int, int>> platforms, ladders;

public:
    explicit DKView(DKBoard &p);

    void drawBoard(sf::RenderWindow &win);

    void updateBarrels();

    int getBarrelsVecSize() const;

    std::vector<std::pair<int, int>> barrels;


};


#endif //DK_DKVIEW_H
