#include "Board.hpp"
#include "MyConstants.hpp"

void Board::dropToken(int slot, int highest_spot)
{
	sf::Color token_color{};
	TokenState token_state{};

	switch (m_turn)
	{
	case PlayerTurn::Player_1:
		token_color = Constants::player1_col;
		token_state = TokenState::Player_1;
		break;
	case PlayerTurn::Player_2:
		token_color = Constants::player2_col;
		token_state = TokenState::Player_2;
		break;
	case PlayerTurn::Player_3:
		token_color = Constants::player3_col;
		token_state = TokenState::Player_3;
		break;
	}

	switch (m_rotation)
	{
	case BoardRotation::Rotation_0:
	case BoardRotation::Rotation_2:
		m_tokens[slot][highest_spot].setFillColor(token_color);
		m_token_states[slot][highest_spot] = token_state;
		break;

	case BoardRotation::Rotation_1:
	case BoardRotation::Rotation_3:
		m_tokens[highest_spot][slot].setFillColor(token_color);
		m_token_states[highest_spot][slot] = token_state;
		break;
	}
}
