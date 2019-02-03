#include "stdafx.h"
#include "MonteCarlo.h"
#include "Board.h"
#include "Game.h"
#include "Cell.h"


MonteCarlo::MonteCarlo()
{
}


MonteCarlo::~MonteCarlo()
{
}

void MonteCarlo::method()
{
	size_t movable = 0;
	size_t whites = 0;
	std::vector <pos> movables;

	const size_t boardSize = 8;

	// Check if the checkers are movable, count them and create an array of them //

	for (size_t x = 0; x < boardSize; x++) {
		for (size_t y = 0; y < boardSize; y++) {
			pos currPos(x, y);
			if (mboard.mCells.at(currPos).GetState() == Cell::State::WHITE) {
				whites++;
				if ((mboard.mCells.at(pos(currPos.first - 1, currPos.second + 1)).GetState() == Cell::State::BLANK &&
					currPos.first - 1 >= 0 && currPos.first - 1 < 8 && currPos.second + 1 >= 0 && currPos.second + 1 < 8) ||
					(mboard.mCells.at(pos(currPos.first + 1, currPos.second + 1)).GetState() == Cell::State::BLANK &&
						currPos.first + 1 >= 0 && currPos.first + 1 < 8 && currPos.second + 1 >= 0 && currPos.second + 1 < 8) ||
						(mboard.mCells.at(pos(currPos.first - 1, currPos.second + 1)).GetState() == Cell::State::BLACK &&
							mboard.mCells.at(pos(currPos.first - 2, currPos.second + 2)).GetState() == Cell::State::BLANK &&
							(currPos.first - 2) >= 0 && (currPos.first - 2 < 8) && (currPos.second + 2 >= 0) && (currPos.second + 2 < 8)) ||
							(mboard.mCells.at(pos(currPos.first + 1, currPos.second + 1)).GetState() == Cell::State::BLACK &&
								mboard.mCells.at(pos(currPos.first + 2, currPos.second + 2)).GetState() == Cell::State::BLANK&&
								currPos.first + 2 >= 0 && currPos.first + 2 < 8 && currPos.second + 2 >= 0 && currPos.second + 2 < 8)) {
					movables.push_back(currPos);
					movable++;
				}
			}
		}
	}

	if (movable > 0) {
		size_t randomElem = size_t(rand()) % movable;
		bool LeftOrRight = rand() % 2 == 0;
		// TRUE = LEFT ////// FALSE = RIGHT //
		pos randomCheckerPos(movables.at(randomElem).first, movables.at(randomElem).second);


		if (LeftOrRight) { // TO THE LEFT
			if (mboard.mCells.at(pos(randomCheckerPos.first - 1, randomCheckerPos.second + 1)).GetState() == Cell::State::BLANK) {
				mboard.mCells.at(pos(randomCheckerPos.first - 1, randomCheckerPos.second + 1)).SetState(Cell::State::WHITE);
				mboard.mCells.at(pos(randomCheckerPos.first, randomCheckerPos.second)).SetState(Cell::State::BLANK);
			}
			else if (mboard.mCells.at(pos(randomCheckerPos.first - 1, randomCheckerPos.second + 1)).GetState() == Cell::State::BLACK &&
				mboard.mCells.at(pos(randomCheckerPos.first - 2, randomCheckerPos.second + 2)).GetState() == Cell::State::BLANK) {
				mboard.mCells.at(pos(randomCheckerPos.first, randomCheckerPos.second)).SetState(Cell::State::BLANK);
				mboard.mCells.at(pos(randomCheckerPos.first - 1, randomCheckerPos.second + 1)).SetState(Cell::State::BLANK);
				mboard.mCells.at(pos(randomCheckerPos.first - 2, randomCheckerPos.second + 2)).SetState(Cell::State::WHITE);
				mWhiteScore++;

			}
			else {
				if (mboard.mCells.at(pos(randomCheckerPos.first + 1, randomCheckerPos.second + 1)).GetState() == Cell::State::BLANK) {
					mboard.mCells.at(pos(randomCheckerPos.first + 1, randomCheckerPos.second + 1)).SetState(Cell::State::WHITE);
					mboard.mCells.at(pos(randomCheckerPos.first, randomCheckerPos.second)).SetState(Cell::State::BLANK);
				}
				else if (mboard.mCells.at(pos(randomCheckerPos.first + 1, randomCheckerPos.second + 1)).GetState() == Cell::State::BLACK &&
					mboard.mCells.at(pos(randomCheckerPos.first + 2, randomCheckerPos.second + 2)).GetState() == Cell::State::BLANK) {
					mboard.mCells.at(pos(randomCheckerPos.first, randomCheckerPos.second)).SetState(Cell::State::BLANK);
					mboard.mCells.at(pos(randomCheckerPos.first + 1, randomCheckerPos.second + 1)).SetState(Cell::State::BLANK);
					mboard.mCells.at(pos(randomCheckerPos.first + 2, randomCheckerPos.second + 2)).SetState(Cell::State::WHITE);
					mWhiteScore++;
				}
			}
		}
		else { // TO THE RIGHT
			if (mboard.mCells.at(pos(randomCheckerPos.first + 1, randomCheckerPos.second + 1)).GetState() == Cell::State::BLANK) {
				mboard.mCells.at(pos(randomCheckerPos.first + 1, randomCheckerPos.second + 1)).SetState(Cell::State::WHITE);
				mboard.mCells.at(pos(randomCheckerPos.first, randomCheckerPos.second)).SetState(Cell::State::BLANK);
			}
			else if (mboard.mCells.at(pos(randomCheckerPos.first + 1, randomCheckerPos.second + 1)).GetState() == Cell::State::BLACK &&
				mboard.mCells.at(pos(randomCheckerPos.first + 2, randomCheckerPos.second + 2)).GetState() == Cell::State::BLANK) {
				mboard.mCells.at(pos(randomCheckerPos.first, randomCheckerPos.second)).SetState(Cell::State::BLANK);
				mboard.mCells.at(pos(randomCheckerPos.first + 1, randomCheckerPos.second + 1)).SetState(Cell::State::BLANK);
				mboard.mCells.at(pos(randomCheckerPos.first + 2, randomCheckerPos.second + 2)).SetState(Cell::State::WHITE);
				mWhiteScore++;
			}
			else {
				if (mboard.mCells.at(pos(randomCheckerPos.first - 1, randomCheckerPos.second + 1)).GetState() == Cell::State::BLANK) {
					mboard.mCells.at(pos(randomCheckerPos.first - 1, randomCheckerPos.second + 1)).SetState(Cell::State::WHITE);
					mboard.mCells.at(pos(randomCheckerPos.first, randomCheckerPos.second)).SetState(Cell::State::BLANK);
				}
				else if (mboard.mCells.at(pos(randomCheckerPos.first - 1, randomCheckerPos.second + 1)).GetState() == Cell::State::BLACK &&
					mboard.mCells.at(pos(randomCheckerPos.first - 2, randomCheckerPos.second + 2)).GetState() == Cell::State::BLANK) {
					mboard.mCells.at(pos(randomCheckerPos.first, randomCheckerPos.second)).SetState(Cell::State::BLANK);
					mboard.mCells.at(pos(randomCheckerPos.first - 1, randomCheckerPos.second + 1)).SetState(Cell::State::BLANK);
					mboard.mCells.at(pos(randomCheckerPos.first - 2, randomCheckerPos.second + 2)).SetState(Cell::State::WHITE);
					mWhiteScore++;
				}

			}
		}
		mLastPlayer = Game::Player::WHITE;
		mBlackScore = 12 - whites;
		return true;
	}
	else {
		mLastPlayer = Game::Player::WHITE;
		return false;
	}
	
}



