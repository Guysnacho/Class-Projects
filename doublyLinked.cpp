#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

typedef struct node {
  int data;
  struct node *next;
  struct node *backw;
} node;

struct node *top, *bottom;

struct node* getNew(){
  struct node *newN;
  newN = (struct node*)malloc(sizeof(node));
  return newN;
}

void add(int newNum){
  //Get the new node
  if(bottom != top){
    bottom->next = getNew();
    //Make the new node, the bottom node
    bottom->next->data = newNum;
    bottom->next->backw = bottom;
    bottom = bottom->next;
  } else {
    //Initialize bottom with the new number and with the top as its previous
    bottom = getNew();
    bottom->data = newNum;
    bottom->backw = top;
    //Set top's next to bottom
    top->next = bottom;
  }

  cout<<"Aaaaand, done!"<<endl;
}

//Come back to this
void deleteLast(){
  //No need to make a brand new node here. Just move bottom backa and delete the old bottom

  //Check if bottom = top
  if(bottom == top && top== NULL){
    cout<<"Sorry, underflow error"<<endl;
    return;
  } else {
    bottom->next = bottom;
    bottom = bottom->backw;
    free(bottom->next);
    bottom->next= NULL;
  }
}

void print(){

}

void reverse(){

}

int main() {
  //Initialize the starting node
  top = (struct node*)malloc(sizeof(node));
  bottom = top;
  top->backw = NULL;
  top->next = bottom;

  //Prompt the user to add something to the first node
  cout<<"Lets make a doubly-linked list.\nFirst off, what's the first number you want to throw into it? - ";
  cin>>top->data;
  cout<<"\nAlright, thank you. Now we can start!";

  //Make a standard menu
  int select = 0;
  while(select < 4) {
    printf("\n\n0. Add a node to the beginning\n1. Remove the last node\n2. Print the doubly linked list\n3. Reverse the list\n4. Quit\nPlease unput your command (0-4): ");
    scanf("%d", &select);
    if(select == 4)
      break;
    switch (select) {
      case 0:int newNum;
        cout<<"Okay, what's the new number? - ";
        cin>>newNum;
        add(newNum);
        break;
      case 1:deleteLast();
        break;
      case 2:print();
        break;
      case 3: reverse();
        break;
      case 4: break;
      break;
    }
  };

  return 0;
}
