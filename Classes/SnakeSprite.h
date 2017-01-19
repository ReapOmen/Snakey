#ifndef SNAKESPRITE_H_INCLUDED
#define SNAKESPRITE_H_INCLUDED

#include "cocos2d.h"
#include "logic/Snake.h"

class SnakeSprite : public cocos2d::Sprite {

public:

    SnakeSprite(Snake* snake);

    virtual ~SnakeSprite();

    virtual void update();

    static SnakeSprite* create(Snake* snake);

private:

    Snake* _snake;
};

#endif // SNAKESPRITE_H_INCLUDED
