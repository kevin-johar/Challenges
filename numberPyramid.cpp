//
//  numberPyramid.cpp
//  Challenges
//
//  Created by Kevin Johar on 2018-02-26.
//  Copyright © 2018 Kevin Johar. All rights reserved.
//

#include <iostream>
using namespace std;

int main () {
    int num, check(1), spaces;
    
    cout<<"Please input an int value: ";
    cin>>num;
    spaces = num;
    
    //First for loop is considering how many rows there are in the pyramid based off user input
    for (int i=0 ; i<num ; i++) {
        for (int j=1;j<spaces;j++) {
            cout<<"-";
        }
        spaces--;
            
        for (int k=1 ; k<=num ; k++) {
            cout<<k;
        }
        cout<<endl;
    }
}
             
