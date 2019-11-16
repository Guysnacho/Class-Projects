/*
// --------------------------------------------------------------------------------
// AUTHOR: Samuel Adetunji
// FILENAME: Lab8.cpp
// SPECIFICATION: Make a binary min heap
// FOR: CS 2413 Data Structure Section 504
// Expected output: A menu with the expression heap's available functions
// Actual Output: A menu with the expression heap's available functions
// Shoutouts: Special thanks to the textbook for useful psuedocode. Also special thanks to Kau Shal for the display code
// I repurposed it into C++ code
// Special Notes - I used old code from my Lab6 to help with the display
// --------------------------------------------------------------------------------
*/

#include <math.h>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int arr[] = {28,12,17,5,7,22,13,12,4,11,16};//11 items

void min_heapify(int height, int index){
  int smol = index;
  int left = (2*index)+1;
  int right = (2*index)+2;

  if(left< height && arr[left] < arr[smol])
    smol = left;

  if(right <height && arr[right] < arr[smol])
    smol = right;

  if(smol != index){
    int hold = arr[index];
    arr[index] = arr[smol];
    arr[smol] = hold;

    min_heapify(height, index);
  }
}

/*
NAME: buildHeap
Input: none
Output: none
Purpose: To help build the initial heap
*/
void buildIt(){
  //Set the last node of the heap that wont be a leaf
  int last = (11/2)-1;

  //I repeated the heapify because it didn't completely work going through it once.
  for(int c = last; c >= 0; c--){
    min_heapify(11, c);
  }
  //Heapify 2
  for(int c = last; c >= 0; c--){
    min_heapify(11, c);
  }
  //Heapify 3
  for(int c = last; c >= 0; c--){
    min_heapify(11, c);
  }
  //Heapify 4
  for(int c = last; c >= 0; c--){
    min_heapify(11, c);
  }
}

/*
NAME: printIt
Input: none
Output: none
Purpose: To print out the heap
*/
void printIt(){
  for(int c = 0; c<11; c++){
    for(int d = 0;d < pow(2,c)&&(d+pow(2,c))< 11; d++){
      cout<<arr[d+(int)pow(2,c)-1]<<"   ";
    }
    cout<<endl;
  }
}

/*
NAME: deleteRoot
Input: none
Output: none
Purpose: To delete the root of the heap
*/
void deleteRoot(){
  int index, size;
  //Find the last index in the array
  for(int c = (sizeof(arr)/sizeof(arr[0]))-1;c>=0;c--){
    if(arr[c] != NULL){
      index = size = c;
      break;
    }
  }

  //Delete the root
  arr[0] = arr[index];

  //Set the last node of the heap that wont be a leaf
  int last = (index/2)-1;

  for(int c = last; c >= 0; c--){
    min_heapify(index + 1, c);
  }

  for(int c = last; c >= 0; c--){
    min_heapify(index + 1, c);
  }

  for(int c = last; c >= 0; c--){
    min_heapify(index + 1, c);
  }

  for(int c = last; c >= 0; c--){
    min_heapify(index + 1, c);
  }
}

int main() {
  cout<<"Weeeeelcome to this awesome heap program! ......It took me a while for some reason.";
  //Display a fire menu for the user
  int select = 0;
  while(select < 3) {
    cout<<"\n\n0. Build a Min-Heap\n1. Delete the current root\n2. Display the heap\n3. Quit\nPlease input your command (0-3): ";
    cin>>select;
    if(select == 3)
      break;
    switch (select) {
      case 0: buildIt();
      break;
      case 1: deleteRoot();
      break;
      case 2: printIt();
      break;
      case 3: break;
      break;
    }
  };
  return 0;
}
