#pragma once
#include <SDL_mixer.h>
#include <iostream>

#define FREE_CHANNEL -1
#define INFINITE_LOOP -1
#define VOLUME_GET -1
#define PLAY_ONCE 0

#define MUSIC_TEST_PATH                 "Sound/music/asd.mp3"
#define CHUNKSOUND_TEST_PATH            "Sound/tracks/slash.ogg"
#define CHUNKSOUND_MARIO_OVERWORLD_PATH "Sound/Mario/overworld.wav"
#define CHUNKSOUND_MARIO_SMALLJUMP_PATH "Sound/Mario/jump.wav"
#define CHUNKSOUND_MARIO_BIGJUMP_PATH   "Sound/Mario/jumpbig.wav"
#define CHUNKSOUND_STOMP_PATH           "Sound/Mario/stomp.wav"
#define CHUNKSOUND_BLOCK_HIT_PATH       "Sound/Mario/blockhit.wav"
#define CHUNKSOUND_BLOCK_BREAK_PATH     "Sound/Mario/blockbreak.wav"
#define CHUNKSOUND_MARIO_GROW_PATH      "Sound/Mario/mushroomeat.wav"
#define CHUNKSOUND_MARIO_DEATH_PATH     "Sound/Mario/death.wav"
#define CHUNKSOUND_MARIO_SHRINK_PATH    "Sound/Mario/shrink.wav"
#define CHUNKSOUND_COIN_TAKEN_PATH      "Sound/Mario/coin.wav"
#define CHUNKSOUND_MUSHROOM_APPEAR_PATH "Sound/Mario/mushroomappear.wav"
#define CHUNKSOUND_LIVES_UP_PATH        "Sound/Mario/oneup.wav"
#define CHUNKSOUND_FIREBALL_PATH        "Sound/Mario/fireball.wav"
#define CHUNKSOUND_MOB_HIT_PATH         "Sound/Mario/shot.wav"
#define CHUNKSOUND_INVINCIBILITY_PATH   "Sound/Mario/starmusic.wav"
#define CHUNKSOUND_INVINCIBILITY_FAST_PATH "Sound/Mario/starmusic-fast.wav"
#define CHUNKSOUND_UNDERGROUND_PATH     "Sound/Mario/underground.wav"
#define CHUNKSOUND_PIPE_ENTER_PATH      "Sound/Mario/pipe.wav"
#define CHUNKSOUND_LEVEL_END_PATH       "Sound/Mario/levelend.wav"
#define CHUNKSOUND_TIME_TO_SCORE_PATH   "Sound/Mario/scorering.wav"
#define CHUNKSOUND_CASTLE_PATH          "Sound/Mario/castle.wav"
#define CHUNKSOUND_BROWSER_FIRE_PATH    "Sound/Mario/fire.wav"

enum
{
    CHUNKSOUND_TEST = 0,
    CHUNKSOUND_MARIO_OVERWORLD = 1,
    CHUNKSOUND_MARIO_SMALLJUMP = 2,
    CHUNKSOUND_STOMP = 3,
    CHUNKSOUND_BLOCK_HIT = 4,
    CHUNKSOUND_BLOCK_BREAK = 5,
    CHUNKSOUND_MARIO_GROW = 6,
    CHUNKSOUND_MARIO_DEATH = 7,
    CHUNKSOUND_MARIO_BIGJUMP = 8,
    CHUNKSOUND_MARIO_SHRINK = 9,
    CHUNKSOUND_COIN_TAKEN = 10,
    CHUNKSOUND_MUSHROOM_APPEAR = 11,
    CHUNKSOUND_LIVES_UP = 12,
    CHUNKSOUND_FIREBALL = 13,
    CHUNKSOUND_MOB_HIT = 14,
    CHUNKSOUND_INVINCIBILITY = 15,
    CHUNKSOUND_INVINCIBILITY_FAST = 16,
    CHUNKSOUND_UNDERGROUND = 17,
    CHUNKSOUND_PIPE_ENTER = 18,
    CHUNKSOUND_LEVEL_END = 19,
    CHUNKSOUND_TIME_TO_SCORE = 20,
    CHUNKSOUND_CASTLE = 21,
    CHUNKSOUND_BROWSER_FIRE = 22,
    CHUNKSOUND_NO = 23
};

class Audio
{
public:

    Audio();

    void loadMusic(std::string musicPath);
    void loadChunkSounds();
    void playMusic();
    void setMusicVolume(int volume);
    int  getMusicVolume();
    void setChunkVolume(int CHUNSOUND_CONSTANT, int volume);
    void setEfxVolume(int volume);
    void playChunkSound(int CHUNKSOUND_CONSTANT, int loops);
    void haltChunkSound(int CHUNKSOUND_CONSTANT);
    void haltAllChunkSounds();
    void freeMemory();
    bool isChunkSoundPlaying(int CHUNKSOUND_CONSTANT);

private:

    void loadChunkSound(std::string chunkFilePath, int i);

    Mix_Music *bgMusic_;
    Mix_Chunk *chunkSounds_[CHUNKSOUND_NO];
    int chunkQuantity_;
};
