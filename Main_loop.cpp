//============================================================================
// Name        : Main_loop.cpp
// Author      : Vladislav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

#include "Graphics.h"
#include "Utils.h"
#include "Audio.h"
#include "Player.h"
#include "Rival.h"
#include "Game.h"
#include "Round.h"
#include "DrawGame.h"
#include "AudioGame.h"
#include "TestFramework.h"

using namespace std;

void game(sf::RenderWindow& window, AudioGame& AudioGame1, vector<sf::Sprite>& fons, vector<sf::Text> texts)
{

	vector<Card> cards = load();
	sf::Sprite fon_game = fons[0];

	sf::Text win_game = texts[0];
	sf::Text lose_game = texts[1];
	sf::Text confirmation_text = texts[2];
	sf::Text no_winners = texts[3];

	Player Player1; // class of a Player

	// Automatic randomization
	srand(time(0));

	// Player gets six cards
	int amount_cards = 6;
	for (int i = 0; i < amount_cards; i++) {
		int pos = rand() % cards.size();
		Card new_card = cards[pos];
		Player1.getCard(new_card);

		// Card are deleted from deck
		cards.erase(cards.begin() + pos);
	}

	Rival Rival1;

	// Rival gets six cards
	for (int i = 0; i < amount_cards; i++) {
		int pos = rand() % cards.size();
		Card new_card = cards[pos];

		Rival1.getCard(new_card);
		cards.erase(cards.begin() + pos);
	}

	Game Game1;
	DrawGame DrawGame1(fons[0], confirmation_text);
	Round Round1;

	bool match = true;

	while (match == true) {

        Round1.run(window, DrawGame1, AudioGame1, Game1, Player1, Rival1);
        match = false;
	}

}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Card game!", sf::Style::Fullscreen);
	vector<sf::Sprite> fons_game = load_background();
	sf::Sprite fon_game = fons_game[0];

	vector<sf::Text> texts = load_texts();

	sf::Text play_game = texts[0];
	sf::Text quit_game = texts[1];
	sf::Text controller = texts[2];
	sf::Text setting_1 = texts[3];
	sf::Text setting_2 = texts[4];

	for (int i = 0; i < 5; i++) {
		texts.erase(texts.begin());
	}

	AudioGame AudioGame1;

	bool show_settings = false;

	AudioGame1.playMainMusic();

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				show_settings = false;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				// Get a mouse position
				// Check a text position

				sf::Vector2i pos_mouse = sf::Mouse::getPosition();

				sf::Vector2f pos_text_game = play_game.getPosition();
				sf::Vector2f pos_text_controller = controller.getPosition();
				sf::Vector2f pos_text_quit = quit_game.getPosition();

				if (intersection(pos_mouse, pos_text_game) == true) {
					AudioGame1.playClick();
					game(window, AudioGame1, fons_game, texts);
				}

				if (intersection(pos_mouse, pos_text_controller) == true) {
					AudioGame1.playClick();
					show_settings = true;
				}

				if (intersection(pos_mouse, pos_text_quit) == true) {
					AudioGame1.playClick();
					window.close();
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}

		}

		window.clear();
		window.draw(fon_game);
		if (show_settings == false) {
			window.draw(play_game);
			window.draw(controller);
			window.draw(quit_game);
		}
		else {
			window.draw(setting_1);
			window.draw(setting_2);
		}
		window.display();
	}

    return 0;
}
