#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Stos{

private:

    int* A; // dynamiczna tablica dla stosu.
    int top; // gora stosu (poczatkowo == -1).
    int wielkosc; // maksymalny rozmiar stosu.


public:

    Stos(int rozmiar){ // konstruktor tworzacy dynamiczna tablice dla stosu.
        A = new int[wielkosc];
        wielkosc = rozmiar;
        top = -1;
    }

    int getSize(){ // zwraca maksymalny rozmiar stosu.
        return wielkosc;
    }

    int getTop(){
        return top;
    }

    bool isEmpty(){ // sprawdza czy stos jest pusty, true = pusty / false = niepusty.
        if(top == -1){
            return true;
        }
        return false;
    }

    bool isFull(){ // sprawdza czy stos jest pelny, true = pelny / false = niepelny.
        if(top == wielkosc - 1){
            return true;
        }
        return false;
    }

    bool Push(int value){ // dodaje nowy element na gore stosu lub nie jesli stos jest pelny.
        if(isFull()){
            return false;
        }

        top++;
        A[top] = value;
        return true;
    }

    int Pop(){ // zwraca i "usuwa" element z gory stosu lub nie jesli stos jest pusty.
        if(isEmpty()){
            return NULL;
        }
        top--;
        return A[top + 1];
    }

    void Display(){  // wyswietla elementy stosu od dolu do gory lub nie jesli stos jest pusty.
        if(isEmpty()){
            printf("Stos jest pusty.\n");
            return;
        }

        printf("Elementy stosu: \n\n");
        for(int i = 0; i <= top; i++){
            printf("\t%d\n", A[i]);
        }
        printf("\n");
    }

};

int main(){

    int n, rozmiar, value;
    string operacja;
    printf("Wybierz wielkosc stosu: ");
    while(true){
        scanf("%d", &n);
        if (n < 1){
            printf("Wybierz wartosc wieksza lub rowna 1.\n");
            continue;
        }
        break;
    }
    Stos stos(n);
    rozmiar = stos.getSize();
    printf("Stworzyles stos o wielkosci: %d  (jego elementy znajduja sie na indeksach <0 ; %d>)\n", rozmiar, rozmiar - 1);
    printf("Dostepne operacje:\n\n");
    printf("\t - PUSH -> Dodaje element na gore stosu.\n");
    printf("\t - POP -> Zabiera element z gory stosu.\n");
    printf("\t - ISEMPTY -> Sprawdza czy stos jest pusty.\n");
    printf("\t - ISFULL -> Sprawdza czy stos jest pelny.\n");
    printf("\t - TOP -> Zwraca indeks gory stosu.\n");
    printf("\t - DISPLAY -> Wypisuje wartosci stosu.\n\n");

    while(true){
    printf("Operacja: ");
    cin >> operacja;
    if (operacja == "PUSH"){
        printf("Wartosc liczbowa: ");
        cin >> value;
        if(!stos.Push(value)){
            printf("Stos jest pelny. Nie mozna dodac nowych elementow.\n");
        } else {
        printf("Dodano wartosc %d do stosu.\n", value);
        }
    }

    if (operacja == "POP"){
        value = stos.Pop();
        if(value == NULL){
            printf("Stos jest pusty. Nie mozna usunac z niego elementow.\n");
        } else {
            printf("Usunieto wartosc %d ze stosu.\n", value);
        }
    }

    if(operacja == "ISEMPTY"){
        if(stos.isEmpty()){
            printf("Stos jest pusty.\n");

        } else {
            printf("Stos nie jest pusty. Jego najwyzsza wartosc znajduje sie na indeksie %d.\n", stos.getTop());
        }
    }

     if(operacja == "ISFULL"){
        if(stos.isFull()){
            printf("Stos jest pelny.\n");
        } else {
             printf("Stos nie jest pelny. Jego najwyzsza wartosc znajduje sie na indeksie %d.\n", stos.getTop());
        }
    }

     if(operacja == "TOP"){
        value = stos.getTop();
        if(value == - 1){
            printf("Stos jest pusty.\n");
        } else {
            printf("Indeks najwyzszej wartosci stosu: %d\n", value);
        }
    }

    if(operacja == "DISPLAY"){
        stos.Display();
    }

    if (operacja == "END"){
        break;
    }
}



    return 0;



}
