#include <iostream>
#include <fstream>
#include <string>
using namespace std;

float avgCharsPerLine(string filename)
{
	ifstream file(filename);
	int lengths[99], lines;
	string str;
	for(lines=0;getline(file,str);lines++){
			lengths[lines] = str.length();
		}
	int sum = 0;
	for(int i=0;i<lines;i++){
		sum += lengths[i];
	}
	return sum/lines;
}

int fillArray(string filename, string array[][5]){
	ifstream file(filename);
	int lines;
	string str;
	for(lines=0;getline(file,str);lines++){
		int row = 0;
		string current;
		for(int i=0;i<str.length();i++){
			string test = ""+str[i]+str[i+1];
			if(test != ", ")
				current += char(str[i]);
			else{
				array[lines][row] = current;
				row++;
				current = "";
			}
		}		
		if(current != ""){
				array[lines][row] =  current;
			}
	}
}
