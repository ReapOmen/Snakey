#include "PauseLayer.h"

USING_NS_CC;

bool PauseLayer::init() {

    if (!Layer::init()) {
        return false;
    }

    _bResume = MenuItemImage::create("play.png", "play_selected.png");
    Size s = Director::getInstance()->getVisibleSize();
    _bResume->setPosition(Vec2(s.width/2, s.height/2));

    _menu = Menu::create(_bResume, NULL);
    _menu->alignItemsVerticallyWithPadding(10.0f);
    addChild(_menu);

    return true;
}

void PauseLayer::setButtonCallback(const std::function< void(Ref*)>& callback) {

    _bResume->setCallback(callback);
}
