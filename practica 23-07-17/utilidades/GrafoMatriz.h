// grafomatriz.h
// Definicion de TDA Grafo implementado con Matriz de Adyacencia

#ifndef _GRAFOMATRIZ_H
#define _GRAFOMATRIZ_H

typedef int *pint; // para el dimensionamiento de la matriz

#include "./Vertice.h" //archivo de cabecera para definición de vértices

class GrafoMatriz
{					// definición de la clase
private:			// definición de atributos
	int maxVerts;	// máximo numero de vértices
	int numVerts;	// número de vértices que contiene el grafo
	Vertice *verts; // vector de vértices
	int **matAd;	// matriz de adyacencia

public:					// métodos públicos
	GrafoMatriz();		// constructor sin parámetros
	GrafoMatriz(int v); // constructor conociendo cantidad máxima de vértices
						// metodos que actualizan atributos
	void setMaxVerts(int n);			   // actualiza numero maximo de vertices
	void setNumVerts(int n);			   // actualiza numero de vertices existentes en grafo
	void setVertice(int va, Vertice v);	   // modifica los atributos de un vertice, conociendo su nombre
	void setVertice(TipoG a, Vertice v);   // modifica los atributos de un vertice, conociendo su nombre
	void setArco(int va, int vb);		   // actualiza valor de arco recibiendo numeros de vertices en grafo no valorados
	void setArco(int va, int vb, int v);   // actualiza valor de arco recibiendo numeros de vertices
	void setArco(TipoG a, TipoG b);		   // actualiza valor de arco recibiendo nombres de vertices en grafos no valorados
	void setArco(TipoG a, TipoG b, int v); // actualiza valor de arco recibiendo nombres de vertices
										   // metodos que devuelven estado de atributos
	int getMaxVerts();			   // devuelve numero maximo de vertices
	int getNumVerts();			   // devuelve cantidad de vertices existentes en grafo
	Vertice getVertice(int va);	   // devuelve atributos de un vertice, conociendo su numero
	Vertice getVertice(TipoG a);   // devuelve atributos de un vertice, conociendo su nombre
	int getArco(int va, int vb);   // devuelve el valor de un arco recibiendo numeros de vertices
	int getArco(TipoG a, TipoG b); // devuelve el valor de un arco recibiendo nombres de vertices

	int getNumVertice(TipoG v); // devuelve el numero de vertice conociendo su valor
	void nuevoVertice(TipoG v); // crea un nuevo vertice recibiendo su valor

	bool adyacente(int va, int vb);	  // determina si dos vertices son adyacentes recibiendo numeros de vertices
	bool adyacente(TipoG a, TipoG b); // determina si dos vertices son adyacentes recibiendo sus datos
};

GrafoMatriz::GrafoMatriz()
{								// constructor por defecto (sin parámetros)
	setMaxVerts(1);				// cantidad maxima de vertices por defecto
	setNumVerts(getMaxVerts()); // cantidad de vertices del grafo tomado de max.Num.Vertices
}

GrafoMatriz::GrafoMatriz(int v)
{							// constructor conociendo cantidad maxima de vértices
	setMaxVerts(v);			// actualiza cantidad maxima de vertices con el parámetro
	setNumVerts(0);			// actualiza numero de vertices del grafo con 0 (no existen vertices aun)
	verts = new Vertice[v]; // inicializa vector de vértices con v elementos
	matAd = new pint[v];	// inicializa //recorre filas de matriz de adyacenciamatriz de adyacencia con v filas
	for (int i = 0; i < v; i++)
	{
		matAd[i] = new int[v]; // crea v elementos asociados a este elemento de la matriz de adyacenciar inicializa cada elemento vector (fila) de matriz de adyacencia con "v" posibles arcos
		for (int j = 0; j < v; j++)
		{						  // recorre todos los "arcos" de cada elemento de la matriz de adyacencia
			matAd[i][j] = 0xFFFF; // inicializa cada "arco" con un valor por defecto (255 => 0xFFFF en haxadecimal)
		}
	}
}

void GrafoMatriz::setMaxVerts(int n)
{ // actualiza cantidad maxima de vertices
	maxVerts = n;
}

void GrafoMatriz::setNumVerts(int n)
{ // actualiza numero de vertices
	numVerts = n;
}

void GrafoMatriz::setVertice(int va, Vertice v)
{ // modifica los atributos de un vertice, conociendo su numero
	if ((va >= 0) && (va < getNumVerts()))
	{				   // numero de vertice si existe en el grafo
		verts[va] = v; // actualiza atributos
	}
}

void GrafoMatriz::setVertice(TipoG a, Vertice v)
{						   // modifica los atributos de un vertice, conociendo su dato
	int va;				   // variable para contener numero de vertice
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	if ((va >= 0) && (va < getNumVerts()))
	{				   // numero de vertice si existe en el grafo
		verts[va] = v; // actualiza atributos
	}
}

void GrafoMatriz::setArco(int va, int vb)
{ // actualiza valor del arco almacenado en matriz de adyacencia, de dos vertices recibidos por su numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{					   // comprueba existencia de los dos vertices
		matAd[va][vb] = 1; // actualiza valor del arco en la matriz de adyacencia
	}
}

void GrafoMatriz::setArco(int va, int vb, int v)
{ // actualiza valor del arco almacenado en matriz de adyacencia, de dos vertices recibidos por su numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{					   // comprueba existencia de los dos vertices
		matAd[va][vb] = v; // actualiza valor del arco en la matriz de adyacencia
	}
}

