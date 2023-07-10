// listaG.h
// implementa la definicion y estructura del TDA Lista Simplemente enlazada para uso con grafos
#ifndef _LISTAG_H
#define _LISTAG_H

#include "NodoG.h"

class ListaG{
private:
	NodoG* primero;							//atributo que permite almacenar la direccion de memoria del primer nodo de la lista
	
public:
	ListaG();								//constructor
	void setPrimero(NodoG* p);				//metodo que actualiza el apuntador al primer nodo de la lista
	NodoG* getPrimero();					//metodo que devuelve la direccion del primer nodo de la lista
	bool esVacia();							//metodo devuelve true si la lista esta vacia
	void anula();							//metodo que anula todos los elementos de la lista
	void insertarAlInicio(Tipo v);			//metodo que inserta un elemento dentro de la lista
	void insertarAlInicio(Tipo v, int q);	//metodo que inserta un elemento dentro de la lista
	void insertarAlFinal(Tipo v, NodoG* nuevo);			//metodo que inserta un elemento al final de la lista
	void insertarAlFinal(Tipo v, int q);	//metodo que inserta un elemento al final de la lista
	void insertarUnNodo(Tipo v, NodoG* ant);//metodo que inserta un elemento nuevo en la lista luego del nodo ant
	void insertarUnNodo(Tipo v, int q, NodoG* ant);	//metodo que inserta un elemento nuevo en la lista luego del nodo ant
	void insertarEnOrden(Tipo v);			//metodo que inserta ordenadamente un valor dentro de una lista
	void insertarEnOrden(Tipo v, int q);	//metodo que inserta ordenadamente un valor dentro de una lista
	NodoG* ultimoValorDeLista(NodoG* p = nullptr, bool primero = true);			//metodo que devuelve la direccion del ultimo nodo de la lista
	NodoG* ultimoValorDeLista1(NodoG* p = nullptr, bool primero = true);			//metodo que devuelve la direccion del ultimo nodo de la lista
	NodoG* buscarValorEnLista(Tipo v);		//metodo que devuelve la direccion del nodo que contiene el valor v
	void eliminarNodoDeLista(Tipo v);		//metodo que elimina el nodo que contiene el valor v de lista
};



ListaG::ListaG(){							//constructor
	setPrimero(NULL);	
}

void ListaG::setPrimero(NodoG* p){			//metodo que actualiza el apuntador al primer nodo de la lista
	primero = p;
}

NodoG* ListaG::getPrimero(){				//metodo que devuelve la direccion del primer nodo de la lista
	return primero;
}

bool ListaG::esVacia(){						//metodo devuelve true si la lista esta vacia
	return primero == NULL;					//devuelve true si primero apunta a null
}

void ListaG::anula(){						//metodo que anula todos los elementos de la lista
	setPrimero(NULL);						//inicializar el apuntador de inicio de la lista
}

void ListaG::insertarAlInicio(Tipo v){		//metodo que inserta un elemento dentro de la lista
	NodoG* nuevo;							//declaracion de un nuevo nodo
	
	nuevo = new NodoG(v);					//llamar metodo constructor de nodo pasandole el valor recibido como parametro
	nuevo->setPunt(getPrimero());			//llamar al metodo que actualiza la direccion a la cual debe apuntar el nuevo nodo
	setPrimero(nuevo);						//actualiza la direccion del primer elemento de la lista: es el nuevo nodo creado
}

void ListaG::insertarAlInicio(Tipo v, int q){	//metodo que inserta un elemento dentro de la lista
	insertarAlInicio(v);

	getPrimero()->setPeso(q);
}

void ListaG::insertarAlFinal(Tipo v, NodoG* nuevo = nullptr){		//metodo que inserta un elemento al final de la lista
	NodoG* ultimo = getPrimero();			//apuntador al ultimo nodo de la lista
	
	if(nuevo == nullptr){
		nuevo = new NodoG(v);
	}

	if (ultimo == NULL){
		setPrimero(nuevo);
	} else {								//existen otros nodos ya en la lista
		ultimo = ultimoValorDeLista();		//apuntar al ultimo nodo de la lista
		ultimo->setPunt(nuevo);			//actualiza el apuntador del que era el ultimo nodo de la lista
	}

}

void ListaG::insertarAlFinal(Tipo v, int q) {
	insertarAlFinal(v, new NodoG(v, q));
}

NodoG* ListaG::ultimoValorDeLista1(NodoG* p, bool primero) {
	if(primero) {
		p = getPrimero();
	}

	if(p->getPunt() == nullptr) {
		return p;
	}

	ultimoValorDeLista1(p->getPunt(), false);
}

NodoG* ListaG::ultimoValorDeLista(NodoG* p, bool primero) {
	if(primero) {
		p = getPrimero();
	}

	if(p->getPunt() == nullptr) {
		return p;
	}

	ultimoValorDeLista(p->getPunt(), false);
}

NodoG* ListaG::buscarValorEnLista(Tipo v){
	NodoG* actual = getPrimero();					//copiar la direccion del primer nodo de la lista
	while (actual != NULL){					//repetir el ciclo mientras el nodo apuntado por actual no apunta a NULL
		if (actual->getDato() == v){		//el valor almacenado en el nodo referido desde actual es igual al valor buscado
			return actual;					//devuelvo la direccion del nodo actual
		}
		actual = actual->getPunt();			//apuntador actual avanza al siguiente nodo
	}
	return NULL;							//si el valor no se encuentra, devolver null
}

