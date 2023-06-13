using namespace std;
#include <iostream>
#include "../../utilidades/lista.h"
#define EXT 99999

void ingresarLista(Lista *l1)
{
    string linea;
    cout << endl
         << "Ingrese un dato (Presione Enter para dejar de ingresar): ";
    getline(cin, linea);

    if (linea.empty())
    {
        return;
    }

    int dato = stoi(linea);

    if (dato == NULL)
    {
        return;
    }

    cout << "Dato ingresado: " << dato << endl;

    l1->insertarFinal(dato);
    ingresarLista(l1);
}

void imprimirLista(Lista l1)
{
    if (l1.esVacia())
    {
        cout << "La lista esta vacia";
        return;
    }

    Nodo *act = l1.getPrimero();

    while (act != NULL)
    {
        cout << endl
             << "> " << act->getDato() << endl;
        act = act->getSiguiente();
    }
}

void buscarEnLista(Lista l)
{
    Tipo valor;
    cout << endl
         << "Ingrese un valor a buscar: ";
    cin >> valor;

    Nodo *res = l.buscarElemento(valor);

    if (res == NULL)
    {
        cout << "No se encontro [ " << valor << " ]";
    }
    else
    {
        cout << "Se encontro [ " << valor << " ]";
    }
}

void eliminarElemento(Lista *l)
{
    Tipo valor;
    cout << endl
         << "Ingrese un valor a eliminar: ";
    cin >> valor;

    bool res = l->eliminarNodoPorValor(valor);

    if (res)
    {
        cout << "Se elimino el elemento [ " << valor << " ]";
    }
    else
    {
        cout << "No se elimino el elemento [ " << valor << " ]";
    }
}

int main()
{
    Lista l, l2, l3;

    cout << "Valores a ingresar en la lista : " << endl;
    ingresarLista(&l);
    // cout << "Valores a ingresar en la lista : " << endl;
    // ingresarLista(&l2);
    // cout << "Valores ingresados en la lista : " << endl;
    // l3.intercalar(l.getPrimero(), l2.getPrimero(), &l3);
    // imprimirLista(l3);

    l.invertirLista();

    cout << "Primero " << l.getPrimero()->getDato() << endl;
    cout << "Ultimo " << l.ultimo()->getDato() << endl;

    imprimirLista(l);

    return 0;

    cout << "Valores ingresados en la lista inverso : " << endl;
    imprimirLista(l);
    cout << endl
         << "La cantidad de nodos en la lista es: " << l.contarNodos(l.getPrimero());

    system("pause");
    return 0;
}
