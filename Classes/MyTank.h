#ifndef __MY_TANK__
#define __MY_TANK__
#include "cocos2d.h"
#include "Entity.h"

class Tank: public Entity
{
public:
	enum class State {
		STOP = 0,
		MOVE = 1,
		LEFT_MOVE = 2,
		RIGHT_MOVE = 3,
		BACK_MOVE = 4,
		LEFT_ROTATE = 5,
		RIGHT_ROTATE = 6,
		ACCELERATE_MOVE = 7,

		START_ACCE = 8,
		STOP_ACCE = 9,
	};

public:
	static Tank* create();

	virtual bool init();

	Tank::State getCurrentState() { return currentState; };

protected:
	//FSM
	virtual void startStraightMove();

	virtual void addLeftMove();
	virtual void addRightMove();
	virtual void turnToStraightMove();

	virtual void stopMove();

	virtual void startLeftRotate();
	virtual void startRightRotate();
	virtual void stopLeftRotate();
	virtual void stopRightRotate();

	virtual void turnToLeftRotate();
	virtual void turnToRightRotate();

	virtual void addLeftMoveFromRotate();
	virtual void addRightMoveFromRotate();

	virtual void startBackMove();
	virtual void stopBackMove();

private:
	State currentState = State::STOP;

protected:
	float towerTowards = 0;
	float maxSpeed = DEFAULT_MAX_SPEED;
	float rotateRadius = DEFAULT_ROTATE_RADIUS;

	cocos2d::Sprite* tankBody;
	cocos2d::Sprite* tankTower;

public:
	const float MAX_MOVE_TIME = 1e7;
	const float START_ACCE_TIME = 0.4f;
	const float STOP_ACCE_TIME = 0.4f;
	const float DEFAULT_ROTATE_RADIUS = 80.0f;
	const float DEFAULT_MAX_SPEED = 100.0f;
};


#endif //__MY_TANK__