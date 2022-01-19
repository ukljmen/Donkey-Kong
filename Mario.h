
#ifndef DK_MARIO_H
#define DK_MARIO_H
enum MarioState{ WALK,JUMP,LADDERING};

struct Mario{
    int x;
    int y;
    int height=30;
    int width=15;
    MarioState mstate;
};

#endif //DK_MARIO_H
