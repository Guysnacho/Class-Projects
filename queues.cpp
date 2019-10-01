#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
#define MAX 10

// --------------------------------------------------------------------------------
// AUTHOR: Samuel Adetunji
// FILENAME: Lab3.cpp
// SPECIFICATION: Make 3 queues with traffic logic
// FOR: CS 2413 Data Structure Section 504
// TEST CASES for main: none, all random
// Expected output: The state of the array when needed
// Actual Output: The state of the array when needed

//TEST CASES for dropElement:
// Test case1: the arrays with their random numbers
// Input: the array and its rear
// Expected output: 0 when there was an underflow error, 1 when there wasnt
// Actual Output: 0 when there was an underflow error, 1 when there wasnt

//TEST CASES for addElement:
// Test case1: the arrays with their random numbers
// Input: the array, its new number, and its rear index
// Expected output: 0 when there was an overflow error, 1 when there wasnt
// Actual Output: 0 when there was an overflow error, 1 when there wasnt

//TEST CASES for display:
// Test case1: each array with their random numbers
// Input: the array and its rear index
// Expected output: the entire array printed to the screen
// Actual Output: the entire array printed to the screen

//TEST CASES for getNum:
// Test case1: returns a number from 100-999
// Input: none
// Expected output: and integer from 100-999

//TEST CASES for prioGet:
// Test case1: returns the priority for each new number
// Input: none
// Expected output: a number from 1-3
// --------------------------------------------------------------------------------

// NAME : dropElement
// INPUT PARAMETERS: int pri[]: the given array, int *rear: a pointer to the the rear index of the current array
// OUTPUT: 0 if there was an error, 1 if there wasn't
// PURPOSE: removes an element from the array
int dropElement(int pri[], int *rear){
  //Deletes elements fromt he front of the line
  if(*rear == 0){
    cout<<"\nUnderflow error"<<endl;
    return 0;
  }
  int hold= pri[0]; //holds the dropped element

  for(int c=0;c<*rear;c++){
    pri[c]=pri[c+1];
  }
  *rear-=1;
  return hold;
}

// NAME : addElement
// INPUT PARAMETERS: int pri[]: the given array,int num: the number to be added, int *rear: a pointer to the the rear index of the current array
// OUTPUT: 0 if there was an error, 1 if there wasn't
// PURPOSE: adds an element to the array
int addElement(int pri[], int num, int *rear){
//Adds elements as needed
  if(*(rear)==MAX-1){
    cout<<"\nOverflow error, sorry"<<endl;
    return 0;
  } else {
    pri[*rear] = num;
    *(rear)+=1;
  }
  return 1;
}

// NAME : display
// INPUT PARAMETERS: int pri[]: the given array, int *rear: a pointer to the the rear index of the current array
// OUTPUT: the entire given array printed to the counsle
// PURPOSE: displays the entire array
void display(int pri[], int rear){
  for(int c=0;c<rear;c++){
    cout<<pri[c]<< "  ";
  }
  cout<<endl;
}

// NAME : getNum
// INPUT PARAMETERS: None
// OUTPUT: returns a number from 100-999
// PURPOSE: to return a new number for the array
int getNum(){
  //Random number getter
  int rando = rand()%999 + 100;//the new random number
  if(rando>=1000)
    rando = 999;
  return rando;
}

// NAME : prioGet
// INPUT PARAMETERS: None
// OUTPUT: returns a number from 1-3
// PURPOSE: to return the priority of a new number from getNum()
int prioGet(){
  int rando = rand()%3+1;//the new random priority
  if(rando>1000)
    rando = 1000;
  return rando;
}

