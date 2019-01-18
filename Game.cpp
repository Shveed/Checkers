#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>


Game::Game() : mWhiteScore(0), mBlackScore(0), mLastPlayer(Player::NONE), bIsSurrender(false)
{
}


Game::~Game()
{
}

Game::Player Game::GetWinner() const
{
	Player winner(Player::NONE);

	if (bIsSurrender) {
		if (mLastPlayer == Player::WHITE) {
			winner = Player::BLACK;
		}
		else if (mLastPlayer == Player::BLACK) {
			winner = Player::WHITE;
		}
	}
	else {
		if (mWhiteScore == 12) {
			winner = Player::WHITE;
		}
		else if (mBlackScore == 12) {
			winner = Player::BLACK;
		}
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
		SwitchPlayer();
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
	auto newMove = mIO.GetMove();
	return std::move(newMove);
}

void Game::SwitchPlayer()
{
	if (mLastPlayer == Player::WHITE) {
		mLastPlayer = Player::BLACK;
	}
	else {
		mLastPlayer = Player::WHITE;
	}
}

void Game::UpdateScore()
{
	if (mLastPlayer == Player::WHITE) {
		mBlackScore++;
	}
	else {
		mWhiteScore++;
	}
}
