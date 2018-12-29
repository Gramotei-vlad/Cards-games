/*
 * AudioGame.cpp
 *
 *  Created on: 20 дек. 2018 г.
 *      Author: связной
 */
#include "AudioGame.h"
#include "Audio.h"

AudioGame::AudioGame()
{
	main_music_ = load_main_music();
	click_ = load_click();
}

void AudioGame::playMainMusic()
{
	main_music_.play();
}

void AudioGame::playClick()
{
	click_.play();
}
