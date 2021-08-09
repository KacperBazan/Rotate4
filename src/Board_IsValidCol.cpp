#include "Board.hpp"
#include <cassert>

/* Returns true if the collumn isn't blocked by the sides blocking number. */
bool Board::isValidCol(int collumn)
{
	TokenState Empty{ TokenState::Empty };

	switch (m_rotation)
	{
	case BoardRotation::Rotation_0:

		for (size_t row = 0; row < m_block_num[0]; row++)
		{
			if (m_token_states[collumn][row] == Empty)
				return true;
		}
		return false;

	case BoardRotation::Rotation_1:

		for (size_t row = 0; row < m_block_num[1]; row++)
		{
			if (m_token_states[row][collumn] == Empty)
				return true;
		}
		return false;

	case BoardRotation::Rotation_2:

		for (size_t row = 0; row < m_block_num[2]; row++)
		{
			if (m_token_states[collumn][5 - row] == Empty)
				return true;
		}
		return false;

	case BoardRotation::Rotation_3:

		for (size_t row = 0; row < m_block_num[3]; row++)
		{
			if (m_token_states[6 - row][collumn] == Empty)
				return true;
		}
		return false;

	default:
		assert(false && "m_rotation has reached an invalid value.");
		break;
	}
}