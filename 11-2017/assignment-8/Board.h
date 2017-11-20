// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang Thurs 5pm
//
// Assignment 8
// Board.h

#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <fstream>
using namespace std;

class Board{
	public:
		Board();
		Board(bool); // false = ai, true = human
		Board(bool s, char a, char b, char e);
		void getBoard(char b[3][3]);
		void clearBoard();
		void printBoard();
		void getAvailableMoves(bool m[3][3]); // returns a 3x3 array of bools that show where moves can be placed.
		int getAvailableMoves(int mv[9]);
		bool playerWon(char); //checks board to see if someone won
		bool gameOver();
		int score();
		bool turn = true; // false = ai, true = human
		bool move(bool, int);
		void nextTurn(); 
		char human = 'X';
		char AI = 'O';
		char empty = '-';
		void setHuman(char);
		void setAI(char);
		void setEmpty(char);
		char getHuman();
		char getAI();
		char getEmpty();
		void output(string);

	private:
		char board[3][3];
};
#endif