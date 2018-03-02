//
//  pronicNumbers.cpp
//  Challenges
//
//  Created by Kevin Johar on 2018-03-02.
//  Copyright © 2018 Kevin Johar. All rights reserved.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void checkPronic (int a) {
    int pronic(0);
    
    //Loop sifts through all values of i, where i*(i+1)=input
    //If such a value is found the loop is exited and that value is stored in the pronic variable
    for (int i=0 ; i<a ; i++) {
        pronic = i*(i+1);
        
        if (pronic == a) {
            break;
        }
    }
    
    //The output states true/false based on if the input is a pronic number
    cout<<a<<": "<<std::boolalpha<<(pronic==a)<<endl;
    
    return;
}

//Function to control the continuation of the program
bool loop (bool repeat) {
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
            return repeat;
    }
}

int main () {
    /*This program tells the user whether their input is a pronic number or not.
      A pronic number is one where the product of two consecutive numbers is equal to said number.
      n = x * (x+1)*/
    
    //Variable Declaration
    int input;
    bool repeat = true;
    
    cout<<"I will tell you if you've entered a pronic number or not."<<endl;
    
    //Infinite loop until user dictates exit
    while (repeat) {
        cout<<"\nPlease enter an integer: ";
        cin>>input;
        
        //Calls the function to check if the input is a pronic number
        checkPronic(input);
        
        //Calls function to ask user if they'd like to exit the program and assigns respective value to infinite loop control variable
        repeat = loop(repeat);
        
    }
    
    cout<<"Goodbye!"<<endl;
    
    return 0;
}
