#include <iostream>

using namespace std;

int busquedaLineal(int vector[], int n, int valorBusqueda) {//  
    int i = 0;  //                                              O(1)
    int posResultado = -1; //                                   O(1)

    // En el peor de los casos el dato esta 
    // en la posicion n o no esta en el vector
    while(i < n) { //                                           O(n)
        if(vector[i] == valorBusqueda) {//                      O(1)
            posResultado = i;//                                 O(1)
            break;//                                            O(1)
        }

        i++;//                                                  O(1)
    }

    return posResultado;//
}

// n = 5
// 1, 2, 3, 4, 5, 6
int buscarBinaria(int valor, int arreglo[], int n) {
    int posInit, posFin, posMed; //                     O(1)

    posInit = 0; //                                     O(1)
    posFin = n - 1; //                                  O(1)

    while(posInit <= posFin) { //                       O(n)
        posMed = (posInit + posFin) / 2; //             O(1)
 
        if(arreglo[posMed] == valor) {  //              O(1)
            return posMed; //                           O(1)
        } //                                            O(1)

        if(arreglo[posMed] > valor) { //                O(1)
            posFin = posMed - 1;
            continue;
        } 
        
        posInit = posMed + 1;
    }

    return -1;
}

int probar(int n = 10) {
    cout << "n: " << n << " ";          //       O(1)
        int contador = 0;                     //       O(1)

    for(int i = 1; i <= n; i++) {           //       O(n)
        for(int j = 1; j <= i; j++) {  //             O(n*n)  
            for(int k = 1; k <= j; k++) {
                contador++;
                // cout << "Hola";
            }
        }

    }
        cout << contador << endl;
}

int main() {
    int datos[] = { 10, 20, 30, 40, 50, 60, 70 };

    int buscarValor = busquedaLineal(datos, 7, 20);

    if(buscarValor == -1) {
        cout << "No se encontro el valor en el vector";
    } else {
        cout << "Se encontre el valor en la posicion " << buscarValor;
    }

    probar(2);
    probar(3);
    probar(4);
    probar(5);
    probar(6);
    probar(7);
    probar(8);
    probar(9);
}