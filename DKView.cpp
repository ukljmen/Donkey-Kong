
#include "DKView.h"

DKView::DKView(DKBoard &p) : brd(p) {

    platformBig.setPointCount(4);
    platformBig.setPoint(0, sf::Vector2f(0.f, 0.f));
    platformBig.setPoint(1, sf::Vector2f(350.f, 0.f));
    platformBig.setPoint(2, sf::Vector2f(350.f, 15.f));
    platformBig.setPoint(3, sf::Vector2f(0.f, 15.f));
    platformBig.setFillColor(sf::Color::Red);

    platformSmall.setPointCount(4);
    platformSmall.setPoint(0, sf::Vector2f(0.f, 0.f));
    platformSmall.setPoint(1, sf::Vector2f(300.f, 0.f));
    platformSmall.setPoint(2, sf::Vector2f(300.f, 15.f));
    platformSmall.setPoint(3, sf::Vector2f(0.f, 15.f));
    platformSmall.setFillColor(sf::Color::Red);

    player.setPointCount(4);
    player.setPoint(0, sf::Vector2f(0.f, 0.f));
    player.setPoint(1, sf::Vector2f(15.f, 0.f));
    player.setPoint(2, sf::Vector2f(15.f, 30.f));
    player.setPoint(3, sf::Vector2f(0.f, 30.f));
    player.setFillColor(sf::Color::Blue);

    ladder.setPointCount(4);
    ladder.setPoint(0, sf::Vector2f(0.f, 0.f));
    ladder.setPoint(1, sf::Vector2f(25.f, 0.f));
    ladder.setPoint(2, sf::Vector2f(25.f, 60.f));
    ladder.setPoint(3, sf::Vector2f(0.f, 60.f));
    ladder.setFillColor(sf::Color::Cyan);

    barrel.setRadius(5);
    barrel.setFillColor(sf::Color(229, 70, 36));

    cannon.setPointCount(12);
    cannon.setPoint(0, sf::Vector2f(34.f, 120.f));
    cannon.setPoint(1, sf::Vector2f(34.f, 110.f));
    cannon.setPoint(2, sf::Vector2f(4.f, 110.f));
    cannon.setPoint(3, sf::Vector2f(1.f, 113.f));
    cannon.setPoint(4, sf::Vector2f(1.f, 117.f));
    cannon.setPoint(5, sf::Vector2f(4.f, 120.f));
    cannon.setPoint(6, sf::Vector2f(8.f, 120.f));
    cannon.setPoint(7, sf::Vector2f(10.f, 123.f));
    cannon.setPoint(8, sf::Vector2f(13.f, 125.f));
    cannon.setPoint(9, sf::Vector2f(14.f, 125.f));
    cannon.setPoint(10, sf::Vector2f(17.f, 123.f));
    cannon.setPoint(11, sf::Vector2f(19.f, 120.f));
    cannon.setFillColor(sf::Color::Black);

    crown.setPointCount(7);
    crown.setPoint(0, sf::Vector2f(0.f, 0.f));
    crown.setPoint(1, sf::Vector2f(0.f, 20.f));
    crown.setPoint(2, sf::Vector2f(30.f, 20.f));
    crown.setPoint(3, sf::Vector2f(30.f, 0.f));
    crown.setPoint(4, sf::Vector2f(20.f, 8.f));
    crown.setPoint(5, sf::Vector2f(16.f, 0.f));
    crown.setPoint(6, sf::Vector2f(12.f, 8.f));
    crown.setFillColor(sf::Color::Yellow);

    std::pair<int, int> pair;
    for (int i = 0; i < 5; i++) {
        pair.first = i % 2 * 50;
        pair.second = brd.getBoardHeight() - 15 * (i + 2) - 60 * (i + 1);
        platforms.push_back(pair);

    }

    for (int i = 1; i < 7; i++) {
        pair.first = i % 2 * 180 + 80;
        pair.second = brd.getBoardHeight() - 15 * (i) - 60 * (i);
        ladders.push_back(pair);

    }

}


void DKView::drawBoard(sf::RenderWindow &win) {


    win.draw(crown);
    crown.setPosition(78, 36);

    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            win.draw(platformBig);
            platformBig.setPosition(0, brd.getBoardHeight() - 15);
            win.draw(ladder);
            ladder.setPosition(ladders[i].first, ladders[i].second);
            continue;
        }
        win.draw(platformSmall);
        platformSmall.setPosition(platforms[i - 1].first, platforms[i - 1].second);
        win.draw(ladder);
        ladder.setPosition(ladders[i].first, ladders[i].second);
    }
    updateBarrels();
    for (int i = 0; i < barrels.size(); i++) {
        win.draw(barrel);
        barrel.setPosition(barrels[i].first, barrels[i].second);
    }


    win.draw(player);
    player.setPosition(brd.getMarioX(), brd.getMarioY());

    win.draw(cannon);

}

void DKView::updateBarrels() {
    barrels = brd.getBarrelVec();
}

int DKView::getBarrelsVecSize() const {
    return barrels.size();
}
