#ifndef __MAINBATTLE_SCENE_H__
#define __MAINBATTLE_SCENE_H__

#include "cocos2d.h"

class MainBattleScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(MainBattleScene);
};

#endif // __MAINBATTLE_SCENE_H__