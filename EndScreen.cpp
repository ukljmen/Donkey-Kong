

#include "EndScreen.h"


EndScreen::EndScreen(DKBoard &o) : bordend(o) {


    if (!fontey.loadFromFile("arial.ttf")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    txtLose.setFont(fontey);
    txtLose.setString("Game Over");
    txtWon.setFont(fontey);
    txtWon.setString(" YOU WIN ");
    hScores.setFont(fontey);
    hScores.setString("Highscores:");
    pos.setFont(fontey);
    pos.setString("example");
    finalTime.setFont(fontey);
    finalTime.setString("examples");

}

void EndScreen::displayLose(sf::RenderWindow &win) {

    win.draw(txtLose);
    txtLose.setPosition(100, 100);

}

void EndScreen::displayWin(sf::RenderWindow &win) {
    std::vector<int> times;
    int c;
    std::fstream file;
    file.open("Times.txt", std::ios::in);
    while (!file.eof()) {
        file >> c;
        times.push_back(c);
    }

    for (int i = 0; i < times.size(); ++i) {
        for (int j = 1; j < times.size(); ++j) {
            if (times.at(j - 1) > times.at(j)) {
                c = times[j];
                times[j] = times[j - 1];
                times[j - 1] = c;
            }
        }
    }
    win.draw(txtWon);
    txtWon.setPosition(120, 15);
    std::stringstream ss1, ss2;
    ss1 << bordend.getTime();
    std::string s1 = ss1.str(), s2;
    finalTime.setString("Your Time: " + s1);
    win.draw(finalTime);
    finalTime.setPosition(110, 45);
    win.draw(hScores);
    hScores.setPosition(60, 80);

    ss1.str("");
    ss2.str("");
    ss1 << times.at(0);
    s1 = ss1.str();
    ss2 << 1;
    s2 = ss2.str();
    pos.setString(s2 + ".  " + s1);
    win.draw(pos);
    pos.setPosition(60, 135);
    for (int i = 0; i < 10; ++i) {
        if (i == times.size() - 1) { break; }
        ss1.str("");
        ss2.str("");
        ss1 << times.at(i);
        s1 = ss1.str();
        ss2 << i + 1;
        s2 = ss2.str();
        pos.setString(s2 + ".  " + s1);
        win.draw(pos);

        if (i == 8) {
            pos.setPosition(43, 160 + 25 * i);
            continue;
        }
        if (i == 9 || (i == times.size() - 2 && times.size() - 2 < 9)) {
            pos.setPosition(60, 135);
            break;
        }

        pos.setPosition(60, 160 + 25 * i);
    }

    file.close();
}

void EndScreen::saveTime() {
    std::fstream file;
    file.open("Times.txt", std::ios::out | std::ios::app);
    file << bordend.getTime() << std::endl;
    file.close();

}
