#include "CircleBy.h"
using namespace cocos2d;

CircleBy* CircleBy::create(float t, Vec2 pos, Vec2* speed, float radius, int direction = CircleBy::LEFT)
{
	CircleBy* ptr = new CircleBy();
	if(ptr && ptr->init(t, pos, speed, radius, direction)){
		ptr->autorelease();
		return ptr;
	}else{
		delete ptr;
		ptr = nullptr;
		return nullptr;
	}
}

bool CircleBy::init(float t, Vec2 pos, Vec2* speed, float radius, int direction)
{
	if(!ActionInterval::initWithDuration(t)) return false;
	this->interval = Director::getInstance()->getAnimationInterval();
	this->pos = pos;
	this->speed = speed;
	this->origin_speed = *speed;
	this->acceleration = speed->length() * speed->length() / radius; //a = v^2 / r
	this->direction = direction;
	return true; 
}

static inline Vec2 getDelta(double len, Vec2 base, int direction)
{
	Vec2 tmp = base.getPerp();
	if(direction == CircleBy::RIGHT) 
		{ tmp = tmp.getPerp(); tmp = tmp.getPerp(); }

	tmp.scale((float)(len / (double)tmp.length()));
	return tmp;
}

void CircleBy::update(float t)
{
	delta = getDelta((double)acceleration * interval, *speed, direction);
	//log("Delta len per interval: %f", delta * interval);
	(*speed) += delta;
	speed->scale((float)((double)origin_speed.length() / (double)speed->length()));
	pos += (*speed) * interval;
	getTarget()->setPosition(pos);
}