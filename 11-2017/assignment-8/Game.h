// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang Thurs 5pm
//
// Assignment 8
// Game.h

#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <fstream>
#include "Board.h"
using namespace std;

class Game{
	public:
		Game();
		void newGame();
		Board getBoard();
		bool hasWinner();
		int aiMove();
		void promptPlayerToMove();
		int minimax(Board);
		int max(Board);
		int min(Board);
		int score(Board); //// win = 10, lose = -10, tie = 0
		void setTurn(bool);
		void swapTurn();
		bool getTurn();
		string config[4][2];
	
	private:
		int scores[5]; // win = 10, lose = -10, tie = 0. used for minimax algo
		int aiMoves[9][5]; //coords of ai moves. used for minimax algo
		char aiChar;
		char humanChar;
		char emptyChar;
		Board brd[]; // this array *could* save every state of the game as it goes on, BUT i think that's silly. For this project the array isn't really needed. I would have made a class of "Move" that board uses arrays of but I just figured that class wouldn't have enough methods.
};
#endif