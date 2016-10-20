
#pragma once

class MarioGame;

class Level1Factory
{
public :

    Level1Factory(MarioGame& game);
    void build();

private :

    void createGround();
    void createBricks();
    void createPipes();
    void createBrick(int x, int y, int TEXTURE_CONSTANT);
    void createInactiveBrick(int x, int y, int TEXTURE_CONSTANT);

    MarioGame& game_;
};
