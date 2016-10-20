
#include "Interface.h"
#include "../Controller/MarioGame.h"
#include <sstream>

Interface::Interface(MarioGame& game, StringFactory& strFac):strFac_(strFac), coin_(game), game_(game)
{
    infoScreenTimer_.setActionsPerSec(0.33f);
    pressEnterStringInterval_.setActionsPerSec(1.25f);

    marioImage_.setShowingPosition(200, 550);
    marioImage_.setTexture(game_.getTexture(TEXTURE_MARIO_SMALL_MARIOSTAND));
    marioImage_.queryTexture();

    logo_.setShowingPosition(100, 430);
    logo_.setTexture(game_.getTexture(TEXTURE_MARIO_LOGO));
    logo_.queryTexture();
    logo_.setShowingWidth(300);

    startingBackground_.setTexture(game_.getTexture(TEXTURE_MARIO_LEVEL_1));
    startingBackground_.queryTexture();
    startingBackground_.setShowingPosition(0, 320);

    firstScreenShow_ = false;
    infoScreenShow_ = false;
}

void Interface::loadStrings()
{
    interface_[0].reloadText(&strFac_, "MARIO", FONT_MARIO, 15);
    interface_[1].reloadText(&strFac_, "WORLD", FONT_MARIO, 15);
    interface_[2].reloadText(&strFac_, "TIME", FONT_MARIO, 15);
    interface_[3].reloadText(&strFac_, "1-1", FONT_MARIO, 15);
    interface_[4].reloadText(&strFac_, "x", FONT_MARIO, 15);

    interface_[5].reloadText(&strFac_, "WORLD", FONT_MARIO, 15);
    interface_[6].reloadText(&strFac_, "1-1", FONT_MARIO, 15);
    interface_[7].reloadText(&strFac_, "x", FONT_MARIO, 15);

    interface_[8].reloadText(&strFac_, "Remastered by Pankiev", FONT_MARIO, 15);
    interface_[9].reloadText(&strFac_, "Press Enter", FONT_MARIO, 15);

    interface_[5].setShowingPosition(190,500);
    interface_[6].setShowingPosition(280,500);
    interface_[7].setShowingPosition(250,560);

    interface_[8].setShowingPosition(100, 610);
    interface_[9].setShowingPosition(175, 650);

    livesString_.setShowingPosition(290, 560);

    pointsString_.reloadText(&strFac_, "000000", FONT_MARIO, 15);
    timeString_.reloadText(&strFac_, "400", FONT_MARIO, 15);
    coinsString_.reloadText(&strFac_, "00", FONT_MARIO, 15);
    livesString_.reloadText(&strFac_,"3", FONT_MARIO, 15);
}

void Interface::action()
{
    repostionWithMarioCamera();

    if(firstScreenShow_)
        showFirstScreenHandle();
    else if(infoScreenShow_)
        showInfoScreenHandle();
}

void Interface::showInfoScreen()
{
    infoScreenShow_ = true;
    infoScreenTimer_.reset();
    livesUpdate(game_.getLives());
    stageUpdate(game_.createStageString());
    SDL_SetRenderDrawColor(game_.getRenderer(), 0, 0, 0, 255);

    interface_[5].restartRendering();
    interface_[6].restartRendering();
    interface_[7].restartRendering();
    marioImage_.restartRendering();
    game_.addImage(&marioImage_);
    game_.addImage(&interface_[5]);
    game_.addImage(&interface_[6]);
    game_.addImage(&interface_[7]);
    livesString_.restartRendering();
    game_.addImage(&livesString_);
}

void Interface::repostionWithMarioCamera()
{
    SDL_Rect camera = game_.getMarioCamera();
    interface_[0].setShowingPosition(camera.x + 40, 360);
    interface_[1].setShowingPosition(camera.x + 280, 360);
    interface_[2].setShowingPosition(camera.x + 400, 360);
    interface_[3].setShowingPosition(camera.x + 295, 385);
    interface_[4].setShowingPosition(camera.x + 195, 385);
    pointsString_.setShowingPosition(camera.x + 40, 385);
    timeString_.setShowingPosition(camera.x + 415, 385);
    coinsString_.setShowingPosition(camera.x + 210, 385);
    coin_.setShowingPosition(camera.x + 180, 386);
    coin_.action();
}

