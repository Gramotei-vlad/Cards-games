/*
 * Audio.cpp
 *
 *  Created on: 21 июля 2018 г.
 *      Author: связной
 */
#include "Audio.h"

sf::SoundBuffer buffer; // Buffer for click
sf::SoundBuffer buffer2; // Buffer for a main music

sf::Sound load_click() {
	sf::Sound click;
	buffer.loadFromFile("src\\Music\\click3.wav");
	click.setBuffer(buffer);
	return click;
}

sf::Sound load_main_music() {
	sf::Sound main_music;
	buffer2.loadFromFile("src\\Music\\Skate Park Shuffle.ogg");
	main_music.setBuffer(buffer2);
	return main_music;
}
