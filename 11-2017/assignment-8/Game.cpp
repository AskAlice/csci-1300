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
this checks for available moves, if there is a move, it makes a random number,
that is within the size of the array of available moves, as to pick a random index.
it makes that move. If the move fails, it will just say that there was an error. It doesn't ever fail though.
*/
int Game::aiMove(){
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
	return r;
}


/*
it checks if the board is empty, if so it prints the board.
then it takes an input, if the input doesn't work with stoi then it returns to the label to get a new input.
if the move fails, it returns to the label to get a new input
*/
void Game::promptPlayerToMove(){
	int a[9];
	if(brd[0].getAvailableMoves(a) == 9) brd[0].printBoard();
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

//unused minimax function.. doesn't even work, but I tried :(

int Game::max(Board b){
	int bestScore = 100;
	int bestMove;
	int move = -1;
	int score = -2;
	int moves[9];
	int i;
	bool turn = b.turn;
	if(!b.gameOver()){
		int s = b.getAvailableMoves(moves);
		for(i=0;i<s;i++){
			Board c = b;
			if(!turn) cout << " " << moves[i];
			else cout << " ( "<< moves[i] << ") ";
			c.move(turn, moves[i]);
			int o = c.score();
			cout << "score" << o;
			int sc = -max(c);
			if(sc > score){
				score = sc;
				move = moves[i];
				break;
			}
		}
	}else{
		score = 10;
	}
	if(move == -1) return -1;
	cout << endl<< score <<endl;
	if(score == 0) b.move(turn, moves[i]);
	return score;
}
