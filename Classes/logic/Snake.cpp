#include "Snake.h"

USING_NS_CC;

Snake::Snake(const Size& sceneSize, float segmentWidth, float segmentHeight)
: _snakeStructure(),
  _segmentWidth(segmentWidth),
  _segmentHeight(segmentHeight),
  _speed(-_segmentWidth, 0.0f),
  _isMovingOnX(true),
  _shouldChangeDirection(true) {

    // getting the middle of the scene
    float midX = sceneSize.width / 2.0f;
    float midY = sceneSize.height / 2.0f;

    // calculating the position of the 2nd segment of the snake whose anchor
    // point will be in the bottom left corner
    float segmentY = midY;
    float segmentX = midX - (_segmentWidth / 2.0f);

    // adding 3 segments to the snake data structure
    _snakeStructure.push_back(Vec2(segmentX + _segmentWidth, segmentY));
    _snakeStructure.push_back(Vec2(segmentX, segmentY));
    _snakeStructure.push_back(Vec2(segmentX - _segmentWidth, segmentY));

}

Snake::Snake(const Snake& snake)
: _snakeStructure(snake._snakeStructure),
  _segmentWidth(snake._segmentWidth),
  _segmentHeight(snake._segmentHeight),
  _speed(snake._speed),
  _isMovingOnX(snake._isMovingOnX),
  _shouldChangeDirection(snake._shouldChangeDirection) {

}

Snake& Snake::operator=(const Snake& snake) {

    _snakeStructure = snake._snakeStructure;
    _segmentWidth =  snake._segmentWidth;
    _segmentHeight = snake._segmentHeight;
    _speed = snake._speed;
    _isMovingOnX = snake._isMovingOnX;
    _shouldChangeDirection = snake._shouldChangeDirection;

    return *this;
}

void Snake::update() {

    _shouldChangeDirection = true;
    size_t len = _snakeStructure.size();

    for (size_t i = 0; i < len - 1; ++i) {
        _snakeStructure[i].set(_snakeStructure[i + 1].x, _snakeStructure[i + 1].y);
    }
    _snakeStructure[len - 1] += _speed;
}

const vector<Vec2>& Snake::getSnake() const {

    return _snakeStructure;
}

void Snake::changeDirection(int direction) {

    if(_shouldChangeDirection) {

        if (_isMovingOnX) {

            if (direction == UP) {

                _speed = Vec2(0.0f, _segmentHeight);
                _isMovingOnX = !_isMovingOnX;
                _shouldChangeDirection = false;
            } else if (direction == DOWN) {

                _speed = Vec2(0.0f, -_segmentHeight);
                _isMovingOnX = !_isMovingOnX;
                _shouldChangeDirection = false;
            }
        } else {

            if (direction == LEFT) {

                _speed = Vec2(-_segmentWidth, 0.0f);
                _isMovingOnX = !_isMovingOnX;
                _shouldChangeDirection = false;
            } else if (direction == RIGHT) {

                _speed = Vec2(_segmentWidth, 0.0f);
                _isMovingOnX = !_isMovingOnX;
                _shouldChangeDirection = false;
            }
        }
    }
}

bool Snake::collidesWithItself() const {

    Vec2 newHead = Vec2(_snakeStructure[_snakeStructure.size() - 1]);
    newHead += _speed;

    for(const Vec2& segment : _snakeStructure) {

        if(newHead == segment) {

            return false;
        }
    }

    return true;
}

float Snake::getSegmentWidth() const {

    return _segmentWidth;
}

float Snake::getSegmentHeight() const {

    return _segmentHeight;
}

Vec2 Snake::getSpeed() const {

    return _speed;
}

void Snake::grow(const Vec2& pos) {

    _snakeStructure.push_back(pos);
}

bool Snake::canEat(const Vec2& pos) {

    Vec2 newHead = _snakeStructure[_snakeStructure.size() - 1] + _speed;

    return newHead == pos;
}
