#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "cocos2d.h"

class Entity: public cocos2d::Node
{
public:
	static Entity* create();

	virtual bool init();

public:
	void setHealth(int hp) 			{ health = hp; }
	void modifyHealth(int delta) 	{ health += delta; }
	int getHealth()					{ return health; }
	void modifyMaxHealth(int hp) 	{ maxHealth = hp; }

	void setAttack(int att)			{ attack = att; }
	int getAttack() 				{ return attack; }

	void setDefent(int def) 		{ defent = def; }
	int getDefent() 				{ return defent; }

	void setSpeed(cocos2d::Vec2 s)  { speed = s; }
	cocos2d::Vec2 getSpeed()		{ return speed; }

protected:
	int health = 100;
	int maxHealth = 100;
	int attack = 0;
	int defent = 0;
	float orient = 0;
	cocos2d::Vec2 speed; //speed vector per second
	cocos2d::Rect boxRect;  //box colleider
};


#endif //__ENTITY_H__