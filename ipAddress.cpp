//
//  ipAddress.cpp
//  Challenges
//
//  Created by Kevin Johar on 2018-03-06.
//  Copyright © 2018 Kevin Johar. All rights reserved.
//

#include <iostream>
using namespace std;

bool checkInputLength (string);
bool checkIPNum(int, int, int, int);
void invalid ();
unsigned long position (string, string,int);
string subStr (string,unsigned long,unsigned long,unsigned long, int);
int assignInt (string, string, string, string, int);

int main () {
    //Variable declaration for user input, and string manipulation respectively
    string input,str1,str2,str3,str4,loop("y");
    int num1(0), num2(0), num3(0), num4(0);
    size_t pos1,pos2,pos3;
    bool validity = true;
    
    //Sets delimiter
    string delim = ".";
    
    while (true) {
        //Requests user input
        cout<<"Please input an ip address and I will validate your input: ";
        cin>>input;
        
        validity = checkInputLength(input);
        
        if (validity==false) {
            break;
        }
        
        while (validity) {
        //Calls the position function to determine and assign the position of the delimiter in the inputted string
        pos1 = position(delim, input,1);
        pos2 = position(delim, input,2);
        pos3 = position(delim, input,3);
        
        //Calls the subStr function to determine and assign the respective substrings created
        str1 = subStr(input, pos1, pos2, pos3, 1);
        str2 = subStr(input, pos1, pos2, pos3, 2);
        str3 = subStr(input, pos1, pos2, pos3, 3);
        str4 = subStr(input, pos1, pos2, pos3, 4);
        
        //Assigns substrings to an int type value
        num1 = assignInt(str1, str2, str3, str4, 1);
        num2 = assignInt(str1, str2, str3, str4, 2);
        num3 = assignInt(str1, str2, str3, str4, 3);
        num4 = assignInt(str1, str2, str3, str4, 4);
        }
        
        validity = checkIPNum(num1, num2, num3, num4);
        
        if (validity==false) {
            break;
        }
    }
    
    validity = true;
    
    while (validity) {
    cout<<"\nWould you like to try again? (y/n) ";
    cin>>loop;
        
        if (loop!="n")
            main();
    }
    
    cout<<"Goodbye!"<<endl;
    
    return 0;
}

bool checkInputLength (string input) {
    //If input is not within the valid ip address size range, it is invalid
    if (input.length()<7 || input.length()>15) {
        invalid();
        return false;
    }
    
    return true;
}

bool checkIPNum (int num1, int num2, int num3, int num4) {
    //If ip address is made up of individual values greater than 255
    if ((num1/256)>1 || (num2/256)>1 || (num3/256)>1 || (num4/256)>1) {
        invalid();
        return false;
    }
    
    return true;
}

void invalid () {
    cout<<"This is an invalid ip address.\n"<<endl;
}

//Determines the positions of the delimiter "."
unsigned long position (string delim,string input,int x) {
    unsigned long pos1, pos2, pos3;
    
    pos1 = input.find(delim);
    pos2 = input.find(delim, pos1+1);
    pos3 = input.find(delim, pos2+1);
    
    switch (x) {
        case 1:
            return pos1;
        case 2:
            return pos2;
        case 3:
            return pos3;
        default:
            return 513;
    }
}

//Creates a substring for any values between delimiters
string subStr (string input, unsigned long pos1, unsigned long pos2, unsigned long pos3, int x) {
    string str1, str2, str3, str4;
    
    str1 = input.substr(0,pos1-0);
    str2 = input.substr(pos1+1,(pos2-1)-pos1);
    str3 = input.substr(pos2+1,(pos3-1)-pos2);
    str4 = input.substr(pos3+1);
    
    switch (x) {
        case 1:
            return str1;
        case 2:
            return str2;
        case 3:
            return str3;
        case 4:
            return str4;
        default:
            return "error";
            
    }
}

//Assigns substrings to an int type value
int assignInt (string str1, string str2, string str3, string str4, int x) {
    int num1, num2, num3, num4;
    
    num1 = atoi(str1.c_str());
    num2 = atoi(str2.c_str());
    num3 = atoi(str3.c_str());
    num4 = atoi(str4.c_str());
    
    switch (x) {
        case 1:
            return num1;
        case 2:
            return num2;
        case 3:
            return num3;
        case 4:
            return num4;
        default:
            return 513;
    }
}
