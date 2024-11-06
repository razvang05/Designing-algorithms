<<<<<<< HEAD
Gheorghe Marius Razvan 324CA

Problema1 ----Servere----
Pentru rezolvarea acestei probleme citesc cei 2 vectori puterile
si pragurile de alimentare.
Ca sa gasesc valoarea puterii de alimentare am ales sa apelez la grafic
facand diferenta dintre vectorii p si c si suma dintre ei pentru
a reduce intervalul de cautare pe grafic pentru a lua valori pozitive.
Am facut maximul pentru diferentele dintre c-p,cel mai din stanga maxim
si minimul dintre c+p, cel mai din dreapta minim iar apoi am facut media 
aritmetica dintre cele 2 unde am observat ca se gaseste curentul optim de
alimentare sau mai bine zis puterea.
Complexitatea este O(n) deoarece trec linear prin vectorii c si p.

Problema 2 ----Colorare----
Pentru rezolvarea acestei probleme voi citi numarul de perechi iar pe acestea
le stochez intr un vector de pereche cu nr si tipul de numere(H sau V),
functiile vor fi de tipul long long pentru ca vom lucra cu valori destul de
mari de aceea suntem nevoiti sa si folosim %MOD. Functia "powmod" o 
folosesc pentru ridicarea la putere in timp logaritmic cu complexitatea de 
O(N*logn).In "get_result vom verifica inceputul lantului de dreptunghiuri,
daca incepe cu H vom avea 6 combinari pentru primele 2 dreptunghiuri suprapuse
iar celelalte in format H vor ramane 3^(n-1) combinari de culori.Daca incepe
cu V primul dreptunghi va avea 6 posibilitati de colorare iar urmatoarele
vor avea 2^(n-1) combinari, apoi dupa ce am citit o pereche vom verifica 
perechea urmatoare cu cea precedenta pentru a vedea cum luam combinatiile.
Daca tipurile au ramas ca cele trecute pentru V lasam 2^(n) iar pentru H 3^(n),
iar daca se schimba tipul dintre perechea prezenta si cea precedenta pentru
V va fi 2^(n-1) deoarece primul V dupa H va veni 1 iar daca este H va veni
2*3^(n-1).Complexitatea algoritmului este O(n) deoarece parcurg o singura
data vectorul de perechi.

Problema 3 ----Compresie----
Pentru rezolvarea acestei probleme citesc cei 2 vectori primiti la intrare,
Parcurg primul vector si voi face sumele partiale pentru acesta stocandu-le,
pe fiecare intr un tablou.Apoi parcurg al 2 lea vector si tin intr o variabila
suma partiala temporara si voi verifica daca se afla in tabloul format la 
parcurgerea primului vector, aceasta cautare o voi face cu o cautare binara,
pentru care am creat functia binary_search.
Ca si complexitate algoritmul parcurge linear ambii vectori deci va fi
complexitate in O(N).

Problema 4 ----Criptat----
Pentru rezolvarea acestei probleme voi folosi ceva asemanator cu problema
rucsacului atunci cand trebuie sa gasesc lungimea maxima a parolei,parcurgand
descrescator pentru a nu socoti de mai multe ori un cuvant precedent.
Voi citi toate cuvintele intr un vector words,voi face frecventa
pentru fiecare litera din fiecare cuvant si le voi stoca intr un map
de N ori pentru fiecare cuvant.
Apoi parcurg fiecare litera posibila si iau toata combinatiile de parola
de lungime maxima pentru litera respectiva, acest lucru facandu l astfel:
iau un vector dp de lungimea maxima a parolei 10001,se trece prin toate
cuvintele la litera respectiva se ia lungimea si frecventa literei in acel
cuvant,se parcurge de la final vectorul pentru a nu adauga o lungime de mai
multe ori apoi verific daca se indeplineste conditia de maxim,adica fac maxim
intre lungimea curenta si lungimea + frecventa literei dominante.
Apoi verific daca numarul de aparitii al literei este mai mare decat jumatate
din lungimea parolei.
Complexitatea este O(26*10000*N) pentru ca parcurg pentru fiecare litera toate
cuvintele si mai parcurg si lungimile.

Problema 5 ----Oferta----
Pentru rezolvarea acestei probleme am folosit notiunea de programare dinamica,
utilizand un vector de costuri "cost" folosit pentru a stoca minimul necesar
cumpararii celor n produse.
Pot sa iau produsul singur,in format de 2 sau de 3.
Unul singur adaug pretul produsului la costul total calculat.
Doua produse,verific daca prin cumpararea in comun a celor 2 
si cu reducere e mai ieftina daca as cumpara separat,sau daca
cumpar 3 produse(2 cele mai scumpe si al 3 lea ieftin ) voi calcula
cele mai scumpe 2 din 3 si voi compara.
Deci costul va fi minimul pe care il calculez in ficare structura de decizie.
Complexitatea algoritmului va fi O(n) deoarece voi parcurge toate elementele
vectorului si voi faca doar verificari O(1) in interiorul parcurgerii.
=======
# PA_project1
>>>>>>> d60b940acc8ab8663a87e170a2bd2f9fc968bbb7
