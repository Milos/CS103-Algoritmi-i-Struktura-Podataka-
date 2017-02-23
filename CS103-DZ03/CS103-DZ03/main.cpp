//
//  main.cpp
//  CS103-DZ03
//
//  Created by Milos Menicanin on 12/17/16.
//  Copyright © 2016 Milos Menicanin. All rights reserved.
//


/*
Napisati program u C-u koji učitava niz realnih brojeva od n elemenata i realan broj x. 
Napisati rekurzivnu funkciju PoslednjaPojava koja vraća najveći indeks elemenata niza koji je jednak broju x, a ako ga nema vraća -1. Iz glavnog programa pozvati funkciju PoslednjaPojava.
*/

#include <iostream>
using namespace std;
int x;


int poslednjaPojava(int niz[], int n) {
    int index = n-1;
    //Baze Cases
    if (n == 0) {
        return -1;
    }
    if (niz[index] == x) {
        return index;
    }
    //Recursive Case
    return poslednjaPojava(niz, n-1);
}

int main(int argc, const char * argv[]) {
    
    //  Case 1
//    x = 2;
//    int const n = 1; // broj elemenata niza
//    int niz[n] = {2};
//    cout << poslednjaPojava(niz, n) << endl;
    
    //    Case 2
//    x = 2;
//    int const n = 0; // broj elemenata niza
//    int niz[n] = {};
//    cout << poslednjaPojava(niz, n) << endl;
    
    //    Case 3
    x = 2;
    int const n = 4; // broj elemenata niza
    int niz[n] = {1,2,2,3};
    cout << poslednjaPojava(niz, n) << endl;
    
    return 0;
}
