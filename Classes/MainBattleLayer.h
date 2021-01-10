#ifndef __MAIN_BATTLE_LATER_H__
#define __MAIN_BATTLE_LATER_H__

#include "cocos2d.h"
class MainBattleLayer : public cocos2d::Node
{
public:
	virtual bool init();
	CREATE_FUNC(MainBattleLayer);

	void setVisibleCenter(float, float);
	cocos2d::Vec2 getVisibleCenter();
	void moveVisibleCenter(float, float);

	float getScale() { return scale; };
	void setScale(float);
private:
	cocos2d::Size SceneSize;
	cocos2d::Vec2 SceneOrigin;
	cocos2d::Vec2 SceneCenter;

	cocos2d::Vec2 visibleCenterPos; //game position
	float scale = 1.0f;
};


#endif //__MAIN_BATTLE_LATER_H__