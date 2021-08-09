#include "Board.hpp"
#include <cassert>

/*	Find the highest possible spot a token can be placed in given a particular
	collumn. Assumes that the collumn is valid, as in not blocked by the
	current rotations blocking number. */
int Board::highestSpot(int col)
{
	TokenState Empty{ TokenState::Empty };

	switch (m_rotation)
	{
	case BoardRotation::Rotation_0:
		for (int i = 1; i < 6; i++)
		{
			if (m_token_states[col][i] != Empty)
			{
				if (m_token_states[col][i - 1] == Empty)
					return i - 1;
			}
		}
		if (m_token_states[col][5] == Empty)
			return 5;

	case BoardRotation::Rotation_1:
		for (int i = 1; i < 7; i++)
		{
			if (m_token_states[i][col] != Empty)
			{
				if (m_token_states[i - 1][col] == Empty)
					return i - 1;
			}
		}
		if (m_token_states[6][col] == Empty)
			return 6;

	case BoardRotation::Rotation_2:
		for (int i = 1; i < 6; i++)
		{
			if (m_token_states[col][5 - i] != Empty)
			{
				if (m_token_states[col][6 - i] == Empty)
					return 6 - i;
			}
		}
		if (m_token_states[col][0] == Empty)
			return 0;

	case BoardRotation::Rotation_3:
		for (int i = 1; i < 7; i++)
		{
			if (m_token_states[6 - i][col] != Empty)
			{
				if (m_token_states[7 - i][col] == Empty)
					return 7 - i;
			}
		}
		if (m_token_states[0][col] == Empty)
			return 0;

	default:
		assert(false && "m_rotation has reached an invalid value.");
		break;
	}
}