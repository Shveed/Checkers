#pragma once
#include <utility>
#include <map>
#include "Cell.h"


class Cell;
using pos = std::pair<size_t, size_t>;
using movePos = std::pair<pos, pos>;
using map = std::map<pos, Cell>;

class IO
{
public:
	IO();
	~IO();
	static movePos GetMove();
	static void DrawBoard(const map& board);
private:
	static std::string CastState(Cell::State);
};

