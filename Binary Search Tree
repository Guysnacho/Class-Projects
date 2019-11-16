// --------------------------------------------------------------------------------
// AUTHOR: Samuel Adetunji
// FILENAME: Lab6.cpp
// SPECIFICATION: Make a binary search tree with basic functions
// FOR: CS 2413 Data Structure Section 504
// Expected output: A menu with the tree's available functions
// Actual Output: A menu with the tree's available functions
// Shoutouts: Special thanks to my prof Mario Pitalua Rodriguez for the
// psuedocode on some of these functions. Also to Phyley CS on youtube for the
// queue explanation
// --------------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <queue>
using namespace std;

typedef struct branch {
  int data;
  struct branch *left = NULL;
  struct branch *right = NULL;
} branch;

//My messy attempt at queue functions from Lab3
/*
// NAME : dropElement
// INPUT PARAMETERS: int pri[]: the given array, int *rear: a pointer to the the rear index of the current array
// OUTPUT: 0 if there was an error, 1 if there wasn't
// PURPOSE: removes an element from the array
int dropElement(branch* pri[], int *rear){
  //Deletes elements fromt he front of the line
  if(*rear == 0){
    cout<<"\nUnderflow error"<<endl;
    return 0;
  }
  branch* hold= pri[0]; //holds the dropped element

  for(int c=0;c<*rear;c++){
    pri[c]=pri[c+1];
  }
  *rear-=1;
  return hold->data;
}

// NAME : addElement
// INPUT PARAMETERS: int pri[]: the given array,int num: the number to be added, int *rear: a pointer to the the rear index of the current array
// OUTPUT: 0 if there was an error, 1 if there wasn't
// PURPOSE: adds an element to the array
int addElement(branch* pri[], branch* num, int *rear){
//Adds elements as needed
  if(*(rear)==16-1){
    cout<<"\nOverflow error, sorry"<<endl;
    return 0;
  } else {
    pri[*rear] = num;
    *(rear)+=1;
  }
  return 1;
}
*/
// NAME: getNew
// Input: none
// Output: a new random number
// Function to get a new random number
int newNum(){
  return rand()%50+1;
}

// NAME: insert
// Input: the root node of the tree, a new integer
// Output: none
// Purpose: adds a new branch to the tree
void insert(branch* nSeed, int num){
  //Check if we were passed a null tree
  if(nSeed == NULL){
    nSeed = (branch*)malloc(sizeof(branch));
    nSeed->data = num;
    return;
  }
  //Simple recursive insertion
  if(num < nSeed->data){
    if(nSeed->left!= NULL){
      insert(nSeed->left, num);
    } else if(nSeed->left == NULL){
      nSeed->left = (branch*)malloc(sizeof(branch));
      nSeed->left->data = num;
      return;
    }
  } else if(num > nSeed->data){
    if(nSeed->right!= NULL){
      insert(nSeed->right, num);
    } else if(nSeed->right == NULL){
      nSeed->right = (branch*)malloc(sizeof(branch));
      nSeed->right->data = num;
      return;
    }
  }
}

// NAME: newTree
// Input: none
// Output: a new filled up binary tree
// Purpose: builds a new tree with random numbers from 1-50
branch* newTree(){
  //Initialize the tree and add an int to the root node
  branch* seed = (branch*)malloc(sizeof(branch));

  //Fill up the tree with 15 more elements
  for(int c = 0; c <15; c++){
    int num = newNum();
    cout<<num<<" ";
    insert(seed, num);
  }
  return seed;
}

// NAME: findLargestNode
// Input: the root node of the tree
// Output: the branch with the largest integer
// Purpose: Just to find the largest node in the tree
branch* findLargestNode(branch* Seed){
  if(Seed == NULL || Seed->right == NULL)
    return Seed;

  return findLargestNode(Seed->right);
}

