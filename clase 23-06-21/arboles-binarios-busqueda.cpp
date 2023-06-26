// ArbolBinario2.cpp
// implementa un AB basico
// Autor: Julio Santillán Castillo

using namespace std;
#include <iostream>
#include "../utilidades/arbolBinario.h"


int mayor(NodoBinario* n1, NodoBinario* n2) {
	if(n1->getDato() > n2->getDato()) {
		return n1->getDato();
	} 
	
	return n2->getDato();
}

int mayorValorPorNivel2(NodoBinario* nodo, int nivel = 0) {
	if(nodo == NULL) {
		return 0;
	}

	NodoBinario* hDer, *hIzq, NodoBinario, *hijoMayor;

	hIzq = nodo->getHijoIzquierdo();

	hDer = nodo->getHijoDerecho();

	if(hIzq->getDato() < hDer->getDato()) { // comparamos los hijos
		hijoMayor = hDer;

		cout << "El mayor valor del nivel " << nivel << " es " << hijoMayor->getDato() << endl;
	}

	nivel = nivel + 1;

	hIzq = hIzq->getHijoIzquierdo();

	hDer = hDer->getHijoIzquierdo();

	if(hijoMayor->getDato() < hIzq->getDato()) { // comparamos los hijos
		hijoMayor = hIzq;

		cout << "El mayor valor del nivel " << nivel << " es " << hijoMayor->getDato() << endl;
	}

	if(hijoMayor->getDato() < hDer->getDato()) { // comparamos los hijos
		hijoMayor = hDer;

		cout << "El mayor valor del nivel " << nivel << " es " << hijoMayor->getDato() << endl;
	}


}

bool buscarValorEnABB(ArbolBinario abb) {
    Tipo valor;
    cout << "Ingrese el valor a buscar: ";
    cin >> valor;

    return abb.buscarNodo(valor) != NULL;
}

int main(){
	system("color f0");
	ArbolBinario a;	
	
	void leerABB(ArbolBinario *b);		
	void imprimirAB(ArbolBinario a);

	leerABB(&a);

	imprimirAB(a);

    bool encontrado = buscarValorEnABB(a);
    cout << endl << "Se encontro el valor: " << (encontrado ? "SI" : "NO") << endl; 
	
	cout << endl;
	system("pause");
}

void leerABB(ArbolBinario *b){
    Tipo valor, fin = 99999;

    cout << endl;
    valor = datoDesdeEntrada(fin);
    
    if(valor == fin) {
        return;
    }

    b->insertarNodo(valor);

    leerABB(b);
}

void imprimirEsp(int c){	
	for (int i = 1; i <= c; i++){	
		cout << "   ";
    }
}

void imprimirAB(ArbolBinario a){
	cout << endl << "IMPRESION SIMPLE DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABSimple(a.getRaiz());
	
	cout << endl << "IMPRESION JERARQUICA DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);
}

void verDatosAB(ArbolBinario a){
	cout << endl << "IMPRESION DE DATOS GENERALES DE ARBOL BINARIO" << endl << endl;
	cout << endl << "El arbol " << (a.esVacio() ? "SI" : "NO") << " esta vacio";
	cout << endl << "El arbol posee " << a.contarNodos(a.getRaiz()) << " nodos";
	cout << endl << "La altura del arbol es " << a.calcularAltura(a.getRaiz());
	cout << endl << "El nodo raiz es: " << a.getRaiz()->getDato();
}

