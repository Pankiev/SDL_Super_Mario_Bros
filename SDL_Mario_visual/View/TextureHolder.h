#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#define TEXTURE_MARIO_SMALL_MARIOSTAND_PATH     "images/mario/mario.bmp"
#define TEXTURE_MARIO_GROUND_RED_1_PATH         "images/mario1/gnd_red_1.bmp"
#define TEXTURE_MARIO_GROUND_RED_2_PATH         "images/mario1/gnd_red2.bmp"
#define TEXTURE_MARIO_LEVEL_1_PATH              "images/mario1/11.bmp"
#define TEXTURE_MARIO_SMALL_MARIOMOVE_1_PATH    "images/mario/mario_move0.bmp"
#define TEXTURE_MARIO_SMALL_MARIOMOVE_2_PATH    "images/mario/mario_move1.bmp"
#define TEXTURE_MARIO_SMALL_MARIOMOVE_3_PATH    "images/mario/mario_move2.bmp"
#define TEXTURE_MARIO_BIG_MARIOMOVE_1_PATH      "images/mario/mario1_move0.bmp"
#define TEXTURE_MARIO_BIG_MARIOMOVE_2_PATH      "images/mario/mario1_move1.bmp"
#define TEXTURE_MARIO_BIG_MARIOMOVE_3_PATH      "images/mario/mario1_move2.bmp"
#define TEXTURE_MARIO_BIG_MARIOSTAND_PATH       "images/mario/mario1.bmp"
#define TEXTURE_MARIO_BIG_MARIOJUMP_PATH        "images/mario/mario1_jump.bmp"
#define TEXTURE_MARIO_SMALL_MARIODIE_PATH       "images/mario/mario_death.bmp"
#define TEXTURE_MARIO_BRICK_RED_PATH            "images/mario1/brickred.bmp"
#define TEXTURE_MARIO_SMALL_JUMP_PATH           "images/mario/mario_jump.bmp"
#define TEXTURE_GOOMBAS1MOVE_1_PATH             "images/mario1/goombas_0.bmp"
#define TEXTURE_GOOMBAS1MOVE_2_PATH             "images/mario1/goombas_1.bmp"
#define TEXTURE_GOOMBAS1DEAD_PATH               "images/mario1/goombas_ded.bmp"
#define TEXTURE_DEBRIS1_PATH                    "images/mario1/block_debris0.bmp"
#define TEXTURE_DEBRIS2_PATH                    "images/mario1/block_debris1.bmp"
#define TEXTURE_DEBRIS3_PATH                    "images/mario1/block_debris2.bmp"
#define TEXTURE_MUSHROOM_PATH                   "images/mario1/mushroom.bmp"
#define TEXTURE_MARIO_GROW_PATH                 "images/mario/mario_lvlup.bmp"
#define TEXTURE_BUSH_CENTER_1_PATH              "images/mario1/bush_center_0.bmp"
#define TEXTURE_BUSH_CENTER_2_PATH              "images/mario1/bush_center_1.bmp"
#define TEXTURE_BUSH_LEFT_PATH                  "images/mario1/bush_left.bmp"
#define TEXTURE_BUSH_RIGHT_PATH                 "images/mario1/bush_right.bmp"
#define TEXTURE_BUSH_TOP_PATH                   "images/mario1/bush_top.bmp"
#define TEXTURE_COULD_CENTER_BOTTOM_PATH        "images/mario1/cloud_center_bot.bmp"
#define TEXTURE_COULD_CENTER_TOP_PATH           "images/mario1/cloud_center_top.bmp"
#define TEXTURE_COULD_LEFT_BOTTOM_PATH          "images/mario1/cloud_left_bot.bmp"
#define TEXTURE_COULD_LEFT_TOP_PATH             "images/mario1/cloud_left_top.bmp"
#define TEXTURE_COULD_RIGHT_BOTTOM_PATH         "images/mario1/cloud_right_bot.bmp"
#define TEXTURE_COULD_RIGHT_TOP_PATH            "images/mario1/cloud_right_top.bmp"
#define TEXTURE_GRASS_LEFT_PATH                 "images/mario1/grass_left.bmp"
#define TEXTURE_GRASS_CENTER_PATH               "images/mario1/grass_center.bmp"
#define TEXTURE_GRASS_RIGHT_PATH                "images/mario1/grass_right.bmp"
#define TEXTURE_PIPE_LEFT_TOP_PATH              "images/mario1/pipe_left_top.bmp"
#define TEXTURE_PIPE_RIGHT_TOP_PATH             "images/mario1/pipe_right_top.bmp"
#define TEXTURE_PIPE_LEFT_BOTTOM_PATH           "images/mario1/pipe_left_bot.bmp"
#define TEXTURE_PIPE_RIGHT_BOTTOM_PATH          "images/mario1/pipe_right_bot.bmp"
#define TEXTURE_CASTLE_BRICK_PATH               "images/mario1/castle0_brick.bmp"
#define TEXTURE_CASTLE_CENTER_CENTER_PATH       "images/mario1/castle0_center_center.bmp"
#define TEXTURE_CASTLE_CENTER_CENTER_TOP_PATH   "images/mario1/castle0_center_center_top.bmp"
#define TEXTURE_CASTLE_CENTER_LEFT_PATH         "images/mario1/castle0_center_left.bmp"
#define TEXTURE_CASTLE_CENTER_RIGHT_PATH        "images/mario1/castle0_center_right.bmp"
#define TEXTURE_CASTLE_TOP_1_PATH               "images/mario1/castle0_top0.bmp"
#define TEXTURE_CASTLE_TOP_2_PATH               "images/mario1/castle0_top1.bmp"
#define TEXTURE_END_GLOBE_PATH                  "images/mario1/end0_dot.bmp"
#define TEXTURE_END_PIPE_PATH                   "images/mario1/end0_l.bmp"
#define TEXTURE_END_FLAG_PATH                   "images/mario1/end0_flag.bmp"
#define TEXTURE_UNKNOWN_BOX1_1_PATH             "images/mario1/blockq_0.bmp"
#define TEXTURE_UNKNOWN_BOX1_2_PATH             "images/mario1/blockq_1.bmp"
#define TEXTURE_UNKNOWN_BOX1_3_PATH             "images/mario1/blockq_2.bmp"
#define TEXTURE_EMPTY_BOX_PATH                  "images/mario1/blockq_used.bmp"
#define TEXTURE_COIN_BOX_1_PATH                 "images/mario1/coin_an0.bmp"
#define TEXTURE_COIN_BOX_2_PATH                 "images/mario1/coin_an1.bmp"
#define TEXTURE_COIN_BOX_3_PATH                 "images/mario1/coin_an2.bmp"
#define TEXTURE_COIN_BOX_4_PATH                 "images/mario1/coin_an3.bmp"
#define TEXTURE_COIN_INTERFACE_1_PATH           "images/mario1/coin_0.bmp"
#define TEXTURE_COIN_INTERFACE_2_PATH           "images/mario1/coin_1.bmp"
#define TEXTURE_COIN_INTERFACE_3_PATH           "images/mario1/coin_2.bmp"
#define TEXTURE_FLOWER_1_PATH                   "images/mario1/flower0.bmp"
#define TEXTURE_FLOWER_2_PATH                   "images/mario1/flower1.bmp"
#define TEXTURE_FLOWER_3_PATH                   "images/mario1/flower2.bmp"
#define TEXTURE_FLOWER_4_PATH                   "images/mario1/flower3.bmp"
#define TEXTURE_STAR_1_PATH                     "images/mario1/star_0.bmp"
#define TEXTURE_STAR_2_PATH                     "images/mario1/star_1.bmp"
#define TEXTURE_STAR_3_PATH                     "images/mario1/star_2.bmp"
#define TEXTURE_STAR_4_PATH                     "images/mario1/star_3.bmp"
#define TEXTURE_FIREBALL_1_PATH                 "images/mario1/fireball_0.bmp"
#define TEXTURE_FIREBALL_2_PATH                 "images/mario1/fireball_1.bmp"
#define TEXTURE_FIREBALL_3_PATH                 "images/mario1/fireball_2.bmp"
#define TEXTURE_FIREBALL_4_PATH                 "images/mario1/fireball_3.bmp"
#define TEXTURE_FIREWORK_1_PATH                 "images/mario1/firework0.bmp"
#define TEXTURE_FIREWORK_2_PATH                 "images/mario1/firework1.bmp"
#define TEXTURE_FIREWORK_3_PATH                 "images/mario1/firework2.bmp"
#define TEXTURE_KOOPA1_WALK_1_PATH              "images/mario1/koopa_0.bmp"
#define TEXTURE_KOOPA1_WALK_2_PATH              "images/mario1/koopa_1.bmp"
#define TEXTURE_KOOPA1_JUMP_1_PATH              "images/mario1/koopa_2.bmp"
#define TEXTURE_KOOPA1_JUMP_2_PATH              "images/mario1/koopa_3.bmp"
#define TEXTURE_KOOPA1_SHELL_MODE_PATH          "images/mario1/koopa_ded.bmp"
#define TEXTURE_MARIO_INVINCIBILITY_STAND_PATH  "images/mario/mario2s.bmp"
#define TEXTURE_MARIO_FIRE_STAND_PATH           "images/mario/mario2.bmp"
#define TEXTURE_MARIO_FIRE_JUMP_PATH            "images/mario/mario2_jump.bmp"
#define TEXTURE_MARIO_FIRE_MOVE_1_PATH          "images/mario/mario2_move0.bmp"
#define TEXTURE_MARIO_FIRE_MOVE_2_PATH          "images/mario/mario2_move1.bmp"
#define TEXTURE_MARIO_FIRE_MOVE_3_PATH          "images/mario/mario2_move2.bmp"
#define TEXTURE_MUSHROOM_1UP_PATH               "images/mario1/mushroom_1up.bmp"
#define TEXTURE_MARIO_INVINCIBILITY_MOVE_1_PATH "images/mario/mario2s_move0.bmp"
#define TEXTURE_MARIO_INVINCIBILITY_MOVE_2_PATH "images/mario/mario2s_move1.bmp"
#define TEXTURE_MARIO_INVINCIBILITY_MOVE_3_PATH "images/mario/mario2s_move2.bmp"
#define TEXTURE_MARIO_INVINCIBILITY_JUMP_PATH   "images/mario/mario2s_jump.bmp"
#define TEXTURE_MARIO_SMALL_INVINCIBILITY_STAND_1_PATH "images/mario/mario_s0.bmp"
#define TEXTURE_MARIO_SMALL_INVINCIBILITY_STAND_2_PATH "images/mario/mario_s1.bmp"
#define TEXTURE_MARIO_SMALL_INVINCIBILITY_JUMP_1_PATH "images/mario/mario_s0_jump.bmp"
#define TEXTURE_MARIO_SMALL_INVINCIBILITY_JUMP_2_PATH "images/mario/mario_s1_jump.bmp"
#define TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_1_PATH "images/mario/mario_s0_move0.bmp"
#define TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_2_PATH "images/mario/mario_s1_move0.bmp"
#define TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_3_PATH "images/mario/mario_s0_move1.bmp"
#define TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_4_PATH "images/mario/mario_s1_move1.bmp"
#define TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_5_PATH "images/mario/mario_s0_move2.bmp"
#define TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_6_PATH "images/mario/mario_s1_move2.bmp"
#define TEXTURE_COIN_1_PATH                     "images/mario1/coin_use00.bmp"
#define TEXTURE_COIN_2_PATH                     "images/mario1/coin_use01.bmp"
#define TEXTURE_COIN_3_PATH                     "images/mario1/coin_use02.bmp"
#define TEXTURE_LEVEL1_UNDERGROUND_PATH         "images/mario1/level1_undergroung.jpg"
#define TEXTURE_BRICK_2_PATH                    "images/mario1/brick1.bmp"
#define TEXTURE_GROUND_2_PATH                   "images/mario1/gnd1.bmp"
#define TEXTURE_PIPE_HORIZONTAL_BOT_CENTER_PATH "images/mario1/pipe_hor_bot_center.bmp"
#define TEXTURE_PIPE_HORIZONTAL_TOP_CENTER_PATH "images/mario1/pipe_hor_top_center.bmp"
#define TEXTURE_PIPE_HORIZONTAL_BOT_LEFT_PATH   "images/mario1/pipe_hor_bot_left.bmp"
#define TEXTURE_PIPE_HORIZONTAL_TOP_LEFT_PATH   "images/mario1/pipe_hor_top_left.bmp"
#define TEXTURE_PIPE_HORIZONTAL_BOT_RIGHT_PATH  "images/mario1/pipe_hor_bot_right.bmp"
#define TEXTURE_PIPE_HORIZONTAL_TOP_RIGHT_PATH  "images/mario1/pipe_hor_top_right.bmp"
#define TEXTURE_MARIO_BIG_SQUAT_PATH            "images/mario/mario1_squat.bmp"
#define TEXTURE_MARIO_FIRE_SQUAT_PATH           "images/mario/mario2_squat.bmp"
#define TEXTURE_MARIO_SMALL_CLIMB_1_PATH        "images/mario/mario_end.bmp"
#define TEXTURE_MARIO_SMALL_CLIMB_2_PATH        "images/mario/mario_end1.bmp"
#define TEXTURE_MARIO_BIG_CLIMB_1_PATH          "images/mario/mario1_end.bmp"
#define TEXTURE_MARIO_BIG_CLIMB_2_PATH          "images/mario/mario1_end1.bmp"
#define TEXTURE_MARIO_FIRE_CLIMB_1_PATH         "images/mario/mario2_end.bmp"
#define TEXTURE_MARIO_FIRE_CLIMB_2_PATH         "images/mario/mario2_end1.bmp"
#define TEXTURE_MARIO_LOGO_PATH                 "images/mario1/super_mario_bros.bmp"
#define TEXTURE_LEVEL_2_PATH                    "images/mario1/12.bmp"
#define TEXTURE_BRICK_3_PATH                    "images/mario1/gnd1_2.bmp"
#define TEXTURE_MUSHROOM_1UP_2_PATH             "images/mario1/mushroom1_1up.bmp"
#define TEXTURE_MOVING_PLATFORM_PATH            "images/mario1/platform.bmp"
#define TEXTURE_GOOMBAS_BLUE_DEAD_PATH          "images/mario1/goombas1_ded.bmp"
#define TEXTURE_GOOMBAS_BLUE_MOVE_1_PATH        "images/mario1/goombas1_0.bmp"
#define TEXTURE_GOOMBAS_BLUE_MOVE_2_PATH        "images/mario1/goombas1_1.bmp"
#define TEXTURE_PIRANHA_PLANT_GREEN_1_PATH      "images/mario1/plant_0.bmp"
#define TEXTURE_PIRANHA_PLANT_GREEN_2_PATH      "images/mario1/plant_1.bmp"
#define TEXTURE_PIRANHA_PLANT_BLUE_1_PATH       "images/mario1/plant1_0.bmp"
#define TEXTURE_PIRANHA_PLANT_BLUE_2_PATH       "images/mario1/plant1_1.bmp"
#define TEXTURE_KOOPA2_WALK_1_PATH              "images/mario1/koopa1_0.bmp"
#define TEXTURE_KOOPA2_WALK_2_PATH              "images/mario1/koopa1_1.bmp"
#define TEXTURE_KOOPA2_JUMP_1_PATH              "images/mario1/koopa1_2.bmp"
#define TEXTURE_KOOPA2_JUMP_2_PATH              "images/mario1/koopa1_3.bmp"
#define TEXTURE_KOOPA2_SHELL_MODE_PATH          "images/mario1/koopa1_ded.bmp"
#define TEXTURE_KOOPA3_WALK_1_PATH              "images/mario1/koopa2_0.bmp"
#define TEXTURE_KOOPA3_WALK_2_PATH              "images/mario1/koopa2_1.bmp"
#define TEXTURE_KOOPA3_JUMP_1_PATH              "images/mario1/koopa2_2.bmp"
#define TEXTURE_KOOPA3_JUMP_2_PATH              "images/mario1/koopa2_3.bmp"
#define TEXTURE_KOOPA3_SHELL_MODE_PATH          "images/mario1/koopa2_ded.bmp"
#define TEXTURE_LEVEL1_2_UNDERGROUND_PATH       "images/mario1/123.bmp"
#define TEXTURE_LEVEL1_3_PATH                   "images/mario1/13.bmp"
#define TEXTURE_TREE_1_CORTEX_PATH              "images/mario1/t_bot.bmp"
#define TEXTURE_TREE_1_TOP_LEFT_PATH            "images/mario1/t_left.bmp"
#define TEXTURE_TREE_1_TOP_RIGHT_PATH           "images/mario1/t_right.bmp"
#define TEXTURE_TREE_1_TOP_CENTER_PATH          "images/mario1/t_center.bmp"
#define TEXTURE_UNDERGROUND_END_UP_PATH         "images/mario1/UndergroundUpperGround.bmp"
#define TEXTURE_BRICK_CASTLE_LEVEL_PATH         "images/mario1/gnd_4.bmp"
#define TEXTURE_LEVEL1_4_PATH                   "images/mario1/14.bmp"
#define TEXTURE_LAVA_PATH                       "images/mario1/lava_0.bmp"
#define TEXTURE_LAVA_TOP_PATH                   "images/mario1/lava_1.bmp"
#define TEXTURE_BROWSER_MOVE_1_PATH             "images/mario1/bowser2.bmp"
#define TEXTURE_BROWSER_MOVE_2_PATH             "images/mario1/bowser3.bmp"
#define TEXTURE_BROWSER_SHOT_MOVE_1_PATH        "images/mario1/bowser0.bmp"
#define TEXTURE_BROWSER_SHOT_MOVE_2_PATH        "images/mario1/bowser1.bmp"
#define TEXTURE_BROWSER_FIRE_SHOT_1_PATH        "images/mario1/fire_0.bmp"
#define TEXTURE_BROWSER_FIRE_SHOT_2_PATH        "images/mario1/fire_1.bmp"

