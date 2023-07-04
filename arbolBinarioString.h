// ArbolBinario String
// Clase que contiene metodos de gestion de un AB de strings

#ifndef _ARBOL_BINARIOS_H
#define _ARBOL_BINARIOS_H

#include "nodoArbolString.h"
#include <iostream>

class ArbolBinario
{
private:
	NodoBinario *raiz;
	NodoBinario *leerNodo(int margen);
	void inorden(NodoBinario *r);
	void preorden(NodoBinario *r);
	void postorden(NodoBinario *r);
	NodoBinario *insertar(NodoBinario *r, Tipo valor);
	NodoBinario *eliminar(NodoBinario *r, Tipo valor);
	NodoBinario *buscar(NodoBinario *r, Tipo v);
	NodoBinario *reemplazar(NodoBinario *r);

public:
	ArbolBinario();

	void setRaiz(NodoBinario *v);
	NodoBinario *getRaiz();

	bool esVacio();
	NodoBinario *construirAB(Tipo dato, NodoBinario *i, NodoBinario *d);

	void leer();
	void imprimirABSimple(NodoBinario *p);
	void imprimirABJerarquia(NodoBinario *p, int n);

	int contarNodos(NodoBinario *r);
	int calcularAltura(NodoBinario *r);
	void verHojas(NodoBinario *r);

	void recorrerEnPreorden();
	void recorrerEnInorden();
	void recorrerEnPostorden();

	void insertarNodo(Tipo valor);
	void eliminarNodo(Tipo valor);
	NodoBinario *buscarNodo(Tipo v);

	void vaciar(NodoBinario *r);
	NodoBinario *nodoHijoIzq();
	NodoBinario *nodoHijoDer();

	bool arbolLleno(NodoBinario *r);
	void copiaArbol(ArbolBinario &a);
	NodoBinario *copiarArbol(NodoBinario *r);
};

void imprimirEspacio(int cantidadEspacios)
{
	if (cantidadEspacios == 0)
	{
		return;
	}

	cout << "   ";

	imprimirEspacio(cantidadEspacios - 1);
}

NodoBinario *ArbolBinario::construirAB(Tipo dato, NodoBinario *i, NodoBinario *d)
{
	return new NodoBinario(dato, i, d);
}

Tipo leerValor(int fin = 99999)
{
	Tipo valor;

	cout << "Ingrese valor para el nodo. Ingrese [" << fin << "] para terminar: ";
	cin >> valor;

	return valor;
}

Tipo datoDesdeEntrada(Tipo fin = "99999", string mensaje = "Ingrese valor para el nodo")
{
	string linea;
	cout << endl
		 << mensaje << "(Presione Enter para dejar de ingresar): ";
	getline(cin, linea);

	if (linea.empty())
	{
		return fin;
	}

	return linea;
}

NodoBinario *ArbolBinario::leerNodo(int margen = 0)
{
	Tipo valor, fin = "99999";
	NodoBinario *nuevoN;

	cout << endl;

	valor = datoDesdeEntrada(fin);

	if (valor == fin)
	{
		return NULL;
	}

	nuevoN = new NodoBinario(valor);

	imprimirEspacio(margen);

	cout << "--- SUBARBOL IZQUIERDO(N. PADRE " << nuevoN->getDato() << ") ---";
	nuevoN->setHijoIzquierdo(leerNodo(margen + 1));
	imprimirEspacio(margen);

	cout << "--- SUBARBOL DERECHO(N. PADRE " << nuevoN->getDato() << ") ---";
	nuevoN->setHijoDerecho(leerNodo(margen + 1));

	return nuevoN;
}

void ArbolBinario::leer()
{
	setRaiz(leerNodo());
}

void ArbolBinario::preorden(NodoBinario *r)
{
	if (r == NULL)
	{
		return;
	}
	cout << " " << r->getDato();
	preorden(r->getHijoIzquierdo());
	preorden(r->getHijoDerecho());
}

void ArbolBinario::inorden(NodoBinario *r)
{
	if (r == NULL)
	{
		return;
	}
	inorden(r->getHijoIzquierdo());
	cout << " " << r->getDato();
	inorden(r->getHijoDerecho());
}

void ArbolBinario::postorden(NodoBinario *r)
{
	if (r == NULL)
	{
		return;
	}
	postorden(r->getHijoIzquierdo());
	postorden(r->getHijoDerecho());
	cout << " " << r->getDato();
}

