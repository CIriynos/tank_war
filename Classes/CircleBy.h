#ifndef __CircleBy_H__	
#define __CircleBy_H__

#include "cocos2d.h"

class CircleBy: public cocos2d::ActionInterval
{
public:
	enum {LEFT = 0, RIGHT = 1};

	//acceleration -> always perpendicular to speed vector
	static CircleBy* create(float t, cocos2d::Vec2 pos, 
		cocos2d::Vec2* speed, float radius, int direction);

	virtual bool init(float t, cocos2d::Vec2 pos, 
		cocos2d::Vec2* speed, float radius, int direction);

	virtual void update(float);
protected:
	cocos2d::Vec2  pos;
	cocos2d::Vec2* speed = nullptr;
	cocos2d::Vec2  origin_speed;
	cocos2d::Vec2  delta;
	float interval;
	float acceleration;
	int direction;
};

#endif //__CircleBy_H__