#ifndef utilidadesH

#define utilidadesH

#include <iostream>

using namespace std;

int leerN()
{		   // funcion que ingresa cantidad de valores a procesar
	int x; // var de lectura

	cout << endl
		 << "Ingrese un valor positivo: ";
	cin >>
		x;

	if (x < 1)
	{				 // valor no admitido
		x = leerN(); // volver a ingresar un valor
	}
	return x; // devolver el valor leido
}

int leerN(int li, int ls)
{		   // funcion que ingresa cantidad de valores a procesar
	int x; // var de lectura

	cout << endl
		 << "Ingrese un valor positivo: ";
	cin >> x;

	if ((x < li) || (x > ls))
	{				 // valor no admitido
		x = leerN(); // volver a ingresar un valor
	}
	return x; // devolver el valor leido
}

#endif