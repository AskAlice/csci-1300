// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang Thurs 5pm
//
// Assignment 8
// Board.cpp

#include "Board.h"
#include <iostream>
using namespace std;

Board::Board(){
	clearBoard();
}

Board::Board(bool b){
	if(!b) turn = true;
	else turn = false;
	clearBoard();
}
Board::Board(bool s, char a, char b, char e){
	if(!s) turn = false;
	else turn = true;
	human = a;
	AI = b;
	clearBoard();
}
void Board::output(string s){
	ofstream f("log.txt",ios_base::app); //ios_base::app makes it append to the file
	f << s;
	f.close();
}
void Board::getBoard(char bd[3][3]){
	bd = board;
}

void Board::clearBoard(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			board[i][j] = empty;
		}
	}
}
bool Board::playerWon(char c){
	if(c != human && c != AI) return false;
	for(int i=0;i<3;i++){
			if(board[i][0] == c 
			&& board[i][1] == c
			&& board[i][2] == c){
				return true;
			}
			if(board[0][i] == c 
			&& board[1][i] == c
			&& board[2][i] == c){
				return true;
			}
	}
    if(board[0][0] == c 
	&& board[1][1] == c
	&& board[2][2] == c){
    	return true;
	}
	if(board[0][2] == c 
	&& board[1][1] == c
	&& board[2][0] == c){
    	return true;
	}
	return false;
}
bool Board::gameOver(){
	if(playerWon(human) || playerWon(AI)) return true;
	for(int i=0;i<3;i++){
		if(board[i][0] == empty
		|| board[i][1] == empty
		|| board[i][2] == empty)
		return false;
	}
	return true; // tie
}
void Board::printBoard(){
	int ct = 1;
	cout << "======================";
	output("======================");

	for(int i=0;i<3;i++){
		cout << endl << "|";
		output("\n|");
		for(int j=0;j<3;j++){
			cout << "  ";
			output("  ");
			if(board[i][j] == empty){
				cout << ct;	
			} 
			else{
			 cout << char(board[i][j]);
		
			}
			if(board[i][j] == human)
				output("X");
			else if(board[i][j] == AI)
				output("O");
			else
				output("-");
			cout << "   |";
			output("   |");
			ct++;
		}
		cout << endl << "======================";		
		output("\n======================");		
	} cout << endl; output("\n\n");
	if(gameOver()){
		cout << "Game Over. "; 
		output("Game Over. "); 
	if(playerWon(human)){ 
		cout << "You won!";
		output("You won!");
	}
	else if(playerWon(AI)){
		cout << "You lost!";	
		output("You lost!");	
	} 
	else{
		cout << "It's a tie!";
		output("It's a tie!");
	}
	cout << endl;
	output("\n");
	}
	

}

void Board::getAvailableMoves(bool m[3][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j] == empty) m[i][j] = true;
			else m[i][j] = false;
		}
	}
}
int Board::getAvailableMoves(int m[9]){
	int ct = 1;
	int in = 0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j] == empty){
				m[in] = ct;
				in++;
			}
			ct++;
		}
	}
	return in;
}
void Board::setHuman(char c){
	human = c;
	clearBoard();
}
void Board::setAI(char c){
	AI = c;
	clearBoard();
}
void Board::setEmpty(char c){
	empty = c;
	clearBoard();
}
bool Board::move(bool c, int p){
	if(p > 9) return false;
	if(p < 1) return false;
	int ct = 1;
	char moveChar;
	if(!c) moveChar = AI;
	else moveChar = human;
	if(turn && (moveChar == AI)){
		cout << endl << "Invalid move, it's not the AI's turn!"<<endl;
		output("\nInvalid move, it's not the AI's turn!\n");
		return false;
	}
	if(!turn && (moveChar == human)){
	cout << endl << "Invalid move, it's not your turn!"<<endl;
	output("\nInvalid move, it's not your turn!\n");
	return false;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(ct==p){
				if(board[i][j] == empty){
					 board[i][j] = char(moveChar);
					 if(moveChar == human) turn = false;
					 else if(moveChar == AI) turn = true;
					 return true;
				}
				else return false;
			}
			ct++;
		}
	}
	return true;
}
int Board::score(){
	if(playerWon(human)) return -10;
	else if(playerWon(AI)) return 10;
	return 0;
}