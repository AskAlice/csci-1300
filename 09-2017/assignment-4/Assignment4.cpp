// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang
//
// Assignment 4
// Assignment4.cpp

#include <iostream>
using namespace std;


/*
* dist takes two parameters, str1, and str2.
* the strings must be the same length or else it will return zero.
* returns an int which is the hamming distance of the two strings.
* it uses a for loop to iterate through the strings, and if the characters don't match for a certain index, the distance increases
*/
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

/*
* similarityScore takes two parameters, str1, and str2.
* the strings must be the same length or else it will return zero.
* it returns a float using this formula:
* (stringLength - hammingDistance) / stringLength
*/
float similarityScore(string str1, string str2){
    if(str1.length() != str2.length()){
        return 0;
    }
    return (float) (str1.length() - dist(str1,str2)) / str1.length();
}

/*
* countMatches takes three parameters, a genome and a sequence to compare, strings, and a minimum score, a float.
* it counts how many matches of a certain sequence are in a genome, using a threshold of similarity.
* uses a for loop that iterates through the genome string and checks the similarity score with a substring of the genome at that position, which is the length of the sequence to compare.
* returns the count of matches found.
*/
int countMatches(string genome, string sequence1, float min_score){
    int ct = 0;
    for(int i=0; i<=genome.length()-sequence1.length();i++){
        float score = similarityScore(genome.substr(i,sequence1.length()),sequence1);
        if(score >= min_score)
            ct++;
    }
    return ct;
}

/*
* findBestMatch takes two parameters, genome and seq, both strings. and returns a float of the best similarity score found of that sequence within the genome.
* similar to countMatches, uses a for loop that iterates through the genome string and checks the similarity score with a substring of the genome at that position, which is the length of the  sequence to compare.
*/
float findBestMatch(string genome, string seq){
    float bestScore = 0;
    for(int i=0; i<genome.length();i++){
        float score = similarityScore(genome.substr(i,seq.length()),seq);
        if(score >= bestScore)
            bestScore = score;
    }
    return bestScore;
}

/*
* findBestGenome takes 4 parameters, all strings. the first three parameters are all genomes, and the last parameter is the sequence being matched in this case.
* it uses findBestMatch on each genome with the sequence.
* It will return the sequence that is the greatest.
* If the top two greatest sequences are equal, then it will return 0.
*/
int findBestGenome(string genome1, string genome2, string genome3, string seq){
    float g1 = findBestMatch(genome1,seq);
    float g2 = findBestMatch(genome2,seq);
    float g3 = findBestMatch(genome3,seq);

    if (g3 > g2 && g3 > g1)
        return 3;
    if(g2 > g3 && g2 > g1)
        return 2;
    if(g1 > g3 && g1 > g2)
        return 1;
return 0;
}
