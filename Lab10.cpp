/*
--------------------------------------------------------------------------------
AUTHOR: Samuel Adetunji
FILENAME: Lab10.cpp
SPECIFICATION: A simple hashing program that uses chaining to handle collisions
FOR: CS 2413 Data Structure Section 504
Expected output: A couple of prompts followed with a functioning hash table
Actual Output: A couple of prompts followed with a functioning hash table
Shoutouts: Shoutout to my lab teaching assistant for telling us that the array was supposed to be an array of linked lists.
Special Notes: I finally got used to typing std:: before standard functions like cout and cin
--------------------------------------------------------------------------------
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

typedef struct node{
  node* next = NULL;
  int data = 0;
}node;

int keys[] = {7,24,18,52,36,54,11,23};//Pre-provided keys, change here if you want to try different test cases
node* table[9];//The table that we'll be manipulating in a second

/*
NAME: print
Input: none
Output: none
Purpose: to print every value in the hash table
*/
void print(){
  //One loop to go through every index
  for(int c = 0;c < 9;c++){
    //A lot of the code here is just for formatting
    std::cout<<c<<": ";
    node* taxi = table[c];
    for(int d = 0; ; d++){
      if(taxi-> data ==0){
        std::cout<<"\n";
        break;
      }
      std::cout<<taxi->data;
      if(taxi->next==NULL){
        std::cout<<"\n";
        break;
      }
      std::cout<<" -> ";
      taxi = taxi->next;
    }
  }
}

/*
NAME: push
Input: address of the current linked list node and its key
Output: none
Purpose: to push values to the linked list
*/
void push(node* current, int key){
  node* taxi = current;
  for(int c = 0;c<9;c++){
    if(taxi->data==0){
      taxi->data = key;
      break;
    } else if(taxi->next != NULL){
        taxi = taxi->next;
    } else {
      taxi->next = (node*)malloc(sizeof(node));
      taxi->next->data = key;
      return;
    }
  }
}

/*
NAME: chainSlot
Input: address of the current table slot being addressed
Output: none
Purpose: to handle chaining while we build the table
Note: In hindsight, I'm pretty sure this is a useless function.
*/
void chainSlot(int index, int key){
  //First we address Null slots in the array
  if(table[index] == NULL){
    return;
  }
  //Now we push the key to the index and
  if(table[index]!= NULL){
    push(table[index], key);
  }
}

/*
NAME: buildTable
Input: none
Output: none
Purpose: to build the hash table
*/
void buildTable(){
  //This is to initialize each index. I was getting problems before doing this.
  for(int c = 0;c < 9; c++){
    table[c]=(node*)malloc(sizeof(node));
  }
  //We'll loop through the keys and assign addresses as needed
  for(int c = 0; c<9;c++){
    int address = keys[c]%9;
    chainSlot(address, keys[c]);
  }
}

/*
NAME : main
Input: none
Output: returns a zero
Purpose: Start the program, provide a menu for the user.
*/
int main(int argc, char const *argv[]) {
  std::cout <<"*This is a simple hash table exercise. Its built to handle 9 unique addresses. The hash function is as follows*"<<std::endl<<"h(k) = k mod m with m being the number of addresses and k being the key.";

  //Build unneccesary menu
  int select = 0;
  while(select < 3) {
    std::cout<<"\nHeres a menu even though the program doesn't really need it.\n\n0. Build hash table.\n1. Display table\n2. Quit\nPlease input your command (0-2): ";
    std::cin>>select;
    if(select == 2)
      break;
    switch (select) {
      case 0: buildTable();
      break;
      case 1: print();
      //Formatting
      std::cout<<std::endl;
      break;
      case 2: break;
      break;
    }
  };
  return 0;
}
