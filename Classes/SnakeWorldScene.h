#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SnakeSprite.h"

class SnakeWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);

    virtual void update(float delta) override;

    CREATE_FUNC(SnakeWorld);

private:

    SnakeSprite* _snakeSprite;

    void checkCollision();

    void addKeyListener();
};

#endif // __HELLOWORLD_SCENE_H__
