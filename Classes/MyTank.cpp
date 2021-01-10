#include "MyTank.h"
#include "MoveWithAcceleration.h"
#include "CircleBy.h"

#include <cassert>

using namespace cocos2d;

Tank* Tank::create()
{
	Tank* ptr = new Tank();
	if(ptr && ptr->init())
	{
		ptr->autorelease();
		return ptr;
	}
	else{
		delete ptr;
		ptr = nullptr;
		return nullptr;
	}
}

bool Tank::init()
{
	if(!Entity::init()) return false;

	tankBody = Sprite::create("tank\\tankbody.png");
	tankTower = Sprite::create("tank\\tankhead.png");
	if(tankBody == nullptr || tankTower == nullptr) return false;

	log("%f %f", tankBody->getContentSize().width, tankBody->getContentSize().height);

	tankBody->setPosition(Vec2(0, 0));
	tankTower->setPosition(Vec2(0, 30));
	towerTowards = 0;

	addChild(tankBody, 0);
	addChild(tankTower, 1);
}

void Tank::startStraightMove()
{
	assert(currentState == State::STOP);
	assert(speed == Vec2::ZERO);

	//update state
	currentState = State::START_ACCE;

	//create acceleration
	Vec2 acce(0, maxSpeed / START_ACCE_TIME);
	acce.rotateByAngle(Vec2(0, 0), orient);

	//create actions
	auto action1 = AMove::create(START_ACCE_TIME, getPosition(), &speed, acce);
	auto action2 = CallFunc::create([=](){
		currentState = State::MOVE;
		auto action_s = MoveBy::create(1.0f, speed);
		auto action_r = RepeatForever::create(action_s);
		runAction(action_r);
	});
	auto seq = Sequence::create(action1, action2, nullptr);
	
	runAction(seq);
}

void Tank::stopMove()
{
	assert(
		currentState == State::MOVE 
	 || currentState == State::LEFT_MOVE
	 || currentState == State::RIGHT_MOVE);

	stopAllActions();

	//create acceleration
	Vec2 acce(speed / STOP_ACCE_TIME, 0);
	acce.rotateByAngle(Vec2(0, 0), orient);
	acce = acce.getPerp(); acce = acce.getPerp();

	//create actions
	auto action1 = AMove::create(STOP_ACCE_TIME, getPosition(), &speed, acce);
	auto action2 = CallFunc::create([=](){
		currentState = State::STOP;
	});
	auto seq = Sequence::create(action1, action2, nullptr);

	runAction(seq);
}

void Tank::addLeftMove()
{
	assert(currentState == State::MOVE);

	currentState = State::LEFT_MOVE;
	stopAllActions();

	auto action = CircleBy::create(MAX_MOVE_TIME, getPosition(), &speed,
		rotateRadius, CircleBy::LEFT);
	runAction(action);
}

void Tank::addRightMove()
{
	assert(currentState == State::MOVE);

	currentState = State::LEFT_MOVE;
	stopAllActions();

	auto action = CircleBy::create(MAX_MOVE_TIME, getPosition(), &speed,
		rotateRadius, CircleBy::RIGHT);
	runAction(action);
}

void Tank::turnToStraightMove()
{
	assert(currentState == State::LEFT_MOVE || currentState == State::RIGHT_MOVE);

	currentState = State::MOVE;
	stopAllActions();
	
	auto action = CallFunc::create([=](){
		auto action_s = MoveBy::create(1.0f, speed);
		auto action_r = RepeatForever::create(action_s);
		runAction(action_r);
	});
	runAction(action);
}

void Tank::startLeftRotate()
{

}
void Tank::startRightRotate()
{

}
void Tank::stopLeftRotate()
{

}
void Tank::stopRightRotate()
{

}

void Tank::turnToLeftRotate()
{

}
void Tank::turnToRightRotate()
{

}

void Tank::addLeftMoveFromRotate()
{

}
void Tank::addRightMoveFromRotate()
{

}

void Tank::startBackMove()
{

}
void Tank::stopBackMove()
{

}