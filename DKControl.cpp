
#include "DKControl.h"
#include <cstdlib>
#include <ctime>

DKControl::DKControl(DKBoard &dkb, DKView &dkv, EndScreen &edsc) {
    bord = &dkb;
    view = &dkv;
    end = &edsc;


}

void DKControl::play() {

    sf::RenderWindow win(sf::VideoMode(350, 510), "Donkey Kong");
    sf::Event event;
    sf::Clock clk, clkBrl, timer;
    int eventcontainer;
    int jumpPhase = -1;
    srand(time(NULL));
    int randomtime = 4;

    while (win.isOpen()) {


        if (bord->getGameState() == RUNNING) {

            while (win.pollEvent(event)) {
                if (event.type == sf::Event::Closed) { win.close(); }

                if (timer.getElapsedTime().asSeconds() > 1) {
                    bord->addTime();
                    timer.restart();
                }


                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == 73) {
                        eventcontainer = 73;
                    }
                    if (event.key.code == 74) {
                        eventcontainer = 74;
                    }
                }

                if (event.type == sf::Event::KeyPressed) {

                    if (event.key.code == 71) {
                        eventcontainer = 71;
                    }
                    if (event.key.code == 72) {
                        eventcontainer = 72;
                    }
                    if (event.key.code == 73) {
                        eventcontainer = 73;
                    }
                    if (event.key.code == 74) {
                        eventcontainer = 74;
                    }

                }
            }

            if (clkBrl.getElapsedTime().asSeconds() > randomtime) {

                bord->createBarrel();
                randomtime = rand() % 4 + 3;
                if (view->barrels[0].second - 50 > bord->getMarioY()) { bord->eraseBarrel(); }
                clkBrl.restart();
            }

            if (clk.getElapsedTime().asSeconds() > 0.2) {

                for (int i = 0; i < view->getBarrelsVecSize(); i++) {
                    if (view->barrels[i].second % 150 == 110) {
                        if (view->barrels[i].first < 305) { bord->barrelGoRight(i); }
                        else bord->barrelGoDown(i);

                    }
                    if (view->barrels[i].second % 150 == 35) {
                        if (view->barrels[i].first > 35) { bord->barrelGoLeft(i); }
                        else bord->barrelGoDown(i);
                    }

                    if (view->barrels[i].second % 150 % 75 != 35) { bord->barrelGoDown(i); }

                    if (bord->getMarioX() - view->barrels[i].first < 10 &&
                        bord->getMarioX() - view->barrels[i].first > -15) {
                        if (bord->getMarioY() - view->barrels[i].second < 10 &&
                            bord->getMarioY() - view->barrels[i].second > -30) {

                            bord->setGameStateLost();
                        }
                    }
                }

                if (bord->getMarioState() == JUMP) {
                    jumpPhase++;
                    if (jumpPhase < 5) { bord->goUP(); }
                    if (jumpPhase > 5) {
                        bord->goDown();
                        if (jumpPhase == 10) {
                            bord->endJumpLadder();
                        }
                    }
                    switch (eventcontainer) {

                        case 71:
                            if (bord->getMarioX() > 10) {
                                if ((bord->getMarioY() + 25) % 150 <= 40 && (bord->getMarioY() + 25) % 150 >= 15 &&
                                    bord->getMarioX() < 55) {
                                } else bord->goLeft();
                            }
                            eventcontainer = 0;
                            clk.restart();

                            break;

                        case 72:
                            if (bord->getMarioX() < 325) {
                                if (bord->getMarioY() % 150 <= 90 && bord->getMarioY() % 150 >= 65 &&
                                    bord->getMarioX() > 285) {
                                } else bord->goRight();
                            }
                            eventcontainer = 0;
                            clk.restart();
                            break;
                        default:
                            clk.restart();
                    }
                    continue;

                }

                if (bord->getMarioState() == LADDERING) {

                    switch (eventcontainer) {

                        case 73:
                            bord->goUP();

                            if (bord->getMarioY() % 75 == 15) {

                                bord->endJumpLadder();
                                continue;
                            }

                            if (bord->getMarioY() < 57) {
                                bord->setGameStateWon();
                                end->saveTime();
                                continue;
                            }
                            eventcontainer = 0;
                            clk.restart();
                            break;

                        case 74:
                            bord->goDown();

                            if (bord->getMarioY() % 75 == 15) {

                                bord->endJumpLadder();
                                continue;
                            }
                            eventcontainer = 0;
                            clk.restart();
                            break;

                        default:

                            clk.restart();
                            break;
                    }
                }


                if (bord->getMarioState() == WALK) {
                    switch (eventcontainer) {

                        case 71:
                            if (bord->getMarioX() > 10) {
                                if (bord->getMarioY() % 150 == 15 && bord->getMarioX() < 55) {
                                } else bord->goLeft();
                            }
                            eventcontainer = 0;
                            clk.restart();

                            break;

                        case 72:
                            if (bord->getMarioX() < 325) {
                                if (bord->getMarioY() % 150 == 90 && bord->getMarioX() > 285) {
                                } else bord->goRight();
                            }
                            eventcontainer = 0;
                            clk.restart();
                            break;

                        case 73:
                            if ((bord->getMarioX() >= 255 && bord->getMarioX() <= 275 &&
                                 bord->getMarioY() % 150 == 15) ||
                                (bord->getMarioX() >= 75 && bord->getMarioX() <= 95 &&
                                 bord->getMarioY() % 150 == 90)) {
                                bord->ladderStart();
                                continue;
                            }
                            bord->Jump();
                            jumpPhase = 0;
                            bord->goUP();
                            eventcontainer = 0;
                            clk.restart();
                            break;

                        case 74:
                            if ((bord->getMarioX() >= 255 && bord->getMarioX() <= 275 &&
                                 bord->getMarioY() % 150 == 90) ||
                                (bord->getMarioX() >= 75 && bord->getMarioX() <= 95 &&
                                 bord->getMarioY() % 150 == 15)) {
                                bord->ladderStart();
                                continue;
                            }
                            eventcontainer = 0;
                            clk.restart();
                            break;

                        default:
                            clk.restart();
                            break;
                    }
                }

            }
            win.clear(sf::Color(80, 0, 80));

            view->drawBoard(win);

        } else {

            while (win.pollEvent(event)) {
                if (event.type == sf::Event::Closed) { win.close(); }
            }


            if (bord->getGameState() == FINISHED_LOST) {
                win.clear(sf::Color(80, 10, 10));
                end->displayLose(win);
            }
            if (bord->getGameState() == FINISHED_WON) {
                win.clear(sf::Color(80, 180, 80));
                end->displayWin(win);
            }

        }

        win.display();
    }

}
