/*
 * Game.cpp
 *
 *  Created on: 12 дек. 2018 г.
 *      Author: связной
 */
#include "Game.h"

Game::Game()
{
	deck = load();
	Game::setTrumpCards();
}

void Game::setTrumpCards()
{
	cout << "Set trump" << endl;
	srand(time(0));

	vector<string> suits = {"diamonds", "clubs", "hearts", "spades"};
	int num = rand() % suits.size();
	trump = suits[num];
	for (Card& card : deck)
	{
		if (card.showSuit() == trump)
		{
			card.changeValue(3 * card.showTrumpValue());
		}
	}
}

string Game::getTrump() const
{
	return trump;
}

vector<Card> Game::showDesk() const
{
	return desk_cards;
}

bool Game::checkDeck() const
{
	if (deck.size() == 0)
	{
		return false;
	}
	return true;
}

bool Game::checkCard(const Card card) const
{
	for (Card curr_card : desk_cards)
	{
		if (curr_card.showImageValue() == card.showImageValue())
		{
			return true;
		}
	}
	return false;
}

bool Game::movePermition(const Card card) const
{
	return Game::checkCard(card) || Game::showDesk().size() == 0;
}

bool Game::defendPermition(const Card player_card, const Card rival_card) const
{
	return player_card.showTrumpValue() > rival_card.showTrumpValue() &&
			(player_card.showSuit() == rival_card.showSuit() ||
			 player_card.showSuit() == trump);
}

bool Game::whoAttacks() const
{
	return player_assaulter_;
}

bool Game::moveCard() const
{
	return move_card_;
}


// Метод, написанный с помощью говнокода.
// Если проблемы со психикой, не лезте сюда
void Game::setPositionsCards(bool attack)
{
	size_t amount_desk_cards = desk_cards.size();
	if (attack == false)
	{
		sf::Vector2f pos_card = desk_cards[amount_desk_cards - 2].showCard().getPosition();
		desk_cards[amount_desk_cards - 1].setPosition(pos_card.x, pos_card.y + 50.f);
	}
	else
	{
		if (amount_desk_cards % 2 == 0)
		{
			amount_desk_cards += 1;
		}

		switch(amount_desk_cards)
		{
		case 1:
			amount_desk_cards = desk_cards.size();
			desk_cards[amount_desk_cards - 1].setPosition(550.f, 310.f);
			break;
		case 3:
			amount_desk_cards = desk_cards.size();
			desk_cards[amount_desk_cards - 1].setPosition(700.f, 310.f);
			break;
		case 5:
			amount_desk_cards = desk_cards.size();
			desk_cards[amount_desk_cards - 1].setPosition(400.f, 310.f);
			break;
		case 7:
			amount_desk_cards = desk_cards.size();
			desk_cards[amount_desk_cards - 1].setPosition(850.f, 310.f);
			break;
		case 9:
			amount_desk_cards = desk_cards.size();
			desk_cards[amount_desk_cards - 1].setPosition(250.f, 310.f);
			break;
		case 11:
			amount_desk_cards = desk_cards.size();
			desk_cards[amount_desk_cards - 1].setPosition(1000.f, 310.f);
			break;
		case 13:
			amount_desk_cards = desk_cards.size();
			desk_cards[amount_desk_cards - 1].setPosition(100.f, 310.f);
			break;
		}
	}
}

void Game::changeAssaulter()
{
	cout << "New round // ";
	desk_cards.clear();
	player_assaulter_ = not player_assaulter_;
	// cout << bool(player_assaulter_) << endl;
	cout << "Completed" << endl;
}

void Game::giveoutCards(Player& Player1, Rival& Rival1)
{
	cout << "Give out cards // ";
	srand(time(0));
	while (Player1.amountCards() < 6) {
		if (deck.size() > 0) {
			int pos = rand() % deck.size();
			Card new_card = deck[pos];

			Player1.getCard(new_card);
			deck.erase(deck.begin() + pos);
		}
		else
		{
			break;
		}
	}

	while (Rival1.amountCards() < 6) {
		if (deck.size() > 0) {
			int pos = rand() % deck.size();
			Card new_card = deck[pos];

			Rival1.getCard(new_card);
			deck.erase(deck.begin() + pos);
		}
		else
		{
			break;
		}
	}
	cout << "Completed" << endl;
}

