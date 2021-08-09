#include "Board.hpp"
#include "MyConstants.hpp"

/* Draw the SFML shapes representing the board and tokens to the window. */
void Board::draw(sf::RenderWindow& window)
{
	window.clear(Constants::bg);

	/* Draw the board that holds the tokens. */
	for (sf::RectangleShape& rect : m_boards)
	{
		window.draw(rect);
	}
	for (sf::CircleShape& circle : m_curves)
	{
		window.draw(circle);
	}

	/* Draw glow of winning tokens. */
	for (sf::CircleShape& win_token : m_winning_tokens)
	{
		window.draw(win_token);
	}

	/* Draw each token. */
	for (auto& i : m_tokens)
	{
		for (auto& token : i)
		{
			window.draw(token);
		}
	}

	window.display();
}