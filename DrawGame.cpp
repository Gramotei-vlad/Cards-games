/*
 * DrawGame.cpp
 *
 *  Created on: 18 дек. 2018 г.
 *      Author: связной
 */
#include "DrawGame.h"

DrawGame::DrawGame()
{
	vector<sf::Sprite> fons_game = load_background();
	vector<sf::Text> texts = load_texts();

	fon_game = fons_game[0];
	play_text = texts[0];
	quit_text = texts[1];
	controller_text = texts[2];
	setting_1 = texts[3];
	setting_2 = texts[4];
	win_game = texts[5];
	lose_game = texts[6];
	confirmation_text = texts[7];
	no_winners = texts[8];
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

void DrawGame::close(sf::RenderWindow& window)
{
	window.close();
}

void DrawGame::showMenu(sf::RenderWindow& window)
{
	window.draw(play_text);
	window.draw(controller_text);
	window.draw(quit_text);
}

void DrawGame::showSettings(sf::RenderWindow& window)
{
	window.draw(setting_1);
	window.draw(setting_2);
}

vector<sf::Text> DrawGame::gameTexts() const
{
	return {play_text, controller_text, quit_text,
		    setting_1, setting_2, win_game,
		lose_game, confirmation_text, no_winners};
}

void DrawGame::showDeck(sf::RenderWindow& window, const Game& Game1)
{
	if (Game1.checkDeck() == true)
	{
		Card card;
		card.setPosition(1225, 300);
		window.draw(card.showCard());
	}
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

void DrawGame::showEndOfMatch(sf::RenderWindow& window, const string& name)
{
	if (name == "player")
	{
		window.draw(win_game);
	}
	else if (name == "rival")
	{
		window.draw(lose_game);
	}
	else
	{
		window.draw(no_winners);
	}

}
