#ifndef SNAKESPRITE_H_INCLUDED
#define SNAKESPRITE_H_INCLUDED

#include "cocos2d.h"
#include "logic/Snake.h"

class SnakeSprite : public cocos2d::Sprite {

public:

    SnakeSprite(const cocos2d::Size& sceneSize, float segmentWidth, float segmentHeight);

    virtual ~SnakeSprite();

    virtual void update();

    void changeDirection(int direction);

    bool collidesWithItself() const;

    float getSegmentWidth() const;

    float getSegmentHeight() const;

    static SnakeSprite* create(const cocos2d::Size& sceneSize, float segmentWidth, float segmentHeight);

private:

    Snake* _snake;
};

#endif // SNAKESPRITE_H_INCLUDED
