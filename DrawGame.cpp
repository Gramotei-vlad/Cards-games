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
	bot_takes_cards = texts[9];
	setting_3 = texts[10];
	trump_info = texts[11];
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
	window.draw(setting_3);
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
	for (Card card : actives_cards)
	{
		window.draw(card.showCard());
	}
}

void DrawGame::showPlayerCards(sf::RenderWindow& window, const Player& Player1)
{
	vector<sf::Sprite> player_cards = Player1.showCards();
	for (sf::Sprite card : player_cards)
	{
		window.draw(card);
	}
}

void DrawGame::showRivalCards(sf::RenderWindow& window, const Rival& Rival1)
{
	vector<sf::Sprite> rival_cards = Rival1.showCards();
	for (sf::Sprite card : rival_cards)
	{
		window.draw(card);
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

void DrawGame::showBotTakesCards(sf::RenderWindow& window)
{
	window.draw(bot_takes_cards);
}

void DrawGame::showTrumpInfo(sf::RenderWindow& window, const Game Game1)
{
	trump_info.setString(Game1.getTrump());
	window.draw(trump_info);
}
