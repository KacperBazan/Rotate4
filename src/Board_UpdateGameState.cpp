#include "Board.hpp"

/* Check if there is a 4-in-a-row anywhere on the board.*/
void Board::updateGameState()
{
	/* Check Verticals */
	for (size_t col = 0; col < 7; col++)
	{
		for (size_t row = 0; row < 3; row++)
		{
			if (m_token_states[col][row] == TokenState::Empty)
				continue;

			TokenState player_token{ m_token_states[col][row] };

			if (m_token_states[col][row + 1] == player_token &&
				m_token_states[col][row + 2] == player_token &&
				m_token_states[col][row + 3] == player_token)
			{
				setGameState(player_token);
				return;
			}
		}
	}

	/* Check Horizontals */
	for (size_t row = 0; row < 6; row++)
	{
		for (size_t col = 0; col < 4; col++)
		{
			if (m_token_states[col][row] == TokenState::Empty)
				continue;

			TokenState player_token{ m_token_states[col][row] };

			if (m_token_states[col + 1][row] == player_token &&
				m_token_states[col + 2][row] == player_token &&
				m_token_states[col + 3][row] == player_token)
			{
				setGameState(player_token);
				return;
			}
		}
	}

	/* Check Descending Diagonals */
	for (size_t col = 0; col < 4; col++)
	{
		for (size_t row = 0; row < 3; row++)
		{
			if (m_token_states[col][row] == TokenState::Empty)
				continue;

			TokenState player_token{ m_token_states[col][row] };

			if (m_token_states[col + 1][row + 1] == player_token &&
				m_token_states[col + 2][row + 2] == player_token &&
				m_token_states[col + 3][row + 3] == player_token)
			{
				setGameState(player_token);
				return;
			}
		}
	}

	/* Check Ascending Diagonals */
	for (size_t col = 3; col < 7; col++)
	{
		for (size_t row = 0; row < 3; row++)
		{
			if (m_token_states[col][row] == TokenState::Empty)
				continue;

			TokenState player_token{ m_token_states[col][row] };

			if (m_token_states[col - 1][row + 1] == player_token &&
				m_token_states[col - 2][row + 2] == player_token &&
				m_token_states[col - 3][row + 3] == player_token)
			{
				setGameState(player_token);
				return;
			}
		}
	}
}
