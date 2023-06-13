// #include <iostream>

// using namespace std;

#ifndef LEERN_H
#define LEERN_H

int leerN(char mensaje[] = "Ingrese la cantidad de numeros (mayor a 0): ") {
    int n;
    cout << mensaje;
    cin >> n;
    
    if(n < 1) {
        n = leerN();
    }

    return n;
}

// SI RETORNA -111 QUIERE DECIR QUE (SE PRESIONO ENTER) YA NO QUIERE INGRESAR MAS DATOS
int leerNumero() {
    string linea;

    cout << endl << "Ingrese un dato (Presione Enter para dejar de ingresar): ";
    getline(cin, linea);

    if (linea.empty()) {
        return -111;
    }

    int dato = stoi(linea);
}

#endif