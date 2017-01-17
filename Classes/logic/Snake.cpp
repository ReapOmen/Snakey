#include "Snake.h"

USING_NS_CC;

Snake::Snake(const Size& sceneSize, float segmentWidth, float segmentHeight)
: _snakeStructure(),
  _segmentWidth(segmentWidth), _segmentHeight(segmentHeight),
  _speed(-_segmentWidth, 0.0f),
  _isMovingOnX(true) {

    // getting the middle of the scene
    float midX = sceneSize.width / 2.0f;
    float midY = sceneSize.height / 2.0f;

    // calculating the position of the 2nd segment of the snake whose anchor
    // point will be in the bottom left corner
    float segmentY = midY - (_segmentHeight / 2.0f);
    float segmentX = midX - (_segmentWidth / 2.0f);

    // adding 3 segments to the snake data structure
    _snakeStructure.push_back(Vec2(segmentX - _segmentWidth, segmentY));
    _snakeStructure.push_back(Vec2(segmentX, segmentY));
    _snakeStructure.push_back(Vec2(segmentX + _segmentWidth, segmentY));
}

Snake::~Snake() {

}

void Snake::update() {

    for (int i = _snakeStructure.size() - 1; i > 0; --i) {
        _snakeStructure[i].set(_snakeStructure[i-1].x, _snakeStructure[i-1].y);
    }
    _snakeStructure[0] += _speed;
}

const vector<Vec2>& Snake::getSnake() const {

    return _snakeStructure;
}

void Snake::changeDirection(int direction) {

    if (_isMovingOnX) {

        if (direction == UP) {

            _speed = Vec2(0.0f, _segmentHeight);
            _isMovingOnX = !_isMovingOnX;
        } else if (direction == DOWN) {

            _speed = Vec2(0.0f, -_segmentHeight);
            _isMovingOnX = !_isMovingOnX;
        }
    } else {

        if (direction == LEFT) {

            _speed = Vec2(-_segmentWidth, 0.0f);
            _isMovingOnX = !_isMovingOnX;
        } else if (direction == RIGHT) {

            _speed = Vec2(_segmentWidth, 0.0f);
            _isMovingOnX = !_isMovingOnX;
        }
    }
}
