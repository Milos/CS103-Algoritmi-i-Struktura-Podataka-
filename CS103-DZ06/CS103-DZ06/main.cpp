//
//  main.cpp
//  CS103-DZ06
//
//  Created by Milos Menicanin on 1/3/17.
//  Copyright © 2017 Milos Menicanin. All rights reserved.
//

/*
 8. [C/C++]Napisati rekurzivnu funkciju koja:
 a. Zamenjuje u listi L svako pojavljivanje vrednosti informacionog polja E1 sa E2
 b. Izbacuje iz liste L prvo pojavljivanje čvora čiji je informacioni element jednak E, ako postoji.
 c. Izbacuje iz liste L sve čvorove u kojima je vrednost informacionog elementa E.
 */

#include <iostream>
#include <string>
using namespace std;

class LinkedList{
  
  struct Node {
    string x;
    Node *next;
  };
  
public:
  LinkedList(){
    head = NULL;
  }
  
  void addValue(string val) {
    Node *n = new Node();
    n->x = val;
    n->next = head;
    
    head = n;
  }
  
  string popValue(){
    if (head == NULL) {
      cout << "Null" << endl;
    };
    
    Node *n = head;
    string ret = n->x;
    
    head = head->next;
    delete n;
    return ret;
  }
  
  void print(){
    Node *temp;
    temp = head;
    while(temp){
      printf("%s->", temp->x.c_str());
      temp = temp->next;
    }
    printf("NULL");
    printf("\n");
  }
  
  void recursiveFunction(Node *head) {
    if (head == NULL) {
      return;
    }
    //    Node *tmp = new Node();
    
    if (head->x == "E1") {
      head->x = "E2";
    }
        if (head->x == "E") {
          delete head;
          recursiveFunction(head->next);
        }
        if (head->next && head->next->x == "E") {
          Node *tmp = head->next;
          head->next = tmp->next;
          delete tmp;
        }
    
    recursiveFunction(head->next);
  }
  
  void recursive(){
    recursiveFunction(head);
  }

private:
  Node *head;
};

int main() {
  LinkedList list;
  
  list.addValue("E");
  list.addValue("E1");
  list.addValue("B1");
  list.addValue("E");
  list.addValue("E1");
  list.addValue("B2");
  list.addValue("E");
  list.addValue("Z");

  //  cout << list.popValue() << endl;
  
  list.print();
  list.recursive();
  list.print();
  
  return 0;
}
