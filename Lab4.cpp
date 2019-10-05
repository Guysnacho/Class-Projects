#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
#define max 1000 // The maximum number of elements
int top = -1; //The top index of the stack
char st[max]; // The soon to be populated stack

// --------------------------------------------------------------------------------
// AUTHOR: Samuel Adetunji
// FILENAME: Lab4.cpp
// SPECIFICATION: Convert base 10 numbers to base from 2-27
// FOR: CS 2413 Data Structure Section 504
// TEST CASES for main: base 2 and base 16, base 10 - 5, 15
// Expected output: the converted number
// Actual Output: The converted number
// Contributions: Code for push and display from my Lab2.cpp. Slightly modified the display but left the push the same i believe
// --------------------------------------------------------------------------------

// NAME : push
// INPUT PARAMETERS: the stack array and the new value
// OUTPUT: None
// PURPOSE: adds a new character to the stack
void push(char st[], char var){
  top++;
  st[top] = var;
}

// NAME : display
// INPUT PARAMETERS: the stack array
// OUTPUT: none
// PURPOSE: prints the entire stack backwards
void display(char st[]){
  if(top==-1)
    cout<<"*Tumbleweed flies in the distance*";
  else {
    for(int c=top;c >= 0;c--){
      cout<<st[c];
    }
  }
  cout<<endl;
}

// NAME : convert
// INPUT PARAMETERS: the current base ten number and the base we're converting to
// OUTPUT: *unused* returns a pointer to the array
// PURPOSE: a recursive function that converts the base 10 number to whatever base
char* convert(int baseTen, int conBase){
  //cout<<(char)(c+5);
  int hold2 = baseTen/conBase;
  if(baseTen < conBase){
    int hold = baseTen%conBase;
    if(conBase>9){
      if(hold>9){
        push(st, (char)(hold+55));
      } else {
        push(st, (char)(hold+48));
      }
    }
    if(conBase<=9)
      push(st, (char)(hold+48));
    return st;
  }
  int hold = baseTen%conBase;
  if(hold>9){
    push(st,(char)(hold+55));
    convert(hold2,conBase);
  } else {
    push(st, (char)(hold+48));
    convert(hold2,conBase);
  }
}

// NAME : main
// INPUT PARAMETERS: none
// OUTPUT: returns a zero
// PURPOSE: initializes the starting baseTen and conversion base numbers. also prompts the user to input values
int main() {
  cout<<"Alriiighty then, lets convert some numbers"<<endl<<"Please enter a base 10 number - ";

  int baseTen, conBase = 0;
  cin>>baseTen;
  cout<<endl<<"Please enter the conversion base - ";
  cin>>conBase;

  cout<<"Your base "<<conBase<<" representation of the number "<<baseTen<<" is: ";
  convert(baseTen, conBase);
  display(st);
  return 0;
}
