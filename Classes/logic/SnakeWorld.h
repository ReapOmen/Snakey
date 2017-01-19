#ifndef SNAKEWORLD_H_INCLUDED
#define SNAKEWORLD_H_INCLUDED

#include <cstdlib>
#include <ctime>

#include "cocos2d.h"
#include "Snake.h"

class SnakeWorld {

public:

    /**
     * Sets up a world in which there is a snake and an apple.
     *
     * @param sceneSize the size of the scene/world
     */
    SnakeWorld(const cocos2d::Size& sceneSize);

    virtual ~SnakeWorld();

    /**
     * Updates the world: makes the snake move one time while checking for
     * any collisions (walls, apples, the snake itself).
     */
    virtual void update();

    /**
     * Gets the snake that was created by the world.
     * @return the snake of this world.
     */
    Snake* getSnake() const;

    /**
     * Gets the position of the apple in the world.
     * @return the position of the apple.
     */
    cocos2d::Vec2 getApple() const;

    /**
     * Checks whether the game is over or not.
     * @return true if the game is over, false otherwise.
     */
    bool isGameOver() const;

private:

    cocos2d::Size _sceneSize;

    float _tileWidth, _tileHeight;

    Snake* _snake;

    bool _gameOver;

    cocos2d::Vec2 _apple;

    bool checkCollision();

    void randomApple();

    bool canPlace(float x, float y) const;
};


#endif // SNAKEWORLD_H_INCLUDED
