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

    /**
     * Copy constructor of Snake.
     * @param snake the object to copy
     */
    Snake(const Snake& other);

    Snake(Snake&& other);

    Snake& operator=(const Snake& other);

    Snake& operator=(Snake&& other);

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
     *  When calling this method make sure you use the static constants provided.
     */
    virtual void changeDirection(int direction);

    /**
     * Checks whether the next move of the snake will make the snake collide with
     * itself.
     * @return true if the snake will collide with itself and false otherwise.
     */
    virtual bool collidesWithItself() const;

    /**
     * Gets the width of the snake's segments.
     * @return the width of the snake's segments.
     */
    float getSegmentWidth() const;

    /**
     * Gets the height of the snake's segments.
     * @return the height of the snake's segments.
     */
    float getSegmentHeight() const;

    /**
     * Gets the speed of the snake.
     * @return the speed of the snake.
     */
    cocos2d::Vec2 getSpeed() const;

    /**
     * Adds a new segment to the snake and make it grow.
     *
     * @param pos the position of the apple that is eaten and which
     *            makes the snake grow
     */
    void grow(const cocos2d::Vec2& pos);

    /**
     * Checks whether the snake will reach the given position
     * next time it moves.
     *
     * @param applePos the position of the apple
     *
     * @return the height of the snake's segments.
     */
    bool canEat(const cocos2d::Vec2& applePos);

private:

    vector<cocos2d::Vec2> _snakeStructure;

    float _segmentWidth, _segmentHeight;

    cocos2d::Vec2 _speed;

    bool _isMovingOnX, _shouldChangeDirection;
};

#endif // __SNAKE_H__
