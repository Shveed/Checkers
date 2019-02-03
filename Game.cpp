#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <vector>


Game::Game() : mWhiteScore(0), mBlackScore(0), mLastPlayer(Player::NONE), bIsSurrender(false)
{
}


Game::~Game()
{
}

Game::Player Game::GetWinner() const
{
	Player winner(Player::NONE);

	
		if (mWhiteScore > mBlackScore) {
			winner = Player::WHITE;
		}
		else if (mWhiteScore < mBlackScore) {
			winner = Player::BLACK;
		}
		else {
			winner = Player::NONE;
		}
	return Player();
}

void Game::Start()
{
	mboard.ResetMap();
	// check if game is over
	while (GetWinner() == Player::NONE) {
		Board::MoveResult moveResult(Board::MoveResult::PROHIBITED);
		while (moveResult == Board::MoveResult::PROHIBITED) {
			bool direction = GetDirection();
			auto newMove = MakeIO();

			moveResult = mboard.MakeMove(newMove.first, newMove.second, direction);
		}
		//Parse Move Result
		if (moveResult == Board::MoveResult::SUCCESSFUL_COMBAT) {
			// update score
			UpdateScore();
		}
		// update last player
		//SwitchPlayer();
	}
}



bool Game::GetDirection() const
{
	bool direction;

	switch (mLastPlayer) {
	case Player::WHITE:
		direction = false;
		break;
	default:
		direction = true;
	}
	return direction;
}

movePos Game::MakeIO()
{
	// Print board
	system("cls");
	auto map = mboard.GetMap();
	mIO.DrawBoard(map);
	// Ask for a move
	if (mLastPlayer == Game::Player::WHITE) {
		auto newMove = mIO.GetMove();
		return std::move(newMove);
	}
	else {
		if (!MonteCarlo()) {
			GetWinner();
			system("pause");
		}
	}
}

/*void Game::SwitchPlayer()
{
	if (mLastPlayer == Player::WHITE) {
		mLastPlayer = Player::BLACK;
	}
	else {
		mLastPlayer = Player::WHITE;
	}
}*/

void Game::UpdateScore()
{
}


//////////////////////  HERE STARTS MONTE CARLO  //////////////////////


bool Game::MonteCarlo()
{
	
	
}


