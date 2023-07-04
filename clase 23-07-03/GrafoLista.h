
// Definicion de TDA Grafo implementado con Lista de Adyacencia

#ifndef _GRAFOLISTA_H
#define _GRAFOLISTA_H

typedef int * pint;						//para el dimensionamiento de la matriz

#include "../utilidades/vertice.h"
#include "ListaG.h"

class GrafoLista {									//definicion de la clase
private:											//declaracion de atributos
	int maxVerts; 									//máximo numero de vértices
	int numVerts; 									//número de vértices que contiene el grafo
	Vertice* verts; 								//vector de vértices
	ListaG** arcos; 								//Lista de adyacencia
	bool esMenorAlMaximo(int n, int n2 = -1);

public:												// métodos públicos de la clase GrafoMatriz
	GrafoLista();									//constructor por defecto
	GrafoLista(int v);								//constructor conociendo cantidad máxima de vértices

	void setMaxVerts(int n);	 					//actualiza numero maximo de vertices
	void setNumVerts(int n);	 					//actualiza numero de vertices existentes en grafo
	void setVertice(int va, Vertice v);				//modifica los atributos de un vertice, conociendo su nombre
	void setVertice(Tipo a, Vertice v);				//modifica los atributos de un vertice, conociendo su nombre
	void setArco(int va, int vb);					//actualiza valor de arco recibiendo numeros de vertices en grafo no valorados
	void setArco(int va, int vb, int v);			//actualiza valor de arco recibiendo numeros de vertices
	void setArco(Tipo a, Tipo b);					//actualiza valor de arco recibiendo nombres de vertices en grafos no valorados
	void setArco(Tipo a, Tipo b, int v);			//actualiza valor de arco recibiendo nombres de vertices en grafos no valorados

	int getMaxVerts();								//devuelve numero maximo de vertices
	int cantidadVertices();								//devuelve cantidad de vertices existentes en grafo
	Vertice getVertice(int va);						//devuelve atributos de un vertice, conociendo su numero
	Vertice getVertice(Tipo a);						//devuelve atributos de un vertice, conociendo su valor
	bool getArco(int va, int vb);					//devuelve el valor de un arco recibiendo numeros de vertices
	bool getArco(Tipo a, Tipo b);					//devuelve el valor de un arco recibiendo valores de vertices

	int getNumVertice(Tipo v, int i = 0);						//devuelve el numero de vertice conociendo su valor
	void nuevoVertice (Tipo v);						//crea un nuevo vertice recibiendo su valor

	bool adyacente(int va, int vb);					//determina si dos vertices son adyacentes recibiendo numeros de vertices
	bool adyacente(Tipo a, Tipo b);					//determina si dos vertices son adyacentes recibiendo sus valores
	ListaG listaAdyacencia(int v);					//metodo que devuelve la lista de adyacencia del vertice v
};

GrafoLista::GrafoLista() {							//constructor por defecto (sin parámetros)
	setMaxVerts(1);									//cantidad maxima de vertices por defecto
	setNumVerts(getMaxVerts());						//cantidad de vertices del grafo tomado de max.Num.Vertices
}

GrafoLista::GrafoLista(int verticesMaximos) {
	setMaxVerts(verticesMaximos);									
	setNumVerts(0);									//cantidad de vertices del grafo tomado de max.Num.Vertices
	verts = new Vertice[verticesMaximos]; 						//inicializa vector de vértices con v elementos
	arcos = new ListaG*[verticesMaximos]; 						// vector de punteros a listas
	
	for (int i = 0; i < verticesMaximos; i++){
		arcos[i] = new ListaG; 						//a cada elemento del vector le asigna una lista
	}
}

void GrafoLista::setMaxVerts(int n) {
	maxVerts = n;
}

void GrafoLista::setNumVerts(int n) {		 		//actualiza numero de vertices
	numVerts = n;
}

bool GrafoLista::esMenorAlMaximo(int n, int n2) {
	bool c1 = (n >= 0 && n < cantidadVertices());
	bool def = (n2 == -1);

	bool c2 = def || (n2 >= 0 && n2 < cantidadVertices());

	return c1 && c2;
}

void GrafoLista::setVertice(int va, Vertice v) {			//modifica los atributos de un vertice, conociendo su numero
	if (esMenorAlMaximo(va)) {
		verts[va] = v;										//actualiza atributos
	} 
}

void GrafoLista::setVertice(Tipo a, Vertice v) {
	int pos = getNumVertice(a);									//calcula numero de vertice del primer nombre recibido
	
	setVertice(pos, v);
}