void GrafoMatriz::setArco(TipoG a, TipoG b)
{						   // actualiza valor del arco almacenado en matriz de adyacencia, de dos vertices recibidos por su nombre
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice del segundo nombre recibido
	if ((va >= 0) && (vb >= 0))
	{					   // comprueba existencia de los dos vertices
		matAd[va][vb] = 1; // actualiza valor en la matriz de adyacencia
	}
}

void GrafoMatriz::setArco(TipoG a, TipoG b, int v)
{						   // modifica el valor almacenado en matriz de adyacencia, de dos vertices recibidos por su nombre
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice del segundo nombre recibido
	if ((va >= 0) && (vb >= 0))
	{					   // comprueba existencia de los dos vertices
		matAd[va][vb] = v; // actualiza valor en la matriz de adyacencia
	}
}

int GrafoMatriz::getMaxVerts()
{ // devuelve cantidad maxima de vertices
	return maxVerts;
}

int GrafoMatriz::getNumVerts()
{ // devuelve cantidad de vertices
	return numVerts;
}

Vertice GrafoMatriz::getVertice(int va)
{ // retorna todos los atributos del vértice, si existe en el grafo, conociendo su numero
	if ((va < 0) || (va >= getNumVerts()))
	{ // numero de vertice incorrecto
		Vertice x;
		return x; // como Vértice no existe, devuelve vertice vacío
	}
	else
	{					  // numero de vertice existente en el grafo
		return verts[va]; // devuelve atributos del vertice
	}
}

Vertice GrafoMatriz::getVertice(TipoG a)
{						   // retorna todos los atributos del vértice si está almacenado en el grafo, conociendo su nombre
	int va;				   // variable para contener numero de vertice
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	if ((va < 0) || (va >= numVerts))
	{ // numero de vertice incorrecto
		Vertice x;
		return x; // como Vértice no existe, devuelve vertice vacío
	}
	else
	{					  // numero de vertice existente en el grafo
		return verts[va]; // devuelve atributos del vertice
	}
}

int GrafoMatriz::getArco(int va, int vb)
{ // retorna el valor del arco almacenado en la matriz de adyacencia para dos numeros de vértices que recibe como parámetro por numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{						  // comprueba existencia de los dos vertices
		return matAd[va][vb]; // devuelve el valor del arco almacenado en la matriz de adyacencia para estos vertices
	}
	else
	{			   // alguno de los vertices no existe
		return -1; // devuelve valor de error por defecto
	}
}

int GrafoMatriz::getArco(TipoG a, TipoG b)
{						   // retorna el valor del arco almacenado en la matriz de adyacencia para dos vértices que recibe como parámetro por nombre
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice correspondiente al primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice correspondiente al segundo nombre recibido
	if ((va >= 0) && (vb >= 0))
	{						  // comprueba existencia de los dos vertices
		return matAd[va][vb]; // devuelve el valor del arco almacenado en la matriz de adyacencia para estos vertices
	}
	else
	{			   // alguno de los dos vertices no existe
		return -1; // devuelve valor de error por defecto
	}
}

int GrafoMatriz::getNumVertice(TipoG v)
{					  // determina el numero de un vertice dentro del grafo, conociendo su valor
	int i;			  // var para recorrer vertices del grafo
	bool enc = false; // var bandera para indicar si se encuentra

	for (i = 0; (i < getNumVerts()) && !enc;)
	{								   // ciclo de recorrido de vertices del grafo
		enc = verts[i].esIgualDato(v); // comprueba si vertice tiene nombre igual a parametro (metodo definido en Vertice.h)
		if (!enc)
		{		 // aun no se encuentra vertice con ese valor
			i++; // continua la búsqueda
		}
	}
	return ((i < getNumVerts()) ? i : -1); // retorna i (si se encontro) o -1 si no encuentra vertice con ese nombre
}

void GrafoMatriz::nuevoVertice(TipoG v)
{										   // crea un nuevo vertice recibiendo su dato
	bool existe = (getNumVertice(v) >= 0); // determina si ese vertice ya existe

	if (!existe)
	{ // si no existe, es nuevo, por lo que lo crea
		if (getNumVerts() < getMaxVerts())
		{									   // si numero de vertices existentes es menor que cantidad maxima de vertices del grafo
			Vertice nv = Vertice(v, numVerts); // construye un nuevo vertice con el nombre recibido
			verts[numVerts] = nv;			   // incorpora el nuevo vertice en vector de vértices
			setNumVerts(getNumVerts() + 1);	   // incrementa cantidad de vertices existentes en el grafo
		}
	}
}

bool GrafoMatriz::adyacente(int va, int vb)
{ // determina si dos vertices forman un arco conociendo su numero
	if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts()))
	{									// comprueba existencia de los dos vertices
		return matAd[va][vb] != 0xFFFF; // comprueba existencia de este arco
	}
	else
	{				  // vertices no existentes
		return false; // como no existen vertices, devuelve falso
	}
}

bool GrafoMatriz::adyacente(TipoG a, TipoG b)
{						   // determina si dos vertices forman un arco conociendo su nombre
	int va, vb;			   // variables para contener numeros de los vertices recibidos por nombre
	va = getNumVertice(a); // calcula numero de vertice del primer nombre recibido
	vb = getNumVertice(b); // calcula numero de vertice del segundo nombre recibido

	if ((va >= 0) && (vb >= 0))
	{									  // si los dos vertices existen
		return (matAd[va][vb] != 0xFFFF); // comprueba existencia de este arco
	}
	else
	{				  // vertices no existentes
		return false; // como no existen vertices, devuelve falso
	}
}
#endif
