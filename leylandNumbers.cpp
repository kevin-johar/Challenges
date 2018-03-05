//
//  leylandNumbers.cpp
//  Challenges
//
//  Created by Kevin Johar on 2018-03-05.
//  Copyright © 2018 Kevin Johar. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

/*
 A leyland number is one where it can be calculated by
 a^b + b^a
 where a,b are greater than 1
 */

//Function that calculates whether the input is a leyland number and returns the respective bool value
bool leylandNum (int num) {
    //Variable declaration
    int a, b, val1, val2, sum;
    
    //Nested for loop structure to simultaneously change value of a and b
    //Very inefficient algorithm for soving for very large inputs (5 digits)
    //IMPROVE CODE ****************
    for (a = 2; a < num; a++) {
        for (b = 2 ; b<num; b++) {
            val1 = pow(b,a);
            val2 = pow(a,b);
            sum = val1 + val2;
        
            if (sum == num) {
                return true;
            }
        }
    }
    return false;
}

int main () {
    //Variable declaration
    int input;
    char loop('y');
    bool leyland;

    //Infinite loop structure to allow for user control
    while (!(loop == 'n')) {
        cout<<"Enter a number: "; cin>>input;
        
        //Assigns the bool value the called function, leyLandNum returns (answers yes or no)
        leyland = leylandNum (input);
        
        if (leyland) {
            cout<<"\n"<<input<<" is a Leyland number!";
        }
        
        else {
            cout<<"\n"<<input<<" is not a Leyland number!";
        }
        
        cout<<"\nDo you want to try again? (y/n)";
        cin>>loop;
        cout<<endl;
    }
}
