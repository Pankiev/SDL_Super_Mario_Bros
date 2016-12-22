
#include "../Mario/Controller/MarioGame.h"
#include "../Mario/Model/ActiveBlock.h"
#include "../Mario/Model/HiddenUnkownBlock.h"
#include "../Mario/Model/AnimatingUnknownBlock.h"
#include "../Mario/Model/BlockCoin.h"
#include "../Mario/Model/Mushroom1UP.h"

#include "../Mario/Model/GoombasBrown.h"
#include "../Mario/Model/GoombasBlue.h"
#include "../Mario/Model/KoopaGreen.h"
#include "../Mario/Model/KoopaBlue.h"
#include "../Mario/Model/KoopaRed.h"
#include "../Mario/Model/PiranhaPlantGreen.h"
#include "../Mario/Model/PiranhaPlantBlue.h"
#include "../Mario/Model/Browser.h"
#include "../Mario/Model/BrowserFireShot.h"

#include "../Mario/Controller/MarioAnimation.h"
#include "../Mario/Model/MoneyBlock.h"
#include "../Mario/Model/Star.h"
#include "../Mario/Model/MovingPlatformElement.h"
#include "../Mario/Controller/SpecalObjectsFactory.h"
#include "../Mario/Model/PipeEnterController.h"
#include "../Mario/Model/EndFlagController.h"

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
   // Object* coll = nullptr;

    if(!m1->isShrinking() && !m1->isLevelingUp() &&
       !m1->isDying() && !m1->isInvincibleMoving() &&
       !m1->isLevelEnding())
    {
        if(!keyState_[SDL_SCANCODE_S])
            m1->standUp();

        if(keyState_[SDL_SCANCODE_S])
            m1->squat();
        else if(keyState_[SDL_SCANCODE_A] && keyState_[SDL_SCANCODE_D] && !m1->isInAir())
            m1->stand();
        else if (keyState_[SDL_SCANCODE_A] && keyState_[SDL_SCANCODE_D]);
        else if (keyState_[SDL_SCANCODE_A])
            m1->slideMove(LEFT, 5.25f);
        else if(keyState_[SDL_SCANCODE_D])
            m1->slideMove(RIGHT, 5.25f);
        else if(m1->getSlideFactor() < 0.1f && m1->getSlideFactor() > -0.1f && !m1->isInAir())
            m1->stand();

        if(keyState_[SDL_SCANCODE_SPACE])
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

    int x,y;
    SDL_GetMouseState(&x, &y);
    x = x*1920.0f/7168.0f+m1->calcCameraRect(7168, 1000).x-12;
    y = y*450/1000+333;
    x -= x%32;
    y -= y%32;

    if(mouseObject == nullptr)
    {
        if(keyState_[SDL_SCANCODE_1])
            mouseObject = new GameBase(((MarioGame&)mainController_), TEXTURE_BUSH_CENTER_2);
        else if(keyState_[SDL_SCANCODE_2])
            mouseObject = new GameBase(((MarioGame&)mainController_), TEXTURE_END_GLOBE);
        else if(keyState_[SDL_SCANCODE_3])
            mouseObject = new GameBase(((MarioGame&)mainController_), TEXTURE_END_PIPE);
        else if(keyState_[SDL_SCANCODE_4])
            mouseObject = new GameBase(((MarioGame&)mainController_), TEXTURE_PIPE_RIGHT_TOP);
        else if(keyState_[SDL_SCANCODE_5])
            mouseObject = new GameBase(((MarioGame&)mainController_), TEXTURE_BUSH_TOP);
        else if(keyState_[SDL_SCANCODE_6])
            mouseObject = new GameBase((MarioGame&)mainController_, TEXTURE_COULD_RIGHT_BOTTOM);
        else if(keyState_[SDL_SCANCODE_7])
            mouseObject = new Block((MarioGame&)mainController_, TEXTURE_PIPE_LEFT_BOTTOM);
        else if(keyState_[SDL_SCANCODE_8])
            mouseObject = new Block((MarioGame&)mainController_, TEXTURE_PIPE_RIGHT_BOTTOM);


        if(mouseObject != nullptr)
            mouseObject->queryTexture();
    }
    if(mouseObject != nullptr)
        mouseObject->setShowingPosition(x,y);
}

