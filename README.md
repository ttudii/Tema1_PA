# Tema1_PA

  Prima tema din cadrul cursului de Proiectarea Algoritmilor a avut in vedere implementarea notiunilor studiate in prima parte a cursului, anunme liste, stive, cozi, arbori (binari de cautare, AVL) pentru aprofundarea notiunilor si intelegerea principiilor de funtionare. Tema este compusa din cinci task-uri si a fost realizata integral folosind limbajul C. Programul simuleaza desfasurarea unui concurs de League of Legends desfasurat in cadrul evenimentului Lan Party organizat de Facultatea de Automatica si Calculatoare.
  
  Datele de intrare sunt continute in 15 foldere, cu cate doua fisiere denumite c.in, respectiv d.in. Primul fisier contine 5 valori de 0 sau 1, indicand care din cele 5 task-uri vor fi aplicate asupra datelor de intrare (pentru primele 3 fisiere se va executa doar primul task, pentru urmatoarele 3 fisiere primele 2 task-uri etc.). Fisierul d.in contine date de intrare reprezentand echipele participante. Prelucrarile asupra datelor (rezolvarea task-urilor) vor fi afisate intr-un r.out.

  Verificarea rezultatelor se realizeaza cu ajutorul unui checker care, folosind executabilul programului, denumit lanParty, si un fisier Makefile, compara rezultatele obtinute cu un set de fisiere care contin ceea ce ar trebui sa se obtina daca rezolvarea a fost corecta.


  Fisier c.in care indica rezolvarea primului task

    1 0 0 0 0

  Fisier d.in continand echipele participante 
    

    45                   // numarul de echipe din fisier
    10 The Waiver Wire   // numarul de jucatori si numele echipei
    Popa Ana-Maria 6     // nume prenume puncte jucator 1
    Popescu Alexandru 10
    Pop Mihaela 6
    Radu Andreea 2
    Dumitru Elena 1
    Stan Adrian 4
    Stoica Andrei 0
    Gheorghe Alexandra 6
    Matei Mihai 3
    Ciobanu Ionut 1


#Task 1

  Primul task presupune citirea echipelor din fisierul d.in si adaugarea acestora intr-o lista, la inceputul acesteiea, complexitatea fiind O(1). Din lista astfel creata, vor fi afisate numele echipelor in ordinea aparitiei.

#Task 2

  Al doilea task presupune eliminarea din lista creata la task-ul 1 a unui numar de echipe, pana se ajunge la un numar de echipe care reprezinta o putere a lui 2, cea mai mare posibila. De fiecare data se elimina echipa cu punctajul cel mai mic, iar in cazul in care doua echipe au punctaj egal, se elimina prima gasita in lista. Punctajul reprezinta media aritmetica a punctajelor fiecarui jucator din cadrul echipei.

#Task 3

  In al treilea task, este implementata o coada de meciuri (meci - structura formata din doua echipe, introduse in ordinea aparitiei in lista). Echipa cu punctaj mai mare este adaugata intr-o stiva a castigatorilor, iar cealalta intr-o stiva a pierzatorilor. In cazul in care doua echipe au acelasi punctaj, va castiga prima introdusa in coada de meciuri. Castigatorii vor forma o noua coada de meciuri, algoritmul repetandu-se pana la aflarea castigatorului.

#Task 4

  Al patrulea task foloseste o lista formata din ultimele 8 echipe ramase in competitie (lista trebuie creata la task-ul anterior, insa este folosita in cadrul task-ului 4) pentru a crea un arbore binar de cautare ordonat in functie de punctaj (in cazul punctajelor egale, ordonarea se va face descresctor, in functie de nume). Nodurile arborelui vor fi introduse in fisier folosind o parcurgere in inordine inversa si vor fi retinute intr-o noua structura de tip lista.

#Task 5

  In task-ul 5 se realizeaza un arbore AVL folosind lista de la task-ul anterior si se va afisa continutul nivelului 2 in fisierul de iesire.
  

  
