// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang Thurs 5pm
//
// Assignment 8
// Game.cpp


#include "Game.h"
#include <fstream>
#include <iostream>


/*
common split function like desecribed on the practicum sheet.
*/
int split(string str, char pat, string words[],int size){
    string current;
    int count = 1;
    if(str == ""){
        count = 0;
    }
    unsigned i=0;
    while(i<str.length()){ // make me use while loops why dont 'cha
        if(count-1 > size)
            return count;
        if(char(str[i]) != pat){
            current += str[i];
        }else{
            words[count-1] = current;
            current = "";
            count++;
        }
        i++;
    }
    if(current != ""){
        words[count-1] = current;
    }
    return count;

}

/*
makes the board, opens config file, reads it using getline and split, and then sets the config accordingly
*/
Game::Game(){
	Board bd;
	brd[0] = bd;
	ifstream f("config.txt");
	string line;
	showScores = false;
	if(f.is_open()){
		for(int i=0; getline(f, line); i++){
			int sz = split(line,':',config[i],2);
		}
		for(int j=0;j<4;j++){
			if(config[j][0] == "EmptyChar"){
				brd[0].setEmpty(config[j][1][0]);
			}
			else if(config[j][0] == "humanChar"){
				brd[0].setHuman(config[j][1][0]);
			}
			else if(config[j][0] == "showScores"){
				int a;
				try{
					a = stoi(config[j][1]);
					if(a != 1) a = 0;
					showScores = false;
				}
				catch(exception e){
					a = 0;
					showScores = false;
				}
				if(a == 1){
					showScores = true;
				}
			}
			if(config[j][0] == "AIChar"){
				brd[0].setAI(config[j][1][0]);
			}
		}
	}
}
/*
returns the board object from the array.
*/
Board Game::getBoard(){
	return brd[0];
}
/*
returns true if there is a winner or a tie.
*/
bool Game::hasWinner(){
	if (brd[0].gameOver()) return true;
	else return false;
}

/*
minimax takes a board as a paramater, and returns the best move, 1-9.
It makes an array of all the possible moves that the AI would take in the imminent turn, then tries all of them recursively,
going as deep as a whole game would last, to determine which moves are good based on the best score of the end of 
the tree search. So say 4, 6, and 9 all have the same score of zero, it will pick 9 because that was the last move
it tried. It will echo the scores of each move if you enable it in the config.txt with the showScores property.
*/
int Game::minimax(Board b){
	int bestScore = 100;
	int bestMove;
	int moves[9];
	int s = b.getAvailableMoves(moves);
	int i;
	if(showScores)
		cout << "Possible Moves:" << endl;
	for(i=0;i<s;i++){
		brd[1] = b;
		if(showScores)
			cout << moves[i];
		brd[1].move(false,moves[i]);
		int score = max(brd[1]);
		if(showScores)
			cout << " score: [" << score << "]";
		if(score <= bestScore){
			bestScore = score;
			bestMove = moves[i];
		}
		if(showScores)
			cout << endl;
	}
	return bestMove;
}

/*
this function is called by minimax and min, it emulates a user's move in the next turn
essentially swapping back and forth between ai and user via max() and min() until the end of the game is reached.
Each move is scored based on whether there's a winner (and whom that is) or not. Lower score is better for the AI,
higher score is better for human.
*/
int Game::max(Board b){
	if(b.gameOver()) return b.score();
	int moves[9];
	int bestScore = -1000;
	int s = b.getAvailableMoves(moves);
	for(int i=0;i<s;i++){
		brd[1] = b;
		brd[1].move(true,moves[i]);
		int score = min(brd[1]);
		if(score >= bestScore){
			bestScore = score;
		}
	}
	return bestScore;
}
/*
this function is called by max, it emulates the AI's move in the next turn
essentially swapping back and forth between ai and user via max() and min() until the end of the game is reached.
Each move is scored based on whether there's a winner (and whom that is) or not. Lower score is better for the AI,
higher score is better for human.
*/
int Game::min(Board b){
	if(b.gameOver()) return b.score();
	int moves[9];
	int bestScore = 1000;
	int s = b.getAvailableMoves(moves);
	for(int i=0;i<s;i++){
		brd[1] = b;
		brd[1].move(false,moves[i]);
		int score = max(brd[1]);
		if(score <= bestScore){
			bestScore = score;
		}
	}
	return bestScore;
}

/*
this checks available moves. If there are none, it prints the board and returns -1. otherwise it will use the
minimax funciton to calculate the best move then print it. In comments are an alternate AI that uses rand() */
int Game::aiMove(){
	int a[9];
	int m = brd[0].getAvailableMoves(a);
	if(m < 0)
	{
		brd[0].printBoard();
		return -1;
	}
	int bestMove = minimax(brd[0]);
	
	brd[0].move(false,bestMove);
	brd[0].printBoard();
	
	/*
	int a[9];
	int r;
	srand(time(0));
	int m = brd[0].getAvailableMoves(a);
	if(m > 0)
		r = rand() % m;
	else {brd[0].printBoard(); return -1;}
	bool success = brd[0].move(false,a[r]);
	if(!success){
		cout << "error";
	}
	brd[0].printBoard();
	*/
	return 1;
}


/*
it checks if the board is empty, if so it prints the board.
then it takes an input, if the input doesn't work with stoi then it returns to the label to get a new input.
if the move fails, it returns to the label to get a new input
*/
void Game::promptPlayerToMove(){
	int a[9];
	if(brd[0].getAvailableMoves(a) == 9)
		brd[0].printBoard();
	label:
		string i;
		cout << "Please enter a number 1-9 to pick a spot: ";
		cin >> i;
		int m;
		try{
			m = stoi(i);
		}
		catch(exception e){
			goto label;
		}
		bool s = brd[0].move(true, m);
		if(!s) goto label;
}
int Game::score(Board b){
	if(b.playerWon(b.human)) return -10;
	else if(b.playerWon(b.AI)) return 10;
	return 0;
}