NodoBinario *ArbolBinario::insertar(NodoBinario *rSub, Tipo valor)
{
	if (rSub == NULL)
	{ // arbol vacio
		rSub = new NodoBinario(valor);
		return rSub;
	}

	if (valor == rSub->getDato())
	{ // si valor se repite no ingreses
		return rSub;
	}

	if (stringToAscii(valor) < stringToAscii(rSub->getDato()))
	{
		NodoBinario *iz = insertar(rSub->getHijoIzquierdo(), valor);
		rSub->setHijoIzquierdo(iz);
	}
	else
	{
		NodoBinario *dr = insertar(rSub->getHijoDerecho(), valor);
		rSub->setHijoDerecho(dr);
	}

	return rSub;
}

void ArbolBinario::insertarNodo(Tipo v)
{
	setRaiz(insertar(getRaiz(), v));
}

NodoBinario *ArbolBinario::reemplazar(NodoBinario *act)
{
	NodoBinario *aux, *p;
	p = act;
	aux = act->getHijoIzquierdo(); // rama de nodos menores

	while (aux->getHijoDerecho() != NULL)
	{
		p = aux;
		aux = aux->getHijoDerecho();
	}

	act->setDato(aux->getDato()); // copia en act el valor del nodo apuntado por a

	if (p == act)
	{
		p->setHijoIzquierdo(aux->getHijoIzquierdo()); // enlaza subarbol izquierdo
	}
	else
	{												// a no es hijo izq de act
		p->setHijoDerecho(aux->getHijoIzquierdo()); // se enlaza subarbol derecho
	}
	return aux;
}

NodoBinario *ArbolBinario::eliminar(NodoBinario *rSub, Tipo v)
{
	if (rSub == NULL)
	{
		return NULL;
	}

	if (v == rSub->getDato())
	{
		NodoBinario *q = rSub;

		if (q->getHijoIzquierdo() == NULL)
		{
			rSub = q->getHijoDerecho();
		}
		else if (q->getHijoDerecho() == NULL)
		{
			rSub = q->getHijoIzquierdo();
		}
		else
		{
			q = reemplazar(q);
		}

		q = NULL;

		return rSub;
	}

	if (v < rSub->getDato())
	{
		NodoBinario *iz = eliminar(rSub->getHijoIzquierdo(), v);
		rSub->setHijoIzquierdo(iz);
	}
	else
	{
		NodoBinario *dr = eliminar(rSub->getHijoDerecho(), v);
		rSub->setHijoDerecho(dr);
	}

	return rSub;
}

void ArbolBinario::eliminarNodo(Tipo v)
{
	setRaiz(eliminar(getRaiz(), v));
}

NodoBinario *ArbolBinario::buscar(NodoBinario *rSub, Tipo v)
{
	if (rSub == NULL)
	{ // Se recorrio toda la rama y no se encontro
		return NULL;
	}

	if (v == rSub->getDato())
	{ // Se encontro
		return rSub;
	}

	NodoBinario *hijo = NULL;

	if (stringToAscii(v) < stringToAscii(rSub->getDato()))
	{
		hijo = rSub->getHijoIzquierdo();
	}
	else
	{
		hijo = rSub->getHijoDerecho();
	}

	return buscar(hijo, v);
}

ArbolBinario::ArbolBinario()
{
	setRaiz(NULL);
}

void ArbolBinario::setRaiz(NodoBinario *v)
{
	raiz = v;
}

NodoBinario *ArbolBinario::getRaiz()
{
	return raiz;
}

bool ArbolBinario::esVacio()
{
	return (getRaiz() == NULL);
}

void ArbolBinario::imprimirABSimple(NodoBinario *p)
{
	if (p == NULL)
	{
		return;
	}

	cout << endl
		 << "> " << p->getDato();
	imprimirABSimple(p->getHijoIzquierdo());
	imprimirABSimple(p->getHijoDerecho());
}

void ArbolBinario::imprimirABJerarquia(NodoBinario *p, int n)
{
	if (p == NULL)
	{
		return;
	}

	imprimirABJerarquia(p->getHijoDerecho(), n + 1);
	imprimirEspacio(n);
	cout << p->getDato() << endl;
	imprimirABJerarquia(p->getHijoIzquierdo(), n + 1);
}

