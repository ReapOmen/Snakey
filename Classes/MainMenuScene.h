#ifndef __MAINMENUSCENE_H__
#define __MAINMENUSCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class MainMenuScene : public cocos2d::Layer {

public:

    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(MainMenuScene);

private:

    cocos2d::Menu* _mainMenu;

    cocos2d::MenuItemImage* _playButton;

    void play(cocos2d::Ref* pSender);

};

#endif // __MAINMENUSCENE_H__
