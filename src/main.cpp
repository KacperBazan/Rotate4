#include <SFML/Graphics.hpp>
#include "MyConstants.hpp"
#include "MyRandom.hpp"
#include "Board.hpp"
#include <iostream>

int main()
{
	/* Window Vars */
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(Constants::screen_width, Constants::screen_height), "Rotate4 by Kacper Bazan", sf::Style::Close, settings);

	/* Project Vars */
	Board board{};

	while (window.isOpen())
	{
		/* Checks if window is ever closed */
		sf::Event window_event{};
		while (window.pollEvent(window_event))
		{
			if (window_event.type == sf::Event::Closed)
				window.close();
		}

		if (board.getGameState() == GameState::Ongoing)
		{
			board.highlight((sf::Vector2f)(sf::Mouse::getPosition(window)), window);
			board.updateGameState();
		}

		board.draw(window);
	}
}