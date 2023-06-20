// ArbolBinario.h
// Clase que contiene metodos de gestion de un AB
// Autor: Julio Santillán C.

#ifndef _ARBOL_BINARIO_H
#define _ARBOL_BINARIO_H

#include "nodoArbol.h"
#include <iostream>				
#include <string>				
using namespace std;

class ArbolBinario {
private:
	NodoBinario* raiz;
    NodoBinario* leerNodo(int margen);
	void inorden(NodoBinario *r);
	void preorden(NodoBinario *r);
	void postorden(NodoBinario *r);
	NodoBinario* insertar(NodoBinario *r, Tipo valor);
	NodoBinario* eliminar(NodoBinario *r, Tipo valor);
	NodoBinario* buscar(NodoBinario *r, Tipo v);
	NodoBinario* reemplazar(NodoBinario *r);
public:									
	ArbolBinario();						

	void setRaiz(NodoBinario* v);		
	NodoBinario* getRaiz();			

	bool esVacio();					
	NodoBinario* construirAB(Tipo dato, NodoBinario* i, NodoBinario* d);

	void leer();
	void imprimirABSimple(NodoBinario* p);		
	void imprimirABJerarquia(NodoBinario *p, int n);

	int contarNodos(NodoBinario *r);				
	int calcularAltura(NodoBinario *r);				
	void verHojas(NodoBinario *r);					

	void recorrerEnPreorden(); 						
	void recorrerEnInorden();						
	void recorrerEnPostorden();						

	void insertarNodo(Tipo valor);					
	void eliminarNodo(Tipo valor);					
	NodoBinario* buscarNodo(Tipo v);				

	void vaciar(NodoBinario *r);					
	NodoBinario* nodoHijoIzq();						
	NodoBinario* nodoHijoDer();						

	bool arbolLleno(NodoBinario *r);				
	void copiaArbol(ArbolBinario &a);				
    NodoBinario* copiarArbol(NodoBinario* r);
};


void imprimirEspacio(int cantidadEspacios){
    if(cantidadEspacios == 0){
        return;
    }

    cout << "   ";

    imprimirEspacio(cantidadEspacios - 1);
}

NodoBinario* ArbolBinario::construirAB(Tipo dato, NodoBinario* i, NodoBinario* d){
	return new NodoBinario(dato, i, d);	
}

Tipo leerValor(int fin = 99999){
	Tipo valor;

	cout << "Ingrese valor para el nodo. Ingrese [" << fin << "] para terminar: ";
	cin >> valor;

	return valor;
}

int datoDesdeEntrada(int fin = 99999, string mensaje = "Ingrese valor para el nodo")
{
    string linea;
    cout << endl
         << mensaje << " (Presione Enter para dejar de ingresar): ";
    getline(cin, linea);

    if (linea.empty())
    {
        return fin;
    }

    int dato = stoi(linea);

    return dato;
}

NodoBinario* ArbolBinario::leerNodo(int margen = 0){
		Tipo valor, fin = 99999;
		NodoBinario* nuevoN;
	
		cout << endl;
		
		valor = datoDesdeEntrada(fin);
		
        if(valor == fin) {
            return NULL;
        }

        nuevoN = new NodoBinario(valor);

        imprimirEspacio(margen);

        cout << "--- SUBARBOL IZQUIERDO (N. PADRE "<< nuevoN->getDato() << ") ---";
        nuevoN->setHijoIzquierdo(leerNodo(margen+1)) ;
        imprimirEspacio(margen);

        cout << "--- SUBARBOL DERECHO (N. PADRE "<< nuevoN->getDato() << ") ---";
        nuevoN->setHijoDerecho(leerNodo(margen+1)) ;
        
        return nuevoN;
}

void ArbolBinario::leer(){
	setRaiz(leerNodo());
}


void ArbolBinario::preorden(NodoBinario *r) {
	if(r == NULL) {
		return;
	}
	cout << " " << r->getDato();
	preorden(r->getHijoIzquierdo());
	preorden(r->getHijoDerecho());

}



