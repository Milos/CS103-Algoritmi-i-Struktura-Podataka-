//
//  main.cpp
//  CS103-DZ02
//
//  Created by Milos Menicanin on 12/5/16.
//  Copyright © 2016 Milos Menicanin. All rights reserved.
//


/*
 5. [C/C++] Za date prirodne brojeve a, n, m izračunati a^n mod m (traži se rešenje logaritamske složenosti).
 Ulaz 		Izlaz
 a = 7      801 (tj. 5764801 mod 1000)
 n = 8
 m = 1000
 */

#include <iostream>
using namespace std;

int isPrirodniBroj(int a, int n, int m) {
    int rezultat = 1;
    while (n >= 1) {
        rezultat *= a;
        n--;
    }
    return rezultat % 1000;
}

int main(int argc, const char * argv[]) {
   
    int rezultat = isPrirodniBroj(7, 8, 1000);
    cout << "Rezultat: " << rezultat << endl;
    
    return 0;
}
/* 
20. Oceniti vremensku složenost sledećeg algoritma:

for (i = 0; i < N; i++) {	// korak za for petlju
    
    for (j = 0; j < N; j++) {  // korak za for petlju
        t++;  // korak za inkrement
    } // korak za poslednje izvrsavanje for petlje
    
} // korak za poslednje izvrsavanje for petlje

for (k = 0; k < N; k++) { // korak za for petlju
    t++; // korak za inkrement
} // korak za poslednje izvrsavanje for petlje


Vremenska slozenost algoritma:
Broj koraka: (2n+1)*n + 1 + 2n +1 = 2n^2+n + 2n + 2 = 2n^2 + 3n + 2   za  0<= n <= N
Veliko O notacija: O(n^2) + O(n)
*/