enum
{
    TEXTURE_MARIO_SMALL_MARIOSTAND = 0,
    TEXTURE_MARIO_GROUND_RED_1 = 1,
    TEXTURE_MARIO_LEVEL_1 = 2,
    TEXTURE_MARIO_SMALL_MARIOMOVE_1 = 3,
    TEXTURE_MARIO_SMALL_MARIOMOVE_2 = 4,
    TEXTURE_MARIO_SMALL_MARIOMOVE_3 = 5,
    TEXTURE_MARIO_SMALL_MARIODIE = 6,
    TEXTURE_MARIO_BRICK_RED = 7,
    TEXTURE_MARIO_SMALL_JUMP = 8,
    TEXTURE_MARIO_GROUND_RED_2 = 9,
    TEXTURE_GOOMBAS1MOVE_1 = 10,
    TEXTURE_GOOMBAS1MOVE_2 = 11,
    TEXTURE_GOOMBAS1DEAD = 12,
    TEXTURE_DEBRIS1 = 13,
    TEXTURE_DEBRIS2 = 14,
    TEXTURE_DEBRIS3 = 15,
    TEXTURE_MUSHROOM = 16,
    TEXTURE_MARIO_BIG_MARIOMOVE_1 = 17,
    TEXTURE_MARIO_BIG_MARIOMOVE_2 = 18,
    TEXTURE_MARIO_BIG_MARIOMOVE_3 = 19,
    TEXTURE_MARIO_BIG_JUMP = 20,
    TEXTURE_MARIO_BIG_STAND = 21,
    TEXTURE_MARIO_GROW = 22,
    TEXTURE_BUSH_CENTER_1 = 23,
    TEXTURE_BUSH_CENTER_2 = 24,
    TEXTURE_BUSH_LEFT = 25,
    TEXTURE_BUSH_RIGHT = 26,
    TEXTURE_BUSH_TOP = 27,
    TEXTURE_COULD_CENTER_BOTTOM = 28,
    TEXTURE_COULD_CENTER_TOP = 29,
    TEXTURE_COULD_LEFT_BOTTOM = 30,
    TEXTURE_COULD_LEFT_TOP = 31,
    TEXTURE_COULD_RIGHT_BOTTOM = 32,
    TEXTURE_COULD_RIGHT_TOP = 33,
    TEXTURE_GRASS_LEFT = 34,
    TEXTURE_GRASS_CENTER = 35,
    TEXTURE_GRASS_RIGHT = 36,
    TEXTURE_PIPE_LEFT_TOP = 37,
    TEXTURE_PIPE_RIGHT_TOP = 38,
    TEXTURE_PIPE_LEFT_BOTTOM = 39,
    TEXTURE_PIPE_RIGHT_BOTTOM = 40,
    TEXTURE_CASTLE_BRICK = 41,
    TEXTURE_CASTLE_CENTER_CENTER = 42,
    TEXTURE_CASTLE_CENTER_CENTER_TOP = 43,
    TEXTURE_CASTLE_CENTER_LEFT = 44,
    TEXTURE_CASTLE_CENTER_RIGHT = 45,
    TEXTURE_CASTLE_TOP_1 = 46,
    TEXTURE_CASTLE_TOP_2 = 47,
    TEXTURE_END_PIPE = 48,
    TEXTURE_END_FLAG = 49,
    TEXTURE_END_GLOBE = 50,
    TEXTURE_UNKNOWN_BOX1_1 = 51,
    TEXTURE_UNKNOWN_BOX1_2 = 52,
    TEXTURE_UNKNOWN_BOX1_3 = 53,
    TEXTURE_EMPTY_BOX = 54,
    TEXTURE_COIN_BOX_1 = 55,
    TEXTURE_COIN_BOX_2 = 56,
    TEXTURE_COIN_BOX_3 = 57,
    TEXTURE_COIN_BOX_4 = 58,
    TEXTURE_COIN_INTERFACE_1 = 59,
    TEXTURE_COIN_INTERFACE_2 = 60,
    TEXTURE_COIN_INTERFACE_3 = 61,
    TEXTURE_FLOWER_1 = 62,
    TEXTURE_FLOWER_2 = 63,
    TEXTURE_FLOWER_3 = 64,
    TEXTURE_FLOWER_4 = 65,
    TEXTURE_STAR_1 = 66,
    TEXTURE_STAR_2 = 67,
    TEXTURE_STAR_3 = 68,
    TEXTURE_STAR_4 = 69,
    TEXTURE_FIREBALL_1 = 70,
    TEXTURE_FIREBALL_2 = 71,
    TEXTURE_FIREBALL_3 = 72,
    TEXTURE_FIREBALL_4 = 73,
    TEXTURE_FIREWORK_1 = 74,
    TEXTURE_FIREWORK_2 = 75,
    TEXTURE_FIREWORK_3 = 76,
    TEXTURE_KOOPA1_WALK_1 = 77,
    TEXTURE_KOOPA1_WALK_2 = 78,
    TEXTURE_KOOPA1_JUMP_1 = 79,
    TEXTURE_KOOPA1_JUMP_2 = 80,
    TEXTURE_KOOPA1_SHELL_MODE = 81,
    TEXTURE_MARIO_FIRE_STAND = 82,
    TEXTURE_MARIO_FIRE_JUMP = 83,
    TEXTURE_MARIO_FIRE_MOVE_1 = 84,
    TEXTURE_MARIO_FIRE_MOVE_2 = 85,
    TEXTURE_MARIO_FIRE_MOVE_3 = 86,
    TEXTURE_MUSHROOM_1UP = 87,
    TEXTURE_MARIO_INVINCIBILITY_STAND = 88,
    TEXTURE_MARIO_INVINCIBILITY_MOVE_1 = 89,
    TEXTURE_MARIO_INVINCIBILITY_MOVE_2 = 90,
    TEXTURE_MARIO_INVINCIBILITY_MOVE_3 = 91,
    TEXTURE_MARIO_INVINCIBILITY_JUMP = 92,
    TEXTURE_MARIO_SMALL_INVINCIBILITY_STAND_1 = 93,
    TEXTURE_MARIO_SMALL_INVINCIBILITY_STAND_2 = 94,
    TEXTURE_MARIO_SMALL_INVINCIBILITY_JUMP_1 = 95,
    TEXTURE_MARIO_SMALL_INVINCIBILITY_JUMP_2 = 96,
    TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_1 = 97,
    TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_2 = 98,
    TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_3 = 99,
    TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_4 = 100,
    TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_5 = 101,
    TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_6 = 102,
    TEXTURE_COIN_1 = 103,
    TEXTURE_COIN_2 = 104,
    TEXTURE_COIN_3 = 105,
    TEXTURE_LEVEL1_UNDERGROUND = 106,
    TEXTURE_BRICK_2 = 107,
    TEXTURE_GROUND_2 = 108,
    TEXTURE_PIPE_HORIZONTAL_BOT_CENTER = 109,
    TEXTURE_PIPE_HORIZONTAL_TOP_CENTER = 110,
    TEXTURE_PIPE_HORIZONTAL_BOT_LEFT = 111,
    TEXTURE_PIPE_HORIZONTAL_TOP_LEFT = 112,
    TEXTURE_PIPE_HORIZONTAL_BOT_RIGHT = 113,
    TEXTURE_PIPE_HORIZONTAL_TOP_RIGHT = 114,
    TEXTURE_MARIO_BIG_SQUAT = 115,
    TEXTURE_MARIO_FIRE_SQUAT = 116,
    TEXTURE_MARIO_SMALL_CLIMB_1 = 117,
    TEXTURE_MARIO_SMALL_CLIMB_2 = 118,
    TEXTURE_MARIO_BIG_CLIMB_1 = 119,
    TEXTURE_MARIO_BIG_CLIMB_2 = 120,
    TEXTURE_MARIO_FIRE_CLIMB_1 = 121,
    TEXTURE_MARIO_FIRE_CLIMB_2 = 122,
    TEXTURE_MARIO_LOGO = 123,
    TEXTURE_LEVEL_2 = 124,
    TEXTURE_BRICK_3 = 125,
    TEXTURE_MUSHROOM_1UP_2 = 126,
    TEXTURE_MOVING_PLATFORM = 127,
    TEXTURE_GOOMBAS_BLUE_MOVE_1 = 128,
    TEXTURE_GOOMBAS_BLUE_MOVE_2 = 129,
    TEXTURE_GOOMBAS_BLUE_DEAD = 130,
    TEXTURE_PIRANHA_PLANT_GREEN_1 = 131,
    TEXTURE_PIRANHA_PLANT_GREEN_2 = 132,
    TEXTURE_PIRANHA_PLANT_BLUE_1 = 133,
    TEXTURE_PIRANHA_PLANT_BLUE_2 = 134,
    TEXTURE_KOOPA2_WALK_1 = 135,
    TEXTURE_KOOPA2_WALK_2 = 136,
    TEXTURE_KOOPA2_JUMP_1 = 137,
    TEXTURE_KOOPA2_JUMP_2 = 138,
    TEXTURE_KOOPA2_SHELL_MODE = 139,
    TEXTURE_KOOPA3_WALK_1 = 140,
    TEXTURE_KOOPA3_WALK_2 = 141,
    TEXTURE_KOOPA3_JUMP_1 = 142,
    TEXTURE_KOOPA3_JUMP_2 = 143,
    TEXTURE_KOOPA3_SHELL_MODE = 144,
    TEXTURE_LEVEL1_2_UNDERGROUND = 145,
    TEXTURE_LEVEL1_3 = 146,
    TEXTURE_TREE_1_CORTEX = 147,
    TEXTURE_TREE_1_TOP_LEFT = 148,
    TEXTURE_TREE_1_TOP_RIGHT = 149,
    TEXTURE_TREE_1_TOP_CENTER = 150,
    TEXTURE_UNDERGROUND_END_UP = 151,
    TEXTURE_BRICK_CASTLE_LEVEL = 152,
    TEXTURE_LEVEL1_4 = 153,
    TEXTURE_LAVA = 154,
    TEXTURE_LAVA_TOP = 155,
    TEXTURE_BROWSER_MOVE_1 = 156,
    TEXTURE_BROWSER_MOVE_2 = 157,
    TEXTURE_BROWSER_SHOT_MOVE_1 = 158,
    TEXTURE_BROWSER_SHOT_MOVE_2 = 159,
    TEXTURE_BROWSER_FIRE_SHOT_1 = 160,
    TEXTURE_BROWSER_FIRE_SHOT_2 = 161,
    TEXTURE_NO = 162
};

class TextureHolder
{
public:
    TextureHolder();

    void loadTextures(SDL_Renderer* renderer);
    void freeMemory();
    SDL_Texture* getTexture(int TEXTURE_CONSTANT);
    void setTransparentColor(Uint32 transparentColor_);

private:

    void malloc();
    void loadTexture(std::string filepath, int i, SDL_Renderer* renderer);

    SDL_Texture** textures_;
    int texturesNo;
    Uint32 transparentColor_;
};
