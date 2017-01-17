#include "SnakeWorldScene.h"
#include "SimpleAudioEngine.h"
#include <vector>
#include "logic/Snake.h"
#include "SnakeSprite.h"

using std::vector;

USING_NS_CC;

Scene* SnakeWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = SnakeWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SnakeWorld::init()
{
    if ( !Layer::init() ) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();

    _snakeSprite = new SnakeSprite(visibleSize, 20, 20);

    addChild(_snakeSprite);

    addKeyListener();

    schedule([this](float delta){_snakeSprite->update();}, 0.5, "rm");

    return true;
}

void SnakeWorld::update(float delta) {

    checkCollision();
}

void SnakeWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void SnakeWorld::checkCollision() {

    Vec2 snakePos = _snakeSprite->getChildren().at(0)->getPosition();
    Size sceneSize = Director::getInstance()->getVisibleSize();

    if (snakePos.x > 0 && snakePos.x < sceneSize.width) {

        _snakeSprite->update();
    }
}

void SnakeWorld::addKeyListener() {

    EventListenerKeyboard *eventListener = EventListenerKeyboard::create();

    eventListener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event* event) {

        if(keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {

            _snakeSprite->changeDirection(Snake::UP);
        } else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {

            _snakeSprite->changeDirection(Snake::DOWN);
        } else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {

            _snakeSprite->changeDirection(Snake::LEFT);
        } else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {

            _snakeSprite->changeDirection(Snake::RIGHT);
        }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}
