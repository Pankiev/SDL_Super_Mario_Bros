
#include "TextureHolder.h"

TextureHolder::TextureHolder()
{
    textures_ = nullptr;
    texturesNo = TEXTURE_NO;
    transparentColor_ = 0;
}

void TextureHolder::loadTextures(SDL_Renderer* renderer)
{
    malloc();
    loadTexture(TEXTURE_MARIO_SMALL_MARIOSTAND_PATH, TEXTURE_MARIO_SMALL_MARIOSTAND, renderer);
    loadTexture(TEXTURE_MARIO_GROUND_RED_1_PATH, TEXTURE_MARIO_GROUND_RED_1, renderer);
    loadTexture(TEXTURE_MARIO_GROUND_RED_2_PATH, TEXTURE_MARIO_GROUND_RED_2, renderer);
    loadTexture(TEXTURE_MARIO_LEVEL_1_PATH, TEXTURE_MARIO_LEVEL_1, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_MARIOMOVE_1_PATH, TEXTURE_MARIO_SMALL_MARIOMOVE_1, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_MARIOMOVE_2_PATH, TEXTURE_MARIO_SMALL_MARIOMOVE_2, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_MARIOMOVE_3_PATH, TEXTURE_MARIO_SMALL_MARIOMOVE_3, renderer);
    loadTexture(TEXTURE_MARIO_BIG_MARIOMOVE_1_PATH, TEXTURE_MARIO_BIG_MARIOMOVE_1, renderer);
    loadTexture(TEXTURE_MARIO_BIG_MARIOMOVE_2_PATH, TEXTURE_MARIO_BIG_MARIOMOVE_2, renderer);
    loadTexture(TEXTURE_MARIO_BIG_MARIOMOVE_3_PATH, TEXTURE_MARIO_BIG_MARIOMOVE_3, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_MARIODIE_PATH, TEXTURE_MARIO_SMALL_MARIODIE, renderer);
    loadTexture(TEXTURE_MARIO_BRICK_RED_PATH, TEXTURE_MARIO_BRICK_RED, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_JUMP_PATH, TEXTURE_MARIO_SMALL_JUMP, renderer);
    loadTexture(TEXTURE_GOOMBAS1MOVE_1_PATH, TEXTURE_GOOMBAS1MOVE_1, renderer);
    loadTexture(TEXTURE_GOOMBAS1MOVE_2_PATH, TEXTURE_GOOMBAS1MOVE_2, renderer);
    loadTexture(TEXTURE_GOOMBAS1DEAD_PATH, TEXTURE_GOOMBAS1DEAD, renderer);
    loadTexture(TEXTURE_DEBRIS1_PATH, TEXTURE_DEBRIS1, renderer);
    loadTexture(TEXTURE_DEBRIS2_PATH, TEXTURE_DEBRIS2, renderer);
    loadTexture(TEXTURE_DEBRIS3_PATH, TEXTURE_DEBRIS3, renderer);
    loadTexture(TEXTURE_MUSHROOM_PATH, TEXTURE_MUSHROOM,  renderer);
    loadTexture(TEXTURE_MARIO_GROW_PATH, TEXTURE_MARIO_GROW,  renderer);
    loadTexture(TEXTURE_MARIO_BIG_MARIOSTAND_PATH, TEXTURE_MARIO_BIG_STAND,  renderer);
    loadTexture(TEXTURE_MARIO_BIG_MARIOJUMP_PATH, TEXTURE_MARIO_BIG_JUMP, renderer);
    loadTexture(TEXTURE_BUSH_CENTER_1_PATH, TEXTURE_BUSH_CENTER_1, renderer);
    loadTexture(TEXTURE_BUSH_CENTER_2_PATH, TEXTURE_BUSH_CENTER_2, renderer);
    loadTexture(TEXTURE_BUSH_RIGHT_PATH, TEXTURE_BUSH_RIGHT, renderer);
    loadTexture(TEXTURE_BUSH_LEFT_PATH, TEXTURE_BUSH_LEFT, renderer);
    loadTexture(TEXTURE_BUSH_TOP_PATH, TEXTURE_BUSH_TOP, renderer);
    loadTexture(TEXTURE_COULD_CENTER_BOTTOM_PATH, TEXTURE_COULD_CENTER_BOTTOM, renderer);
    loadTexture(TEXTURE_COULD_CENTER_TOP_PATH, TEXTURE_COULD_CENTER_TOP, renderer);
    loadTexture(TEXTURE_COULD_LEFT_BOTTOM_PATH, TEXTURE_COULD_LEFT_BOTTOM, renderer);
    loadTexture(TEXTURE_COULD_LEFT_TOP_PATH, TEXTURE_COULD_LEFT_TOP, renderer);
    loadTexture(TEXTURE_COULD_RIGHT_BOTTOM_PATH, TEXTURE_COULD_RIGHT_BOTTOM, renderer);
    loadTexture(TEXTURE_COULD_RIGHT_TOP_PATH, TEXTURE_COULD_RIGHT_TOP, renderer);
    loadTexture(TEXTURE_GRASS_LEFT_PATH, TEXTURE_GRASS_LEFT, renderer);
    loadTexture(TEXTURE_GRASS_CENTER_PATH, TEXTURE_GRASS_CENTER, renderer);
    loadTexture(TEXTURE_GRASS_RIGHT_PATH, TEXTURE_GRASS_RIGHT, renderer);
    loadTexture(TEXTURE_PIPE_LEFT_BOTTOM_PATH, TEXTURE_PIPE_LEFT_BOTTOM, renderer);
    loadTexture(TEXTURE_PIPE_RIGHT_BOTTOM_PATH, TEXTURE_PIPE_RIGHT_BOTTOM, renderer);
    loadTexture(TEXTURE_PIPE_RIGHT_TOP_PATH, TEXTURE_PIPE_RIGHT_TOP, renderer);
    loadTexture(TEXTURE_PIPE_LEFT_TOP_PATH, TEXTURE_PIPE_LEFT_TOP, renderer);
    loadTexture(TEXTURE_CASTLE_BRICK_PATH, TEXTURE_CASTLE_BRICK, renderer);
    loadTexture(TEXTURE_CASTLE_CENTER_CENTER_PATH, TEXTURE_CASTLE_CENTER_CENTER, renderer);
    loadTexture(TEXTURE_CASTLE_CENTER_CENTER_TOP_PATH, TEXTURE_CASTLE_CENTER_CENTER_TOP, renderer);
    loadTexture(TEXTURE_CASTLE_CENTER_LEFT_PATH, TEXTURE_CASTLE_CENTER_LEFT, renderer);
    loadTexture(TEXTURE_CASTLE_CENTER_RIGHT_PATH, TEXTURE_CASTLE_CENTER_RIGHT, renderer);
    loadTexture(TEXTURE_CASTLE_TOP_1_PATH, TEXTURE_CASTLE_TOP_1, renderer);
    loadTexture(TEXTURE_CASTLE_TOP_2_PATH, TEXTURE_CASTLE_TOP_2, renderer);
    loadTexture(TEXTURE_END_FLAG_PATH, TEXTURE_END_FLAG, renderer);
    loadTexture(TEXTURE_END_GLOBE_PATH, TEXTURE_END_GLOBE, renderer);
    loadTexture(TEXTURE_END_PIPE_PATH, TEXTURE_END_PIPE, renderer);
    loadTexture(TEXTURE_UNKNOWN_BOX1_1_PATH, TEXTURE_UNKNOWN_BOX1_1, renderer);
    loadTexture(TEXTURE_UNKNOWN_BOX1_2_PATH, TEXTURE_UNKNOWN_BOX1_2, renderer);
    loadTexture(TEXTURE_UNKNOWN_BOX1_3_PATH, TEXTURE_UNKNOWN_BOX1_3, renderer);
    loadTexture(TEXTURE_EMPTY_BOX_PATH, TEXTURE_EMPTY_BOX, renderer);
    loadTexture(TEXTURE_COIN_BOX_1_PATH, TEXTURE_COIN_BOX_1, renderer);
    loadTexture(TEXTURE_COIN_BOX_2_PATH, TEXTURE_COIN_BOX_2, renderer);
    loadTexture(TEXTURE_COIN_BOX_3_PATH, TEXTURE_COIN_BOX_3, renderer);
    loadTexture(TEXTURE_COIN_BOX_4_PATH, TEXTURE_COIN_BOX_4, renderer);
    loadTexture(TEXTURE_COIN_INTERFACE_1_PATH, TEXTURE_COIN_INTERFACE_1, renderer);
    loadTexture(TEXTURE_COIN_INTERFACE_2_PATH, TEXTURE_COIN_INTERFACE_2, renderer);
    loadTexture(TEXTURE_COIN_INTERFACE_3_PATH, TEXTURE_COIN_INTERFACE_3, renderer);
    loadTexture(TEXTURE_FLOWER_1_PATH, TEXTURE_FLOWER_1, renderer);
    loadTexture(TEXTURE_FLOWER_2_PATH, TEXTURE_FLOWER_2, renderer);
    loadTexture(TEXTURE_FLOWER_3_PATH, TEXTURE_FLOWER_3, renderer);
    loadTexture(TEXTURE_FLOWER_4_PATH, TEXTURE_FLOWER_4, renderer);
    loadTexture(TEXTURE_STAR_1_PATH, TEXTURE_STAR_1, renderer);
    loadTexture(TEXTURE_STAR_2_PATH, TEXTURE_STAR_2, renderer);
    loadTexture(TEXTURE_STAR_3_PATH, TEXTURE_STAR_3, renderer);
    loadTexture(TEXTURE_STAR_4_PATH, TEXTURE_STAR_4, renderer);
    loadTexture(TEXTURE_FIREBALL_1_PATH, TEXTURE_FIREBALL_1, renderer);
    loadTexture(TEXTURE_FIREBALL_2_PATH, TEXTURE_FIREBALL_2, renderer);
    loadTexture(TEXTURE_FIREBALL_3_PATH, TEXTURE_FIREBALL_3, renderer);
    loadTexture(TEXTURE_FIREBALL_4_PATH, TEXTURE_FIREBALL_4, renderer);
    loadTexture(TEXTURE_FIREWORK_1_PATH, TEXTURE_FIREWORK_1, renderer);
    loadTexture(TEXTURE_FIREWORK_2_PATH, TEXTURE_FIREWORK_2, renderer);
    loadTexture(TEXTURE_FIREWORK_3_PATH, TEXTURE_FIREWORK_3, renderer);
    loadTexture(TEXTURE_KOOPA1_WALK_1_PATH, TEXTURE_KOOPA1_WALK_1, renderer);
    loadTexture(TEXTURE_KOOPA1_WALK_2_PATH, TEXTURE_KOOPA1_WALK_2, renderer);
    loadTexture(TEXTURE_KOOPA1_JUMP_1_PATH, TEXTURE_KOOPA1_JUMP_1, renderer);
    loadTexture(TEXTURE_KOOPA1_JUMP_2_PATH, TEXTURE_KOOPA1_JUMP_2, renderer);
    loadTexture(TEXTURE_KOOPA1_SHELL_MODE_PATH, TEXTURE_KOOPA1_SHELL_MODE, renderer);
    loadTexture(TEXTURE_MARIO_FIRE_STAND_PATH, TEXTURE_MARIO_FIRE_STAND, renderer);
    loadTexture(TEXTURE_MARIO_FIRE_JUMP_PATH, TEXTURE_MARIO_FIRE_JUMP, renderer);
    loadTexture(TEXTURE_MARIO_FIRE_MOVE_1_PATH, TEXTURE_MARIO_FIRE_MOVE_1, renderer);
    loadTexture(TEXTURE_MARIO_FIRE_MOVE_2_PATH, TEXTURE_MARIO_FIRE_MOVE_2, renderer);
    loadTexture(TEXTURE_MARIO_FIRE_MOVE_3_PATH, TEXTURE_MARIO_FIRE_MOVE_3, renderer);
    loadTexture(TEXTURE_MUSHROOM_1UP_PATH, TEXTURE_MUSHROOM_1UP, renderer);
    loadTexture(TEXTURE_MARIO_INVINCIBILITY_STAND_PATH, TEXTURE_MARIO_INVINCIBILITY_STAND, renderer);
    loadTexture(TEXTURE_MARIO_INVINCIBILITY_MOVE_1_PATH, TEXTURE_MARIO_INVINCIBILITY_MOVE_1, renderer);
    loadTexture(TEXTURE_MARIO_INVINCIBILITY_MOVE_2_PATH, TEXTURE_MARIO_INVINCIBILITY_MOVE_2, renderer);
    loadTexture(TEXTURE_MARIO_INVINCIBILITY_MOVE_3_PATH, TEXTURE_MARIO_INVINCIBILITY_MOVE_3, renderer);
    loadTexture(TEXTURE_MARIO_INVINCIBILITY_JUMP_PATH, TEXTURE_MARIO_INVINCIBILITY_JUMP, renderer);
    loadTexture(TEXTURE_COIN_1_PATH, TEXTURE_COIN_1, renderer);
    loadTexture(TEXTURE_COIN_2_PATH, TEXTURE_COIN_2, renderer);
    loadTexture(TEXTURE_COIN_3_PATH, TEXTURE_COIN_3, renderer);
    loadTexture(TEXTURE_LEVEL1_UNDERGROUND_PATH, TEXTURE_LEVEL1_UNDERGROUND, renderer);
    loadTexture(TEXTURE_BRICK_2_PATH, TEXTURE_BRICK_2, renderer);
    loadTexture(TEXTURE_GROUND_2_PATH, TEXTURE_GROUND_2, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_STAND_1_PATH, TEXTURE_MARIO_SMALL_INVINCIBILITY_STAND_1, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_STAND_2_PATH, TEXTURE_MARIO_SMALL_INVINCIBILITY_STAND_2, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_JUMP_1_PATH, TEXTURE_MARIO_SMALL_INVINCIBILITY_JUMP_1, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_JUMP_2_PATH, TEXTURE_MARIO_SMALL_INVINCIBILITY_JUMP_2, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_1_PATH, TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_1, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_2_PATH, TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_2, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_3_PATH, TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_3, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_4_PATH, TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_4, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_5_PATH, TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_5, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_6_PATH, TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_6, renderer);
    loadTexture(TEXTURE_PIPE_HORIZONTAL_BOT_CENTER_PATH, TEXTURE_PIPE_HORIZONTAL_BOT_CENTER, renderer);
    loadTexture(TEXTURE_PIPE_HORIZONTAL_TOP_CENTER_PATH, TEXTURE_PIPE_HORIZONTAL_TOP_CENTER, renderer);
    loadTexture(TEXTURE_PIPE_HORIZONTAL_BOT_LEFT_PATH, TEXTURE_PIPE_HORIZONTAL_BOT_LEFT, renderer);
    loadTexture(TEXTURE_PIPE_HORIZONTAL_TOP_LEFT_PATH, TEXTURE_PIPE_HORIZONTAL_TOP_LEFT, renderer);
    loadTexture(TEXTURE_PIPE_HORIZONTAL_BOT_RIGHT_PATH, TEXTURE_PIPE_HORIZONTAL_BOT_RIGHT, renderer);
    loadTexture(TEXTURE_PIPE_HORIZONTAL_TOP_RIGHT_PATH, TEXTURE_PIPE_HORIZONTAL_TOP_RIGHT, renderer);
    loadTexture(TEXTURE_MARIO_BIG_SQUAT_PATH, TEXTURE_MARIO_BIG_SQUAT, renderer);
    loadTexture(TEXTURE_MARIO_FIRE_SQUAT_PATH, TEXTURE_MARIO_FIRE_SQUAT, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_CLIMB_1_PATH, TEXTURE_MARIO_SMALL_CLIMB_1, renderer);
    loadTexture(TEXTURE_MARIO_SMALL_CLIMB_2_PATH, TEXTURE_MARIO_SMALL_CLIMB_2, renderer);
    loadTexture(TEXTURE_MARIO_BIG_CLIMB_1_PATH, TEXTURE_MARIO_BIG_CLIMB_1, renderer);
    loadTexture(TEXTURE_MARIO_BIG_CLIMB_2_PATH, TEXTURE_MARIO_BIG_CLIMB_2, renderer);
    loadTexture(TEXTURE_MARIO_FIRE_CLIMB_1_PATH, TEXTURE_MARIO_FIRE_CLIMB_1, renderer);
    loadTexture(TEXTURE_MARIO_FIRE_CLIMB_2_PATH, TEXTURE_MARIO_FIRE_CLIMB_2, renderer);
    loadTexture(TEXTURE_MARIO_LOGO_PATH, TEXTURE_MARIO_LOGO, renderer);
    loadTexture(TEXTURE_LEVEL_2_PATH, TEXTURE_LEVEL_2, renderer);
    loadTexture(TEXTURE_BRICK_3_PATH, TEXTURE_BRICK_3, renderer);
    loadTexture(TEXTURE_MUSHROOM_1UP_2_PATH, TEXTURE_MUSHROOM_1UP_2, renderer);
    loadTexture(TEXTURE_MOVING_PLATFORM_PATH, TEXTURE_MOVING_PLATFORM, renderer);
    loadTexture(TEXTURE_GOOMBAS_BLUE_DEAD_PATH, TEXTURE_GOOMBAS_BLUE_DEAD, renderer);
    loadTexture(TEXTURE_GOOMBAS_BLUE_MOVE_1_PATH, TEXTURE_GOOMBAS_BLUE_MOVE_1, renderer);
    loadTexture(TEXTURE_GOOMBAS_BLUE_MOVE_2_PATH, TEXTURE_GOOMBAS_BLUE_MOVE_2, renderer);
    loadTexture(TEXTURE_PIRANHA_PLANT_GREEN_1_PATH, TEXTURE_PIRANHA_PLANT_GREEN_1, renderer);
    loadTexture(TEXTURE_PIRANHA_PLANT_GREEN_2_PATH, TEXTURE_PIRANHA_PLANT_GREEN_2, renderer);
    loadTexture(TEXTURE_PIRANHA_PLANT_BLUE_1_PATH, TEXTURE_PIRANHA_PLANT_BLUE_1, renderer);
    loadTexture(TEXTURE_PIRANHA_PLANT_BLUE_2_PATH, TEXTURE_PIRANHA_PLANT_BLUE_2, renderer);
    loadTexture(TEXTURE_KOOPA2_WALK_1_PATH, TEXTURE_KOOPA2_WALK_1, renderer);
    loadTexture(TEXTURE_KOOPA2_WALK_2_PATH, TEXTURE_KOOPA2_WALK_2, renderer);
    loadTexture(TEXTURE_KOOPA2_JUMP_1_PATH, TEXTURE_KOOPA2_JUMP_1, renderer);
    loadTexture(TEXTURE_KOOPA2_JUMP_2_PATH, TEXTURE_KOOPA2_JUMP_2, renderer);
    loadTexture(TEXTURE_KOOPA2_SHELL_MODE_PATH, TEXTURE_KOOPA2_SHELL_MODE, renderer);
    loadTexture(TEXTURE_KOOPA3_WALK_1_PATH, TEXTURE_KOOPA3_WALK_1, renderer);
    loadTexture(TEXTURE_KOOPA3_WALK_2_PATH, TEXTURE_KOOPA3_WALK_2, renderer);
    loadTexture(TEXTURE_KOOPA3_JUMP_1_PATH, TEXTURE_KOOPA3_JUMP_1, renderer);
    loadTexture(TEXTURE_KOOPA3_JUMP_2_PATH, TEXTURE_KOOPA3_JUMP_2, renderer);
    loadTexture(TEXTURE_KOOPA3_SHELL_MODE_PATH, TEXTURE_KOOPA3_SHELL_MODE, renderer);
    loadTexture(TEXTURE_LEVEL1_2_UNDERGROUND_PATH, TEXTURE_LEVEL1_2_UNDERGROUND, renderer);
    loadTexture(TEXTURE_LEVEL1_3_PATH, TEXTURE_LEVEL1_3, renderer);
    loadTexture(TEXTURE_TREE_1_CORTEX_PATH, TEXTURE_TREE_1_CORTEX, renderer);
    loadTexture(TEXTURE_TREE_1_TOP_LEFT_PATH, TEXTURE_TREE_1_TOP_LEFT, renderer);
    loadTexture(TEXTURE_TREE_1_TOP_RIGHT_PATH, TEXTURE_TREE_1_TOP_RIGHT, renderer);
    loadTexture(TEXTURE_TREE_1_TOP_CENTER_PATH, TEXTURE_TREE_1_TOP_CENTER, renderer);
    loadTexture(TEXTURE_UNDERGROUND_END_UP_PATH, TEXTURE_UNDERGROUND_END_UP, renderer);
    loadTexture(TEXTURE_BRICK_CASTLE_LEVEL_PATH, TEXTURE_BRICK_CASTLE_LEVEL, renderer);
    loadTexture(TEXTURE_LEVEL1_4_PATH, TEXTURE_LEVEL1_4, renderer);
    loadTexture(TEXTURE_LAVA_PATH, TEXTURE_LAVA, renderer);
    loadTexture(TEXTURE_LAVA_TOP_PATH, TEXTURE_LAVA_TOP, renderer);
    loadTexture(TEXTURE_BROWSER_MOVE_1_PATH, TEXTURE_BROWSER_MOVE_1, renderer);
    loadTexture(TEXTURE_BROWSER_MOVE_2_PATH, TEXTURE_BROWSER_MOVE_2, renderer);
    loadTexture(TEXTURE_BROWSER_SHOT_MOVE_1_PATH, TEXTURE_BROWSER_SHOT_MOVE_1, renderer);
    loadTexture(TEXTURE_BROWSER_SHOT_MOVE_2_PATH, TEXTURE_BROWSER_SHOT_MOVE_2, renderer);
    loadTexture(TEXTURE_BROWSER_FIRE_SHOT_1_PATH, TEXTURE_BROWSER_FIRE_SHOT_1, renderer);
    loadTexture(TEXTURE_BROWSER_FIRE_SHOT_2_PATH, TEXTURE_BROWSER_FIRE_SHOT_2, renderer);
}

