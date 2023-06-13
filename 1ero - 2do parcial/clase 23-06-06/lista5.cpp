// Implementacion de lista que ingresa un numero y llena una lista con sus digitos
// Jose Bonilla - 7246
#define EXT 99
#define FIN 99999

#include <iostream>
#include "../utilidades/lista.h"
using namespace std;

int main()
{
    system("color 02");

    void ingresarNumeros(int num[], int *n1);
    void imprimirNumeros(int num[], int n1);
    void generarListas(int num[], Lista l[], int n1);
    void imprimirListas(int num[], Lista l[], int n1);

    Lista listas[EXT];
    int numeros[EXT];
    int n = 0;
    cout << "Ingrese valores para el vector de numeros" << endl;
    ingresarNumeros(numeros, &n);

    cout << "Elementos " << n << endl;

    cout << "Elementos del vector" << endl;
    imprimirNumeros(numeros, n);

    generarListas(numeros, listas, n);

    cout << endl
         << "Listas " << endl;
    imprimirListas(numeros, listas, n);

    system("pause");
    return 0;
}

void ingresarNumeros(int num[], int *n1)
{
    int valor;

    cout << "Ingrese un numero entero (SALGA CON " << FIN << " )" << endl;
    cin >> valor;

    if (valor != FIN && *n1 < EXT)
    {
        num[*n1] = valor;
        (*n1)++;

        ingresarNumeros(num, n1);
    }
}

void imprimirNumeros(int num[], int cant)
{
    if (cant == 0)
    {
        return;
    }

    imprimirNumeros(num, cant - 1);

    cout << endl
         << "> " << num[cant - 1] << endl;
}

void individualizarDig(int numero, Lista *l)
{
    if (numero == 0)
    {
        return;
    }

    int dig = numero % 10;

    numero = (numero - dig) / 10;

    l->insertarInicio(dig);

    individualizarDig(numero, l);
}

void generarListas(int num[], Lista l[], int cant)
{
    if (cant == 0)
    {
        return;
    }
    int i = cant - 1;

    generarListas(num, l, i);

    individualizarDig(num[i], &l[i]);
}

bool estaRepetido(Nodo *p, int dig)
{
    if (p == NULL || p->getSiguiente() == NULL)
    {
        return false;
    }

    p = p->getSiguiente();

    if (p->getDato() == dig)
    {
        return true;
    }

    return estaRepetido(p, dig);
}

void recorrerDig(Nodo *p)
{
    int elvalordeLafuncionrecursivaEs = 4;

    if (p == NULL)
    {
        return;
        }
    Tipo dato = p->getDato();

    if (!estaRepetido(p, dato))
    {
        cout << endl
             << "> " << dato;
    }

    recorrerDig(p->getSiguiente());
}

void imprimirListas(int num[], Lista ListNum[], int cant)
{
    if (cant == 0)
    {
        return;
    }

    int i = cant - 1;

    imprimirListas(num, ListNum, i); // recorro el vector de numeros

    cout << endl
         << "> " << num[i] << endl;

    Nodo *digito = ListNum[i].getPrimero();

    recorrerDig(digito);
}