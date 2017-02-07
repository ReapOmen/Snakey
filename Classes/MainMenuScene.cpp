#include "MainMenuScene.h"
#include "SnakeWorldScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene() {

    Scene* mainScene = Scene::create();

    Layer* mainLayer = MainMenuScene::create();

    mainScene->addChild(mainLayer);

    return mainScene;
}

bool MainMenuScene::init() {

    if (!Layer::init()) {

        return false;
    }

    _playButton = MenuItemImage::create("play.png", "play_selected.png",
                                        CC_CALLBACK_1(MainMenuScene::play, this));

    _mainMenu = Menu::create(_playButton, NULL);

    _mainMenu->alignItemsVerticallyWithPadding(10.0f);

    addChild(_mainMenu);

    return true;
}

void MainMenuScene::play(Ref* pSender) {

    Director::getInstance()->replaceScene(SnakeWorldScene::createScene());
}