// NAME: Delete
// Input: the root node of the tree, the integer to be deleted
// Actual Output: A prompt if it has been found and deleted or not
// Purpose: Deletes the last node in the list
void Delete(branch* Seed, int num){
  if(Seed == NULL){
    cout<<num<<" isn't in this tree, sorry."<<endl;
    return;
  } else if(num < Seed->data){
    Delete(Seed->left, num);
  } else if(num > Seed->data){
    Delete(Seed->right, num);
  } else if (Seed->left && Seed->right){
    branch* temp = findLargestNode(Seed->left);
    Seed->data = temp->data;
    Delete(Seed->left, temp->data);
  } else {
    branch* temp = Seed;
    if(!temp->left && !temp->right){
      Seed = NULL;
    } else if(Seed->left != NULL){
      Seed = Seed->left;
    } else {
      Seed = Seed->right;
    }
    free(temp);
  }
}

// NAME: tracePath
// Input: a pointer to the trace path array in find(), the number of indecies in the array
// Actual Output: A printed list of the path taked to get to the sought after branch
// Purpose: Print out the path for the tree
void tracePath(int* path, int index){
  for(int c = 0; c < index;c++){
    cout<<*(path+c)<<" -> ";
  }
}

// NAME: find
// Input: the root node of the tree, the integer to be found
// Output: The branch that we were looking for
// Purpose: Locate and print a path to a particular branch
branch* find(branch* Seed, int num){
  int path[10], slots = 0;
  branch* ant = Seed;
  while(ant != NULL){
    path[slots] = ant->data;
    slots++;
    if(ant->data == num){
      cout<<"Found it."<<endl;
      tracePath(&path[0], slots);
      return Seed;
    } else if(ant == NULL){
      cout<<"Sorry, your item isn't in here..."<<endl;
      return ant;
    }
    if(num < ant->data){
      if(ant->left != NULL){
        ant = ant->left;
      } else {
        cout<<"Sorry, your item isn't in here..."<<endl;
        return NULL;
      }
    } if(num > ant->data){
        if(ant->right != NULL){
        ant = ant->right;
      } else {
        cout<<"Sorry, your item isn't in here..."<<endl;
        return NULL;
      }
    }
  }
  return ant;
}

// NAME : Display
// INPUT PARAMETERS: the root node of the tree
// OUTPUT: The entire tree printed out
// PURPOSE: displays the tree currerntly
void Display(branch* Seed){
  if(Seed == NULL)
    return;
  queue<branch*> q;
  q.push(Seed);
  q.push(NULL);
  for(;;){
    branch* ant = q.front();
    q.pop();
    if(ant != NULL){
      cout<<ant->data<< " ";
      if(ant->left != NULL)
        q.push(ant->left);
      if(ant->right != NULL){
        q.push(ant->right);
      } else{
        cout << "\n";
        if(q.empty())
          break;
        q.push(NULL);
      }
    }
  }
}

// NAME : main
// INPUT PARAMETERS: none
// OUTPUT: returns a zero
// PURPOSE: Start the program, provide a menu for the user.
int main() {
  //Get the random number seed
  srand (time(NULL));
  //Initialize the tree

  cout<<"Alright, lets make trees!"<<endl;
  branch* currTree;
  //Make a standard menu
  int select = 0;
  while(select < 4) {
    cout<<"\n0. Create an integer binary tree.\n1. Remove a specific node\n2. Find an item\n3. Display tree.\n4. Quit.\nPlease unput your command (0-4): ";
    cin>>select;
    if(select == 4)
      break;
    switch (select) {
      //Build the tree
      case 0: cout<<endl<<"Alright, one second while I build this..."<<endl;
      currTree = newTree();
      break;

      //Delete from the tree
      case 1: cout<<"Okay, what do you want deleted? - ";
      int num;
      cin>>num;
      Delete(currTree, num);
      cout<<endl<<"Aaaaaaand, done"<<endl;
      break;

      //Find something in the tree
      case 2: cout<<"Sweet, what are you looking for? - ";
      cin>>num;
      if(find(currTree, num)){
        cout<<"I found a branch with the integer "<<num<<endl;
      } else {
        cout<<"I couldn't find a branch with the integer. Sorry. UwU "<<num<<endl;
      }
      break;

      //Display the tree
      case 3: cout<<"Here is your current binary search tree."<<endl;
      Display(currTree);
      break;

      case 4: break;
      break;
    }
  };
  return 0;
}
