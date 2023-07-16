// recorreGrafo.h
// implementa recorridos en grafos

#ifndef _RECORREGRAFO_H
#define _RECORREGRAFO_H

typedef int Tipo;
#define EXT 99
#include "../utilidades/cola.h"
#include "../utilidades/pila.h"
#include "GrafoMatriz.h"
#include "GrafoLista.h"

class RecorreGrafo {					//definicion de la clase

public:
	int CLAVE; // Clave para vértice no marcado

	RecorreGrafo();						//constructor
	//operaciones con los recorridos con Matriz de adyacencia
	int* recorrerAnchuraMa(GrafoMatriz g, TipoG org);
	int* recorrerProfMa(GrafoMatriz g, TipoG org);
	int* recorrerAnchuraMa(GrafoMatriz g, int v);
	int* recorrerProfMa(GrafoMatriz g, int v);
	//operaciones con los recorridos con Lista de adyacencia
	int* recorrerAnchuraLa(GrafoLista g, TipoG org);
	int* recorrerProfLa(GrafoLista g, TipoG org);
	int* recorrerAnchuraLa(GrafoLista g, int v);
	int* recorrerProfLa(GrafoLista g, int v);
};

RecorreGrafo::RecorreGrafo(){								//constructor
		CLAVE = 0xffff;	 									//Clave vértice no marcado
	}

int* RecorreGrafo::recorrerAnchuraMa(GrafoMatriz g, int v){	//recorre grafo en anchura recibiendo numero de vertice inicial
	int w;
	Cola cola;
	int* m;

	if (v < 0 || v > g.getNumVerts()) {
		return m;			//Vértice no existe
	}
	m = new int[g.getNumVerts()];
								// inicializa los vértices como no marcados
	for (int i = 0; i < g.getNumVerts(); i++) {	//inicializa las claves de cada vertice
		m[i] = CLAVE;
	}
	m[v] = 0; // vértice origen queda marcado
	cola.enqueue(v);
	while (!cola.isEmpty()) {				//mientras haya elementos en la cola
		int cw;
		cw = cola.dequeue();					//extrae un vertice de la cola
		w = cw;
		cout << "Vertice [" << w << "] => " << g.getVertice(w).getDato() << " => visitado" << endl;
		// inserta en la cola los adyacentes de w no marcados
		for (int u = 0; u < g.getNumVerts(); u++){
			if (g.getArco(w,u) && m[u] == CLAVE) { 	// se marca vértice u con número de arcos hasta el
				m[u] = m[w] +1;	
				cola.enqueue(u);
			}
		}
	}
	return m;
}

int* RecorreGrafo::recorrerAnchuraMa(GrafoMatriz g, TipoG org) {	//recorre grafo en anchura recibiendo nombre de vertice inicial
	int v = g.getNumVertice(org);
	if (v >= 0){
		recorrerAnchuraMa(g,v);
	}

	return nullptr;
}	

int * RecorreGrafo::recorrerProfMa(GrafoMatriz g, int v) {  		//recorre grafo en profundidad recibiendo numero de vertice inicial
	int w;
	Pila pila;
	int* m;

	if (v < 0 || v > g.getNumVerts()) {
		return m; 													//Vertice de origen no existe
	}
	m = new int[g.getNumVerts()];
	// inicializa los vértices como no marcados
	for (int i = 0; i < g.getNumVerts(); i++) {
		m[i] = CLAVE;
	}
	m[v] = 0; // vértice origen queda marcado
	pila.push(v);
	while (!pila.isEmpty()) {
		int cw;
		cw = pila.pop();
		w = cw;
		cout << "Vertice [" << w << "] => " << g.getVertice(w).getDato() << " => visitado" << endl;
		// inserta en la pila los adyacentes de w no marcados
		for (int u = 0; u < g.getNumVerts(); u++) {
			if (g.getArco(w,u) != 0xffff  && m[u] == CLAVE) { // se marca vértice u con número de arcos hasta el
				m[u] = m[w] +1;
				pila.push(u);
			}
		}
	}
	return m;
}

int* RecorreGrafo::recorrerProfMa(GrafoMatriz g, TipoG org) {		//recorre grafo en profundidad recibiendo nombre de vertice inicial
	int v = g.getNumVertice(org);
	if (v >= 0){
		recorrerProfMa(g,v);
	}

	return nullptr;
}

int* RecorreGrafo::recorrerAnchuraLa(GrafoLista g, int v){		//recorre grafo en anchura recibiendo numero de vertice inicial
	int w;
	Cola cola;
	int* m;

	if (v < 0 || v > g.getNumVerts()) {
		return m; 												//Vértice no existe
	}
	m = new int[g.getNumVerts()];
	// inicializa los vértices como no marcados
	for (int i = 0; i < g.getNumVerts(); i++) {					//inicializa las claves de cada vertice
		m[i] = CLAVE;
	}
	m[v] = 0; 													// vértice origen queda marcado
	cola.enqueue(v);
	while (!cola.isEmpty()) {									//mientras haya elementos en la cola
		int cw;
		cw = cola.dequeue();										//extrae un vertice de la cola
		w = cw;
		cout << "Vertice [" << w << "] => " << g.getVertice(w).getDato() << " => visitado" << endl;
		// inserta en la cola los adyacentes de w no marcados
		for (int u = 0; u < g.getNumVerts(); u++){
			if (g.getArco(w,u) && m[u] == CLAVE) { 				// se marca vértice u con número de arcos hasta el
				m[u] = m[w] +1;
				cola.enqueue(u);
			}
		}
	}
	return m;
}

int* RecorreGrafo::recorrerAnchuraLa(GrafoLista g, TipoG org) {	//recorre grafo en anchura recibiendo nombre de vertice inicial
	
	int v = g.getNumVertice(org);
	if (v < 0){
		return NULL; 												//Vertice de origen no existe
	} 
	recorrerAnchuraLa(g,v);
	return nullptr;
}	

int* RecorreGrafo::recorrerProfLa(GrafoLista g, int v) {  			//recorre grafo en profundidad recibiendo numero de vertice inicial
	int w;
	Pila pila;
	int* m;

	if (v < 0 || v > g.getNumVerts()) {
		return NULL; 												//Vertice de origen no existe
	}
	m = new int[g.getNumVerts()];
	// inicializa los vértices como no marcados
	for (int i = 0; i < g.getNumVerts(); i++) {
		m[i] = CLAVE;
	}
	m[v] = 0; 														// vértice origen queda marcado
	pila.push(v);
	while (!pila.isEmpty()) {
		int cw;
		cw = pila.pop();
		w = cw;
		cout << "Vertice [" << w << "] => " << g.getVertice(w).getDato() << " => visitado" << endl;
		// inserta en la pila los adyacentes de w no marcados
		for (int u = 0; u < g.getNumVerts(); u++) {
			if (g.getArco(w,u) && m[u] == CLAVE) { 					// se marca vértice u con número de arcos hasta el
				m[u] = m[w] +1;
				pila.push(u);
			}
		}
	}
	return m;
}

int* RecorreGrafo::recorrerProfLa(GrafoLista g, TipoG org) {
	int v = g.getNumVertice(org);
	if (v < 0){
		return NULL; 												//Vertice de origen no existe
	}
	recorrerProfLa(g,v);

	return nullptr;
}
#endif