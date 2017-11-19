#include "Game.h"
// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang Thurs 5pm
//
// Assignment 8
// Play.cpp

#include <chrono>
#include <ctime>
int main(){
	ofstream f("log.txt");
	auto t = std::chrono::system_clock::now();
	time_t tt = std::chrono::system_clock::to_time_t(t);
	f << "Log of game at " << ctime(&tt) << endl << endl;
	Game g;
	while(!g.hasWinner()){
		g.promptPlayerToMove();
		g.aiMove();
	}
return 0;
}