int ArbolBinario::contarNodos(NodoBinario *r)
{
	if (r == NULL)
	{
		return 0;
	}

	return 1 + contarNodos(r->getHijoIzquierdo()) + contarNodos(r->getHijoDerecho());
}

int ArbolBinario::calcularAltura(NodoBinario *r)
{
	if (r == NULL)
	{
		return 0;
	}

	int alturaIz = calcularAltura(r->getHijoIzquierdo());
	int alturaDr = calcularAltura(r->getHijoDerecho());

	if (alturaIz > alturaDr)
	{
		return alturaIz + 1;
	}
	else
	{
		return alturaDr + 1;
	}
}

void ArbolBinario::recorrerEnPreorden()
{						 // recorrido en preorden
	preorden(getRaiz()); // llama a metodo interno de recorrido
}

void ArbolBinario::recorrerEnInorden()
{						// recorrido en ineorden
	inorden(getRaiz()); // llama a metodo interno de recorrido
}

void ArbolBinario::recorrerEnPostorden()
{						  // recorrido en postorden
	postorden(getRaiz()); // llama a metodo interno de recorrido
}

void ArbolBinario::verHojas(NodoBinario *nodo)
{
	if (nodo == NULL)
	{
		return;
	}

	NodoBinario *hDer, *hIzq;

	hIzq = nodo->getHijoIzquierdo();
	hDer = nodo->getHijoDerecho();

	if ((hIzq == NULL) && (hDer == NULL))
	{
		cout << endl
			 << "> " << nodo->getDato();
		return;
	}

	verHojas(hIzq);
	verHojas(hDer);
}

NodoBinario *ArbolBinario::buscarNodo(Tipo v)
{								 // permite buscar y encontrar un nodo con valor v en un arbol binario
	return buscar(getRaiz(), v); // llama a metodo interno de búsqueda
}

void ArbolBinario::vaciar(NodoBinario *r)
{
	if (r != NULL)
	{
		vaciar(r->getHijoIzquierdo());
		vaciar(r->getHijoDerecho());
		r = NULL;
	}
}

NodoBinario *ArbolBinario::nodoHijoIzq()
{ // devuelve direccion del hijo del lado izquierdo
	if (getRaiz())
	{
		return getRaiz()->getHijoIzquierdo(); // devuelve valor apuntado por ramal izq
	}
	else
	{
		return NULL; // arbol vacio
	}
}

NodoBinario *ArbolBinario::nodoHijoDer()
{ // devuelve direccion del hijo del lado derecho
	if (getRaiz())
		return getRaiz()->getHijoDerecho(); // devuelve direccion apuntada por ramal derecjho
	else
		return NULL; // arbol vacio
}

bool ArbolBinario::arbolLleno(NodoBinario *r)
{ // determina si el arbol es lleno o no
	if (r == NULL)
	{				 // arbol vacio
		return true; // si es arbol lleno
	}
	else
	{ // si hay nodos
		if (ArbolBinario::calcularAltura(r->getHijoIzquierdo()) != ArbolBinario::calcularAltura(r->getHijoDerecho()))
		{				  // altura de ramal izq diferente de altura ramal derecho
			return false; // no es arbol lleno
		}
	}
	return arbolLleno(r->getHijoIzquierdo()) && arbolLleno(r->getHijoDerecho());
}

void ArbolBinario::copiaArbol(ArbolBinario &a)
{
	a.setRaiz(copiarArbol(this->raiz));
}

NodoBinario *ArbolBinario::copiarArbol(NodoBinario *r)
{
	NodoBinario *rCop; // nodo copia

	if (r == NULL)
	{				 // no hay nodos en arbol
		rCop = NULL; // en la copia pone null porque arbol esta vacio
	}
	else
	{														  // arbol no vacio
		NodoBinario *izqCop, *derCop;						  // dos nuevos nodos
		izqCop = copiarArbol(r->getHijoIzquierdo());		  // en nuevo izq, pone copia de ramal izq original
		derCop = copiarArbol(r->getHijoDerecho());			  // en nuevo der, pone copia de ramal der del original
		rCop = new NodoBinario(r->getDato(), izqCop, derCop); // crea nuevo nodo
	}
	return rCop; // devuelve apuntador a la copa
}

#endif