void ArbolBinario::inorden(NodoBinario *r) {
	if(r == NULL) {
		return;
	}
	inorden(r->getHijoIzquierdo());
	cout << " " << r->getDato();
	inorden(r->getHijoDerecho());

}



void ArbolBinario::postorden(NodoBinario *r) {
	if(r == NULL) {
		return;
	}
	postorden(r->getHijoIzquierdo());
	postorden(r->getHijoDerecho());
	cout << " " << r->getDato();

}



NodoBinario* ArbolBinario::insertar(NodoBinario* rSub, Tipo v) {		//implementa la inserción de un nodo en AB
	if (rSub == NULL) {									//no hay nodos en arbol
		rSub = new NodoBinario(v);						//crea nuevo nodo y lo apunta desde rsub
	} else {											//si hay nodos en el arbol
		if (v < rSub->getDato()) {						//valor a insertar es menor que valor del nodo actual
			NodoBinario* iz = insertar(rSub->getHijoIzquierdo(), v);	//tratar de insertar a la izq del nodo actual
			rSub->setHijoIzquierdo(iz);							//actualiza apuntador
		} else {										//valor a insertar no es menor que valor nodo actual
			if (v > rSub->getDato()) {					//valor a insertar es mayor que valor nodo actual
				NodoBinario* dr = insertar(rSub->getHijoDerecho(), v);	//tratar de insertar a derecha del nodo actual
				rSub->setHijoDerecho(dr);						//actualiza apuntador
			} else {									//valor a insertar ya existe en arbol
				return NULL; 							//Nodo duplicado tratamiento de repetición
			}			
		} 
	} 
	return rSub;										//devuelve apuntador de nodo insertado
}



NodoBinario* ArbolBinario::eliminar (NodoBinario *rSub, Tipo v) {		//implementa la eliminacion de un nodo del AB
	if (rSub == NULL) {									//arbol no tiene nodos
		return NULL; 									//No se ha encontrado el nodo con el valor ingresado
	} else {											//arbol si tiene nodos
		if (v < rSub->getDato()){						//valor buscado es menor que valor de nodo actual
			NodoBinario* iz = eliminar(rSub->getHijoIzquierdo(), v);	//tratar de eliminar en subarbol izquierdo
			rSub->setHijoIzquierdo(iz);							//actualiza rama izq del nodo raiz
		} else {										//valor buscado no es menor que valor nodo actual
			if (v > rSub->getDato()){					//valor buscado es mayor que valor del nodo actual
				NodoBinario* dr = eliminar(rSub->getHijoDerecho(), v);	//tratar de eliminar en subarbol derecho
				rSub->setHijoDerecho(dr);						//actualiza rama derecha del nodo raiz
			} else { 									//Nodo encontrado con valor buscado
				NodoBinario* q = rSub; 					// nodo a quitar del árbol
				if (q->getHijoIzquierdo() == NULL) {				//ramal izquierdo de este nodo es NULL
					rSub = q->getHijoDerecho(); 				//se toma ramal derecho
				} else {								//si hay nodo apuntado en ramal izquierdo
					if (q->getHijoDerecho() == NULL) {			//No hay nodo apuntado por ramal derecho
						rSub = q->getHijoIzquierdo(); 			//se toma ramal izquierdo
					} else { 							// tiene rama izquierda y derecha
						q = reemplazar(q); 				//reemplaza nodo q
					}
				}
				q = NULL;								//hace que q apunte a null
			}
		}
	}
	return rSub;										//devuelve apuntador a nodo actual
}



	NodoBinario* ArbolBinario::reemplazar(NodoBinario* act) {				//sustituye un nodo por otro en AB (parte de eliminación)
		NodoBinario *a, *p;
		p = act;
		a = act->getHijoIzquierdo();									// rama de nodos menores
		while (a->getHijoDerecho() != NULL) {						//mientras haya nodos en ramal derecho
			p = a;											//actualiza apuntador
			a = a->getHijoDerecho();								//recorre el ramal derecho
		}
		
		act->setDato(a->getDato());							// copia en act el valor del nodo apuntado por a
		if (p == act) { 									// a es el hijo izquierdo de act
			p->setHijoIzquierdo(a->getHijoIzquierdo());							// enlaza subarbol izquierdo
		} else {											//a no es hijo izq de act
			p->setHijoDerecho(a->getHijoIzquierdo()); 						//se enlaza subarbol derecho
		}
		return a;											//devuelve apuntador a nodo actual
	}	



	NodoBinario* ArbolBinario::buscar(NodoBinario* rSub, Tipo v) {		//implementa búsqueda de un nodo en el AB
		if (rSub == NULL) {									//no existen nodos
			return NULL;									//no encontro: devuelve apuntador a NULL
		} else {											//si hay nodos
			if (v == rSub->getDato()){						//valor buscado esta en este nodo
				return rSub;								//devuelve apuntador a este nodo
			} else {										//valor buscado no esta en este nodo
				if (v < rSub->getDato()){					//valor buscado es menor que valor del nodo
					return buscar(rSub->getHijoIzquierdo(), v);		//repite busqueda en subarbol izquierdo
				} else {									//valor buscado no es menor que valor del nodo
					return buscar(rSub->getHijoDerecho(), v);		//repite busqueda en subarbol derecho
				}
			}
		} 
	}






