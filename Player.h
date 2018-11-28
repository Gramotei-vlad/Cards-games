/*
 * Player.h
 *
 *  Created on: 21 но€б. 2018 г.
 *      Author: св€зной
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <SFML/Graphics.hpp>

using namespace std;


class Player {
public:
	void getCard(sf::Sprite card);
	vector<sf::Sprite> showCard();
	void deleteCard(int pos);
private:
	vector<sf::Sprite> player_cards;
};





#endif /* PLAYER_H_ */