// NAME : main
// INPUT PARAMETERS: none
// OUTPUT: 0
// PURPOSE: begins the program, pulls all the shenanigans, initializes all variables, holds all the queue logic.
int main() {
  cout<<"Let the dice rolling begin!\n\n"<<endl;
  srand (time(NULL));
  //Initialize the array and rears
  int prione[MAX];
  int pritwo[MAX];
  int prithr[MAX];
  int orear = 0;
  int trear = 0;
  int threar = 0;

  //Simulating traffic
  int newNum, prio; //the new number and priority, subject to change
  for(;;){
    newNum = getNum();
    prio = prioGet();

    //Decide which array to add to
    if(prio==1){
      addElement(prione,newNum,&orear);
      if(orear==6)
        break;
    } else if(prio==2){
      addElement(pritwo,newNum,&trear);
      if(trear==6)
        break;
    } else if(prio==3){
      addElement(prithr,newNum,&threar);
      if(threar==6)
        break;
    } else {
      continue;
    }
  }

  cout<<"Current array state"<<endl;
  display(prione, orear);
  display(pritwo, trear);
  display(prithr, threar);

  //Complexities begin here
  int exited = 0;//number of elements that have been dropped

  for(int c = 0;c<21;c++){
    //add element
    if(exited>=20)
      break;
    newNum = getNum();
    prio = prioGet();

    //Adding one element
    if(prio==1){
      if(addElement(prione,newNum,&orear)==0)
        break;
    } else if(prio==2){
      if(addElement(pritwo,newNum,&trear)==0)
        break;
    } else if(prio==3){
      if(addElement(prithr,newNum,&threar)==0)
        break;
    }
    //check if 3 have come through
    if(c % 3 == 0){
      if(prio = prioGet()<3){
        //if the rando is less than 3, we drop 2.
        for(int count=0;count<2;count++){
          if(orear>0){
            exited+=2;
            if(dropElement(prione,&orear)== 0){
              cout<<"Underflow error"<<endl;
              exited = 100;
              count = 50;
            }
            cout<<"\nCurrent array state"<<endl;
            display(prione, orear);
            display(pritwo, trear);
            display(prithr, threar);
          } else if(trear>0){
            exited+=2;
            if(dropElement(pritwo,&trear)== 0){
              cout<<"Underflow error"<<endl;
              exited = 100;
              count = 50;
            }
            cout<<"\nCurrent array state"<<endl;
            display(prione, orear);
            display(pritwo, trear);
            display(prithr, threar);
          } else if(threar>0){
            exited+=2;
            if(dropElement(prithr,&threar)==0){
              cout<<"Underflow error"<<endl;
              exited = 100;
              count = 50;
            }
            cout<<"\nCurrent array state"<<endl;
            display(prione, orear);
            display(pritwo, trear);
            display(prithr, threar);
          }
        }
      } else if(prio==3){
        //if the rando is less than 3, we drop 4.
        for(int count=0;count<4;count++){
          if(orear>0){
            exited+=4;
            if(dropElement(prione,&orear)== 0){
              cout<<"Underflow error"<<endl;
              exited = 100;
              count = 50;
            } else {
              cout<<"\nCurrent array state"<<endl;
              display(prione, orear);
              display(pritwo, trear);
              display(prithr, threar);
            }
          } else if(trear>0){
            exited+=4;
            if(dropElement(pritwo,&trear)== 0){
              cout<<"Underflow error"<<endl;
              exited = 100;
              count = 50;
            } else {
              cout<<"\nCurrent array state"<<endl;
              display(prione, orear);
              display(pritwo, trear);
              display(prithr, threar);
            }
          } else if(threar>0){
            exited+=4;
            if(dropElement(prithr,&threar)==0){
              cout<<"Underflow error"<<endl;
              exited = 100;
              count = 50;
            } else {
              cout<<"\nCurrent array state"<<endl;
              display(prione, orear);
              display(pritwo, trear);
              display(prithr, threar);
            }
          }
        }
      }
    }
  }

  cout<<"\nCurrent array state"<<endl;
  display(prione, orear);
  display(pritwo, trear);
  display(prithr, threar);
  return 0;
}
