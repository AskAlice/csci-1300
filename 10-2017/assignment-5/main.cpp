// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang
//
// Assignment 5
// main.cpp

#include "Assignment5.cpp"
#include <iostream>
using namespace std;

int main(){
    float test1[3]={0.25, 1.00, 0.33};
    float test4[5]={0.25, 1.00, 0.5, 0.13, 0.63};
    int test2[] = {1,2,5,3,4};
    int test3[] = {9,8,7,6,5};
    int test5[] = {0,3,-5,4};
    string test5out[4];
    cout << "sumArray({0.25, 1.00, 0.75}, 3) " << sumArray(test1, 3) << endl;
    cout << "search({1,2,5,3,4}, 5, 5) " << search(test2, 5, 5) << endl;
    cout << "calculateDifference({1,2,5,3,4}, {9,8,7,6,5}, 5) " << calculateDifference(test2,test3, 5) << endl;
     cout << "beginning test" << endl;
     for(int i=0;i<5;i++){
        cout << test4[i] << endl;
    }
    cout << "sorting" << endl;
    sortArray(test4, 5);
    for(int i=0;i<5;i++){
        cout << (float) test4[i] << endl;
    }
    cout << "finished test" << endl;
    convert(test5,test5out,4);
    for(int i=0;i<4;i++){
        cout << test5out[i] << endl;
    }
    cout << findMedian(test4,5);
    int matrix[10][10] =
    {
    {0,1,2,3,4,5,6,7,8,9}
    ,{10,11,12,13,14,15,16,17,18,19}
    ,{20,21,22,23,24,25,26,27,28,29}
    ,{30,31,32,33,34,35,36,37,38,39}
    ,{40,41,42,43,44,45,46,47,48,49}
    ,{50,51,52,53,54,55,56,57,58,59}
    ,{60,61,62,63,64,65,66,67,68,69}
    ,{70,71,72,73,74,75,76,77,78,79}
    ,{80,81,82,83,84,85,86,87,88,89}
    ,{90,91,92,93,94,95,96,97,98,99}
    };
    cout << endl;
    simple2DMultiplication(1,matrix);
    for(int i=0; i<10;i++){
        for(int j=0; j<10;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
        simple2DMultiplication(2,matrix);
    for(int i=0; i<10;i++){
        for(int j=0; j<10;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
