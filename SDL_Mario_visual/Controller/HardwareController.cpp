
#include "../Mario/Controller/MarioGame.h"
#include "../Mario/Controller/MarioAnimation.h"


HardwareController::HardwareController(Controller& mainController):mainController_(mainController){}

GameBase* mouseObject = nullptr;

void HardwareController::handle()
{
	keyboardConstantAction();
	keyboardDisposableAction();
	mouseAction();
}
 
void HardwareController::keyboardConstantAction()
{
	keyState_ = SDL_GetKeyboardState(NULL);
	Mario* m1 = ((MarioGame*)&mainController_)->getMainChar();

	if(!m1->isShrinking() && !m1->isLevelingUp() &&
	   !m1->isDying() && !m1->isInvincibleMoving() &&
	   !m1->isLevelEnding())
	{
		if(!keyState_[SDL_SCANCODE_DOWN])
			m1->standUp();

		if(keyState_[SDL_SCANCODE_DOWN])
			m1->squat();
		else if(keyState_[SDL_SCANCODE_LEFT] && keyState_[SDL_SCANCODE_RIGHT] && !m1->isInAir())
			m1->stand();
		else if (keyState_[SDL_SCANCODE_LEFT] && keyState_[SDL_SCANCODE_RIGHT]);
		else if (keyState_[SDL_SCANCODE_LEFT])
			m1->slideMove(LEFT, 5.25f);
		else if(keyState_[SDL_SCANCODE_RIGHT])
			m1->slideMove(RIGHT, 5.25f);
		else if(m1->getSlideFactor() < 0.1f && m1->getSlideFactor() > -0.1f && !m1->isInAir())
			m1->stand();

		if(keyState_[SDL_SCANCODE_UP])
			m1->jump();

		if(m1->isInAir() && !m1->isSquatting())
			m1->jump(); // texture set

		if(m1->getSlideFactor() > 0.1f)
			m1->setFlipMode(SDL_FLIP_NONE);
		else if(m1->getSlideFactor() < -0.1f)
			m1->setFlipMode(SDL_FLIP_HORIZONTAL);

		if(m1->isSquatting())
			m1->Object::setTexture(((MarioAnimation*)m1->getAnimation())->animateSquat());

	}
}

void HardwareController::keyboardDisposableAction()
{
	action_ = checkForAction();
	Mario* m1 = ((MarioGame&)mainController_).getMainChar();
	m1->keepOutOfPipe();
	if(action_)
	{
		if(getEventType() == SDL_KEYDOWN)
		{
			switch(getEventKey())
			{
			case SDLK_n:
				((MarioGame&)mainController_).newGame();
				break;
			case SDLK_ESCAPE:
				mainController_.gameOver();
				break;
			case SDLK_l:
				((MarioGame&)mainController_).loadGame("savedByUser.txt");
				break;
			case SDLK_s:
				((MarioGame&)mainController_).saveGame("savedByUser.txt");
				break;
			case SDLK_r:
				m1->shoot();
				break;
			case SDLK_v:
				m1->pipeEnter();
				break;
			case SDLK_o:
				((MarioGame&)mainController_).nextLevel();
				break;
			default:
				break;
			}
		}
	}
}

void HardwareController::mouseAction()
{
	if(action_)
		if(getEventType() == SDL_QUIT)
			mainController_.gameOver();
}


bool HardwareController::checkForAction()
{
	if(SDL_PollEvent(&event_) != NO_ACTION)
		return true;
	return false;
}

int HardwareController::getEventType()
{
	return event_.type;
}
int HardwareController::getMousePosX()
{
	return event_.motion.x;
}

int HardwareController::getMousePosY()
{
	return event_.motion.y;
}

bool HardwareController::isMouseInRect(SDL_Rect rect)
{
	int x = getMousePosX();
	int y = getMousePosY();
	if(x >= rect.x && x <= rect.x+rect.w &&
	   y >= rect.y && y <= rect.y+rect.h)
		return true;

	return false;
}

int HardwareController::getEventButton()
{
	return event_.button.button;
}

int HardwareController::getEventKey()
{
	return event_.key.keysym.sym;
}
