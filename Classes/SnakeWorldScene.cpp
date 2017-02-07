#include "SnakeWorldScene.h"
#include "SimpleAudioEngine.h"
#include <vector>

#include "logic/Snake.h"
#include "logic/SnakeWorld.h"

#include "SnakeSprite.h"
#include "PauseLayer.h"
#include "MainMenuScene.h"

using std::vector;

USING_NS_CC;

Scene* SnakeWorldScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = SnakeWorldScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SnakeWorldScene::init()
{
    if ( !Layer::init() ) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();

    _snakeWorld = new SnakeWorld(visibleSize);

    _snakeSprite = new SnakeSprite(_snakeWorld->getSnake());

    addChild(_snakeSprite);

    _appleSprite = Sprite::create("apple.png");
    _appleSprite->setAnchorPoint(Vec2::ZERO);
    _appleSprite->setPosition(_snakeWorld->getApple());

    addChild(_appleSprite);

    addKeyListener();

    schedule([this](float delta) {

                 if (!_snakeWorld->isGameOver()) {

                     _snakeWorld->update();
                     _snakeSprite->update();
                     _appleSprite->setPosition(_snakeWorld->getApple());

                 } else {

                     unschedule("update_snake");
                     Scene* toPlay = MainMenuScene::createScene();
                     Director::getInstance()->replaceScene(toPlay);
                 }
              }, 0.5, "update_snake");

    return true;
}

void SnakeWorldScene::menuCloseCallback(Ref* pSender)
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

void SnakeWorldScene::addKeyListener() {

    Snake* snake = _snakeWorld->getSnake();

    EventListenerKeyboard *eventListener = EventListenerKeyboard::create();

    eventListener->onKeyReleased = [snake, this](EventKeyboard::KeyCode keyCode, Event* event) {

        if(keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {

            snake->changeDirection(Snake::UP);
        } else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {

            snake->changeDirection(Snake::DOWN);
        } else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {

            snake->changeDirection(Snake::LEFT);
        } else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {

            snake->changeDirection(Snake::RIGHT);
        } else if (keyCode == EventKeyboard::KeyCode::KEY_P) {

            if (Director::getInstance()->isPaused()) {

                handlePauseEnd();
            } else {

                handlePauseStart();
            }
        }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this);
}

SnakeWorldScene::~SnakeWorldScene() {

    delete _snakeWorld;
}

void SnakeWorldScene::handlePauseStart() {

    Director::getInstance()->pause();
    PauseLayer* pauseLayer = PauseLayer::create();
    pauseLayer->setButtonCallback([this](Ref* ref) { handlePauseEnd(); });
    LayerColor* layer = LayerColor::create(Color4B(255, 255, 255, 255));
    layer->setOpacity(120);
    getScene()->addChild(layer, 0, "color");
    getScene()->addChild(pauseLayer, 0, "pauseLayer");
}

void SnakeWorldScene::handlePauseEnd() {

    getScene()->removeChildByName("pauseLayer", true);
    getScene()->removeChildByName("color", true);
    Director::getInstance()->resume();
}
