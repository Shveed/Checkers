#pragma once

#include "Cell.h"
#include <map>

using map = std::map<pos, Cell>;

class Board
{
public:
	enum class MoveResult { SUCCESSFUL_MOVE, SUCCESSFUL_COMBAT, PROHIBITED };
	Board();
	~Board();
	void ResetMap();

	bool isEndReached(bool direction, pos position, size_t Size);
	size_t getSize() { return mBoardSize; }
	MoveResult MakeMove(const pos &startPos, const pos &endPos, bool direction, bool forceCombat = false);
	const map& GetMap() const { return mCells; };
	map mCells;
private:
	MoveResult CheckMove(const pos &startPos, const pos &endPos, bool direction);
	const size_t mBoardSize;
	

};

