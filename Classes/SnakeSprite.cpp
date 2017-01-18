#include "SnakeSprite.h"

USING_NS_CC;

#define COCOS2D_DEBUG 1

SnakeSprite::SnakeSprite(Snake* snake)
: Sprite(), _snake(snake) {

    const vector<Vec2> snakeSegs = _snake->getSnake();

    for (size_t i = 0; i < snakeSegs.size(); ++i) {

        Sprite* segmentSprite = i == 0 ? Sprite::create("head.png") : Sprite::create("segment.png");
        segmentSprite->setAnchorPoint(Vec2::ZERO);
        segmentSprite->setPosition(snakeSegs[i]);
        addChild(segmentSprite);
    }
}

SnakeSprite::~SnakeSprite() {

    delete _snake;
}

void SnakeSprite::update() {

    vector<Vec2> segments = _snake->getSnake();
    Vector<Node*> children = getChildren();

    for (int i = 0; i < this->getChildrenCount(); ++i) {

        children.at(i)->setPosition(segments[i]);
    }
}
