#include "SnakeSprite.h"

USING_NS_CC;

SnakeSprite::SnakeSprite(Snake* snake)
: Sprite(), _snake(snake) {

    const vector<Vec2> snakeSegs = _snake->getSnake();
    size_t len = snakeSegs.size();

    for (size_t i = 0; i < len; ++i) {

        Sprite* segmentSprite = i == len - 1 ? Sprite::create("head.png") :
                                               Sprite::create("segment.png");
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
    int len = segments.size();

    Vector<Node*> children = getChildren();
    int len2 = children.size();

    int lastChildIndex = len2 - 1;

    for (int i = 0; i < len - len2; ++i) {

        Sprite* segmentSprite = Sprite::create("head.png");
        segmentSprite->setAnchorPoint(Vec2::ZERO);
        segmentSprite->setPosition(segments[i]);
        addChild(segmentSprite);
    }

    children = getChildren();

    if(len != len2) {

        ((Sprite*)children.at(lastChildIndex))->setTexture("segment.png");
    }

    for (int i = 0; i < len; ++i) {

        children.at(i)->setPosition(segments[i]);
    }
}
