#include "Board.hpp"

/*	In Rotate 4, the blocking number refers to how many tokens are needed in a collumn
	to prevent players from placing new tokens in said collumn. Upon starting the game
	the blocking number for each side is 2, meaning that if a token would need to pass
	2 other tokens to enter a collumn, that collumn is not valid. Players are forced
	to choose collumns with a blocking number less than 2 unless every single collumn
	has a blocking number of 2. Then, the blocking number increases to 3, and each
	collumn that had 2 tokens blocking a player, is now valid since 3 tokens are now
	required to prevent a player from placing a token. Blocking numbers are calculated
	starting from the top most row in the collumn, counting downward. Tokens that are
	are added to the blocking number count need to be occupying the top most rows with
	no gaps in between them. */

void Board::calcBlockingNumbers()
{
	/*	This function is called before every turn to determing the blocking number
		of the board. It goes through each row one by one checking for empty spots.
		If it finds an empty spot in that row, that means the blocking number must
		be one greater, except for row 0 which starts with a blocking number of 2. */

	switch (m_rotation)
	{
	case BoardRotation::Rotation_0:
		for (size_t row = 0; row < 6; row++)
		{
			for (size_t col = 0; col < 7; col++)
			{
				if (m_token_states[col][row] == TokenState::Empty)
				{
					m_block_num[0] = row + 1;
					if (row == 0)
						++m_block_num[0];

					return;
				}
			}
		}
		m_block_num[0] = 6;
		m_game_state = GameState::Tied;
		return;

	case BoardRotation::Rotation_1:
		for (size_t row = 0; row < 7; row++)
		{
			for (size_t col = 0; col < 6; col++)
			{
				if (m_token_states[row][col] == TokenState::Empty)
				{
					m_block_num[1] = row + 1;
					if (row == 0)
						++m_block_num[1];

					return;
				}
			}
		}
		m_block_num[1] = 7;
		m_game_state = GameState::Tied;
		return;

	case BoardRotation::Rotation_2:
		for (size_t row = 0; row < 6; row++)
		{
			for (size_t col = 0; col < 7; col++)
			{
				if (m_token_states[col][5 - row] == TokenState::Empty)
				{
					m_block_num[2] = row + 1;
					if (row == 0)
						++m_block_num[2];

					return;
				}
			}
		}
		m_block_num[2] = 6;
		m_game_state = GameState::Tied;
		return;

	case BoardRotation::Rotation_3:
		for (size_t row = 0; row < 7; row++)
		{
			for (size_t col = 0; col < 6; col++)
			{
				if (m_token_states[6 - row][col] == TokenState::Empty)
				{
					m_block_num[3] = row + 1;
					if (row == 0)
						++m_block_num[3];

					return;
				}
			}
		}
		m_block_num[3] = 7;
		m_game_state = GameState::Tied;
		return;
	}
}