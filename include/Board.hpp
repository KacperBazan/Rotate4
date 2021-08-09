#pragma once
#include <SFML/Graphics.hpp>
#include "MyConstants.hpp"

enum class TokenState
{
	Empty = 0,
	Player_1 = 1,
	Player_2 = 2,
	Player_3 = 3,
	max_states = 4
};

enum class BoardRotation
{
	Rotation_0 = 0, //0 Degrees.
	Rotation_1 = 1, //90 Degrees.
	Rotation_2 = 2, //180 Degrees.
	Rotation_3 = 3, //270 Degrees.
	max_rotations = 4
};

enum class PlayerTurn
{
	Player_1 = 0,
	Player_2 = 1,
	Player_3 = 2,
	max_turns = 3
};

enum class GameState
{
	Ongoing = 0,
	Player_1_Won = 1,
	Player_2_Won = 2,
	Player_3_Won = 3,
	Tied = 4,
	max_states = 5
};

class Board
{
private:
	sf::RectangleShape m_boards[2];
	sf::CircleShape m_curves[4];
	sf::CircleShape m_tokens[7][6];
	sf::CircleShape m_winning_tokens[4];

	TokenState m_token_states[7][6];
	BoardRotation m_rotation{};
	PlayerTurn m_turn{};
	GameState m_game_state{};

	int m_prev_highlight[2];
	size_t m_block_num[4];

public:
	Board();
	void draw(sf::RenderWindow& window); // Draw the SMFL elements to the screen.
	void rotate(sf::RenderWindow& window); // Rotate the board 90 degrees.

	bool cursorOnBoard(sf::Vector2f cursor); // Returns true if the player's cursor is on the board.
	bool isValidCol(int col); // Returns true if the collumn is valid given blocking number rules.
	int highestSpot(int col); // Returns the highest possible spot a player may place their token.
	void highlight(sf::Vector2f cursor, sf::RenderWindow& window); // Highlights the hovered collumn.
	void dropToken(int slot, int highest_spot); // Changes the state of the token slot.

	void calcBlockingNumbers(); // Calculates the blocking numbers for the board.
	void IncrementBoardRotation(); // Increments the Board Rotation (m_rotation).
	void IncrementPlayerTurn(); // Increments the Player Turn value (m_turn).

	void updateGameState();
	void setGameState(const TokenState& winner);
	const GameState& getGameState() const { return m_game_state; }
};

