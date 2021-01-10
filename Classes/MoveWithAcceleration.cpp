#include "MoveWithAcceleration.h"
using namespace cocos2d;

MoveWithAcceleration* MoveWithAcceleration::create
	(float t, cocos2d::Vec2 pos, cocos2d::Vec2* speed, cocos2d::Vec2 acceleration)
{
	MoveWithAcceleration* ptr = new MoveWithAcceleration();
	if(ptr && ptr->init(t, pos, speed, acceleration)){
		ptr->autorelease();
		return ptr;
	}else{
		delete ptr;
		ptr = nullptr;
		return nullptr;
	}
}

bool MoveWithAcceleration::init
	(float t, cocos2d::Vec2 pos, cocos2d::Vec2* speed, cocos2d::Vec2 acceleration)
{
	if(!ActionInterval::initWithDuration(t)) return false;
	this->interval = Director::getInstance()->getAnimationInterval();
	this->pos = pos;
	this->speed = speed;
	this->origin_speed = *speed;
	this->acceleration = acceleration;
	return true; 
}

void MoveWithAcceleration::update(float t)
{
	Vec2 delta = acceleration * interval;
	(*speed) += delta;
	pos += (*speed) * interval;
	getTarget()->setPosition(pos);
}