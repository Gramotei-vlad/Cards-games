/*
 * DrawGame.h
 *
 *  Created on: 18 дек. 2018 г.
 *      Author: связной
 */

#ifndef DRAWGAME_H_
#define DRAWGAME_H_
#include "Game.h"

using namespace std;

class DrawGame {
public:
	DrawGame(const sf::Sprite& new_fon_game, const sf::Text& new_confirmation_text);
	void showBackground(sf::RenderWindow& window);
	void showDesk(sf::RenderWindow& window, const Game& Game1);
	void showPlayerCards(sf::RenderWindow& window, const Player& Player1);
	void showRivalCards(sf::RenderWindow& window, const Rival& Rival1);
	void showConfirmation(sf::RenderWindow& window);
	void clear(sf::RenderWindow& window);
	void display(sf::RenderWindow& window);
private:
	sf::Sprite fon_game;
	sf::Text confirmation_text;
};




#endif /* DRAWGAME_H_ */
