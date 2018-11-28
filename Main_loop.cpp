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

using namespace std;

sf::RenderWindow window(sf::VideoMode(1366, 768), "Card game!", sf::Style::Fullscreen);

void game(vector<sf::Sprite>& fons, sf::Sound click) {

	vector<sf::Sprite> cards = load();
	sf::Sprite fon_game = fons[0];

	Player player;

	// Automatic randomization
	srand(time(0));

	// Player gets six cards
	int amount_cards = 6;
	float delta = 0.f;
	for (int i = 0; i < amount_cards; i++) {
		int pos = rand() % cards.size();
		sf::Sprite new_card = cards[pos];
        new_card.setPosition(sf::Vector2f(330.f + delta, 570.f));
		player.getCard(new_card);
		cards.erase(cards.begin() + pos);
		delta += 120.f;
	}

	Rival rival;

	delta = 0.f;

	// Rival gets six cards
	for (int i = 0; i < amount_cards; i++) {
		int pos = rand() % cards.size();
		sf::Sprite new_card = cards[pos];
		new_card.setPosition(sf::Vector2f(330.f + delta, 0.f));
		rival.getCard(new_card);
		cards.erase(cards.begin() + pos);
		delta += 120.f;
	}

	bool round = true;

	vector<sf::Sprite> player_cards = player.showCard(); // Карты на руках
	vector<sf::Sprite> rival_cards = rival.showCard();

	vector<sf::Sprite> cards_for_display = player.showCard(); // Карты для показа

	delta = 0.f;

	while (round == true) {

		sf::Event event2;

		while (window.pollEvent(event2)) {
			// Quit to menu
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				round = false;
			}

            // Play by card
		    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		    	// Тут нужно почистить, но вроде работает

			    sf::Vector2i pos_mouse = sf::Mouse::getPosition();

			    // Player_cards изменил на player.showCard()

			    amount_cards = player_cards.size();

			    for (size_t i = 0; i < player_cards.size(); i++) {

			    	sf::Vector2f pos_new_card = player_cards[i].getPosition();
			    	sf::Sprite check_card = player_cards[i];

				    // Delete a player card and add a card on the desk
				    if (intersection_card(pos_mouse, pos_new_card) == true) {
				    	cout << endl;
				    	cout << "Entered card";
					    click.play();

					    int pos = find_card(cards_for_display, check_card);

					    cards_for_display[pos].setPosition(550.f + delta, 330.f);
					    player_cards.erase(player_cards.begin() + i);
					    player.deleteCard(i);
					    // Offset a card on the desk
					    delta *= -1;
					    if (amount_cards % 2 == 0) {
					    	delta += 150.f;
					    }
					    break;
				    }
				}
			}
        }

		window.clear();
        window.draw(fon_game);

        window.draw(cards_for_display[0]);
        window.draw(cards_for_display[1]);
        window.draw(cards_for_display[2]);
        window.draw(cards_for_display[3]);
        window.draw(cards_for_display[4]);
        window.draw(cards_for_display[5]);


		window.draw(rival_cards[0]);
		window.draw(rival_cards[1]);
		window.draw(rival_cards[2]);
	    window.draw(rival_cards[3]);
		window.draw(rival_cards[4]);
		window.draw(rival_cards[5]);

		window.display();
	}

}


int main()
{
	vector<sf::Sprite> fons_game = load_background();
	sf::Sprite fon_game = fons_game[0];

	vector<sf::Text> texts = load_texts();

	sf::Text play_game = texts[0];
	sf::Text quit_game = texts[1];

	sf::Sound click = load_song();

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				// Get a mouse position
				// Check a text position

				sf::Vector2i pos_mouse = sf::Mouse::getPosition();

				sf::Vector2f pos_text_game = play_game.getPosition();
				sf::Vector2f pos_text_quit = quit_game.getPosition();

				if (intersection(pos_mouse, pos_text_game) == true) {
					click.play();
					game(fons_game, click);
				}

				if (intersection(pos_mouse, pos_text_quit) == true) {
					click.play();
					window.close();
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}

		}

		window.clear();
		window.draw(fon_game);
		window.draw(play_game);
		window.draw(quit_game);
		window.display();
	}

    return 0;
}
