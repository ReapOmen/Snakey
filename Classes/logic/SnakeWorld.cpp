#include "SnakeWorld.h"

USING_NS_CC;

SnakeWorld::SnakeWorld(const Size& sceneSize)
: _sceneSize(sceneSize),
  _tileWidth(sceneSize.width * 20 / 620),
  _tileHeight(sceneSize.height * 20 / 600),
  _snake(new Snake(_sceneSize, _tileWidth, _tileHeight)),
  _gameOver(false) {

}

SnakeWorld::~SnakeWorld() {

    delete _snake;
}

void SnakeWorld::update() {

    if (!_gameOver && !checkCollision()) {

        _snake->update();
    } else {

        _gameOver = true;
    }
}

Snake* SnakeWorld::getSnake() const {

    return _snake;
}

bool SnakeWorld::isGameOver() const {

    return _gameOver;
}

bool SnakeWorld::checkCollision() {

    Vec2 snakePos = _snake->getSnake()[0];

    return !(snakePos.x > 0 && snakePos.y > 0 &&
               snakePos.x + _tileWidth < _sceneSize.width &&
                   snakePos.y + _tileHeight < _sceneSize.height) &&
                       _snake->collidesWithItself();
}


