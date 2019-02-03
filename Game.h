#pragma once
#include"Board.h"
#include "IO.h"
#include "Cell.h"
#include <vector>

using movePos = std::pair<pos, pos>;

class Game
{
public:
	enum class Player { NONE, BLACK, WHITE };
	Game();
	~Game();
	Player GetWinner() const;
	void Start();
	bool MonteCarlo();

private:
	bool GetDirection() const;
	movePos MakeIO();
	void SwitchPlayer();
	void UpdateScore();
	size_t mWhiteScore;
	size_t mBlackScore;
	Player mLastPlayer;
	bool bIsSurrender;
	Board mboard;
	IO mIO;

	Player mPlayer = Player::WHITE;
	
};

