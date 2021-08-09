#pragma once
#include <SFML/Graphics.hpp>

/*	Refers to the possible states each token can be in on the board. It's
	either occupied by one of the three players or it is empty. */
enum class TokenState
{
	Empty = 0,
	Player_1 = 1,
	Player_2 = 2,
	Player_3 = 3,
	max_states = 4
};

/*	Refers to one of the four possible rotations the board can have when
	rotating. */
enum class BoardRotation
{
	Rotation_0 = 0, //0 Degrees.
	Rotation_1 = 1, //90 Degrees.
	Rotation_2 = 2, //180 Degrees.
	Rotation_3 = 3, //270 Degrees.
	max_rotations = 4
};

/* Refers to the three possible player turns. */
enum class PlayerTurn
{
	Player_1 = 0,
	Player_2 = 1,
	Player_3 = 2,
	max_turns = 3
};

/*	Refers to the five possible game states the game could be in, ranging from
	ongoing, won by one of the three players, or a tie. */
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
	sf::RectangleShape m_boards[2]; // Rectangles that make the bulk of the visible board.
	sf::CircleShape m_curves[4]; // Circles that create the rounded edges on the visible board.
	sf::CircleShape m_tokens[7][6]; // The 42 circles that make up the tokens on the visible board.
	sf::CircleShape m_winning_tokens[4]; // The 4 tokens that get highlighted when a game is won.

	TokenState m_token_states[7][6]; // The token states of each of the 42 tokens.
	BoardRotation m_rotation{}; // The current board rotation.
	PlayerTurn m_turn{}; // The current player turn.
	GameState m_game_state{}; // The current game state (Ongoing/ Won/ Tie).

	int m_prev_highlight[2]; // The index of the previously highlighted token.
	size_t m_block_num[4]; // The blocking numbers for each side of the board.

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

	void updateGameState(); // Check if there is a 4-in-a-row anywhere on the board.
	void setGameState(const TokenState& winner); // Set the game state using the value of a token.
	const GameState& getGameState() const { return m_game_state; } // Get the game state.
};

