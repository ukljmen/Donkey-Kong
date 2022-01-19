

#ifndef DK_DKCONTROL_H
#define DK_DKCONTROL_H

#include "DKBoard.h"
#include "DKView.h"
#include "EndScreen.h"
#include <SFML/Graphics.hpp>


class DKControl {
    DKBoard *bord;
    DKView *view;
    EndScreen *end;

public:
    DKControl(DKBoard &dkb, DKView &dkv, EndScreen &edsc);

    void play();
};


#endif //DK_DKCONTROL_H
