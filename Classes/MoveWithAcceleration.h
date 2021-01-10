#ifndef __MOVE_WITH_ACCELERATION_H__
#define __MOVE_WITH_ACCELERATION_H__

#include "cocos2d.h"

typedef
class MoveWithAcceleration: public cocos2d::ActionInterval
{
public:
	//acceleration -> always perpendicular to speed vector
	static MoveWithAcceleration* create(float t, cocos2d::Vec2 pos, 
		cocos2d::Vec2* speed, cocos2d::Vec2 acceleration);

	virtual bool init(float t, cocos2d::Vec2 pos, 
		cocos2d::Vec2* speed, cocos2d::Vec2 acceleration);

	virtual void update(float);
protected:
	cocos2d::Vec2 pos;
	cocos2d::Vec2* speed;
	cocos2d::Vec2 origin_speed;
	cocos2d::Vec2 acceleration;
	float interval;
} AMove;

#endif //__MOVE_WITH_ACCELERATION_H__