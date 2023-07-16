// GrafoLista.h
// Definicion de TDA Grafo implementado con Lista de Adyacencia

#ifndef _GRAFOLISTA_H
#define _GRAFOLISTA_H

typedef int * pint;						//para el dimensionamiento de la matriz

#include "Vertice.h"
#include "ListaG.h"

class GrafoLista {									//definicion de la clase
private:											//declaracion de atributos
	int maxVerts; 									//máximo numero de vértices
	int numVerts; 									//número de vértices que contiene el grafo
	Vertice* verts; 								//vector de vértices
	ListaG** arcos; 								//Lista de adyacencia

public:												// métodos públicos de la clase GrafoMatriz
	GrafoLista();									//constructor por defecto
	GrafoLista(int v);								//constructor conociendo cantidad máxima de vértices

	void setMaxVerts(int n);	 					//actualiza numero maximo de vertices
	void setNumVerts(int n);	 					//actualiza numero de vertices existentes en grafo
	void setVertice(int va, Vertice v);				//modifica los atributos de un vertice, conociendo su nombre
	void setVertice(TipoG a, Vertice v);				//modifica los atributos de un vertice, conociendo su nombre
	void setArco(int va, int vb);					//actualiza valor de arco recibiendo numeros de vertices en grafo no valorados
	void setArco(int va, int vb, int v);			//actualiza valor de arco recibiendo numeros de vertices
	void setArco(TipoG a, TipoG b);					//actualiza valor de arco recibiendo nombres de vertices en grafos no valorados
	void setArco(TipoG a, TipoG b, int v);			//actualiza valor de arco recibiendo nombres de vertices en grafos no valorados

	int getMaxVerts();								//devuelve numero maximo de vertices
	int getNumVerts();								//devuelve cantidad de vertices existentes en grafo
	Vertice getVertice(int va);						//devuelve atributos de un vertice, conociendo su numero
	Vertice getVertice(TipoG a);						//devuelve atributos de un vertice, conociendo su valor
	bool getArco(int va, int vb);					//devuelve el valor de un arco recibiendo numeros de vertices
	bool getArco(TipoG a, TipoG b);					//devuelve el valor de un arco recibiendo valores de vertices

	int getNumVertice(TipoG v);						//devuelve el numero de vertice conociendo su valor
	void nuevoVertice (TipoG v);						//crea un nuevo vertice recibiendo su valor

	bool adyacente(int va, int vb);					//determina si dos vertices son adyacentes recibiendo numeros de vertices
	bool adyacente(TipoG a, TipoG b);					//determina si dos vertices son adyacentes recibiendo sus valores
	ListaG listaAdyacencia(int v);					//metodo que devuelve la lista de adyacencia del vertice v
};

GrafoLista::GrafoLista() {							//constructor por defecto (sin parámetros)
	setMaxVerts(1);									//cantidad maxima de vertices por defecto
	setNumVerts(getMaxVerts());						//cantidad de vertices del grafo tomado de max.Num.Vertices
}

GrafoLista::GrafoLista(int v) {
	setMaxVerts(v);									//cantidad maxima de vertices por defecto
	setNumVerts(0);									//cantidad de vertices del grafo tomado de max.Num.Vertices
	verts = new Vertice[v] ; 						//inicializa vector de vértices con v elementos
	arcos = new ListaG*[v]; 						// vector de punteros a listas
	for (int i = 0; i < v; i++){					//recorre vector de arcos
		arcos[i] = new ListaG; 						//a cada elemento del vector le asigna una lista
	}
}

void GrafoLista::setMaxVerts(int n){				//actualiza cantidad maxima de vertices
	maxVerts = n;
}

void GrafoLista::setNumVerts(int n){		 		//actualiza numero de vertices
	numVerts = n;
}

void GrafoLista::setVertice(int va, Vertice v) {			//modifica los atributos de un vertice, conociendo su numero
	if ((va >= 0) && (va < getNumVerts())) {				//numero de vertice si existe en el grafo
		verts[va] = v;										//actualiza atributos
	} 
}

void GrafoLista::setVertice(TipoG a, Vertice v) {			//modifica los atributos de un vertice, conociendo su numero
	int va;													//variable para contener numero de vertice
	va = getNumVertice(a);									//calcula numero de vertice del primer nombre recibido
	if ((va >= 0) && (va < getNumVerts())) {				//numero de vertice si existe en el grafo
		verts[va] = v;										//actualiza atributos
	} 
}

void GrafoLista::setArco(int va, int vb){					//actualiza valor de arco recibiendo numeros de vertices en grafo no valorados
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts())){	//comprueba existencia de los dos vertices
		arcos[va] -> insertarAlFinal(verts[vb].getDato());					//añade un nuevo vertice en la lista de este elemento del vector
	}
}

void GrafoLista::setArco(int va, int vb, int v){			//actualiza valor de arco recibiendo numeros de vertices y factor de peso
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts())){	//comprueba existencia de los dos vertices
		arcos[va] -> insertarAlFinal(verts[vb].getDato(), v);				//añade un nuevo vertice en la lista de este elemento del vector
	}
}

void GrafoLista::setArco(TipoG a, TipoG b){					//actualiza valor de arco recibiendo nombres de vertices en grafos no valorados
	int va, vb;												//variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a);									//calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b);									//calcula numero de vertice del segundo nombre recibido
	if ((va >= 0) && (vb >= 0)) {							//comprueba existencia de los dos vertices
		arcos[va] -> insertarAlFinal(verts[vb].getDato());	//añade un nuevo vertice en la lista de este elemento del vector
	}
}

