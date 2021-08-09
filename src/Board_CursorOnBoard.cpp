#include "Board.hpp"
#include "MyConstants.hpp"

/* Returns true if the cursor is over the board on the screen. */
bool Board::cursorOnBoard(sf::Vector2f cursor)
{
	using Constants::center;
	using Constants::board_width;
	using Constants::board_height;

	sf::Vector2f tl{}; // Top left corner of the board.
	sf::Vector2f br{}; // Bottom right corner of the board.

	if (m_rotation == BoardRotation::Rotation_0 || m_rotation == BoardRotation::Rotation_2) // Horizontal.
	{
		tl = { center.x - (0.5f * board_width), center.y - (0.5f * board_height) };
		br = { center.x + (0.5f * board_width), center.y + (0.5f * board_height) };
	}
	else // Vertical.
	{
		tl = { center.x - (0.5f * board_height), center.y - (0.5f * board_width) };
		br = { center.x + (0.5f * board_height), center.y + (0.5f * board_width) };
	}

	if (tl.x <= cursor.x && cursor.x <= br.x)
	{
		if (tl.y <= cursor.y && cursor.y <= br.y)
		{
			return true;
		}
	}
	return false;
}