bool Game::playerAttack(Player& Player1, const sf::Vector2i pos_mouse)
{
	vector<Card> player_cards = Player1.listCards();
	vector<sf::Sprite> player_images_cards = Player1.showCards();

	for (size_t i = 0; i < player_images_cards.size(); i++)
	{
		if (intersection_card(pos_mouse, player_images_cards[i].getPosition()) == true)
		{
			Card new_card = Player1.returnCard(i);
			if (Game::movePermition(new_card) == true)
			{
				cout << "Player moves // ";
				Player1.deleteCard(i);
				desk_cards.push_back(new_card);
				active_card = new_card;
				Game::setPositionsCards(true);
				//move_card_ = not move_card_;
				cout << "Completed" << endl;
				return true;
			}
	    }
    }
	return false;
}

bool Game::playerDefend(Player& Player1, const sf::Vector2i pos_mouse)
{
	vector<Card> player_cards = Player1.listCards();
	vector<sf::Sprite> player_images_cards = Player1.showCards();

	for (size_t i = 0; i < player_images_cards.size(); i++)
	{
		if (intersection_card(pos_mouse, player_images_cards[i].getPosition()))
		{
			Card new_card = Player1.returnCard(i);

			if (Game::defendPermition(new_card, active_card) == true)
			{
				cout << "Player defends // ";
				Player1.deleteCard(i);
				desk_cards.push_back(new_card);
				move_card_ = not move_card_;
				Game::setPositionsCards(false);
				cout << "Completed" << endl;
				return true;
	        }
	    }
    }
	return false;
}

void Game::playerTakesCards(Player& Player1, Rival& Rival1)
{
	cout << "Player takes cards from the desk // ";
	while (Rival1.moveCard(Game::showDesk()).showImageValue() != 0)
	{
		Card add_card = Rival1.moveCard(Game::showDesk());
		if (add_card.showImageValue() != 0)
		{
			desk_cards.push_back(add_card);
		}
	}
	for (Card card : desk_cards)
	{
		Player1.getCard(card);
	}
	desk_cards.clear();
	cout << "Completed" << endl;
}

bool Game::rivalAttack(Rival& Rival1)
{
	Card rival_card = Rival1.moveCard(Game::showDesk());
	if (rival_card.showImageValue() == 0)
	{
		cout << "Rival completes a round" << endl;
		Game::changeAssaulter();
		return false;
	}
	else
	{
		desk_cards.push_back(rival_card);
		active_card = rival_card;
	    move_card_ = not move_card_;
		Game::setPositionsCards(true);
		cout << "Rival attacks // ";
		cout << "Completed" << endl;
		return true;
	}
}

bool Game::rivalDefend(Rival& Rival1)
{
	Card rival_card = Rival1.defend(active_card, trump);
	if (rival_card.showImageValue() == 0) {
		// Game::rivalTakesCards(Rival1);
		return false;
	}
	else
	{
		cout << "Rival defends // ";
		desk_cards.push_back(rival_card);
		move_card_ = not move_card_;
		Game::setPositionsCards(false);
		cout << "Completed" << endl;
		return true;
	}
}

void Game::rivalTakesCards(Rival& Rival1)
{
	cout << "Rival takes cards from the desk // ";
	for (Card card : desk_cards)
	{
		Rival1.getCard(card);
	}
	desk_cards.clear();
	cout << "Completed" << endl;
}

string Game::checkWinners(Player& Player1, Rival& Rival1)
{
	if (deck.size() == 0 && desk_cards.size() == 0)
	{
		if (Player1.amountCards() == 0 && Rival1.amountCards() == 0)
		{
			return "no_winners";
		}

		if (Player1.amountCards() == 0)
		{
			return "player";
		}

		if (Rival1.amountCards() == 0)
		{
			return "rival";
		}
	}
	return "Game is not over";
}
