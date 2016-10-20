
#pragma once

#include "../../View/SdlString.h"
#include "../../Model/NewString.h"
#include "InterfaceCoin.h"
#include "../../Controller/Timer.h"

class Interface
{
public:

    Interface(MarioGame& game, StringFactory& strFac);

    void loadStrings();
    void action();
    void repostionWithMarioCamera();
    void addStrings();
    void pointsUpdate(int points);
    void timeUpdate(int points);
    void stageUpdate(std::string newStage);
    void coinsUpdate(int coins);
    void livesUpdate(int lives);

    void showInfoScreen();
    void showFirstScreen();


private:

    void showInfoScreenHandle();
    void showFirstScreenHandle();

    StringFactory& strFac_;
    SdlString interface_[10];
    NewString pointsString_;
    NewString timeString_;
    NewString coinsString_;
    NewString livesString_;
    InterfaceCoin coin_;
    MarioGame& game_;
    Timer infoScreenTimer_;
    Object marioImage_;
    Object logo_;
    Object startingBackground_;

    bool firstScreenShow_;
    bool infoScreenShow_;

    Timer pressEnterStringInterval_;
};