ArbolBinario::ArbolBinario(){				//constructor
	setRaiz(NULL);							//al inicio no hay nodos en el AB
}



void ArbolBinario::setRaiz(NodoBinario* v){		//metodo que actualiza el atributo
	raiz = v;
}



NodoBinario* ArbolBinario::getRaiz(){		//metodo que devuelve el atributo
	return raiz;
}



bool ArbolBinario::esVacio(){				//metodo que determina si el AB carece de nodos
	return (getRaiz() == NULL);				//true si raiz == null 
}











void ArbolBinario::imprimirABSimple(NodoBinario* p){		//metodo que imprime un AB	
	if (p != NULL){
		cout << endl << "> " << p -> getDato();
		imprimirABSimple(p -> getHijoIzquierdo());
		imprimirABSimple(p -> getHijoDerecho());
	}
	return;
}



void ArbolBinario::imprimirABJerarquia(NodoBinario *p, int n){		//visualiza el abb 90@ a la izquierda
    if(p == NULL){	//no apunta a ningun nodo
       return;
	}
    imprimirABJerarquia(p -> getHijoDerecho(), n+1);	//llamado recursivo pasando subarbol derecho
    imprimirEspacio(n);								//espaciar la impresion
    cout << p -> getDato() << endl;				//visualiza el valor almacenado en el nodo
    imprimirABJerarquia(p -> getHijoIzquierdo(), n+1); 	//llamado recursivo pasando subarbol izq
}



int ArbolBinario::contarNodos(NodoBinario *r){				//determina la cantidad de nodos que posee un arbol
	if (r == NULL) {
		return 0;
	} else {
		return 1 + contarNodos(r->getHijoIzquierdo()) + contarNodos(r->getHijoDerecho());
	}
}



int ArbolBinario::calcularAltura(NodoBinario *r){				//determina la altura de un arbol
	if (r == NULL) {
		return 0 ;
	} else {
		int alturaIz = calcularAltura (r->getHijoIzquierdo());
		int alturaDr = calcularAltura (r->getHijoDerecho());
		if (alturaIz > alturaDr) {								//determina si altura de subarbol izq es mayor que la de subarbol der
			return alturaIz + 1;
		} else {
			return alturaDr + 1;
		}
	}
}



void ArbolBinario::recorrerEnPreorden() {		// recorrido en preorden
	preorden(getRaiz());						//llama a metodo interno de recorrido
}



