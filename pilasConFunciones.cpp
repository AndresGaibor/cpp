/**
* Pilas con funciones
* Autor: Andres Gaibor
*/

#include <iostream>
#define EXT 4 // 0, 1, 2, 3

using namespace std;

bool estaLlena(int pos) {
    if(pos == EXT - 1) { // si 3 == 4 - 1 -> 3 == 3  
        return true;
    } else {
        return false;
    }
}

void push(int pila[], int valor, int *contador) {
    cout << "Push" << endl;

    if(estaLlena(*contador)) {
        cout << "La pila esta llena" << endl;
    } else {
        *contador = *contador + 1;
        cout << "Contador: " << *contador << endl;
        cout << "Valor: " << valor << endl;
        pila[*contador] = valor;
    }
}

int pop(int pila[], int *contador) {
    if(*contador >= 0) {
        int valor = pila[*contador];
        *contador = *contador - 1;
        return valor;
    } else {
        cout << "La pila esta vacia" << endl;
        return -1;
    }
}

int main() {
    int pila[EXT];
    
    int contador = -1;

    push(pila, 100, &contador);
    push(pila, 200, &contador);
    push(pila, 300, &contador);
    push(pila, 400, &contador);
    push(pila, 500, &contador);

    cout << endl << "Pop: " << pop(pila, &contador) << endl;
    cout << endl << "Pop: " << pop(pila, &contador) << endl;
    cout << endl << "Pop: " << pop(pila, &contador) << endl;
    cout << endl << "Pop: " << pop(pila, &contador) << endl;
    cout << endl << "Pop: " << pop(pila, &contador) << endl;





    return 0;
}