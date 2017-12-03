#include <iostream>
using namespace std; //so i don't have to write std:: before cout etc
/*
Problem 1
This function takes an integer of the current population, then calculates the population in a year based on:
a birth rate of 8 births per second.
a death every 12 seconds
and a new immigrant every 33 seconds.
Returns an integer with population a year after the input.
*/
int howMany(int currentPop){
    int secondsInYear = 86400 * 365; // 86400 is number of seconds in a day. multiplied by 365 days in a year. 31,536,000
    int bornInYear = secondsInYear / 8; //3,942,000
    int deathsInYear = secondsInYear /12; // 2,628,000
    int immigrantsInYear = secondsInYear/33; //rounds to a whole number because it's an integer
    return (currentPop + bornInYear + immigrantsInYear - deathsInYear); //the forumla which calculates the gain and losses in population is returned
}
/*
Problem 2
This will take an input of time remaining in seconds and the function will ou-tput
the time as days, hours, minutes, and seconds for a 24-hour clock.
Returns nothing
*/
void howLong(int remaining){
    if(remaining > 1000000 || remaining <= 0)
        remaining = 0;
    int days = remaining / 60 / 60 / 24; // the number of days is seconds divided by number of seconds in a minute, number of minutes in an hour, and number of hours in a day. as an int it will round off to the
    int hours = remaining / 60 / 60 % 24;
    int minutes = remaining / 60 % 60;
    int seconds = remaining % 60;
    cout << "Time is " << days << " days, " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds.";
}
/* Problem 3
This will take a whole number of a tempterature in celcius and return the value in F.
*/
int howHot(int celcius){
    return (((float) (celcius * 9)/ (float)5)+32); //multiply by nine, then divide by 5, then add 32, and round down
}
 int main(){
     return 0; //main needs to exist, needs to return an int. 0 means it worked.
 }
