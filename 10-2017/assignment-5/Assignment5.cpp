// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang
//
// Assignment 5
// Assignment5.cpp
#include <iostream>
#include <cmath>

using namespace std;

float sumArray(float array[], int size){
    float result = 0;
    for(int i=0;i<size;i++){
        result += array[i];
    }
    return result;
}

int search(int array[], int size, int target){
    for(int i=0;i<size;i++){
        if(array[i] == target)
            return i;
    }
    return -1;
}

float calculateDifference(int a[], int b[],  int size){
    float difference = 0;
    for(int i=0;i<size;i++){
        difference = (float) pow((a[i]-b[i]),2);
    }
    return difference;
}

void sortArray(float unsortedArray[], int size){
    for(int i=size-1;i>0;i--){
        for(int j=0; j < i; j++){
            if(unsortedArray[j] > unsortedArray[j+1]){
                float temp = unsortedArray[j+1];
                unsortedArray[j+1] = unsortedArray[j];
                unsortedArray[j] = temp;
            }
        }

    }
}

void copyArray(float source[], int size, float dest[]){
    for(int i=0;i<size;i++){
        dest[i]=source[i];
    }
}

void convert(int rating[], string text[], int size){
    for(int i=0;i<size;i++){
        switch(rating[i]){
            case 0: text[i]="Not-read"; break;
            case -5: text[i]="Terrible"; break;
            case -3: text[i]="Disliked"; break;
            case 1: text[i]="Average"; break;
            case 3: text[i]="Good"; break;
            case 5: text[i]="Excellent"; break;
            default: text[i] = "INVALID"; break;

        }
    }
}

float findMedian(float array[], int size){
    float median;
    for(int i=0;i<=size/2;i++){
        median = array[i];
    }
    return median;
}

void simple2DMultiplication(int multiplier, int matrix[10][10]){
    for(int i=0; i<10;i++){
        for(int j=0; j<10;j++){
            matrix[i][j] = matrix[i][j] * multiplier;
        }
    }
}
