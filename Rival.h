/*
 * Rival.h
 *
 *  Created on: 24 ����. 2018 �.
 *      Author: �������
 */

#ifndef RIVAL_H_
#define RIVAL_H_
#include "SFML/Graphics.hpp"

using namespace std;

class Rival {
public:
	void getCard(sf::Sprite card);
	vector<sf::Sprite> showCard();
private:
	vector<sf::Sprite> rival_cards;
};





#endif /* RIVAL_H_ */
