#include "Board.hpp"

void Board::setGameState(const TokenState& winner)
{
	switch (winner)
	{
	case TokenState::Player_1:
		m_game_state = GameState::Player_1_Won;
		break;
	case TokenState::Player_2:
		m_game_state = GameState::Player_2_Won;
		break;
	case TokenState::Player_3:
		m_game_state = GameState::Player_3_Won;
		break;

	default:
		break;
	}
}