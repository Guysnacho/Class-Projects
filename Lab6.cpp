#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

typedef struct branch {
  int data;
  struct branch *left = NULL;
  struct branch *right = NULL;
} branch;

//Function to get a new random number
int newNum(){
  return rand()%50+1;
}

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

branch* findLargestNode(branch* Seed){
  if(Seed == NULL || Seed->right == NULL)
    return Seed;

  return findLargestNode(Seed->right);
}

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

void tracePath(int path[], int slots){
  for(int c = 0; c< slots;c++){
    cout<<path[slots]<<" -> ";
  }
}

branch* find(branch* Seed, int num){
  int path[10], slots = 0;
  branch* ant = Seed;
  while(ant != NULL){
    path[slots] = ant->data;
    slots++;
    if(ant->data == num){
      cout<<"Found it."<<endl;
      tracePath(path, slots);
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
      break;

      case 4: break;
      break;
    }
  };
  return 0;
}
