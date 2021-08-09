#pragma once
#include <SFML/Graphics.hpp>

namespace Constants
{
	/* Screen Variables */
	const int screen_height{ 800 };
	const int screen_width{ 1000 };
	const sf::Vector2f center{ (float)screen_width / 2.0f, (float)screen_height / 2.0f };

	/* Cosmetic Variables */
	const sf::Color bg{ sf::Color(49, 46, 43) };

	/* Board Variables */
	const sf::Color board_col{ sf::Color(208,218,228) };
	const float board_width{ 546.0f };
	const float board_height{ 468.0f };
	const float board_curve{ 50.0f };
	const float rotate_speed{ 0.1f };

	/* Token Variables */
	const sf::Color player1_col{ sf::Color(218, 27, 43) };
	const sf::Color player2_col{ sf::Color(84, 56 ,220) };
	const sf::Color player3_col{ sf::Color(87, 167, 115) };
	const sf::Color player1_col_highlight{ sf::Color(218, 27, 43, 127) };
	const sf::Color player2_col_highlight{ sf::Color(84, 56 ,220, 127) };
	const sf::Color player3_col_highlight{ sf::Color(87, 167, 115, 127) };
	const float token_radius{ 26.0f };
}