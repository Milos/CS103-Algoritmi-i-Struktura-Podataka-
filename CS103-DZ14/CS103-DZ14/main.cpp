//
//  main.cpp
//  CS103-DZ14
//
//  Created by Milos Menicanin on 1/24/17.
//  Copyright © 2017 Milos Menicanin. All rights reserved.
//


/*
 	10.	Prijatelji sede za kružnim stolom. Listom L, čiji svaki čvor sadrži ime i pokazivač na sledeći čvor dat je njihov redosled sedenja. Ako odbrojavanje, počev od prve, svaka k-ta osoba napušta sto, ispisati redosled napuštanja stola. K je broj koji korisnik unosi sa standardnog ulaza. Izlaz treba ispisati u datoteku izlaz.txt. Program napisati u programskom jeziku C.
 */
#include <stdio.h>

struct node
{
  int num;
  struct node *next;
};

void create(struct node **, int);
void display(struct node *, FILE*);
int survivor(struct node **, int, FILE*);

void print(int, char);


#include <iostream>



int main()
{
  //Izmeniti pitanju po potrebi
  static FILE *f = fopen("/Users/milos/Desktop/izlaz.txt", "w");
  if (f == NULL)
  {
    printf("Error opening file!\n");
    exit(1);
  }
  
  struct node *head = NULL;
  int survive, skip, drugari;
  
  printf("Koliko drugara sedi za stolom? ");
  scanf("%d", &drugari);
  create(&head, drugari);


  printf("Drugari koji sede za kruznim stolom su:\n");
  
  fprintf(f, "Drugari koji sede za kruznim stolom su:\n");
  display(head, f);
  printf("k = ");
  scanf("%d", &skip);
  
  
  survive = survivor(&head, skip, f);
  printf("Poslednji je ostao %d\n", survive);
  fprintf(f, "Poslednji je ostao %d\n", survive);
  
  free(head);
  fclose(f);
  
  return 0;
}

int survivor(struct node **head, int k, FILE *f)
{
  
  struct node *p, *q;
  int i;
  
  q = p = *head;
  
  while (p->next != p)
  {
    for (i = 0; i < k - 1; i++)
    {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    printf("%d je napustio sto.\n", p->num);
    fprintf(f, "%d je napustio sto.\n", p->num);
    
    free(p);
    p = q->next;
  }
  *head = p;
  
  return (p->num);
}

void create (struct node **head, int drugari)
{
  struct node *temp, *rear;
  
  for (int i = 1; i<=drugari; i++) {
      temp = (struct node *)malloc(sizeof(struct node));
      temp->num = i;
      temp->next = NULL;
      if (*head == NULL)
      {
        *head = temp;
      }
      else
      {
        rear->next = temp;
      }
      rear = temp;
  }
  rear->next = *head;
}

void display(struct node *head, FILE *f)
{
  struct node *temp;

  temp = head;

  printf("%d   ", temp->num);
  fprintf(f, "%d   ", temp->num);
  
  temp = temp->next;
  while (head != temp)
  {
    printf("%d   ", temp->num);
    fprintf(f, "%d   ", temp->num);
    temp = temp->next;
  }
  printf("\n");
  fprintf(f, "\n");
}
