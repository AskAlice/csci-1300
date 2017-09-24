// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang
//
// Assignment 4
// main.cpp
#include <iostream>
using namespace std;

int distance(string const& str1, string const& str2){
	if(str1.length() != str2.length()){
		cout << "strings are different lengths, can't calculate distance" << endl;
		return 0;
	}
	int diff = 0;
	int i = 0;
	while(i < str1.length()){
		if(!(str1[i] == str2[i]))
			diff += 1;
        i++;
    }
    return diff;
}

int main(){
cout << distance("ATTC","ATTG");
}
