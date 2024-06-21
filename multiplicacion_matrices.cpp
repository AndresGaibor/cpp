#include <iostream>

using namespace std;
#define MAX 100

void leerLongitudMatriz(char nombre, int *n, int *m) {
    cout << "-------------------------------------" << endl;
    cout << "Ingrese la matriz " << nombre << endl;
    cout << "# de filas: ";
    cin >> *n;
    cout << "# de columnas: ";
    cin >> *m;
}

void leerMatriz(char nombre, int n, int m, int matriz[MAX][MAX]) {
    cout << "-------------------------------------" << endl;
    cout << "Leyendo valores de la matriz" << nombre << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << nombre << "[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matriz[i][j];
        }
    }
}

bool sePuedeMultiplicar(int mA, int nB) {
    if(mA != nB) {
        return false;
    }

    return true;
}


void multiplicarMatrices(int nA, int mA, int matrizA[MAX][MAX], int nB, int mB, int matrizB[MAX][MAX], int *nR, int *mR, int matrizR[MAX][MAX]) {
    if(!sePuedeMultiplicar(mA, nB)) {
        cout << "No se puede multiplicar la matriz, la matriz A debe tener la mismas columnas que la filas de la matriz B" << endl;
        return;
    }

    *nR = nA;
    *mR= mB;

    for(int i = 0; i < *nR; i++) {
        for(int j = 0; j < *mR; j++) {
            int suma = 0;
            for(int k = 0; k < mA; k++) {
                suma += matrizA[j][k] * matrizB[k][i];
            }
            
            matrizR[i][j] = suma;
        }
    }


}

void mostrarMatriz(char nombre, int n, int m, int matriz[MAX][MAX]) {
    cout << "-------------------------------------" << endl;
    cout << "Leyendo valores de la matriz" << nombre << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << nombre << "[" << i + 1 << "][" << j + 1 << "] = ";
            cout << matriz[i][j];
        }
    }
}



int main() {
    int nA, mA, nB, mB, nR, mR;
    int matrizA[MAX][MAX], matrizB[MAX][MAX], matrizR[MAX][MAX];

    leerLongitudMatriz('A', &nA, &mA);
    leerMatriz('A', nA, mA, matrizA);
    leerLongitudMatriz('B', &nB, &mB);
    leerMatriz('B', nB, mB, matrizB);

    multiplicarMatrices(nA, mA, matrizA, nB, mB, matrizB, &nR, &mR, matrizR);

    mostrarMatriz('R', nR, mR, matrizR);

    // int matrizA[][]

}