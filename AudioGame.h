/*
 * AudioGame.h
 *
 *  Created on: 20 ���. 2018 �.
 *      Author: �������
 */

#ifndef AUDIOGAME_H_
#define AUDIOGAME_H_
#include "SFML/Audio.hpp"

using namespace std;


class AudioGame {
public:
	AudioGame();
	void playMainMusic();
	void playClick();
private:
	sf::Sound main_music_;
	sf::Sound click_;
};



#endif /* AUDIOGAME_H_ */
