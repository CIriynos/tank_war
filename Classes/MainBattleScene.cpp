#include "MainBattleScene.h"
#include "MainBattleLayer.h"
#include "MyTank.h"
#include "PlayerTank.h"
using namespace cocos2d;

Scene* MainBattleScene::createScene()
{
	return MainBattleScene::create();
}

bool MainBattleScene::init()
{
	if (!Scene::init()) return false;
	
	//used for the global position in game
	auto layer = MainBattleLayer::create();

	auto tank = PlayerTank::create();
	auto landscape = Sprite::create("land.png");

	layer->addChild(landscape, -1);
	layer->addChild(tank, 2);

	tank->setPosition(0, 0);

	addChild(layer, 0);

	return true;
}

void MainBattleScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}