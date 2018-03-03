//
//  uglyNumbers.cpp
//  Challenges
//
//  Created by Kevin Johar on 2018-03-03.
//  Copyright © 2018 Kevin Johar. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

/*
 Function that runs the algorithm to solve for and return the exponents (x,y,z)
 in the equation -> Ugly = a^x * b^y * c^z
 */
//Function recieves user input as well as one which prime factor is being checked for
int expCalc (int input, int num) {
    //Check acts as a temp value to dictate for how long the function runs
    //Count keeps track of the exponent value, increasing by 1 each time the loop runs
    int check(0), count(0);
    while (check == 0) {
        check = input % num;
        
        if (check == 0) {
            input = input/num;
            count++;
        }
    }
    return count;
}

//Prints program description as a header
void header () {
    cout<<"----------------------------------------------------------"<<endl;
    cout<<" I will tell you if the inputted number is an ugly number."<<endl;
    cout<<" An ugly number is one with only 2,3 and 5 as prime factors."<<endl;
    cout<<"----------------------------------------------------------"<<endl;
}

int main () {
    //Variable declaration
    int input, two, three, five, ugly;
    char loop = 'n';
    
    //Prints header
    header();
    
    //Infinite loop
    while (!(loop == 'y')) {
        //Asks for user input
        cout<<"\nEnter a value to check if it's an Ugly Number: ";
        cin>>input;
        
        /*
         Calls expCalc function to solve for the value of each exponent (x,y,z) in
         Ugly = a^x * b^y * c^z
         */
        two = expCalc(input, 2);
        three = expCalc(input, 3);
        five = expCalc(input, 5);
        
        //With exponent values, the equation allows us to calculate a number using
        //only the prime factors involved in that number
        ugly = pow(2,two) * pow(3, three) * pow(5, five);
        
        //If the calculated value is equal to the inputted value, this means the
        //input value can be made by a combination of the prime factors (2,3,5)
        //and is an ugly number
        if (ugly == input) {
            cout<<endl<<input<<" is an ugly number."<<endl;
        }
        
        //Otherwise the input value is not an ugly number
        else {
            cout<<endl<<input<<" is not an ugly number."<<endl;
        }
        
        //User input to exit infinite loop
        cout<<"\nDo you want to exit? (y/n)";
        cin>>loop;
    }
}
