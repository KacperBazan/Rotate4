#include "Board.hpp"
#include "MyConstants.hpp"

/*	Rotate the board 90 degrees and increment the rotation, turn number, and calculate
	the blocking numbers of each side. */
void Board::rotate(sf::RenderWindow& window)
{
	/*	Reset the highlighted token to the sentinel value of -1. The highlight function
		confirms that this value is not -1 before accessing the array of tokens. */
	m_prev_highlight[0] = -1;
	m_prev_highlight[1] = -1;

	float degrees_turned{ 0.0f }; // The amount each object will turn.
	while (degrees_turned <= 90.0f) // Rotate 90 degrees.
	{
		for (sf::RectangleShape& rect : m_boards)
			rect.rotate(Constants::rotate_speed);

		for (sf::CircleShape& circle : m_curves)
			circle.rotate(Constants::rotate_speed);

		for (auto& tokenArr : m_tokens)
		{
			for (auto& token : tokenArr)
				token.rotate(Constants::rotate_speed);
		}

		degrees_turned += Constants::rotate_speed; // Increment by this amount.
		draw(window); // Draw each object to give smooth rotation animation.
	}

	IncrementBoardRotation(); // Change the BoardRotation to it's next value.

	/*	The previous rotation animation has some floating point error. Over time this error
		grows. We check the current BoardRotation and fix that floating point error manually. */
	float fixed_rotation{};
	switch (m_rotation)
	{
	case BoardRotation::Rotation_0: fixed_rotation = 0.0f; break;
	case BoardRotation::Rotation_1: fixed_rotation = 90.0f; break;
	case BoardRotation::Rotation_2: fixed_rotation = 180.0f; break;
	case BoardRotation::Rotation_3: fixed_rotation = 270.0f; break;
	}

	for (sf::RectangleShape& rect : m_boards)
		rect.setRotation(fixed_rotation);

	for (sf::CircleShape& circle : m_curves)
		circle.setRotation(fixed_rotation);

	for (auto& tokenArr : m_tokens)
	{
		for (auto& token : tokenArr)
			token.setRotation(fixed_rotation);
	}
	draw(window);

	IncrementPlayerTurn(); // Indicate that it's the next player's turn.
	calcBlockingNumbers(); // After a token is placed and the board rotates, recheck the blocking numbers. 
}