void ListaG::insertarUnNodo(Tipo v, NodoG* ant){	//metodo que inserta un elemento nuevo en la lista luego del nodo ant
	NodoG* nuevo = new NodoG(v);					//llamar metodo constructor de nodo pasandole el valor recibido como parametro
	nuevo->setPunt(ant -> getPunt());		//llamar al metodo que actualiza la direccion a la cual debe apuntar el nuevo nodo
	ant -> setPunt(nuevo);					//actualiza la direccion del primer elemento de la lista: es el nuevo nodo creado
}

void ListaG::insertarUnNodo(Tipo v, int q, NodoG* ant){	//metodo que inserta un elemento nuevo en la lista luego del nodo ant
	NodoG* nuevo;							//declaracion de un nuevo nodo
	
	nuevo = new NodoG(v, q);				//llamar metodo constructor de nodo pasandole el valor recibido como parametro
	nuevo->setPunt(ant -> getPunt());		//llamar al metodo que actualiza la direccion a la cual debe apuntar el nuevo nodo
	ant -> setPunt(nuevo);					//actualiza la direccion del primer elemento de la lista: es el nuevo nodo creado
}

void ListaG::eliminarNodoDeLista(Tipo v){	//metodo que elimina el nodo que contiene el valor v de lista
	NodoG* actual;							//apunta al nodo actual de la lista
	NodoG* ant;								//apuntador al nodo anterior al que debe eliminarse
	bool enc;								//bandera que indica si v se encuentra o no en la lista
	
	actual = getPrimero();					//copiar la direccion del primer nodo de la lista
	ant = NULL;								//por defecto, no existe un nodo antes del inicio de la lista
	enc = false;							//por defecto, el valor v no se encientra en la lista	

	while ((actual != NULL) && (!enc)){		//repetir el ciclo mientras el nodo apuntado por actual no apunta a NULL y no lo encuentre aun
		enc = (actual->getDato() == v);	//actualiza el valor de la var bandera: encontrado true, no encontrado false
		
		if (!enc){							//valor aun no esta en el nodo actual
			ant = actual;					//el nodo actual se transforma en anterior
			actual = actual -> getPunt();	//actual avanza un nodo en la lista
		}
	}
	//termino la busqueda: encontramos el valor?
	if (actual != NULL){					//si el nodo actual no esta al final de la lista
		if (actual == getPrimero()){		//estamos en inicio de la lista
			setPrimero(actual -> getPunt());//apuntador primero apuntara a donde apuntaba el nodo actual
		} else {							//no estamos al inicio de la lista
			ant -> setPunt(actual -> getPunt());// nodo anterior apunte a donde apuntaba el nodo actual
		}
	}
}

void ListaG::insertarEnOrden(Tipo v){		//metodo que inserta ordenadamente un valor dentro de una lista
	NodoG* nuevo;							//declaracion de un nuevo nodo
	NodoG* ant;								//apuntador al nodo anterior al nodo que se va a insertar
	NodoG* ult = getPrimero();				//apuntador al ultimo nodo de la lista
	
	nuevo = new NodoG(v);					//llamar metodo constructor de nodo pasandole el valor recibido como parametro
	if (ult == NULL){						//lista vacia => nuevo nodo será el primero
		setPrimero(nuevo);					//el inicio de la lista apunta al nuevo nodo
	} else {								//lista no vacia
		if (v < ult -> getDato()){			//nuevo valor es menor que lo almacenado en el nodo apuntado desde ult
			nuevo -> setPunt(getPrimero());	//el nuevo apunta al inicio de la lista
			setPrimero(nuevo);				//el nuevo se situa al inicio de la lista
		} else {							//el nuevo valor no es menor
			ant = ult;						//guardar la direccion del nodo analizado como el nodo anterior
			while((ult -> getPunt() != NULL) && (v > ult->getDato())){
				ant = ult;					//guardar la direccion del nodo ant
				ult = ult -> getPunt();		//ult avanzar en la lista
			}
			if (v > ult->getDato()){
				ant = ult;
			}
			nuevo -> setPunt(ant->getPunt());
			ant->setPunt(nuevo);
		}
	}
}

void ListaG::insertarEnOrden(Tipo v, int q){//metodo que inserta ordenadamente un valor dentro de una lista
	NodoG* nuevo;							//declaracion de un nuevo nodo
	NodoG* ant;								//apuntador al nodo anterior al nodo que se va a insertar
	NodoG* ult = getPrimero();				//apuntador al ultimo nodo de la lista
	
	nuevo = new NodoG(v, q);				//llamar metodo constructor de nodo pasandole el valor recibido como parametro
	if (ult == NULL){						//lista vacia => nuevo nodo será el primero
		setPrimero(nuevo);					//el inicio de la lista apunta al nuevo nodo
	} else {								//lista no vacia
		if (v < ult -> getDato()){			//nuevo valor es menor que lo almacenado en el nodo apuntado desde ult
			nuevo -> setPunt(getPrimero());	//el nuevo apunta al inicio de la lista
			setPrimero(nuevo);				//el nuevo se situa al inicio de la lista
		} else {							//el nuevo valor no es menor
			ant = ult;						//guardar la direccion del nodo analizado como el nodo anterior
			while((ult -> getPunt() != NULL) && (v > ult->getDato())){
				ant = ult;					//guardar la direccion del nodo ant
				ult = ult -> getPunt();		//ult avanzar en la lista
			}
			if (v > ult->getDato()){
				ant = ult;
			}
			nuevo -> setPunt(ant->getPunt());
			ant->setPunt(nuevo);
		}
	}
}
#endif