void HardwareController::keyboardDisposableAction()
{
    action_ = checkForAction();
    Mario* m1 = ((MarioGame&)mainController_).getMainChar();
    //CollisionMap* map = mainController_.getCollsionMap();
    m1->keepOutOfPipe();
    if(action_)
    {
        if(getEventType() == SDL_KEYDOWN)
        {
            switch(getEventKey())
            {
            case SDLK_ESCAPE:
                break;
            case SDLK_c:
                m1->invincibilityMove({m1->getShowingRect().x, m1->getShowingRect().y+2*m1->getShowingRect().h});
                break;
            case SDLK_e:
                m1->invincibilityActivate();
                break;
            case SDLK_l:
                ((MarioGame&)mainController_).loadGame("temp.txt");
                break;
            case SDLK_g:
                m1->grow();
                break;
            case SDLK_t:
                ((MarioGame&)mainController_).saveGame("temp.txt");
                break;
            case SDLK_q:
                mainController_.gameOver();
                break;
            case SDLK_r:
                m1->shoot();
                break;
            case SDLK_x:
    ((MarioGame&)mainController_).addToGame(new EndFlagController((MarioGame&)mainController_, 672));
    //((MarioGame&)mainController_).addToGame(new PipeEnterController
    //((MarioGame&)mainController_, {424, 746}, {500, 730}, {100, 300}, LEVEL_1_2_UNDERGROUND_PATH));
                break;
            case SDLK_v:
                m1->pipeEnter();
                break;
            case SDLK_RETURN:
                ((MarioGame&)mainController_).sameLevel();
                break;
            case SDLK_w:
                ((MarioGame&)mainController_).getMainChar()->move(*((MarioGame&)mainController_).getCollsionMap(), UP, (int)1);
                break;
            case SDLK_s:
                ((MarioGame&)mainController_).getMainChar()->move(*((MarioGame&)mainController_).getCollsionMap(), DOWN, (int)1);
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
    {
        CollisionMap* map = mainController_.getCollsionMap();
        if(getEventType() == SDL_QUIT)
        {
            mainController_.gameOver();
        }
        else if(getEventType() == SDL_MOUSEBUTTONUP)
        {
            Mario* m1 = ((MarioGame&)mainController_).getMainChar();
            int x, y;
            SDL_GetMouseState(&x, &y);
            x = x*1920.0f/7168.0f+m1->calcCameraRect(7168, 1000).x;
            y = y*450/1000+340;
            printf("x: %d, y: %d\n", x, y);
            if(getEventButton() == SDL_BUTTON_LEFT)
            {
                if(mouseObject != nullptr && map->getObjectInPosition(x,y) == nullptr)
                {
                    SDL_Rect temp = mouseObject->getShowingRect();
                    mouseObject->setBothRects(temp);
                    temp.y+=2;
                    temp.h-=2;
                    mouseObject->setCollisionRect(temp);
                    ((MarioGame&)mainController_).addToGame(mouseObject);
                    map->update(mouseObject);
                    mouseObject = nullptr;
                }
            }
            else if(getEventButton() == SDL_BUTTON_RIGHT)
            {
                if(mouseObject != nullptr)
                {
                    mouseObject->die();
                    mouseObject = nullptr;
                }
                else
                {
                    GameBase* g1 = ((GameBase*)map->getObjectInPosition(x,y));
                    if(g1 != nullptr)
                    {
                        map->clearColl(g1->getCollisionRect());
                        g1->die();
                        ((MarioGame&)mainController_).clearActionInactives();
                    }
                }
                //SpecialObjectsFactory f1(((MarioGame&)mainController_));
                //x -= x%32;
                //y -= y%32;
                //f1.producePlatform(6, x, y);
            }
        }
    }
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
