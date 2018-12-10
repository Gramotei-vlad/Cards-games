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

void game(vector<sf::Sprite>& fons, sf::Sound click, vector<sf::Text> texts)
{

	vector<Card> cards = load();
	sf::Sprite fon_game = fons[0];

	sf::Text win_game = texts[0];
	sf::Text lose_game = texts[1];
	sf::Text confirmation_text = texts[2];

	Player player; // class of a Player

	// Automatic randomization
	srand(time(0));

	// Player gets six cards
	int amount_cards = 6;
	for (int i = 0; i < amount_cards; i++) {
		int pos = rand() % cards.size();
		Card new_card = cards[pos];
		player.getCard(new_card);

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

	float delta = 0.f; // offset a player's card on the desk
	float delta_r = 0.f; // offset a rival's card on the desk
	bool player_move = true; // Does player or rival?
	bool rival_defend = true; // Does rival defend?
	bool player_check = false; // Unhide win text
	bool rival_check = false; // Unhide lose text
	bool show_conf_text = false;
	bool backspace = false; // Button backspace are pressed

	Card active_card; // Card on the desk
	Card rival_card;
	vector<Card> actives_cards; // Cards on the desk

	while (round == true) {

		sf::Event event2;

		while (window.pollEvent(event2)) {
			// Quit to menu
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				show_conf_text = true;
				backspace = true;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && backspace == true) {
				round = false;
				show_conf_text = true;
				backspace = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && backspace == true) {
				show_conf_text = false;
				backspace = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && rival_defend == true) {
				rival_defend = false;
				player_move = false;
				delta = 0.f;
				delta_r = 0.f;
				cout << "Player's round is over" << endl;
				cout << endl;
				actives_cards.clear();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) and rival_defend == false) {
				cout << "Player takes cards" << endl;
				for (Card card : actives_cards) {
					player.getCard(card);
				}
				player_move = false;
				delta = 0.f;
				delta_r = 0.f;
				actives_cards.clear();
				player_cards = player.showCards();
			}

            // to play by card
		    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			    sf::Vector2i pos_mouse = sf::Mouse::getPosition();

			    amount_cards = player_cards.size();

			    for (size_t i = 0; i < player_cards.size(); i++) {

			    	sf::Vector2f pos_new_card = player_cards[i].getPosition();
			    	sf::Sprite check_card = player_cards[i];
			    	bool check = false;

			    	if (intersection_card(pos_mouse, pos_new_card) == true
			    					    		&& player_move == true)
			    	{
			    		active_card = player.returnCard(i);
			    		if (rival_defend == true) {
			    			// active_card = player.returnCard(i);
			    			if (actives_cards.size() == 0) {
			    				check = true;
			    			}
			    			else {
			    			for (Card card : actives_cards) {
			    				if (card.showValue() == active_card.showValue()) {
			    				     check = true;
			    				     break;
			    				}
			    			  }
			    		    }
			    			if (check == true) {
			    				click.play();
			    				cout << "Player moves" << endl;

			    				active_card.setPosition(550.f + delta, 330.f);
			    				// delta = delta_r;
			    				delta *= -1;
			    				if (amount_cards % 2 == 0) {
			    					delta += 150.f;
			    				}
			    				player.deleteCard(i);
			    				actives_cards.push_back(active_card);
			    				player_cards = player.showCards();
			    				player_move = false;
			    				break;

			    		     }
			    		}
			    		else {
			    			if (active_card.showValue() >= rival_card.showValue() &&
			    					active_card.showSuit() == rival_card.showSuit())
			    			{
			    				click.play();
			    				cout << "Player defend" << endl;
			    				active_card.setPosition(550.f + delta, 380.f);
			    				// delta = delta_r;
			    				/*delta *= -1;
			    				if (amount_cards % 2 == 0) {
			    					delta += 150.f;
			    				}*/
			    				player.deleteCard(i);
			    				actives_cards.push_back(active_card);
			    				player_cards = player.showCards();
			    				player_move = false;
			    				break;

			    			}
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
				delta = 0;
				delta_r = 0;
				actives_cards.clear();
				player_move = true;
			}
			else {
				cout << "Rival defended" << endl;
				defend_card.setPosition(550.f + delta_r, 380.f);
				delta_r = delta;
				actives_cards.push_back(defend_card);
				player_move = true;
			}
			rival_cards = rival.showCards();
		}
		else if (player_move == false && rival_defend == false) {
			cout << "Rival moves" << endl;
			rival_card = rival.moveCard(actives_cards);
			// cout << rival_card.showValue() << endl;
			if (rival_card.showValue() == 0) {
				player_move = true;
				rival_defend = true;
				delta = 0.f;
				delta_r = 0.f;
				cout << "Rival's round is over" << endl;
				cout << endl;
				cout << rival_defend << endl;
				actives_cards.clear();
			}
			else {
				rival_cards = rival.showCards();
				rival_card.setPosition(550.f + delta_r, 330.f);

				delta_r *= -1;
				// Поменял amount_cards на actives_cards.size()
				if (actives_cards.size() % 2 == 0) {
					delta_r += 150.f;
				}

				actives_cards.push_back(rival_card);
				player_move = true;
			}
		}

		/*if (player_move == false && rival_defend == false) {
			cout << "Rival moves" << endl;
		}*/

		/*if (player_move == false && rival_defend == false) {
            sf::Sprite rival_card = rival.moveCard();
            cout << "Rival moves" << endl;
            rival_card.setPosition(550.f + delta_r, 380.f);
            delta_r = delta;
            cards_for_display.push_back(rival_card);
            player_move = true;
		} */

		//cout << "Rival_defend is" << rival_defend << endl;

		window.clear();
        window.draw(fon_game);

        if (player_cards.size() == 0 && rival_check == false) {
        	cout << "Player wins!" << endl;
        	player_check = true;
        	rival_cards = {};
        	actives_cards.clear();
            window.draw(win_game);
        }

        if (rival_cards.size() == 0 && player_check == false) {
        	cout << "Player loses!" << endl;
        	player_cards = {};
        	rival_check = true;
        	actives_cards.clear();
        	window.draw(lose_game);
        }

        sf::Sprite new_card = active_card.showCard();
        new_card.setPosition(0.f, 0.f);
        window.draw(new_card);

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

		if (show_conf_text == true) {
			if (player_check == true || rival_check == true) {
				confirmation_text.setPosition(500, 400);
			}
			else {
				confirmation_text.setPosition(500, 300);
			}
			window.draw(confirmation_text);
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
	texts.erase(texts.begin()); // Play_text delete
	texts.erase(texts.begin()); // quit_text delete

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
					game(fons_game, click, texts);
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
