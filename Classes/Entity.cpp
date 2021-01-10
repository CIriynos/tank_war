#include "Entity.h"
#include "MainBattleLayer.h"
using namespace cocos2d;

Entity* Entity::create()
{
	Entity* ptr = new Entity();
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

bool Entity::init()
{
	if(!Node::init()) return false;
	speed = Vec2::ZERO;
	return true;
}