/**
* Generar los N valores múltiplos de X. Calcular el promedio de aquellos valores generados que 
* estén dentro del rango comprendido entre A y B; si no están en ese rango, los valores solo deberán imprimirse.
* Autor: Andres Gaibor
*/

#include <iostream>

using namespace std;

float generarMultiplos(int x, int n, int a, int b, int cont = 1, int sum = 0) {
    if(cont == n + 1) {
        return (float) sum / cont;
    }

    int mult = x * cont;

    if(mult >=a && mult <= b) {
        sum += mult;
    } else {
        cout << endl << "Multiplo " << cont << " de " << x << " es: " << mult << endl;
    }

    return generarMultiplos(x, n, a, b, cont + 1, sum);
}


int main() {
    int x;
    cout << "Ingrese un numero X: ";
    cin >> x;
    int n;
    cout << "El numero de multiplos de X: ";
    cin >> n;
    int a;
    cout << "Limite inferior A: ";
    cin >> a;
    int b;
    cout << "Limite superior B: ";
    cin >> b;

    float promedio = generarMultiplos(x, n, a, b);

    cout << "El promedio de los mutiplos comprendidos entre A y B es " << promedio;

    return 0;
}