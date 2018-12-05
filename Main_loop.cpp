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

	vector<Card> cards = load();
	sf::Sprite fon_game = fons[0];

	Player player;

	// Automatic randomization
	srand(time(0));

	// Player gets six cards
	int amount_cards = 6;
	for (int i = 0; i < amount_cards; i++) {
		int pos = rand() % cards.size();
		Card new_card = cards[pos];
		player.getCards(new_card);

		// Card are deleted from deck
		cards.erase(cards.begin() + pos);
	}

	Rival rival;

	// Rival gets six cards
	for (int i = 0; i < amount_cards; i++) {
		int pos = rand() % cards.size();
		Card new_card = cards[pos];

		rival.getCard(new_card);
		cards.erase(cards.begin() + pos);
	}

	bool round = true;

	vector<sf::Sprite> player_cards = player.showCards();
	vector<sf::Sprite> rival_cards = rival.showCards();

	// Player and rival cards for display
	vector<sf::Sprite> cards_for_display = player.showCards();

	float delta = 0.f; // offset a player's card on the desk
	float delta_r = 0.f; // offset a rival's card on the desk
	bool player_move = true; // Does player or rival?
	bool rival_defend = true; // Does rival defend?

	Card active_card; // Card on the desk
	vector<Card> actives_cards; // Cards on the desk
	vector<int> positions;

	while (round == true) {

		sf::Event event2;

		while (window.pollEvent(event2)) {
			// Quit to menu
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				round = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				/*for (int new_pos : positions) {
					cards_for_display.erase(cards_for_display.begin() + new_pos);
				}*/
				actives_cards.clear();
			}

            // to play by card
		    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			    sf::Vector2i pos_mouse = sf::Mouse::getPosition();

			    amount_cards = player_cards.size();

			    for (size_t i = 0; i < player_cards.size(); i++) {

			    	sf::Vector2f pos_new_card = player_cards[i].getPosition();
			    	sf::Sprite check_card = player_cards[i];
			    	bool check = false;

				    // Delete a player card and add a card on the desk
				    if (intersection_card(pos_mouse, pos_new_card) == true
				    		&& player_move == true) {
				    	active_card = player.returnCard(i);
				    	for (Card card : actives_cards) {
				    		if (card.showValue() == active_card.showValue()) {
				    			     check = true;
				    			     break;
				    	          }
				    	}

				    	if (actives_cards.size() == 0) {
				    		check = true;
				    	}

				    	if (check == true) {
				    		cout << endl;
				    	    cout << "Player moves" << endl;
				    		click.play();

				    		int pos = find_card(cards_for_display, check_card);

				    		cards_for_display[pos].setPosition(550.f + delta, 330.f);
				    		// active_card = player.returnCard(i);
				    		player_cards.erase(player_cards.begin() + i);
				    		player.deleteCard(i);

				    		actives_cards.push_back(active_card);
				    		positions.push_back(pos);

				    		// Offset a card on the desk
				    		delta *= -1;
				    		if (amount_cards % 2 == 0) {
				    			delta += 150.f;
				    		}
				    	    player_move = false;
				    	    break;
				    	}
				    }
				}
			}
        }

		if (player_move == false && rival_defend == true) {
			Card defend_card = rival.defend(active_card);
			if (defend_card.showValue() == 0) {
				for (Card card : actives_cards) {
					cout << "Rival takes a card" << endl;
					rival.getCard(card);
				}
				// actives_cards.clear();
				rival_cards = rival.showCards();
				player_move = true;
			}
			else {
				cout << "Rival defended";
				sf::Sprite image_defend_card = defend_card.showCard();
				image_defend_card.setPosition(550.f + delta_r, 380.f);
				delta_r = delta;
				cards_for_display.push_back(image_defend_card);
				actives_cards.push_back(defend_card);
				player_move = true;
			}
		}

		/*if (player_move == false && rival_defend == false) {
            sf::Sprite rival_card = rival.moveCard();
            cout << "Rival moves" << endl;
            rival_card.setPosition(550.f + delta_r, 380.f);
            delta_r = delta;
            cards_for_display.push_back(rival_card);
            player_move = true;
		} */

		window.clear();
        window.draw(fon_game);

        sf::Sprite new_card = active_card.showCard();
        new_card.setPosition(0.f, 0.f);
        window.draw(new_card);

        window.draw(cards_for_display[0]);
        window.draw(cards_for_display[1]);
        window.draw(cards_for_display[2]);
        window.draw(cards_for_display[3]);

        if (cards_for_display.size() >= 5) {
        	window.draw(cards_for_display[4]);
        }

        if (cards_for_display.size() >= 6) {
        	window.draw(cards_for_display[5]);
        }

        if (cards_for_display.size() >= 7) {
        	window.draw(cards_for_display[6]);
        }

        if (cards_for_display.size() >= 8) {
        	window.draw(cards_for_display[7]);
        }

        if (cards_for_display.size() >= 9) {
            window.draw(cards_for_display[8]);
        }

        if (cards_for_display.size() >= 10) {
            window.draw(cards_for_display[9]);
        }

        if (cards_for_display.size() >= 11) {
            window.draw(cards_for_display[10]);
        }

        if (cards_for_display.size() >= 12) {
            window.draw(cards_for_display[11]);
        }


		window.draw(rival_cards[0]);
		window.draw(rival_cards[1]);
		window.draw(rival_cards[2]);
	    window.draw(rival_cards[3]);
		window.draw(rival_cards[4]);
		window.draw(rival_cards[5]);

		if (rival_cards.size() >= 7) {
			window.draw(rival_cards[6]);
		}

		if (rival_cards.size() >= 8) {
			window.draw(rival_cards[7]);
		}

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
	sf::Sound main_music = load_main_music();

	main_music.play();

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
