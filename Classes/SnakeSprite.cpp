#include "SnakeSprite.h"

USING_NS_CC;

#define COCOS2D_DEBUG 1

SnakeSprite::SnakeSprite(const Size& sceneSize, float segmentWidth, float segmentHeight)
: Sprite(), _snake(new Snake(sceneSize, segmentWidth, segmentHeight)) {

    const vector<Vec2> snake = _snake->getSnake();

    for (size_t i = 0; i < snake.size(); ++i) {

        Sprite* segmentSprite = i == 0 ? Sprite::create("head.png") : Sprite::create("segment.png");
        segmentSprite->setAnchorPoint(Vec2::ZERO);
        segmentSprite->setPosition(snake[i]);
        addChild(segmentSprite);
    }
}

SnakeSprite::~SnakeSprite() {

    delete _snake;
}

void SnakeSprite::update() {

    _snake->update();
    vector<Vec2> segments = _snake->getSnake();
    Vector<Node*> children = getChildren();

    for (int i = 0; i < this->getChildrenCount(); ++i) {

        children.at(i)->setPosition(segments[i]);
    }
}

void SnakeSprite::changeDirection(int direction) {

    _snake->changeDirection(direction);
}

bool SnakeSprite::collidesWithItself() const {

    return _snake->collidesWithItself();
}

float SnakeSprite::getSegmentWidth() const {

    return _snake->getSegmentWidth();
}

float SnakeSprite::getSegmentHeight() const {

    return _snake->getSegmentHeight();
}
