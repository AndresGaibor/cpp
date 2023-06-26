// ArbolBinario2.cpp
// implementa un AB basico
// Autor: Julio Santillán Castillo

using namespace std;
#include <iostream>
#include "../utilidades/arbolBinario.h"

// sumatoria de las nodos ramas
int sumarNodosNoHoja(NodoBinario* nodo) {
	if(nodo == NULL) {
		return 0;
	}

	NodoBinario* hDer, *hIzq;

	hIzq = nodo->getHijoIzquierdo();
	hDer = nodo->getHijoDerecho();
	
	if ((hIzq == NULL) && (hDer == NULL)) {
		return 0;
	} 

	return nodo->getDato() + sumarNodosNoHoja(hIzq) + sumarNodosNoHoja(hDer); 
}

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
int mayorValorPorNivel(NodoBinario* nodo, int nivel = 0) {
	if(nodo == NULL) {
		return 0;
	}

	NodoBinario* hDer, *hIzq, NodoBinario, *hijoMayor;

	hIzq = nodo->getHijoIzquierdo();
	hDer = nodo->getHijoDerecho();

	hijoMayor = hIzq;
	
	if(hIzq->getDato() < hDer->getDato()) { // comparamos los hijos
		hijoMayor = hDer;

		cout << "El mayor valor del nivel " << nivel << " es " << hijoMayor->getDato() << endl;
	}

	nivel = nivel + 1;


	mayorValorPorNivel(hIzq);
	mayorValorPorNivel(hDer);
}


int main(){					//programa principal
	system("color f0");
	ArbolBinario a;			//declara un árbol binario
	
	void leerAB(ArbolBinario *b);		//prototipo de funcion ingreso AB
	void imprimirAB(ArbolBinario a);	//prototipo de funcion que imprime AB
	void verDatosAB(ArbolBinario a);	//prototipo de funcion para visualizar datos generales de un arbol
	void verHojasAB(ArbolBinario a);	//prototipo de funcion para visualizar los nodos hoja del Ab
	void recorrerAB(ArbolBinario a);	//protipo de la funcion que implementa los diversos recorridos de un AB
	
	leerAB(&a);							//llamado a funcion de ingreso AB
	verDatosAB(a);						//llamado a impresion datos generales AB

	imprimirAB(a);						//llamado a funcion que imprime un AB

	verHojasAB(a);						//llamado a impresion de nodos hoja del AB
	recorrerAB(a);						//llamado a la funcion que implementa diversos recorridos de AB
	
	cout << "La suma de las ramas es " << sumarNodosNoHoja(a.getRaiz());

	cout << endl;
	system("pause");
}

NodoBinario* leerNodo(int margen = 0, string mensaje = "IZQUIERDO", NodoBinario *padre = nullptr){
		Tipo valor, fin = 99999;
		NodoBinario* nuevoN;
	
		cout << endl;
		imprimirEspacio(margen);
		cout << "--- SUBARBOL " << mensaje <<" (N. PADRE "<< ((padre != nullptr) ? to_string(padre->getDato()) : "RAIZ") << ") ---" << endl;
		valor = datoDesdeEntrada(fin);
		
        if(valor == fin) {
            return NULL;
        }

        nuevoN = new NodoBinario(valor);

        // imprimirEspacio(margen);

        nuevoN->setHijoIzquierdo(leerNodo(margen+1, "IZQUIERDO", nuevoN)) ;
        // imprimirEspacio(margen);

        nuevoN->setHijoDerecho(leerNodo(margen+1, "DERECHO", nuevoN)) ;
        
        return nuevoN;
}

void leerAB(ArbolBinario *b){
	b -> setRaiz(leerNodo(0));	//actualiza raiz del arbol nuevo con apuntador devuelto
}

void imprimirEsp(int c){	//funcion para imprimir espacios
	for (int i = 1; i <= c; i++){	//ciclo impresion espacios
		cout << "   ";
    }
}

void imprimirAB(ArbolBinario a){
	cout << endl << "IMPRESION SIMPLE DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABSimple(a.getRaiz());	//llama metodo impresion simple de AB
	
	cout << endl << "IMPRESION JERARQUICA DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);	//llama a metodo impresion con formato jerarquico de AB
}

void verDatosAB(ArbolBinario a){		//visualizar datos generales de un arbol
	cout << endl << "IMPRESION DE DATOS GENERALES DE ARBOL BINARIO" << endl << endl;
	cout << endl << "El arbol " << (a.esVacio() ? "SI" : "NO") << " esta vacio";
	cout << endl << "El arbol posee " << a.contarNodos(a.getRaiz()) << " nodos";
	cout << endl << "La altura del arbol es " << a.calcularAltura(a.getRaiz());
	cout << endl << "El nodo raiz es: " << a.getRaiz()->getDato();
}

void verHojasAB(ArbolBinario a){		//visualizar los nodos hoja del Ab
	cout << endl << "IMPRESION DE NODOS HOJA DE ARBOL BINARIO" << endl << endl;
	a.verHojas(a.getRaiz());			//llama a metodo que visualiza nodos hoja del AB
}

void recorrerAB(ArbolBinario a){		//funcion que implementa los diversos recorridos de un AB
	cout << endl << "RECORRIDOS DE ARBOL BINARIO" << endl << endl;
	cout << endl << "RECORRIDO EN PREORDEN" << endl;
	a.recorrerEnPreorden();		//llama al metodo correspondiente
	cout << endl << "RECORRIDO EN INORDEN" << endl;
	a.recorrerEnInorden();		//llama al metodo correspondiente
	cout << endl << "RECORRIDO EN POSORDEN" << endl;
	a.recorrerEnPostorden();		//llama al metodo correspondiente
}