void GrafoLista::setArco(TipoG a, TipoG b, int v) {			//modifica el valor almacenado en lista de adyacencia, de dos vertices recibidos por su nombre
	int va, vb;												//variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a);									//calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b);									//calcula numero de vertice del segundo nombre recibido
	if ((va >= 0) && (vb >= 0)) {							//comprueba existencia de los dos vertices
		arcos[va] -> insertarAlFinal(verts[vb].getDato(), v);	//añade un nuevo vertice en la lista de este elemento del vector
 	}
}

int GrafoLista::getMaxVerts(){								//devuelve cantidad maxima de vertices
	return maxVerts;
}

int GrafoLista::getNumVerts(){								//devuelve cantidad de vertices
	return numVerts;
}

Vertice GrafoLista::getVertice(int va) {					//retorna todos los atributos del vértice, si existe en el grafo, conociendo su numero
	if ((va < 0) || (va >= getNumVerts())) {				//numero de vertice incorrecto
		Vertice x;
		return x;											//como Vértice no existe, devuelve vertice vacío
	} else {												//numero de vertice existente en el grafo
 		return verts[va];									//devuelve atributos del vertice
	}
}

Vertice GrafoLista::getVertice(TipoG a) {					//retorna todos los atributos del vértice si está almacenado en el grafo, conociendo su nombre
	int va;													//variable para contener numero de vertice
	va = getNumVertice(a);									//calcula numero de vertice del primer nombre recibido
	if ((va < 0) || (va >= numVerts)) {						//numero de vertice incorrecto
		Vertice x;
		return x;											//como Vértice no existe, devuelve vertice vacío
	} else {												//numero de vertice existente en el grafo
 		return verts[va];									//devuelve atributos del vertice
	}
}

bool GrafoLista::getArco(int va, int vb) {					//retorna el valor del arco almacenado en la matriz de adyacencia para dos numeros de vértices que recibe como parámetro por numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts())){	//comprueba existencia de los dos vertices
		return arcos[va] -> buscarValorEnLista(verts[vb].getDato()) != NULL;
	}
	return false;
}

bool GrafoLista::getArco(TipoG a, TipoG b) {					//retorna el valor del arco almacenado en la matriz de adyacencia para dos vértices que recibe como parámetro por nombre
	int va, vb;												//variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a);									//calcula numero de vertice correspondiente al primer nombre recibido
	vb = getNumVertice(b);									//calcula numero de vertice correspondiente al segundo nombre recibido
	if ((va >= 0) && (vb >= 0)) {							//comprueba existencia de los dos vertices
		return arcos[va] -> buscarValorEnLista(verts[vb].getDato()) != NULL;
	}
	return false;
}

int GrafoLista::getNumVertice(TipoG v) {						//determina el numero de un vertice dentro del grafo, conociendo su valor
	int i;													//var para recorrer vertices del grafo
	bool enc = false;										//var bandera para indicar si se encuentra

	for ( i = 0; (i < getNumVerts()) && !enc;) {			//ciclo de recorrido de vertices del grafo
		enc = verts[i].esIgualDato(v);						//comprueba si vertice tiene dato igual a parametro (metodo definido en Vertice.h)
		if (!enc) {											//aun no se encuentra vertice con ese valor	
			i++;											//continua la búsqueda
		}
	}
	return ((i < getNumVerts()) ? i : -1);					//retorna i (si se encontro) o -1 si no encuentra vertice con ese nombre
}

void GrafoLista::nuevoVertice(TipoG v) {						//crea un nuevo vertice recibiendo su valor
	bool existe = (getNumVertice(v) >= 0);					//determina si ese vertice ya existe

	if (!existe) {											//si no existe, es nuevo, por lo que lo crea
		if (getNumVerts() < getMaxVerts()){					//si numero de vertices existentes es menor que cantidad maxima de vertices del grafo
			Vertice nv = Vertice(v, numVerts);				//construye un nuevo vertice con el nombre recibido
			verts[numVerts] = nv; 							//incorpora el nuevo vertice en vector de vértices
			setNumVerts(getNumVerts()+1);					//incrementa cantidad de vertices existentes en el grafo
		}
	}
}

bool GrafoLista::adyacente(int va, int vb) {				//determina si dos vertices forman un arco conociendo su numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts())){	//comprueba existencia de los dos vertices
		return arcos[va] -> buscarValorEnLista(verts[vb].getDato()) != NULL;				
	} else {												//vertices no existentes
		return false;										//como no existen vertices, devuelve falso
	}
}

bool GrafoLista::adyacente(TipoG a, TipoG b) {				//determina si dos vertices forman un arco conociendo su nombre
	int va, vb;												//variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a);									//calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b);									//calcula numero de vertice del segundo nombre recibido

	if ((va >= 0) && (vb >= 0)) {							//si los dos vertices existen
		return arcos[va] -> buscarValorEnLista(verts[vb].getDato()) != NULL;	
	} else {												//vertices no existentes
		return false;										//como no existen vertices, devuelve falso
	}
}

ListaG GrafoLista::listaAdyacencia(int v){					//metodo que devuelve la lista de adyacencia del vertice v
	return *arcos[v];
}
#endif
