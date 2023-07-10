// Grafo3.cpp
// GESTIONA UN GRAFO CON LISTA DE ADYACENCIA

#include <iostream>
using namespace std;
#include "GrafoLista.h"


int leerN(){		//funcion que ingresa cantidad de valores a procesar
	int x; 			//var de lectura
	
	cout << endl << "Ingrese un valor positivo: ";
	cin >> x;
	
	if (x < 1){			//valor no admitido
		x = leerN();	//volver a ingresar un valor 
	}
	return x;		//devolver el valor leido
}

int leerN(int li, int ls){		//funcion que ingresa cantidad de valores a procesar
	int x; 			//var de lectura
	
	cout << endl << "Ingrese un valor positivo: ";
	cin >> x;
	
	if ((x < li) || (x > ls)){			//valor no admitido
		x = leerN();	//volver a ingresar un valor 
	}
	return x;		//devolver el valor leido
}

int main(){
	system("color fc");							//interfaz
	GrafoLista g;								//declara un grafo para manipular las clases
	int n;										//cantidad de vertices a crear
	
	GrafoLista ingresarVertices(int n1);
	void ingresarArcos(GrafoLista *g);			//añade arcos => grafos no valorados
	void ingresarArcosValor(GrafoLista *g);		//añade arcos => grafos valorados
	void imprimirGrafo(GrafoLista g);			//prototipo de la funcion que presenta los vertices del grafo
	void imprimirLista(GrafoLista g);			//prototipo de la funcion que presenta los vertices apuntados desde cada uno, y su peso
	
	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);					//llamado a funcion de ingreso de los datos referentes al grafo
	// ingresarArcos(&g);							//llamado a la funcion que ingresa los arcos del grafo
	ingresarArcosValor(&g);					//llamado a la funcion que ingresa los arcos valorados del grafo
	imprimirGrafo(g);							//llamado a la funcion que imprime la matriz de adyacencia
	//imprimirLista(g);
	
	cout << endl;
	system("pause");
}

GrafoLista ingresarVertices(int n1){			//funcion que ingresa los datos de los vértices de un grafo
	Tipo aux;
	GrafoLista a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux; 
		a.nuevoVertice(aux);
	}
	return a;
}
void tituloVertice(Vertice x){
	cout << endl << "Vertice #" << x.getNum() + 1 << " - " << x.getDato() << " - ";
}

void ingresarArcos(GrafoLista *g){				//funcion que ingresa los datos de los arcos de un grafo
	int numeroVertices = g->cantidadVertices();
	
	int cantidadArcos;
	Tipo valorVerticeB;

	for (int i = 0; (i < numeroVertices); i++){
		Vertice x = g->getVertice(i);
		tituloVertice(x);
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		
		cantidadArcos = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; j < cantidadArcos; j++){
			cout << endl << "Valor del Vertice Destino: ";
			string linea;
			getline(cin, linea);
			valorVerticeB = linea;
			g->setArco(x.getDato(), valorVerticeB);
		}
	}
}



void ingresarArcosValor(GrafoLista *g){
	int numeroVertices = g -> cantidadVertices();
	int na, peso;
	Tipo aux;

	for (int i = 0; (i < numeroVertices); i++){
		Vertice x = g -> getVertice(i);
		tituloVertice(x);
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; j < na; j++){
			cout << endl << "Valor del Vertice Destino: ";
			cin >> aux; 
			cout << endl << "PESO DEL ARCO";
			peso = leerN(0, 100);
			cin.ignore();
			g -> setArco(x.getDato(), aux, peso);
		}
	}
}

void imprimirGrafo(GrafoLista g) {
	int nv = g.cantidadVertices();

	cout << endl << "nv " << nv;

	int na;
	Tipo aux;
	cout << endl << "===============================================";
	cout << endl << "L I S T A    D E    A D Y A C E N C I A";

	for (int i = 0; i < nv; i++){
		Vertice x = g.getVertice(i);
		tituloVertice(x);

		for (int j = 0; (j < nv); j++){
			if (g.adyacente(i,j)){
				Vertice x = g.getVertice(j);
				cout << endl << "\t\t--->" << x.getDato();
			}
		}
	}
	cout << endl << "===============================================";
	cout << endl;
}

void mostrarArcos(NodoG* arco) {
	if(arco == nullptr) {
		return;
	}

	cout << arco->getDato() << " > " << arco->getPeso() << endl;
	mostrarArcos(arco->getPunt());
}

void imprimirLista(GrafoLista g){
	cout << endl << "ELEMENTOS CONTENIDOS EN LA LISTA";

	for (int i = 0; i < g.cantidadVertices(); i++){
		Vertice x = g.getVertice(i);
		tituloVertice(x);

		ListaG listaArcos = g.listaAdyacencia(i);

		mostrarArcos(listaArcos.getPrimero());
	}
}
