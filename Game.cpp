/*
 * Game.cpp
 *
 *  Created on: 12 дек. 2018 г.
 *      Author: связной
 */
#include "Game.h"

vector<Card> Game::showDesk() const
{
	return desk_cards;
}

bool Game::checkCard(const Card card) const
{
	for (Card curr_card : desk_cards)
	{
		if (curr_card.showValue() == card.showValue())
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
	return player_card.showValue() > rival_card.showValue() &&
			player_card.showSuit() == rival_card.showSuit();
}

bool Game::whoAttacks() const
{
	return player_assaulter_;
}

bool Game::moveCard() const
{
	return move_card_;
}

void Game::setPositionsCards()
{
	float delta_x = 0.f;
	float delta_y = 0.f;
	for (size_t i = 0; i < desk_cards.size(); i++)
	{
		delta_y = i % 2 == 0 ? 0.f : 50.f;
		if (i != 0 && i != 1)
		{
			if (i % 2 == 0)
			{
				delta_x *= -1;
				delta_x += 150.f;
			}
		}
		desk_cards[i].setPosition(550.f + delta_x, 330.f + delta_y);
	}
}

void Game::changeAssaulter()
{
	cout << "New round" << endl;
	desk_cards.clear();
	player_assaulter_ = not player_assaulter_;
	cout << bool(player_assaulter_) << endl;
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
				cout << "Player moves" << endl;
				Player1.deleteCard(i);
				desk_cards.push_back(new_card);
				active_card = new_card;
				move_card_ = not move_card_;
				Game::setPositionsCards();
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
				cout << "Player defends" << endl;
				Player1.deleteCard(i);
				desk_cards.push_back(new_card);
				move_card_ = not move_card_;
				Game::setPositionsCards();
				return true;
	        }
	    }
    }
	return false;
}

void Game::playerTakesCards(Player& Player1, Rival& Rival1)
{
	cout << "Player takes cards from the desk" << endl;
	while (Rival1.moveCard(Game::showDesk()).showValue() != 0)
	{
		Card add_card = Rival1.moveCard(Game::showDesk());
		if (add_card.showValue() != 0)
		{
			desk_cards.push_back(add_card);
		}
	}
	for (Card card : desk_cards)
	{
		Player1.getCard(card);
	}
	desk_cards.clear();
}

bool Game::rivalAttack(Rival& Rival1)
{
	Card rival_card = Rival1.moveCard(Game::showDesk());
	if (rival_card.showValue() == 0)
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
		Game::setPositionsCards();
		cout << "Rival attacks" << endl;
		return true;
	}
}

bool Game::rivalDefend(Rival& Rival1)
{
	Card rival_card = Rival1.defend(active_card);
	if (rival_card.showValue() == 0) {
		Game::rivalTakesCards(Rival1);
		return false;
	}
	else
	{
		cout << "Rival defends" << endl;
		desk_cards.push_back(rival_card);
		move_card_ = not move_card_;
		Game::setPositionsCards();
		return true;
	}
}

void Game::rivalTakesCards(Rival& Rival1)
{
	cout << "Rival takes cards from the desk" << endl;
	for (Card card : desk_cards)
	{
		Rival1.getCard(card);
	}
	desk_cards.clear();
}
