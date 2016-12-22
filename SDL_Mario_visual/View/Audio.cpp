
#include "Audio.h"
#include "../ApplicationError.h"

Audio::Audio()
{
	bgMusic_ = nullptr;
	chunkQuantity_ = CHUNKSOUND_NO;
	for(int i=0; i<chunkQuantity_; i++)
	{
		chunkSounds_[i] = nullptr;
	}
}

void Audio::loadMusic(std::string musicFilePath)
{
	if(bgMusic_ != nullptr)
		Mix_FreeMusic(bgMusic_);

	bgMusic_ = Mix_LoadMUS(musicFilePath.c_str());
	if(bgMusic_ == NULL)
	{
		printf("Music load error: %s\n", Mix_GetError());
		throw *(new ApplicationError);
	}
}

void Audio::loadChunkSounds()
{
	Mix_AllocateChannels(CHUNKSOUND_NO);
	loadChunkSound(CHUNKSOUND_TEST_PATH,            CHUNKSOUND_TEST);
	loadChunkSound(CHUNKSOUND_MARIO_OVERWORLD_PATH, CHUNKSOUND_MARIO_OVERWORLD);
	loadChunkSound(CHUNKSOUND_MARIO_SMALLJUMP_PATH, CHUNKSOUND_MARIO_SMALLJUMP);
	loadChunkSound(CHUNKSOUND_MARIO_BIGJUMP_PATH,   CHUNKSOUND_MARIO_BIGJUMP);
	loadChunkSound(CHUNKSOUND_STOMP_PATH,           CHUNKSOUND_STOMP);
	loadChunkSound(CHUNKSOUND_BLOCK_HIT_PATH,       CHUNKSOUND_BLOCK_HIT);
	loadChunkSound(CHUNKSOUND_BLOCK_BREAK_PATH,     CHUNKSOUND_BLOCK_BREAK);
	loadChunkSound(CHUNKSOUND_MARIO_GROW_PATH,      CHUNKSOUND_MARIO_GROW);
	loadChunkSound(CHUNKSOUND_MARIO_DEATH_PATH,     CHUNKSOUND_MARIO_DEATH);
	loadChunkSound(CHUNKSOUND_MARIO_SHRINK_PATH,    CHUNKSOUND_MARIO_SHRINK);
	loadChunkSound(CHUNKSOUND_COIN_TAKEN_PATH,      CHUNKSOUND_COIN_TAKEN);
	loadChunkSound(CHUNKSOUND_MUSHROOM_APPEAR_PATH, CHUNKSOUND_MUSHROOM_APPEAR);
	loadChunkSound(CHUNKSOUND_LIVES_UP_PATH,        CHUNKSOUND_LIVES_UP);
	loadChunkSound(CHUNKSOUND_FIREBALL_PATH,        CHUNKSOUND_FIREBALL);
	loadChunkSound(CHUNKSOUND_MOB_HIT_PATH,         CHUNKSOUND_MOB_HIT);
	loadChunkSound(CHUNKSOUND_INVINCIBILITY_PATH,   CHUNKSOUND_INVINCIBILITY);
	loadChunkSound(CHUNKSOUND_INVINCIBILITY_FAST_PATH, CHUNKSOUND_INVINCIBILITY_FAST);
	loadChunkSound(CHUNKSOUND_UNDERGROUND_PATH,     CHUNKSOUND_UNDERGROUND);
	loadChunkSound(CHUNKSOUND_PIPE_ENTER_PATH,      CHUNKSOUND_PIPE_ENTER);
	loadChunkSound(CHUNKSOUND_LEVEL_END_PATH,       CHUNKSOUND_LEVEL_END);
	loadChunkSound(CHUNKSOUND_TIME_TO_SCORE_PATH, CHUNKSOUND_TIME_TO_SCORE);
	loadChunkSound(CHUNKSOUND_CASTLE_PATH, CHUNKSOUND_CASTLE);
	loadChunkSound(CHUNKSOUND_BROWSER_FIRE_PATH, CHUNKSOUND_BROWSER_FIRE);
}

void Audio::playMusic()
{
	Mix_PlayMusic(bgMusic_, INFINITE_LOOP);
}

void Audio::setMusicVolume(int volume)
{
	Mix_VolumeMusic((double)(volume*1.28f));
}

int Audio::getMusicVolume()
{
	return Mix_VolumeMusic(VOLUME_GET);
}

void Audio::setChunkVolume(int CHUNKSOUND_CONSTANT, int volume)
{
	Mix_VolumeChunk(chunkSounds_[CHUNKSOUND_CONSTANT], volume*1.28f);
}

void Audio::setEfxVolume(int volume)
{
	for(int i=0; i<chunkQuantity_; i++)
	{
		if(chunkSounds_[i] != nullptr)
		{
			setChunkVolume(i, volume);
		}
	}
}

void Audio::playChunkSound(int CHUNKSOUND_CONSTANT, int loops)
{
	Mix_PlayChannel(CHUNKSOUND_CONSTANT, chunkSounds_[CHUNKSOUND_CONSTANT], loops);
}

void Audio::loadChunkSound(std::string chunkFilePath, int i)
{
	chunkSounds_[i] = Mix_LoadWAV(chunkFilePath.c_str());
	if(chunkSounds_[i] == NULL)
	{
		printf("Sound chunk load error: %s\n", Mix_GetError());
		throw *(new ApplicationError);
	}
}

void Audio::haltChunkSound(int CHUNKSOUND_CONSTANT)
{
	Mix_HaltChannel(CHUNKSOUND_CONSTANT);
}

void Audio::haltAllChunkSounds()
{
	Mix_HaltChannel(-1);
}

void Audio::freeMemory()
{
	for(int i=0; i<chunkQuantity_; i++)
	{
		if(chunkSounds_[i] != nullptr)
		{
			Mix_FreeChunk(chunkSounds_[i]);
			chunkSounds_[i] = nullptr;
		}
	}

	if(bgMusic_ != nullptr)
	{
		Mix_FreeMusic(bgMusic_);
		bgMusic_ = nullptr;
	}
	Mix_AllocateChannels(0);
}

bool Audio::isChunkSoundPlaying(int CHUNKSOUND_CONSTANT)
{
	return Mix_Playing(CHUNKSOUND_CONSTANT);
}