void TextureHolder::malloc()
{
    textures_ = new SDL_Texture*[texturesNo];
    for(int i=0; i<texturesNo; i++)
    {
        textures_[i] = nullptr;
    }
}

void TextureHolder::loadTexture(std::string filepath, int i, SDL_Renderer* renderer)
{
    SDL_Surface *surface = IMG_Load(filepath.c_str());
    if(surface == NULL)
    {
        std::cout << "Image load error: " << IMG_GetError() << std::endl;
        throw *(new std::exception);
    }
    SDL_SetColorKey(surface, SDL_TRUE, transparentColor_);
    textures_[i] = SDL_CreateTextureFromSurface(renderer, surface);

    if(textures_[i] == NULL)
    {
        std::cout << "Image convert error:  " << IMG_GetError() << std::endl;
        throw *(new std::exception);
    }

    SDL_FreeSurface(surface);
}

SDL_Texture* TextureHolder::getTexture(int TEXTURE_CONSTANT)
{
    return textures_[TEXTURE_CONSTANT];
}

void TextureHolder::freeMemory()
{
    for(int i=0; i<texturesNo; i++)
    {
        if(textures_[i] != nullptr)
        {
            SDL_DestroyTexture(textures_[i]);
            textures_[i] = nullptr;
        }
    }
    delete[] textures_;
    textures_ = nullptr;
}

void TextureHolder::setTransparentColor(Uint32 transparentColor)
{
    transparentColor_ = transparentColor;
}