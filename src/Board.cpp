/* Member function definitions for the class "Board". */

#include "Board.hpp"
#include "MyConstants.hpp"

/* Constructor. */
Board::Board()
	: m_rotation{ BoardRotation::Rotation_0 }, m_turn{ PlayerTurn::Player_1 }
	, m_game_state{ GameState::Ongoing }, m_prev_highlight{ -1, -1 }
{
	/* Constants. */
	using Constants::board_width;
	using Constants::board_height;
	using Constants::board_curve;
	using Constants::board_col;
	using Constants::token_radius;
	using Constants::center;
	using Constants::bg;

	/* Upon the start, the number of rows that block incoming tokens is 2 for each side. */
	for (size_t i = 0; i < 4; i++)
		m_block_num[i] = 2;

	/* Create two rectangles that make up the body. */
	m_boards[0] = sf::RectangleShape{ { board_width - 2 * board_curve, board_height } };
	m_boards[1] = sf::RectangleShape{ { board_width, board_height - 2 * board_curve } };

	/* Initialize each rectangle with colors and positions. */
	for (sf::RectangleShape& rect : m_boards)
	{
		rect.setFillColor(board_col);
		rect.setOrigin(0.5f * rect.getSize());
		rect.setPosition(center);
	}

	/* Initialize four circles that represent the curved board. */
	for (sf::CircleShape& circle : m_curves)
	{
		circle.setRadius(board_curve);
		circle.setFillColor(board_col);
		circle.setOrigin({ board_curve, board_curve });
	}

	/* Place each circle on the corner of the board to create the curves. */
	m_curves[0].setPosition({ center.x - 0.5f * board_width + board_curve, center.y - 0.5f * board_height + board_curve });
	m_curves[1].setPosition({ center.x + 0.5f * board_width - board_curve, center.y - 0.5f * board_height + board_curve });
	m_curves[2].setPosition({ center.x - 0.5f * board_width + board_curve, center.y + 0.5f * board_height - board_curve });
	m_curves[3].setPosition({ center.x + 0.5f * board_width - board_curve, center.y + 0.5f * board_height - board_curve });

	/* Create 42 tokens, using token size and board size to calculate the gap. */
	float gap_x{ 2 * token_radius + ((board_width - (14.0f * token_radius)) / 8.0f) };
	float gap_y{ 2 * token_radius + ((board_height - (12.0f * token_radius)) / 7.0f) };
	sf::Vector2f gap{ gap_x,gap_y };
	sf::Vector2f corner{ center.x - 0.5f * board_width - token_radius , center.y - 0.5f * board_height - token_radius };
	sf::Vector2f pos{ corner };

	for (auto& tokenArr : m_tokens)
	{
		pos.x += gap.x;
		pos.y = corner.y;
		for (auto& token : tokenArr)
		{
			pos.y += gap.y;
			token.setRadius(token_radius);
			token.setFillColor(bg);
			token.setOrigin({ token_radius, token_radius });
			token.setPosition(pos);
		}
	}

	/* Change the origin of the curved edges to the center of the screen. */
	for (sf::CircleShape& circle : m_curves)
	{
		sf::Vector2f current_pos{ circle.getPosition() };
		circle.setOrigin(center.x - current_pos.x + board_curve, center.y - current_pos.y + board_curve);
		circle.setPosition(center);
	}

	/* Change the origin of the holes to the center of the screen. */
	for (auto& tokenArr : m_tokens)
	{
		for (auto& token : tokenArr)
		{
			sf::Vector2f current_pos{ token.getPosition() };
			token.setOrigin(center.x - current_pos.x + token_radius, center.y - current_pos.y + token_radius);
			token.setPosition(center);
		}
	}

	/* Initialize the four winning tokens. */
	for (sf::CircleShape& win_token : m_winning_tokens)
	{
		win_token.setRadius(token_radius - 15.0f);
		win_token.setFillColor(Constants::win_col);
		win_token.setOrigin({ token_radius - 15.0f, token_radius - 15.0f });
	}

	/* Default each token_state to false. */
	for (auto& tokenStateArr : m_token_states)
	{
		for (auto& token_state : tokenStateArr)
		{
			token_state = TokenState::Empty;
		}
	}
}

///Note: Can overload ++ operator.
/* Increment m_rotation*/
void Board::IncrementBoardRotation()
{
	/* Use a buffer int variable to increment the enum class. */
	int rotation{ (int)m_rotation };
	++rotation;

	/* Wrap around if the enum reaches the maximum. */
	if (rotation >= (int)BoardRotation::max_rotations)
		rotation = 0;

	m_rotation = (BoardRotation)rotation;
}

///Note: Can overload ++ operator.
/* Increment m_turn. */
void Board::IncrementPlayerTurn()
{
	/* Use a buffer int variable to increment the enum class. */
	int turn{ (int)m_turn };
	++turn;

	/* Wrap around if the enum reaches the maximum. */
	if (turn >= (int)PlayerTurn::max_turns)
		turn = 0;

	m_turn = (PlayerTurn)turn;
}


