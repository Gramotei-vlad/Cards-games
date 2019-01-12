/*
 * Round.cpp
 *
 *  Created on: 18 дек. 2018 г.
 *      Author: связной
 */
#include "Round.h"
#include <time.h>

void delay(int ms) // аргумент- требуемое время задержки в миллисекундах
{
  int c = clock() + ms;
  while (clock() < c);
}

Round::Round()
{
	round = true;
}

Game Round::startRound(Player& Player1, Rival& Rival1) {
	Game Game1;
	Game1.giveoutCards(Player1, Rival1);
	return Game1;
}

void Round::stopRound() {
	round = false;
}

void Round::run(sf::RenderWindow& window, DrawGame& DrawGame1, AudioGame& AudioGame1)
{
	Player Player1;
	Rival Rival1;

	Game Game1 = startRound(Player1, Rival1);

	bool check = true;
	bool backspace = false; // Backspace is not pressed
	bool player_adds_cards = false;

	while (round == true)
	{
		sf::Event event3;

		while (window.pollEvent(event3)) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				backspace = true;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && backspace == true)
			{
				backspace = false;
				Round::stopRound();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)
					&& backspace == true) {
				backspace = false;
			}

			if (Game1.whoAttacks() == true) {

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					sf::Vector2i pos_mouse = sf::Mouse::getPosition();
					if (Game1.playerAttack(Player1, pos_mouse) == true)
					{
						AudioGame1.playClick();
						if (player_adds_cards == false)
						{
							if (Game1.rivalDefend(Rival1) == false)
							{
								player_adds_cards = true;
							}
						}
					}


				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					if (player_adds_cards == true)
					{
						Game1.rivalTakesCards(Rival1);
					}
					else
					{
						Game1.changeAssaulter();
					}
					player_adds_cards = false;
					Game1.giveoutCards(Player1, Rival1);
					delay(100);
				}

			} else {
				if (check == true) {
					if (Game1.rivalAttack(Rival1) == true)
					{
						check = false;
					}
					else
					{
						Game1.giveoutCards(Player1, Rival1);
					}
				}
				// check = false;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					sf::Vector2i pos_mouse = sf::Mouse::getPosition();
					if (Game1.playerDefend(Player1, pos_mouse) == true) {
						AudioGame1.playClick();
						check = true;
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					Game1.playerTakesCards(Player1, Rival1);
					Game1.giveoutCards(Player1, Rival1);
					check = true;
					delay(100);
				}
			}
		}

		string name = Game1.checkWinners(Player1, Rival1);

		DrawGame1.clear(window);
		DrawGame1.showBackground(window);
		if (name == "Game is not over")
		{
			DrawGame1.showDeck(window, Game1);
			DrawGame1.showPlayerCards(window, Player1);
			DrawGame1.showDesk(window, Game1);
			DrawGame1.showRivalCards(window, Rival1);
			DrawGame1.showTrumpInfo(window, Game1);
		}
		else
		{
			if (backspace == false)
			{
				DrawGame1.showEndOfMatch(window, name);
			}
		}

		if (player_adds_cards == true)
		{
			DrawGame1.showBotTakesCards(window);
		}

		if (backspace == true)
		{
			DrawGame1.showConfirmation(window);
		}

		DrawGame1.display(window);
	}

}



