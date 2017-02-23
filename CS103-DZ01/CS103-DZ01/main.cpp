//
//  main.cpp
//  CS103-DZ01
//
//  Created by Milos Menicanin on 12/4/16.
//  Copyright © 2016 Milos Menicanin. All rights reserved.
//


/*
Problem: Napisati program kojim se stampaju svi brojevi od 1000 do 10 000 koji imaju osobinu da su deljivi sa brojem koji se dobija izbacivanjem cifara desetica i hiljada iz tog istog broja
----------------------------------------------------------------------------------------------------------
Resenje:
desetica = (broj / 10) % 10
hiljada = (broj / 1000) % 10

delilac = broj - hiljada * 1000
delilac = delilac - desetica * 10
delilac = (delilac / 10) + delilac % 10
resenje = if delilac nije 0 AND broj % delilac == 0 then print
*/

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    for (int broj = 1000; broj < 10000; broj++) {
        int desetica = (broj / 10) % 10;
        int hiljada = (broj / 1000) % 10;
        
        int delilac = broj - hiljada * 1000;
        delilac = delilac - desetica * 10;
        delilac = (delilac / 10) + delilac % 10;

        if ((delilac != 0) && (broj % delilac == 0) ) {
            cout << broj << endl;
        }
    }
    return 0;
}
