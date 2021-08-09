#include "Board.hpp"
#include "MyConstants.hpp"

void Board::highlight(sf::Vector2f cursor, sf::RenderWindow& window)
{
	/* Constants. */
	using Constants::center;
	using Constants::board_width;
	using Constants::board_height;

	/* De-highlight the previous token if one has been set from the default [-1,-1] value. */
	if (m_prev_highlight[0] >= 0 && m_prev_highlight[1] >= 0)
		m_tokens[m_prev_highlight[0]][m_prev_highlight[1]].setFillColor(Constants::bg);

	/* If the cursor isn't even on the board, there is nothing to highlight. */
	if (!cursorOnBoard(cursor))
		return;

	float local_x{}; // The distance from the left of the board.
	float inc{}; // How far each token is spaced horizontally.

	if (m_rotation == BoardRotation::Rotation_0 || m_rotation == BoardRotation::Rotation_2) // Horizontal.
	{
		inc = board_width / 7.0f;
		local_x = cursor.x - center.x + (0.5f * board_width);
	}
	else // Vertical.
	{
		inc = board_height / 6.0f;
		local_x = cursor.x - center.x + (0.5f * board_height);
	}

	/*	Determine the slot on the board using the position and increment lengths for each slot.
		For example if the mouse cursor has a local x pos of 140px and the increment is 30px,
		the slot would be number 4, since 140/30 = 4.666. */
	int slot{ (int)(local_x / inc) };

	/*	Sometimes, the mouse cursor lands right on the edge of the board, leading to the calculation
		 of a slot that doesn't exist. We reduce it by one depending on the rotation. */
	if (m_rotation == BoardRotation::Rotation_0 || m_rotation == BoardRotation::Rotation_2)
		if (slot >= 7) { slot = 6; }
	if (m_rotation == BoardRotation::Rotation_1 || m_rotation == BoardRotation::Rotation_3)
		if (slot >= 6) { slot = 5; }

	/*	If the board is rotated by 90 or 180 degrees, the respective slot numbers are reversed.
		Alter the slot values to match their proper position in the 2D matrix. */
	if (m_rotation == BoardRotation::Rotation_1)
		slot = 5 - slot;
	if (m_rotation == BoardRotation::Rotation_2)
		slot = 6 - slot;

	/* If the slot is a valid one to put a token in as per the rules of Rotate 4...*/
	if (isValidCol(slot))
	{
		/* Determine the token color based on the player turn. */
		sf::Color token_color{};
		switch (m_turn)
		{
		case PlayerTurn::Player_1: token_color = Constants::player1_col_highlight; break;
		case PlayerTurn::Player_2: token_color = Constants::player2_col_highlight; break;
		case PlayerTurn::Player_3: token_color = Constants::player3_col_highlight; break;
		}

		/* Determine the highest spot the token can be placed in. */
		int highest_spot{ highestSpot(slot) };

		/* Highlight the correct token by using the rotation as a guide. */
		switch (m_rotation)
		{
		case BoardRotation::Rotation_0:
		case BoardRotation::Rotation_2:
			m_tokens[slot][highest_spot].setFillColor(token_color);
			m_prev_highlight[0] = slot;
			m_prev_highlight[1] = highest_spot;
			break;

		case BoardRotation::Rotation_1:
		case BoardRotation::Rotation_3:
			m_tokens[highest_spot][slot].setFillColor(token_color);
			m_prev_highlight[0] = highest_spot;
			m_prev_highlight[1] = slot;
			break;
		}

		/*	If a token is highlighted and clicked, drop the token and rotate the board
			for the next player. */
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			dropToken(slot, highest_spot);
			rotate(window);
		}
	}
}