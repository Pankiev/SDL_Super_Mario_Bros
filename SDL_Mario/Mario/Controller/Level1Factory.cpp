
#include "Level1Factory.h"
#include "MarioGame.h"
#include "../Model/ActiveBlock.h"

Level1Factory::Level1Factory(MarioGame& game):game_(game)
{

}

void Level1Factory::build()
{
    createGround();
    createBricks();
    //createPipes();
}

void Level1Factory::createGround()
{
    for(int i = 800-2*BLOCK_HEIGHT; i<800; i+=BLOCK_HEIGHT)
        for(int j=0; j+BLOCK_WIDTH<=GAME_WIDTH; j+=BLOCK_WIDTH)
        {
            if((j <= 2180 || j>= 2250) && (j <= 2730 || j>= 2820)
                && (j<=4865 || j>=4940))
                createInactiveBrick(j,i,TEXTURE_MARIO_GROUND_RED_1);
        }
}

void Level1Factory::createBricks()
{
    createBrick(640, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(640+2*BLOCK_WIDTH, 576, TEXTURE_MARIO_BRICK_RED);
    createBrick(640+2*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(640+4*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(300+0*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(300+1*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(300-1*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(300-2*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(300-3*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(300+2*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(300+3*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(300+4*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(300+5*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);

        for(int j=140; j<BLOCK_WIDTH*8+140; j+=BLOCK_WIDTH)
                createBrick(j,576,TEXTURE_MARIO_BRICK_RED);

    createBrick(600,500,TEXTURE_MARIO_BRICK_RED);
    createBrick(2464, 608, TEXTURE_MARIO_BRICK_RED);
    createBrick(2464+2*BLOCK_WIDTH, 608, TEXTURE_MARIO_BRICK_RED);
    for(int i=0; i<8; i++)
        createBrick(2560+i*BLOCK_WIDTH, 480, TEXTURE_MARIO_BRICK_RED);

    for(int i=0; i<3; i++)
        createBrick(2913+i*BLOCK_WIDTH, 480, TEXTURE_MARIO_BRICK_RED);

    createBrick(3008, 608, TEXTURE_MARIO_BRICK_RED);


//384


    for(int i = 608; i<BLOCK_HEIGHT*4+608; i+=BLOCK_HEIGHT)
        for(int j=4480; j<BLOCK_WIDTH*4+4480; j+=BLOCK_WIDTH)
        {
            if(i-608>=j-4480)
                createInactiveBrick(j,i,TEXTURE_MARIO_GROUND_RED_2);
        }
    for(int i = 608; i<BLOCK_HEIGHT*4+608; i+=BLOCK_HEIGHT)
        for(int j=4960; j<BLOCK_WIDTH*4+4960; j+=BLOCK_WIDTH)
        {
            if(i-608>=j-4960)
                createInactiveBrick(j,i,TEXTURE_MARIO_GROUND_RED_2);
        }
}

void Level1Factory::createBrick(int x, int y, int TEXTURE_CONSTANT)
{
    ActiveBlock* brick = new ActiveBlock(game_, TEXTURE_CONSTANT);
    brick->setBothPosition(x, y);
    brick->setCollisionRect(x, y+2, brick->getCollisionRect().w, brick->getCollisionRect().h-2);
    game_.addToGame(brick);
    game_.getCollsionMap()->update(brick);
}

void Level1Factory::createInactiveBrick(int x, int y, int TEXTURE_CONSTANT)
{
    Block* brick = new Block(game_, TEXTURE_CONSTANT);
    brick->setBothPosition(x, y);
    brick->setCollisionRect(x, y+2, brick->getCollisionRect().w, brick->getCollisionRect().h-2);
    game_.addToGame(brick);
    game_.getCollsionMap()->update(brick);
}

void Level1Factory::createPipes()
{
    //createBrick(1216, 639, TEXTURE_MARIO_PIPE);
}
