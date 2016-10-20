
#include "Block.h"
#include "../Controller/MarioGame.h"

Block::Block(MarioGame& game, int BLOCK_TYPE):Block(game)
{
    setTexture(BLOCK_TYPE);
    setLayer(10);
    setId(234);
}

Block::Block(MarioGame& game):GameBase(game)
{
    setBothRects({0,0, BLOCK_WIDTH, BLOCK_HEIGHT});
    setName("Block");
}

void Block::marioHit()
{
    game_.playSoundEfx(CHUNKSOUND_BLOCK_HIT);
}
