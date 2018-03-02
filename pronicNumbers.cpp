//
//  pronicNumbers.cpp
//  Challenges
//
//  Created by Kevin Johar on 2018-03-02.
//  Copyright © 2018 Kevin Johar. All rights reserved.
//

#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

//Improved version of code to work without a loop
void improvedPronic (int a) {
    //Since i*(i+1) is almost equal to i^2, then the sqrt of i gives us the lesser
    //of the two consecutive values.
    int pronic = pow(a,0.5);
    
    //This assigns the var pronic, the value i*(i+1)
    pronic = pronic*(pronic+1);
    
    //The output states true/false based on if the input is a pronic number
    //Boolalpha changes the numerical value (0 or 1) to the alphabetical value (true or false)
    cout<<a<<": "<<std::boolalpha<<(pronic==a)<<endl;
}

//Function to control the continuation of the program
bool loop () {
    char again;
    
    //Requests user input regarding the continuation of the program
    cout<<"\nWould you like to try again? (y/n) ";
    cin>>again;
    
    switch (again) {
            // Program exits
        case 'n':
            return false;
            // Program continues
        default:
            return true;
    }
}

/*This program tells the user whether their input is a pronic number or not.
 A pronic number is one where the product of two consecutive numbers is equal to said number.
 n = x * (x+1)*/
int main () {
    //Variable Declaration
    int input;
    bool repeat = true;
    
    cout<<"I will tell you if you've entered a pronic number or not."<<endl;
    
    //Infinite loop until user dictates exit
    while (repeat) {
        cout<<"\nPlease enter an integer: ";
        cin>>input;
        
        //Calls the improved function to check if the input is a pronic number
        improvedPronic(input);
        
        //Calls function to ask user if they'd like to exit the program and assigns respective value to infinite loop control variable
        repeat = loop();
        
    }
    
    cout<<"Goodbye!"<<endl;
    
    return 0;
}
