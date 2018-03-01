//
//  armstrongNumbers.cpp
//  Challenges
//
//  Created by Kevin Johar on 2018-02-26.
//  Copyright © 2018 Kevin Johar. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //Char variable to control exit out of the program, dictated by the user
    char loop = 'y';
    
    //Explanation of an Armstrong number
    cout<<"An Armstrong number is one where the sum of each digit's cube is the number itself"<<endl;
    cout<<"Ex. 153, 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153\n"<<endl;
    
    //While loop to repeat program until user exits
    while (!(loop=='n')) {
        //Variable declaration
        int input,mod(0),temp(0),hold;
        
        //Recieves user input
        cout<<"I will calculate the Armstrong Number of any integer!"<<endl;
        cout<<"Please input an integer: ";
        cin>>input;

        //Holds the user input for comparison later
        hold = input;
        
        /*For loop using modular arithmetic to find the sum of each digit's cubes for the inputted number*/
        for (;input!=0; input/=10) {
            mod = input%10;
            temp=temp+(pow(mod,3));
        }
        
        //If the original number is equal to the calculated sum of the digit's cubes, armstrong num
        if (hold==temp) {
            cout<<"\nThis is an armstrong number!\n"<<endl;
        }
        
        //Otherwise not an armstrong num
        else {
            cout<<"\nThis is not an armstrong number!\n"<<endl;
        }
        
        //Asks the user if they would want to try the program again
        cout<<"Would you like to try again? (y/n):";
        cin>>loop;
        cout<<"\n";
    }
    
    return 0;
}
