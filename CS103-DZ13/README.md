
# DZ13

[8.] Traži se prva pojava uzorka **p=abcabd** u tekstu **s=abcabbabbabcabd**.  
a. Izračunati brojeve pomeranja uzorka - tabelu koja se koristi za algoritam KMP.  
 b. Izračunati broj pokušaja i broj poređenja karaktera?  



## a. Izracunavanje brojeva pomeranja uzorka  
**Uzorak**: *abcabd*  
####Prefix tabela:

| *i* | 1 | 2 | 3 | 4 | 5 | 6 |
|:--|:--|:--|:--|:--|:--|:--|
| *Uzorak[i]* | a | b | c | a | b | d |
| *Prefix[i]* |  |  |  |  |  |  |

1. **Slovo *a*** (**a**bcabd)
: Za slovo **a** (prvo slovo) nema prefiksa ni sufiksa, tako da je vrednost pomeranja **0**.

2. **Slovo *b*** (**ab**cabd)
: Za slovo **b** jedini prefiks je *a*, a jedini sufiks je *b*, tako da je vrednost pomeranja **0** pošto nisu isti.  

3. **Slovo *c*** (**abc**abd)
: Za slovo **c** mogući prefiksi su: *a*,*ab* a mogući sufiksi su *c*,*bc* tako da je vrednost pomeranja **0** pošto nisu isti.  

4. **Slovo *a*** (**abca**bd)
: Za slovo **a** mogući prefiksi su: *a*,*ab*,*abc* a mogući sufiksi su *a*,*ca*,*bca* tako da je vrednost pomeranja **1** pošto je *a* i prefiks i sufiks.  
  
5. **Slovo *b*** (**abcab**d)
: Za slovo **b** mogući prefiksi su: *a*,*ab*,*abc*,*abca* a mogući sufiksi su *b*,*ab*,*cab*,*bcab* tako da je vrednost pomeranja **2** pošto je *ab* i prefiks i sufiks.  

**Slovo *d*** (**abcabd**)
: Za slovo **d** mogući prefiksi su: *a*,*ab*,*abc*,*abca*,*abcab* a mogući sufiksi su *d*,*bd*,*abd*,*cabd*,*bcabd* tako da je vrednost pomeranja **0** pošto nisu isti.

####Prefix tabela (nakon izračunavanja broja pomeraja):

| *i* | 1 | 2 | 3 | 4 | 5 | 6 |
|:--|:--|:--|:--|:--|:--|:--|
| *Uzorak[i]* | a | b | c | a | b | d |
| *Prefix[i]* | 0 | 0 | 0 | 1 | 2 | 0 |

## b. Izračunati broj pokušaja i broj poređenja
  
1. abcab*b*abbabcabd  
abcabd  
Prvih 5 karaktera se poklapaju. Onda se proveravava 6. karakter. Pošto se 6. karakter ne poklapa. Uzorak se pomera u desno za vrednost i=6. U tabeli možemo videti da je broj pomeraja za tu vrednost 0, tj. pomeramo u desno za 1 po default-u.  
`brojPoredjenja += 6;`  
`brojPokusaja++;`

2. abcabbabbabcabd  
_abcabd  
Pošto se 1. karakter ne poklapa. Uzorak se pomera u desno za vrednost i=1. U tabeli možemo videti da je broj pomeraja za tu vrednost 0, tj. pomeramo u desno za 1 po default-u.  
`brojPoredjenja++;`  
`brojPokusaja++;`
3. abcabbabbabcabd  
__abcabd  
Pošto se 1. karakter ne poklapa. Uzorak se pomera u desno za vrednost i=1. U tabeli možemo videti da je broj pomeraja za tu vrednost 0, tj. pomeramo u desno za 1 po default-u.  
`brojPoredjenja++;`  
`brojPokusaja++;`
4. abcabbabbabcabd  
___abcabd  
Pošto se 3. karakter ne poklapa. Uzorak se pomera u desno za vrednost i=3. U tabeli možemo videti da je broj pomeraja za tu vrednost 0, tj. pomeramo u desno za 1 po default-u.  
`brojPoredjenja += 3;`  
`brojPokusaja++;`
5. abcabbabbabcabd  
____abcabd  
Pošto se 1. karakter ne poklapa. Uzorak se pomera u desno za vrednost i=1. U tabeli možemo videti da je broj pomeraja za tu vrednost 0, tj. pomeramo u desno za 1 po default-u.  
`brojPoredjenja++;`  
`brojPokusaja++;`
6. abcabbabbabcabd  
_____abcabd  
Pomera se u desno (i=1).  
`brojPoredjenja++;`  
`brojPokusaja++;`
7. abcabbabbabcabd  
______abcabd  
Pomera se u desno (i=3).  
`brojPoredjenja += 3;`  
`brojPokusaja++;`

8. abcabbabbabcabd  
_______abcabd  
Pomera se u desno (i=1).  
`brojPoredjenja++;`  
`brojPokusaja++;`

9. abcabbabbabcabd  
________abcabd  
Pomera se u desno (i=1).  
`brojPoredjenja++;`  
`brojPokusaja++;`

10. abcabbabbabcabd  
_________abcabd  
Uzorak je pronađen (Početni indeks: i=10)  
`brojPoredjenja += 6;`  
`brojPokusaja++;`


