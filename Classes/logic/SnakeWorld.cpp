#include "SnakeWorld.h"

#define COCOS2D_DEBUG 1
USING_NS_CC;

SnakeWorld::SnakeWorld(const Size& sceneSize)
: _sceneSize(sceneSize),
  _tileWidth(sceneSize.width * 20 / 620),
  _tileHeight(sceneSize.height * 20 / 600),
  _snake(new Snake(_sceneSize, _tileWidth, _tileHeight)),
  _gameOver(false),
  _apple(Vec2(-1.0f, -1.0f)) {

  randomApple();
}

SnakeWorld::SnakeWorld(const SnakeWorld& other)
: _sceneSize(other._sceneSize),
  _tileWidth(other._tileWidth),
  _tileHeight(other._tileHeight),
  _snake(new Snake(*(other._snake))),
  _gameOver(other._gameOver),
  _apple(other._apple) {

}

SnakeWorld::SnakeWorld(SnakeWorld&& other)
: _sceneSize(other._sceneSize),
  _tileWidth(other._tileWidth),
  _tileHeight(other._tileHeight),
  _snake(new Snake(*(other._snake))),
  _gameOver(other._gameOver),
  _apple(other._apple) {

}

SnakeWorld& SnakeWorld::operator=(const SnakeWorld& other) {

    if (this != &other) {

        _sceneSize = other._sceneSize;
        _tileWidth = other._tileWidth;
        _tileHeight = other._tileHeight;
        _snake = new Snake(*(other._snake));
        _gameOver = other._gameOver;
        _apple = other._apple;
    }

    return *this;
}

SnakeWorld::~SnakeWorld() {

    delete _snake;
}

void SnakeWorld::update() {

    if (!_gameOver && checkCollision()) {

        if (_snake->canEat(_apple)) {

            _snake->grow(_apple);
            randomApple();
        }
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

Vec2 SnakeWorld::getApple() const {

    return _apple;
}

bool SnakeWorld::checkCollision() {

    Vec2 snakePos = _snake->getSnake()[_snake->getSnake().size() - 1] +
                    _snake->getSpeed();

    return snakePos.x > -_tileWidth && snakePos.y > -_tileHeight &&
            snakePos.x < _sceneSize.width && snakePos.y < _sceneSize.height &&
             !_snake->collidesWithItself();
}

void SnakeWorld::randomApple() {

    int maxWidth = _sceneSize.width / _tileWidth;
    int maxHeight = _sceneSize.height / _tileHeight;

    srand(time(NULL));

    int x = rand() % maxWidth, y = rand() % maxHeight;

    while (!canPlace(x, y)) {

        x = rand() % maxWidth;
        y = rand() % maxHeight;
    }

    _apple.x = x * _tileWidth;
    _apple.y = y * _tileHeight;
}

bool SnakeWorld::canPlace(float x, float y) const {

    vector<Vec2> segments = _snake->getSnake();
    Vec2 pos = Vec2(x, y);

    for (const Vec2& segment : segments) {

        if (segment == pos) {

            return false;
        }
    }

    return pos == _apple ? false : true;
}
