//  LinkedList.cpp
//      Expemplifies use of linked lists in C++
//
//  Author: Nathan Davis
//  CU ID: nada8251
//  GitHub Username: npdavis116
//  Hours to complete lab: Spent roughly 8 hours on this, with much help from office hours
//

#include "LinkedList.h"
#include <sstream>

// constructor, initialize class variables and pointers here if need.
// initializes the top_ptr_ variable to null
LinkedList::LinkedList(){
top_ptr_ = nullptr;
top_ptr_->prev = nullptr;
}

//deconstructor, deconstructs the list one by one
//However, unnecessary due to shared pointer
LinkedList::~LinkedList(){}

//takes data input into function and builds a new node with populated data.
shared_ptr<node> LinkedList::InitNode(string title, string type){
  shared_ptr<node> ret(new node);
  ret->title = title; 
  ret->type = type;                   
  ret->time = time;            
  return ret;                           
}

// returns string with list contents
string LinkedList::Report(){
  string ret;
  stringstream ss;
  shared_ptr<node> cursor = top_ptr_; // sets top pointer as cursor for list reading
  cout << "Your Cinematic Universe in Order: "
  while (cursor != nullptr) {         // goes through linked list and builds
    ss <<"Title: "<<cursor->title<<", Media Type: "<<cursor->type<<", Date (timeline or release): "<<cursor->time<<endl;         // string from it
    cursor = cursor->next;
  }
  ret = ss.str();                       // sets ret to string rep. of list
  return ret;                           //returns string rep. of linked list
}

// uses the append function to initiate a new node at the end of the list.
void LinkedList::AppendData(int data){
  shared_ptr<node> nube(new node);  // initiates new node
  nube->title = title; 
  nube->type = type;                   
  nube->time = time;                 // fills new node with data
  Append(nube);                     // adds new node with data to the end of the list
}
// same as append, but adds an empty node
void LinkedList::Append(shared_ptr<node> new_node){
  if(top_ptr_== NULL){    //if top pointer is empty, then adds a new node at top of list
    top_ptr_ = new_node;
  }
  else{
    shared_ptr<node> cursor = top_ptr_; // in all other cases, find null pointer 
    while(cursor->next != NULL){        // to add new node at end of list
      cursor = cursor->next; 
    }
    cursor->next = new_node;
  }
}
// similar to the append/append data functions, we use insert in insert data to insert a node
// then fill it with data
void LinkedList::InsertData(int offset, int data){
    shared_ptr<node> nube(new node); // creates new node
    nube->data = data;               // adds data to node
    Insert(offset, nube);            // uses "insert" to add new node at specified offset
}

// inserts new empty node at specified offset
void LinkedList::Insert(int offset, shared_ptr<node> new_node)
{
  if(offset < 0){ // discard any error cases
    return;
  }
  if(offset == 0){                    // sets top node if no offset
    new_node->next = top_ptr_;
    SetTop(new_node);
  }
  else {                              // for within the list use a cursor 
    int counter = 0;                  // to iterate through the list 
    shared_ptr<node> cursor = top_ptr_;
    while (cursor != nullptr && counter < offset - 1){ // until reaches end or the offset
      cursor = cursor->next;
      counter++;
    }
    if (counter != offset - 1){       // returns if offset-1 never reached or surpassed for some reason
      return;
      }
    new_node->next = cursor->next;   // sets new node pointer at cursor pointer location
    cursor->next = new_node;         // sets new node at cursor location
  }
}


// removes a node at specific offset
void LinkedList::Remove(int offset){
  shared_ptr<node> cursor(top_ptr_); // sets cursor to top pointer
  shared_ptr<node> precursor;         // precursor is used to store previous cursor

  if(offset == 0){
    top_ptr_ = cursor -> next;        // sets cursor at top if no offset
  }
  else if(offset > 0 and offset <= this->Size()){ // for all other cases,
    int i = 0;              //iterate through list until offset is reached
    while(i<offset){
      precursor = cursor;
      cursor = cursor ->next;
      i++;
    }
    
    precursor -> next = cursor -> next; // points precursor to next, going "around"
  }                             // removed node, therefofre removing it from the list
  else {
      return;   // all other cases are invalid
    }                                    
}

//counts the size of linked list using while loop and returns the size.

int LinkedList::Size(){   
  shared_ptr<node> cursor = top_ptr_;
  int size = 0;
  while(cursor != nullptr){
  cursor = cursor -> next;
  size++;
  } 
  return size;
}

//iterates through the linked list and looks for specific data point
//returns true if found, and false if not found.
bool LinkedList::Contains(int data){
  shared_ptr<node> cursor = top_ptr_;
  while(cursor != nullptr){
    if(cursor->data == data){
      return true;
    }
    cursor = cursor->next;

  }
  return false;
}

// This function is implemented for you
// It returns the top pointer
shared_ptr<node> LinkedList::GetTop(){
  return top_ptr_;
}

// This function is implemented for you
// It sets a given pointer as the top pointer
//initializes the top pointer with given pointer
void LinkedList::SetTop(shared_ptr<node> top_ptr){
  top_ptr_ = top_ptr;
}
