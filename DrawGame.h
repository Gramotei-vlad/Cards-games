/*
 * DrawGame.h
 *
 *  Created on: 18 дек. 2018 г.
 *      Author: связной
 */

#ifndef DRAWGAME_H_
#define DRAWGAME_H_
#include "Game.h"
#include "Graphics.h"

using namespace std;

class DrawGame {
public:
	DrawGame();
	void showMenu(sf::RenderWindow& window);
	void showBackground(sf::RenderWindow& window);
	void showDeck(sf::RenderWindow& window, const Game& Game1);
	void showDesk(sf::RenderWindow& window, const Game& Game1);
	void showPlayerCards(sf::RenderWindow& window, const Player& Player1);
	void showRivalCards(sf::RenderWindow& window, const Rival& Rival1);
	void showConfirmation(sf::RenderWindow& window);
	void showSettings(sf::RenderWindow& window);
	void showEndOfMatch(sf::RenderWindow& window, const string& name);
	void clear(sf::RenderWindow& window);
	void display(sf::RenderWindow& window);
	void close(sf::RenderWindow& window);
	vector<sf::Text> gameTexts() const;
private:
	sf::Sprite fon_game;
	sf::Text play_text;
	sf::Text quit_text;
	sf::Text controller_text;
	sf::Text setting_1;
	sf::Text setting_2;
	sf::Text win_game;
	sf::Text lose_game;
	sf::Text confirmation_text;
	sf::Text no_winners;
};




#endif /* DRAWGAME_H_ */
