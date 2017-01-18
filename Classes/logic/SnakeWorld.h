#ifndef SNAKEWORLD_H_INCLUDED
#define SNAKEWORLD_H_INCLUDED

#include "cocos2d.h"
#include "Snake.h"
//#include "Apple.h"

class SnakeWorld {

public:

    SnakeWorld(const cocos2d::Size& sceneSize);

    virtual ~SnakeWorld();

    virtual void update();

    Snake* getSnake() const;

    bool isGameOver() const;

private:
    //Apple _apple;

    cocos2d::Size _sceneSize;

    float _tileWidth, _tileHeight;

    Snake* _snake;

    bool _gameOver;

    bool checkCollision();

};


#endif // SNAKEWORLD_H_INCLUDED
