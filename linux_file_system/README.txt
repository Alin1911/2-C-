Andrei Alin-Ionuț 313CC Tema-1

Am decis sa impart tema in 3 fisiere.
Voi vorbi despre ele in ordinea marimi si complexitatii.

Primul este fisierul "file.h" in care se afla structurile folosite, am decis sa 
folosesc liste simplu inlantuite pentru aceeasta tema.

Al 2-lea fisier "list.c" este fisierul care contine functia principala "main",
in ea am implementat un "du while" pentru citirea de la tastatura in continuu, 
am folosit apoi un "switch case" pentru compara si decide ce comanda a introdus
utilizatorul, pentru a gasi cazul am implementat if-uri, apoi in functie 
de cazul in care ne aflam urmeaza sa se apeleze functia corespunzatoare din 
fisierul "list.h".

Al 3-lea fisier "list.h", este fisierul care contine functiile apelate din 
"list.c", acum voi prezenta fiecare functie:

-create_fs corespunzatoare comenzi "create fs" ea primeste ca argument un 
pointer de tip "Directory" aloca memorie si initializeaza directorul "/";

-delete_fs corespunzatoare comenzi "delete fs" ea primeste ca argument un 
pointer de tip "Directory" si elibereaza memoria alocata directorului "/",
cand aceasta este apelata programul din main iese din "do while" si programul se
inchide;

-touch corespunzatoare comenzi "touch nume continut" aceasta are doua argumente
un pointer de tip "Directory" ce reprezinta directorul curent si un pointer
de tip "File" ce reprezinta noul fisier, verificam in ce stadiu se afla lista
de fisiere din directorul curent daca, daca nu este vida cautam locul unde 
trebuie inserat fisierul, daca trebuie undeva in lista cautam locul si inseram
sau daca trebuie la inceput inseram simplu la inceputul listei de fisiere, daca 
lista este vida fiserul e pus simplu ca prim element al listei

-mkdir corespunzatoare comenzi "mkdir nume" aceasta are doua argumente
un pointer de tip "Directory" ce reprezinta directorul curent si un al 2-lea
pointer de tip "Directory" ce reprezinta noul director, verificam in ce stadiu 
se afla lista de directoare din directorul curent daca, daca nu este vida cautam 
locul unde trebuie inserat directorul, daca trebuie undeva in lista cautam locul
si inseram sau daca trebuie la inceput inseram simplu la inceputul listei de 
directoare, daca lista este vida directorul e pus simplu ca prim element al 
listei.

-ls corespunzatoare comenzi "ls" afiseaza prima data fisierele apoi directoarele
din directorul curent printr-o parcurgere a listelor de directoare si fisiere
din directorul curent.

-pwd corespunzatoare comenzi "pwd" afiseaza calea catre directorul curent,
am parcurs inapoi prin pointerul "parentDir" am stocat numele directoarelor 
intr-un vector de pointeri si am afisat in ordinea dorita de mine.

-cd corespunzatoare comenzi "cd nume"  aceasta are doua argumente un pointer 
de tip "Directory" ce reprezinta directorul in care ne aflam si numele 
directorului in care dorim sa ajungem , daca numele e ".." ne intoarcem un 
director inapoi prin parentDir, iar daca e altceva cautam in lista de directoare
din directorul curent si cand gasim schimbam directorul curent.

-tree corespunzatoare comenzi "tree" aceasta am implementat-o recursiv 
reapelandu-se cu directorul curent si o iteratie anume in functe de numarul de
reapelari ale sale.

-rmdir corespunzatoare comenzi "rmdir nume"  aceasta are doua argumente un 
pointer de tip "Directory" ce reprezinta directorul in care ne aflam si numele 
directorului pe care dorim sa il stergem, cautam in lista de directoare din 
directorul curent, daca elementul este primul din lista trecem la urmatorul si
eliberam memoria pentru primul pointer, daca elementul se afla undeva in lista
avem doi pointeri de tip lista de directoarea copiem elemntele din lista de 
directoare pana gasim numele directorul de sters dupa care iesim din parcurgere 
apoi in pointerul "next" al ultimului elemenmt pus in noua lista punem pointerul 
next al elemntului cu numele cautat de noi si elibeream memoria pointarului cu 
numele cautat de noi cu adresa salvata in pointerul cu care am parcurs lista.

-rm corespunzatoare comenzi "rm nume"  aceasta are doua argumente un 
pointer de tip "Directory" ce reprezinta directorul in care ne aflam si numele 
fisierului pe care dorim sa il stergem, cautam in lista de fisiere din 
directorul curent, daca elementul este primul din lista trecem la urmatorul si
eliberam memoria pentru primul pointer, daca elementul se afla undeva in lista
avem doi pointeri de tip lista de fisiere copiem elemntele din lista de 
fisiere pana gasim numele directorul de sters dupa care iesim din parcurgere 
apoi in pointerul "next" al ultimului elemenmt pus in noua lista punem pointerul 
next al elemntului cu numele cautat de noi si elibeream memoria pointarului cu
 numele cautat de noi cu adresa salvata in pointerul cu care am parcurs lista.