void ArbolBinario::recorrerEnInorden() {		// recorrido en ineorden
	inorden(getRaiz());							//llama a metodo interno de recorrido
}



void ArbolBinario::recorrerEnPostorden() {		// recorrido en postorden
	postorden(getRaiz());						//llama a metodo interno de recorrido
}



void ArbolBinario::verHojas(NodoBinario *r){						//metodo de recorrido de nodos hoja							//visualiza las hojas de un AB
	if (r != NULL){													//nodo recibido no es nulo
		if ((r -> getHijoIzquierdo() == NULL) && (r -> getHijoDerecho() == NULL)) {	//no tiene nodos hijo => hoja
			cout << endl << "> " << r -> getDato();					//visualiza dato contenido
		} else {													//si tiene nodos hijo => nodo rama
			verHojas(r -> getHijoIzquierdo());								//recorrer subarbol izq
			verHojas(r -> getHijoDerecho());								//recorres subarbol der
		}
	}
	return;
}



NodoBinario* ArbolBinario::buscarNodo(Tipo v){					//permite buscar y encontrar un nodo con valor v en un arbol binario
	return buscar(getRaiz(), v);								//llama a metodo interno de búsqueda
}



void ArbolBinario::insertarNodo(Tipo v){						//permite insertar un nuevo nodo con valor v en un arbol binario
	setRaiz(insertar(getRaiz(), v));							//llama a metodo interno de insercion de nodo
}



void ArbolBinario::eliminarNodo(Tipo v){						//permite eliminar un nodo con valor v de un arbol binario
	setRaiz(eliminar(getRaiz(), v));							//llama a metodo interno de eliminacion de nodo
}



void ArbolBinario::vaciar(NodoBinario *r) {
	if (r != NULL)	{
		vaciar(r->getHijoIzquierdo());
		vaciar(r->getHijoDerecho());
		r = NULL;
	}
}



NodoBinario* ArbolBinario::nodoHijoIzq() {		//devuelve direccion del hijo del lado izquierdo
	if(getRaiz()){
		return getRaiz()->getHijoIzquierdo();				//devuelve valor apuntado por ramal izq
	} else {
		return NULL; 							//arbol vacio
	}
}
	


NodoBinario* ArbolBinario::nodoHijoDer() {		//devuelve direccion del hijo del lado derecho
	if(getRaiz())
		return getRaiz()->getHijoDerecho();				//devuelve direccion apuntada por ramal derecjho
	else
		return NULL; 							//arbol vacio
}



bool ArbolBinario::arbolLleno(NodoBinario *r){	//determina si el arbol es lleno o no
	if (r == NULL) {							//arbol vacio	
		return true;							//si es arbol lleno
	} else {									//si hay nodos
		if (ArbolBinario::calcularAltura(r->getHijoIzquierdo()) != ArbolBinario::calcularAltura(r->getHijoDerecho())) {	//altura de ramal izq diferente de altura ramal derecho
			return false;						//no es arbol lleno
		}
	}
	return arbolLleno(r->getHijoIzquierdo()) && arbolLleno(r->getHijoDerecho());
}



void ArbolBinario::copiaArbol(ArbolBinario &a) {
	a.setRaiz(copiarArbol(this->raiz));
}



NodoBinario* ArbolBinario::copiarArbol(NodoBinario* r) {
	NodoBinario *rCop;									//nodo copia
	
	if (r == NULL) {									//no hay nodos en arbol
		rCop = NULL;									//en la copia pone null porque arbol esta vacio
	} else {											//arbol no vacio
		NodoBinario* izqCop, *derCop;					//dos nuevos nodos
		izqCop = copiarArbol(r->getHijoIzquierdo());				//en nuevo izq, pone copia de ramal izq original
		derCop = copiarArbol(r->getHijoDerecho());				//en nuevo der, pone copia de ramal der del original
		rCop = new NodoBinario(r->getDato(), izqCop, derCop);	//crea nuevo nodo
	}
	return rCop;										//devuelve apuntador a la copa
}


#endif