void GrafoLista::setArco(int posVa, int posVb){					//actualiza valor de arco recibiendo numeros de vertices en grafo no valorados
	if (esMenorAlMaximo(posVa, posVb)){
		arcos[posVa]->insertarAlFinal(verts[posVb].getDato());					//añade un nuevo vertice en la lista de este elemento del vector
	}
}

void GrafoLista::setArco(int va, int vb, int peso) {			//actualiza peso de arco recibiendo numeros de vertices y factor de peso
	setArco(va, vb);

	arcos[va]->ultimoValorDeLista()->setPeso(peso);
}

void GrafoLista::setArco(Tipo a, Tipo b){					//actualiza valor de arco recibiendo nombres de vertices en grafos no valorados
	int va, vb;												//variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a);									//calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b);									//calcula numero de vertice del segundo nombre recibido
	
	setArco(va, vb);
}

void GrafoLista::setArco(Tipo a, Tipo b, int v) {			//modifica el valor almacenado en lista de adyacencia, de dos vertices recibidos por su nombre
	int va, vb;												//variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a);									//calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b);									//calcula numero de vertice del segundo nombre recibido
	
	setArco(va, vb, v);
}

int GrafoLista::getMaxVerts(){								//devuelve cantidad maxima de vertices
	return maxVerts;
}

int GrafoLista::cantidadVertices(){								//devuelve cantidad de vertices
	return numVerts;
}

Vertice GrafoLista::getVertice(int va) {					//retorna todos los atributos del vértice, si existe en el grafo, conociendo su numero
	if ((va < 0) || (va >= cantidadVertices())) {				//numero de vertice incorrecto
		Vertice x;
		return x;											//como Vértice no existe, devuelve vertice vacío
	}												//numero de vertice existente en el grafo
 	return verts[va];									//devuelve atributos del vertice
	
}

Vertice GrafoLista::getVertice(Tipo a) {					//retorna todos los atributos del vértice si está almacenado en el grafo, conociendo su nombre
	int va = getNumVertice(a);									//calcula numero de vertice del primer nombre recibido
	
	return getVertice(va);
}

bool GrafoLista::getArco(int va, int vb) {					//retorna el valor del arco almacenado en la matriz de adyacencia para dos numeros de vértices que recibe como parámetro por numero
	if (esMenorAlMaximo(va, vb)){	//comprueba existencia de los dos vertices
		return arcos[va]->buscarValorEnLista(verts[vb].getDato()) != NULL;
	}

	return false;
}

bool GrafoLista::getArco(Tipo a, Tipo b) {					//retorna el valor del arco almacenado en la matriz de adyacencia para dos vértices que recibe como parámetro por nombre
	int va, vb;												//variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a);									//calcula numero de vertice correspondiente al primer nombre recibido
	vb = getNumVertice(b);									//calcula numero de vertice correspondiente al segundo nombre recibido
	
	return getArco(va, vb);
}

int GrafoLista::getNumVertice(Tipo v, int i) {						//determina el numero de un vertice dentro del grafo, conociendo su valor
	if(i >= cantidadVertices()) {
		return -1;
	}

	if(verts[i].esIgualDato(v)) {
		return i;
	}

	return getNumVertice(v, i + 1);
}

void GrafoLista::nuevoVertice(Tipo v) {
	bool existe = (getNumVertice(v) != -1);
	if(existe && cantidadVertices() >= getMaxVerts()) {
		return;
	}

	Vertice nv = Vertice(v, cantidadVertices());				//construye un nuevo vertice con el nombre recibido
	verts[numVerts] = nv; 							//incorpora el nuevo vertice en vector de vértices
	setNumVerts(cantidadVertices() + 1);					//incrementa cantidad de vertices existentes en el grafo
}

bool GrafoLista::adyacente(int va, int vb) {				//determina si dos vertices forman un arco conociendo su numero
	if (esMenorAlMaximo(va, vb)){	//comprueba existencia de los dos vertices
		return arcos[va] -> buscarValorEnLista(verts[vb].getDato()) != NULL;				
	}												//vertices no existentes
	return false;										//como no existen vertices, devuelve falso
	
}

bool GrafoLista::adyacente(Tipo a, Tipo b) {				//determina si dos vertices forman un arco conociendo su nombre
	return getArco(a, b);								//como no existen vertices, devuelve falso
}

ListaG GrafoLista::listaAdyacencia(int v){					//metodo que devuelve la lista de adyacencia del vertice v
	return *arcos[v];
}

#endif