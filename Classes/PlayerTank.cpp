#include "PlayerTank.h"
using namespace cocos2d;

bool PlayerTank::init()
{
	if(!Tank::init()) return false;
	//add event listener
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(PlayerTank::onKeyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(PlayerTank::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
	return true;
}

void PlayerTank::onKeyPressed(EventKeyboard::KeyCode code, Event* event)
{
	if(getCurrentState() == State::START_ACCE
	|| getCurrentState() == State::STOP_ACCE)
	{
		return;
	}
	else if(getCurrentState() == State::STOP)
	{
		if(code == EventKeyboard::KeyCode::KEY_W){
			startStraightMove();
		}
		else if(code == EventKeyboard::KeyCode::KEY_S){
			startBackMove();
		}
		else if(code == EventKeyboard::KeyCode::KEY_A){
			startLeftRotate();
		}
		else if(code == EventKeyboard::KeyCode::KEY_D){
			startRightRotate();
		}
	}
	else if(getCurrentState() == State::MOVE)
	{
		if(code == EventKeyboard::KeyCode::KEY_A){
			addLeftMove();
		}
		else if(code == EventKeyboard::KeyCode::KEY_D){
			addRightMove();
		}
	}
	else if(getCurrentState() == State::LEFT_MOVE)
	{
	}
	else if(getCurrentState() == State::RIGHT_MOVE)
	{
	}
	else if(getCurrentState() == State::BACK_MOVE)
	{
	}
	else if(getCurrentState() == State::LEFT_ROTATE)
	{
		if(code == EventKeyboard::KeyCode::KEY_W){
			addLeftMoveFromRotate();
		}
	}
	else if(getCurrentState() == State::RIGHT_MOVE)
	{
		if(code == EventKeyboard::KeyCode::KEY_W){
			addRightMoveFromRotate();
		}
	}
}

void PlayerTank::onKeyReleased(EventKeyboard::KeyCode code, Event* event)
{
	if(getCurrentState() == State::START_ACCE
	|| getCurrentState() == State::STOP_ACCE)
	{
		return;
	}
	else if(getCurrentState() == State::STOP)
	{
	}
	else if(getCurrentState() == State::MOVE)
	{
		if(code == EventKeyboard::KeyCode::KEY_W){
			stopMove();
		}
	}
	else if(getCurrentState() == State::LEFT_MOVE)
	{
		if(code == EventKeyboard::KeyCode::KEY_A){
			turnToStraightMove();
		}
		else if(code == EventKeyboard::KeyCode::KEY_W){
			turnToLeftRotate();
		}
	}
	else if(getCurrentState() == State::RIGHT_MOVE)
	{
		if(code == EventKeyboard::KeyCode::KEY_D){
			turnToStraightMove();
		}
		else if(code == EventKeyboard::KeyCode::KEY_D){
			turnToRightRotate();
		}
	}
	else if(getCurrentState() == State::BACK_MOVE)
	{
		if(code == EventKeyboard::KeyCode::KEY_S){
			stopBackMove();
		}
	}
	else if(getCurrentState() == State::LEFT_ROTATE){
		if(code == EventKeyboard::KeyCode::KEY_A){
			stopLeftRotate();
		}
	}
	else if(getCurrentState() == State::RIGHT_MOVE){
		if(code == EventKeyboard::KeyCode::KEY_D){
			stopRightRotate();
		}
	}
}