void Interface::addStrings()
{
    for(int i=0; i<5; i++)
        game_.addImage(&interface_[i]);

    game_.addImage(&pointsString_);
    game_.addImage(&timeString_);
    game_.addImage(&coin_);
    game_.addImage(&coinsString_);
}

void Interface::pointsUpdate(int points)
{
    if(points != pointsString_.getCurrentValue())
    {
        std::ostringstream ss;
        ss << points;
        std::string pointsStr = ss.str();
        int zerosNo = 6 - pointsStr.size();
        if(zerosNo > 0)
        {
            std::string zeros;
            zeros.resize(zerosNo, '0');
            pointsStr = zeros + pointsStr;
        }

        pointsString_.reloadText(&strFac_, pointsStr, FONT_MARIO, 15);
    }
}

void Interface::timeUpdate(int time)
{
    if(time != pointsString_.getCurrentValue())
    {
        std::ostringstream ss;
        ss << time;
        std::string pointsStr = ss.str();
        int zerosNo = 3 - pointsStr.size();
        if(zerosNo > 0)
        {
            std::string zeros;
            zeros.resize(zerosNo, '0');
            pointsStr = zeros + pointsStr;
        }
        timeString_.reloadText(&strFac_, pointsStr, FONT_MARIO, 15);
    }
}

void Interface::stageUpdate(std::string newStage)
{
    interface_[3].reloadText(&strFac_, newStage, FONT_MARIO, 15);
    interface_[6].reloadText(&strFac_, newStage, FONT_MARIO, 15);
}

void Interface::coinsUpdate(int coins)
{
    if(coins != coinsString_.getCurrentValue())
    {
        std::string coinsStr;
        coinsStr.clear();

        if(coins < 10)
        {
            coinsStr += '0';
            coinsStr += (char)coins + 48;
        }
        else
        {
            std::ostringstream ss;
            ss << coins;
            coinsStr = ss.str();
        }
        coinsString_.reloadText(&strFac_, coinsStr, FONT_MARIO, 15);
    }
}

void Interface::showInfoScreenHandle()
{
    infoScreenTimer_.calculateTime();
    if(infoScreenTimer_.askForAction())
    {
        infoScreenShow_ = false;
        interface_[5].stopRendering();
        interface_[6].stopRendering();
        interface_[7].stopRendering();
        marioImage_.stopRendering();
        livesString_.stopRendering();
        game_.loadNextLevel();
    }
}

void Interface::livesUpdate(int lives)
{
    std::string livesStr;
    std::ostringstream ss;
    ss << lives;
    livesStr = ss.str();
    livesString_.reloadText(&strFac_, livesStr, FONT_MARIO, 15);
}

void Interface::showFirstScreen()
{
    firstScreenShow_ = true;
    pressEnterStringInterval_.reset();

    startingBackground_.restartRendering();
    game_.addImage(&startingBackground_);
    logo_.restartRendering();
    game_.addImage(&logo_);
    interface_[8].restartRendering();
    game_.addImage(&interface_[8]);
    interface_[9].restartRendering();
    game_.addImage(&interface_[9]);
}

void Interface::showFirstScreenHandle()
{
    if(infoScreenShow_)
    {
        logo_.stopRendering();
        interface_[8].stopRendering();
        startingBackground_.stopRendering();
        interface_[9].stopRendering();
        firstScreenShow_ = false;
    }
    else
    {
        pressEnterStringInterval_.calculateTime();
        if(pressEnterStringInterval_.askForAction())
        {
            if(interface_[9].isRendering())
                interface_[9].stopRendering();
            else
            {
                interface_[9].restartRendering();
                game_.addImage(&interface_[9]);
            }
        }
    }
}
