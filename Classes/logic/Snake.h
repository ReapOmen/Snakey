#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "cocos2d.h"
#include <vector>

using std::vector;

class Snake {

public:

    /** Constants to use when changing the direction of the snake. */
    static const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

    /**
     * Initialises a snake that has 3 segments and will be placed in the middle of the screen.
     * Each segment is recorded as a position on the screen which is associated with the bottom
     * left corner of the segment sprite.
     *
     * @param sceneSize the size of the scene in which the snake is displayed
     * @param segmentWidth the width of each segment of the snake
     * @param segmentHeight the height of each segment of the snake
     */
    Snake(const cocos2d::Size& sceneSize, float segmentWidth, float segmentHeight);

    virtual ~Snake();

    /**
     * Updates the state of the snake by moving everything by an offset.
     */
    virtual void update();

    /**
     * Gets the snake data structure that is read only.
     * @return the vector containing the positions of all segments.
     */
    virtual const vector<cocos2d::Vec2>& getSnake() const;

    /** Changes the direction of the snake.
     * When calling this method make sure you use the static constants provided.
     */
    virtual void changeDirection(int direction);

private:

    vector<cocos2d::Vec2> _snakeStructure;

    float _segmentWidth, _segmentHeight;

    cocos2d::Vec2 _speed;

    // if the snake is moving on the X axis
    bool _isMovingOnX;
};

#endif // __SNAKE_H__
