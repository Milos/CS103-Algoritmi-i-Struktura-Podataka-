//
//  main.cpp
//  CS103-DZ07
//
//  Created by Milos Menicanin on 1/5/17.
//  Copyright © 2017 Milos Menicanin. All rights reserved.
//

/*
 12. [C/C++]Napisati funkciju koja će na osnovu ulaznih stekova stek1 i stek2 stvoriti novi stek koristeći pritom sledeće pravilo da se za novi element u novom steku uvek odabere manji od elemenata na vrhu stekova stek1 i stek2. Ukoliko se jedan od stekova isprazni, onda uzeti preostale elemente iz drugog. Ulazni stekovi moraju nakon završetka funkcije ostati nepromenjeni. Funkcija ima prototip
 Stek *spoji(Stek *stek1, Stek *stek2);
 */

#include <iostream>

struct Stek {
  int data;
  struct Stek *link;
};

Stek *stek1 = NULL;
Stek *stek2 = NULL;
int x;

// Definicije
Stek *spoji(Stek *stek1, Stek *stek2);
void printStek(Stek *head);
void Push(Stek **vrh, int x);

int main() {
  
  printf ("Popunjavanje stek1 (0 = izlaz)\n");
  do {
    scanf("%d", &x);
    Push(&stek1, x);
  } while(x);
  
  printf ("Popunjavanje stek2 (0 = izlaz)\n");
  do {
    scanf("%d", &x);
    Push(&stek2, x);
  } while(x);
  
  Stek *stek = &(*spoji(stek1, stek2));
  
  printf("\nStek 3: ");
  printStek(stek);
  
  printf("\tStek 1: ");
  printStek(stek1);
  
  printf("\tStek 2: ");
  printStek(stek2);
  printf("\n");
  
  return 0;
}

void printStek(Stek * head){
  while(head){
    printf("%d->", head->data );
    head = head->link;
  }
  
  printf("NULL");
  printf("\n");
}

void Push(Stek **vrh, int x) {
  struct Stek* temp = (struct Stek*)malloc(sizeof(struct Stek*));
  temp->data = x;
  temp->link = *vrh;
  *vrh = temp;
}

Stek* spoji(Stek* stek1, Stek* stek2) {
  if (stek1 == NULL) {
    return stek2;
  } else if (stek2 == NULL) {
    return stek1;
  }
  Stek* stek; //initialise
  stek = (struct Stek*)malloc(sizeof(struct Stek*)); //alocate //new Stek (C++)
  
  if (stek1->data < stek2->data) {
    stek->data = stek1->data;
    stek->link = spoji(stek1->link, stek2);
  } else {
    stek->data = stek2->data;
    stek->link = spoji(stek1, stek2->link);
  }
  return stek;
}
