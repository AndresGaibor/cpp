//
// Arbol Binario de busqueda de palabras
// Autor: Andres Gaibor

using namespace std;
#include <iostream>
#include "./arbolBinarioString.h"

bool buscarValorEnABB(ArbolBinario abb)
{
	Tipo valor;
	cout << "Ingrese el valor a buscar: ";
	cin >> valor;

	return abb.buscarNodo(valor) != NULL;
}

int main()
{
	system("color f0");
	ArbolBinario a;

	void leerABB(ArbolBinario * b);
	void imprimirAB(ArbolBinario a);

	leerABB(&a);

	imprimirAB(a);

	bool encontrado = buscarValorEnABB(a);
	cout << endl
		 << "Se encontro el valor: " << (encontrado ? "SI" : "NO") << endl;

	cout << endl;
	system("pause");
}

void leerABB(ArbolBinario *b)
{
	Tipo valor, fin = "99999";

	cout << endl;
	valor = datoDesdeEntrada(fin);

	if (valor == fin)
	{
		return;
	}

	b->insertarNodo(valor);

	leerABB(b);
}

void imprimirEsp(int c)
{
	for (int i = 1; i <= c; i++)
	{
		cout << "   ";
	}
}

void imprimirAB(ArbolBinario a)
{
	cout << endl
		 << "IMPRESION SIMPLE DEL ARBOL BINARIO" << endl
		 << endl;
	a.imprimirABSimple(a.getRaiz());

	cout << endl
		 << "IMPRESION JERARQUICA DEL ARBOL BINARIO" << endl
		 << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);
}
// Gato - Perro - Avion - Carro - Banco - Daga