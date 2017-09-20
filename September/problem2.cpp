// Author: Alice Knag
// Recitation: CSCI 1300-210 X. Zhang
//
// Assignment 3
// Problem 2

#include <iostream>
#include <math.h>
using namespace std;

/*
* windChillCalculator takes two parameters, airTemp, and windSpeed. Both floats
* It then uses the formula 35.74+0.6215T-35.75(V^0.16)+0.4275T(V^0.16) to return a float of the Wind Chill.
* In C++ parenthesis must be used to maintain order of operations.
*/
float windChillCalculator(float airTemp, float windSpeed){
	return (35.74 + (0.6215*airTemp) - (35.75*(pow(windSpeed,0.16)))+((0.4275*airTemp)*(pow(windSpeed,0.16))));
}

/*
* This function takes a three parameters:
* T - The air temperature
* lowWind, highWind - The lower and upper bounds of the wind speeds
* windSpeedStep - the rate per iteration that the windspeed should increase in the while loop
* calls windChillCalculator in a loop that iterates through the wind speeds based on the windSpeed step and the Low and high windspeed bounds.
* outputs the wind chill, the temperature, the wind speed in mph, however many times it needs to to go between the low speed and high speed.
*/
void printWindChill(float T, float lowWind, float highWind, float windSpeedStep){

	float currentWind = lowWind;
	while(currentWind <= highWind){
	float V = currentWind;
	float chill = windChillCalculator(T,currentWind);
	cout << "The wind chill is " << chill << " degrees F for an air temperature of " << T << " degrees F" << " and a wind speed of " << V << " mph." << endl;
	currentWind += windSpeedStep;
	}	
}

/*
* main algorithm
* calls printWindChill using the values 30.0 degrees, 5mph as the low wind speed, 10mph as the high wind speed, and 1 mph as the wind speed step.
* returns 0 as to indicate successful execution. 
*/
int main(){
	printWindChill(30.0, 5.0, 10.0, 1.0);
	return 0;
}