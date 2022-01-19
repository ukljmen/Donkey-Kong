
#include "DKBoard.h"
#include "DKView.h"
#include "DKControl.h"


int main() {


    DKBoard Donkey;
    DKView DKV(Donkey);
    EndScreen ENDS(Donkey);
    DKControl DKC(Donkey, DKV, ENDS);

    DKC.play();

    return 0;
}
