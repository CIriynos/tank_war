#ifndef __PLAYER_TANK_H__
#define __PLAYER_TANK_H__

#include "cocos2d.h"
#include "MyTank.h"

class PlayerTank: public Tank
{
public:
	virtual bool init();
	CREATE_FUNC(PlayerTank);
private:
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
	bool upButton = false;
	bool downButton = false;
	bool leftButton = false;
	bool rightButton = false;
};

#endif //__PLAYER_TANK_H__