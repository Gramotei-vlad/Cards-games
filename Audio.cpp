/*
 * Audio.cpp
 *
 *  Created on: 21 июля 2018 г.
 *      Author: связной
 */
#include "Audio.h"

sf::SoundBuffer buffer;

sf::Sound load_song() {
	sf::Sound click;
	buffer.loadFromFile("src\\Music\\click3.wav");
	click.setBuffer(buffer);
	return click;
}
