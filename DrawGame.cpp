/*
 * DrawGame.cpp
 *
 *  Created on: 18 дек. 2018 г.
 *      Author: связной
 */
#include "DrawGame.h"

DrawGame::DrawGame(const sf::Sprite& new_fon_game, const sf::Text& new_confirmation_text)
{
	fon_game = new_fon_game;
	confirmation_text = new_confirmation_text;
}

void DrawGame::showBackground(sf::RenderWindow& window)
{
	window.draw(fon_game);
}

void DrawGame::clear(sf::RenderWindow& window)
{
	window.clear();
}

void DrawGame::display(sf::RenderWindow& window)
{
	window.display();
}

void DrawGame::showDesk(sf::RenderWindow& window, const Game& Game1)
{
	vector<Card> actives_cards = Game1.showDesk();
	if (actives_cards.size() >= 1) {
		window.draw(actives_cards[0].showCard());
	}
	if (actives_cards.size() >= 2) {
		window.draw(actives_cards[1].showCard());
	}
	if (actives_cards.size() >= 3) {
		window.draw(actives_cards[2].showCard());
	}
	if (actives_cards.size() >= 4) {
		window.draw(actives_cards[3].showCard());
	}
	if (actives_cards.size() >= 5) {
		window.draw(actives_cards[4].showCard());
	}
	if (actives_cards.size() >= 6) {
		window.draw(actives_cards[5].showCard());
	}
}

void DrawGame::showPlayerCards(sf::RenderWindow& window, const Player& Player1)
{
	vector<sf::Sprite> player_cards = Player1.showCards();
	if (player_cards.size() >= 1) {
		window.draw(player_cards[0]);
	}
	if (player_cards.size() >= 2) {
		window.draw(player_cards[1]);
	}
	if (player_cards.size() >= 3) {
		window.draw(player_cards[2]);
	}
	if (player_cards.size() >= 4) {
		window.draw(player_cards[3]);
	}
	if (player_cards.size() >= 5) {
		window.draw(player_cards[4]);
	}
	if (player_cards.size() >= 6) {
		window.draw(player_cards[5]);
	}
	if (player_cards.size() >= 7) {
		window.draw(player_cards[6]);
	}
	if (player_cards.size() >= 8) {
		window.draw(player_cards[7]);
	}
	if (player_cards.size() >= 9) {
		window.draw(player_cards[8]);
	}
	if (player_cards.size() >= 10) {
		window.draw(player_cards[9]);
	}
}

void DrawGame::showRivalCards(sf::RenderWindow& window, const Rival& Rival1)
{
	vector<sf::Sprite> rival_cards = Rival1.showCards();
	if (rival_cards.size() >= 1) {
		window.draw(rival_cards[0]);
	}
	if (rival_cards.size() >= 2) {
		window.draw(rival_cards[1]);
	}
	if (rival_cards.size() >= 3) {
		window.draw(rival_cards[2]);
	}
	if (rival_cards.size() >= 4) {
		window.draw(rival_cards[3]);
	}
	if (rival_cards.size() >= 5) {
		window.draw(rival_cards[4]);
	}
	if (rival_cards.size() >= 6) {
		window.draw(rival_cards[5]);
	}
	if (rival_cards.size() >= 7) {
		window.draw(rival_cards[6]);
	}

	if (rival_cards.size() >= 8) {
		window.draw(rival_cards[7]);
	}

	if (rival_cards.size() >= 9) {
		window.draw(rival_cards[8]);
	}
}

void DrawGame::showConfirmation(sf::RenderWindow& window) {
	window.draw(confirmation_text);
}
