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
    char loop = 'y';
    
    cout<<"An Armstrong number is one where the sum of each digit's cube is the number itself"<<endl;
    cout<<"Ex. 153, 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153\n"<<endl;
    
    while (!(loop=='n')) {
        int input,mod(0),temp(0),hold;
        cout<<"I will calculate the Armstrong Number of any integer!"<<endl;
        cout<<"Please input an integer: ";
        cin>>input;

        hold = input;
        
        for (;input!=0; input/=10) {
            mod = input%10;
            temp=temp+(pow(mod,3));
        }
        
        if (hold==temp) {
            cout<<"\nThis is an armstrong number!\n"<<endl;
        }
        
        else {
            cout<<"\nThis is not an armstrong number!\n"<<endl;
        }
        
        cout<<"Would you like to try again? (y/n):";
        cin>>loop;
        cout<<"\n";
    }
    
    return 0;
}
