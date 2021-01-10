#include "MainBattleLayer.h"
using namespace cocos2d;

bool MainBattleLayer::init()
{
	if(!Node::init()) return false;
	SceneSize = Director::getInstance()->getVisibleSize();
    SceneOrigin = Director::getInstance()->getVisibleOrigin();
    SceneCenter = SceneOrigin + Vec2(SceneSize.width / 2, SceneSize.height / 2);

    auto land = Sprite::create("land.png");
    land->setPosition(0, 0);
    addChild(land, -1); //always beneath everything

    setPosition(SceneCenter);
	return true;
}

void MainBattleLayer::setVisibleCenter(float x, float y)
{
	visibleCenterPos = Vec2(x, y);
	this->setPosition(-x + SceneCenter.x, -y + SceneCenter.y);
}

Vec2 MainBattleLayer::getVisibleCenter()
{
	return visibleCenterPos;
}

void MainBattleLayer::moveVisibleCenter(float x, float y)
{

}

void MainBattleLayer::setScale(float s)
{
	scale = s;
	//adjust ...
}