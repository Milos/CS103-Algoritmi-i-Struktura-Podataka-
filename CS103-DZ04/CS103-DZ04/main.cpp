//
//  main.cpp
//  CS103-DZ04
//
//  Created by Milos Menicanin on 12/24/16.
//  Copyright © 2016 Milos Menicanin. All rights reserved.
//

/*
 Zadatak 19.	Za dati niz dužine n ispitati da li u njemu postoji element koji se javlja vise od n/2 puta.
	Ulaz				Izlaz
	N = 9				Da, broj je 5
	5 7 1 1 5 5 2 5 5
 */

//Boyer-Moore’s Voting Algorithm  O(n)

int FindCandidate(int niz[], int n) {
  int maj_index = 0, count = 1;
  
  for (int i = 1; i < n-1; i++) {
    if (niz[maj_index] == niz[i]) {
      count++;
    } else {
      count --;
    }
    if (count == 0) {
      maj_index = i;
      count = 1;
    }
  }
  return niz[maj_index];
}

bool isMajority(int niz[], int n, int candidate)
{
  int i, count = 0;
  for (i = 0; i < n; i++)
    if (niz[i] == candidate)
      count++;
  if (count > n/2)
    return true;
  else
    return false;
}

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
  
  int const n = 9; // broj elemenata niza
  int niz[n] = {5,7,1,1,5,5,2,5,5};
  int candidate = FindCandidate(niz, n);
  
  if(isMajority(niz, n, candidate)) {
    cout << "Da, broj je " <<  candidate << endl;
  } else {
    cout << "Ne postoji" << endl;
  }
  
  
    return 0;
}
