// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang
//
// Assignment 4
// Assignment4.cpp

#include <iostream>
using namespace std;

int dist(string str1, string str2){
    if(str1.length() != str2.length()){
        cout << "Length Mismatch with " << str1 << " and " << str2 <<  "(Lengths of " << str1.length() << " and " << str2.length() << ")" << endl;
        return 0;
    }
    int diff = 0;
    for(int i=0; i < str1.length(); i++){
        if(str1[i] != str2[i])
            diff++;
    }
	return diff;
}

float similarityScore(string str1, string str2){
    if(str1.length() != str2.length()){
        return 0;
    }
    return (float) (str1.length() - dist(str1,str2)) / str1.length();
}

int countMatches(string genome, string sequence1, float min_score){
    string matching = "";
    int ct = 0;
    for(int i=0; i<genome.length();i++){
        float score = similarityScore(genome.substr(i,sequence1.length()),sequence1);
        if(score >= min_score)
            ct++;
    }
    return ct;
}

float findBestMatch(string genome, string seq){
    float bestScore = 0;
    for(int i=0; i<genome.length();i++){
        float score = similarityScore(genome.substr(i,seq.length()),seq);
        if(score >= bestScore)
            bestScore = score;
    }
    return bestScore;
}

int findBestGenome(string genome1, string genome2, string genome3, string seq){
    float g1 = findBestMatch(genome1,seq);
    float g2 = findBestMatch(genome2,seq);
    float g3 = findBestMatch(genome3,seq);
    if (g3 >= g2 && g3 >= g1)
        return 3;
    if(g2 >= g3 && g2 >= g1)
        return 2;
    if(g1 >= g3 && g1 >= g2)
        return 1;
return 0;
}
