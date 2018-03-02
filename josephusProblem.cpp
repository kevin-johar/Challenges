//
//  josephusProblem.cpp
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

void explain () {
    cout<<"My creater has tasked me with solving the Josephus Problem."<<endl;
    cout<<"In the josephus problem, N people are standing in a circle,"<<endl;
    cout<<"where person 1 kills person 2 with a sword. Person 1 then"<<endl;
    cout<<"passes the sword to person 3 who kills person 4. This"<<endl;
    cout<<"continues until 1 person remains\n"<<endl;
}

int main () {
    //Variable declaration/initialization
    //ppl - user input representing number of people in Josephus' Problem
    int ppl,section1(0),section2(1),remaining(1),temp(1);
    
    explain();
    
    cout<<"Enter a number (N): ";
    cin>>ppl;
    
    while (true) {
        if (ppl >= section1 && ppl <= section2) {
            break;
        }
        section1 = section2;
        section2 = section2 + (pow(2, temp));
        
        temp++;
    }
    
    remaining = ((ppl - section1)*2)-1;
    
    cout<<"Person #"<<remaining<<" is the last one remaining."<<endl;
    
    return 0;
}
