#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SnakeSprite.h"
#include "logic/SnakeWorld.h"

class SnakeWorldScene : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(SnakeWorldScene);

private:

    SnakeSprite* _snakeSprite;

    cocos2d::Sprite* _appleSprite;

    SnakeWorld* _snakeWorld;

    void addKeyListener();
};

#endif // __HELLOWORLD_SCENE_H__
