/**
Nombre: Andres Gaibor
Ingreso de un grafo,
y determine si al recorrer sus vértices (tanto en anchura como en
profundidad) se encuentran ordenados (ascendente o descendentemente)
*/
#include <iostream>
using namespace std;
#include "./utilidades/leerN.h"
#include "./utilidades/GrafoLista.h"
#include "./utilidades/RecorreGrafo.h"
// #include <vector>

GrafoMatriz ingresarVertices(int n1)
{ // funcion que ingresa los datos de los vértices de un grafo
    TipoG aux;
    GrafoMatriz a(n1);

    for (int i = 0; (i < n1); i++)
    {
        cout << endl
             << "Ingrese el nombre del vertice No. " << (i + 1) << ": ";
        std::getline(cin, aux);
        a.nuevoVertice(aux);
    }
    return a;
}

void ingresarArcos(GrafoMatriz *g)
{ // funcion que ingresa los datos de los arcos de un grafo
    int nv = g->getNumVerts();
    int na;
    TipoG aux;

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g->getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNum() + 1 << " - " << x.getDato() << " - ";
        cout << endl
             << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
        na = leerN(0, 10);
        cin.ignore();

        for (int j = 0; (j < na); j++)
        {
            cout << endl
                 << "Identificador del Vertice Destino: ";
            std::getline(cin, aux);
            g->setArco(x.getDato(), aux);
        }
    }
}

void ingresarArcosValor(GrafoMatriz *g)
{ // funcion que ingresa los datos de los arcos de un grafo incluido peso
    int nv = g->getNumVerts();
    int na;
    int peso; // peso del arco
    TipoG aux;

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g->getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNum() + 1 << " - " << x.getDato() << " - ";
        cout << endl
             << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
        na = leerN(0, 10);
        cin.ignore();

        for (int j = 0; (j < na); j++)
        {
            cout << endl
                 << "Identificador del Vertice Destino: ";
            std::getline(cin, aux);
            cout << endl
                 << "PESO DEL ARCO";
            peso = leerN(0, 100);
            cin.ignore();
            g->setArco(x.getDato(), aux, peso);
        }
    }
}

void imprimirGrafo(GrafoMatriz g)
{ // funcion que presenta los datos del grafo
    int nv = g.getNumVerts();
    int na;
    TipoG aux;
    cout << endl
         << "===============================================";
    cout << endl
         << "M A T R I Z     D E    A D Y A C E N C I A";

    for (int i = 0; (i < nv); i++)
    {
        Vertice x = g.getVertice(i);
        cout << endl
             << "Vertice No. " << x.getNum() + 1 << " - " << x.getDato() << " - ";

        for (int j = 0; (j < nv); j++)
        {
            if (g.adyacente(i, j))
            {
                Vertice x = g.getVertice(j);
                cout << endl
                     << "\t\t--->" << x.getDato();
            }
        }
    }
    cout << endl
         << "===============================================";
    cout << endl;
}

void recorrerGrafo(GrafoMatriz g)
{ // funcion que implementa recorrido de un grafo
    RecorreGrafo x;
    TipoG aux;

    cout << endl
         << "Identificador del Vertice de Origen: ";
    std::getline(cin, aux);

    cout << endl
         << "===============================================";
    cout << endl
         << "RECORRIDO DEL GRAFO EN ANCHURA\n"
         << endl;
    int *m = x.recorrerAnchuraMa(g, aux);
    cout << endl
         << "===============================================";

    cout << endl
         << "===============================================";
    cout << endl
         << "RECORRIDO DEL GRAFO EN PROFUNDIDAD\n"
         << endl;
    x.recorrerProfMa(g, aux);
    cout << endl
         << "===============================================";
}

int **matrizCaminos(GrafoMatriz g)
{                            // funcion que implementa el algoritmo de Warshall
    int n = g.getNumVerts(); // cantidad de vertices del grafo
    typedef int *pint;       // pint es tipo que apunta a punteros enteros
    int **P = new pint[n];   // P apunta a un vector de punteros enteros
    for (int i = 0; i < n; i++)
    {                      // recorre el vector P
        P[i] = new int[n]; // Cada elemento de P tiene un nuevo vector de enteros: es ahora una matriz de enteros
    }
    // Se obtiene la matriz inicial: matriz de adyacencia
    for (int i = 0; i < n; i++)
    { // recorre los vertices dispuestos en filas
        for (int j = 0; j < n; j++)
        {                                        // recorre los vertices dispuestos en columnas
            P[i][j] = g.adyacente(i, j) ? 1 : 0; // determina adyacencia entre vertices i y j
        }
    }
    // Desde P0 se obtienen P1, P2, P3 ,..., Pn-1, Pn que es la matriz de caminos
    for (int k = 0; k < n; k++)
    { // etapas de programación dinámica
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (P[i][k] * P[k][j])
                { // k es el indice de la programación dinámica
                    P[i][j] = 1;
                }
            }
        }
    }
    cout << endl
         << "===============================================";
    cout << endl
         << "MATRIZ DE CAMINOS" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Desde el vertice " << g.getVertice(i).getDato() << " se puede llegar a:";
        for (int j = 0; j < n; j++)
        {
            if (P[i][j])
            {
                cout << endl
                     << " ==> Vertice " << g.getVertice(j).getDato();
            }
        }
    }
    cout << endl
         << "===============================================";
    return P; // devuelve la matriz de caminos generada
}

void mayorGradoEntrada(GrafoMatriz g)
{
    int cantidadVertices = g.getNumVerts();
    int nAdyacentes;
    TipoG aux;
    int mayor = 0;
    int posVertice = 0;

    for (int i = 0; i < cantidadVertices; i++)
    {
        Vertice x = g.getVertice(i);

        nAdyacentes = 0;
        for (int j = 0; j < cantidadVertices; j++)
        {
            if (g.adyacente(j, i))
            {
                nAdyacentes++;
            }
        }

        if (nAdyacentes > mayor)
        {
            mayor = nAdyacentes;
            posVertice = i;
        }
    }

    cout << endl
         << "Vertice con mayor grado de entrada: " << g.getVertice(posVertice).getDato() << " con " << mayor << " arcos de entrada";
    cout << endl;
}

void mayorGradoSalida(GrafoMatriz g)
{
    int cantidadVertices = g.getNumVerts();
    int nAdyacentes;
    TipoG aux;
    int mayor = 0;
    int posVertice = 0;

    for (int i = 0; i < cantidadVertices; i++)
    {
        Vertice x = g.getVertice(i);

        nAdyacentes = 0;
        for (int j = 0; j < cantidadVertices; j++)
        {
            if (g.adyacente(i, j))
            {
                nAdyacentes++;
            }
        }

        if (nAdyacentes > mayor)
        {
            mayor = nAdyacentes;
            posVertice = i;
        }
    }

    cout << endl
         << "Vertice con mayor grado de salida: " << g.getVertice(posVertice).getDato() << " con " << mayor << " arcos de salida";
    cout << endl;
}

void rellenarVector(int vector[], int n, int valor)
{
    for (int i = 0; i < n; i++)
    {
        vector[i] = valor;
    }
}

bool recorridoBFS(GrafoMatriz g, int raiz, int orden = 1)
{
    int n = g.getNumVerts(); // cantidad de vertices del grafo
    int visitados[n];
    rellenarVector(visitados, n, 0);

    Cola q;
    q.enqueue(raiz);
    visitados[raiz] = 1;

    int valorAnterior = stoi(g.getVertice(raiz).getDato());

    while (!q.isEmpty())
    {
        int vActual = q.dequeue();

        for (int posAd = 0; posAd < n; ++posAd)
        {
            if (g.getArco(vActual, posAd) > 0 && visitados[posAd] == 0)
            {
                int datoActual = stoi(g.getVertice(posAd).getDato());

                if (datoActual * orden >= valorAnterior * orden)
                { // debe ser igual por si es igual
                    valorAnterior = datoActual;
                }
                else
                {
                    return false;
                }

                cout << "- Vertice " << posAd << " = " << datoActual << endl;

                q.enqueue(posAd);
                visitados[posAd] = 1;
            }
        }
    }

    return true;
}

bool recorridoDFS(GrafoMatriz g, int raiz, int orden = 1)
{
    int n = g.getNumVerts(); // cantidad de vertices del grafo
    int visitados[n];
    rellenarVector(visitados, n, 0);

    Pila q;
    q.push(raiz);
    visitados[raiz] = 1;

    int valorAnterior = stoi(g.getVertice(raiz).getDato());

    while (!q.isEmpty())
    {
        int vActual = q.pop();

        int datoActual = stoi(g.getVertice(vActual).getDato());
        cout << "- Vertice " << vActual << " = " << datoActual << endl;
        for (int posAd = 0; posAd < n; ++posAd)
        {
            if (g.getArco(vActual, posAd) != -1 && visitados[posAd] == 0)
            {

                if (datoActual * orden <= valorAnterior * orden)
                { // debe ser igual por si es igual
                    valorAnterior = datoActual;
                }
                else
                {
                    return false;
                }

                q.push(posAd);
                visitados[posAd] = 1;
            }
        }
    }

    return true;
}

int main()
{
    GrafoMatriz g; // declara un grafo para manipular las clases
    int n;         // cantidad de vertices a crear

    GrafoMatriz ingresarVertices(int n1);
    void ingresarArcos(GrafoMatriz * g);      // añade arcos => grafos no valorados
    void ingresarArcosValor(GrafoMatriz * g); // añade arcos => grafos valorados
    void recorrerGrafo(GrafoMatriz g);        // prototipo de la funcion que implementa recorrido de un grafo
    void imprimirGrafo(GrafoMatriz g);        // prototipo de la funcion que presenta los vertices del grafo
    int **matrizCaminos(GrafoMatriz g);       // prototipo de la funcion que implementa el algoritmo de Warshall
    // void calcularCaminoMinimo(GrafoMatriz g);	//prototipo de la funcion que calcula el camino minimo

    cout << endl
         << "CANTIDAD DE VERTICES DEL GRAFO";
    n = leerN(1, 20); // lectura de cantidad de vertices del grafo
    cin.ignore();

    g = ingresarVertices(n); // llamado a funcion de ingreso de los datos referentes al grafo
    ingresarArcos(&g);       // llamado a la funcion que ingresa los arcos del grafo
    // ingresarArcosValor(&g); // llamado a la funcion que ingresa los arcos valorados del grafo
    imprimirGrafo(g); // llamado a la funcion que imprime la matriz de adyacencia

    recorrerGrafo(g); // llamado a la funcion que recorre un grafo
    matrizCaminos(g); // llamado a la funcion que genera la matriz de caminos

    // 1
    mayorGradoEntrada(g);
    mayorGradoSalida(g);

    bool ordenadoBFSAsc = recorridoBFS(g, 0);
    cout << "El grafo " << (!ordenadoBFSAsc ? "NO " : "") << "esta ordenado por BFS Ascendentemente" << endl;

    bool ordenadoBFSDesc = recorridoBFS(g, 0, -1);
    cout << "El grafo " << (!ordenadoBFSDesc ? "NO " : "") << "esta ordenado por BFS Descendentemente" << endl;

    bool ordenadoDFSAsc = recorridoDFS(g, 0);
    cout << "El grafo " << (!ordenadoDFSAsc ? "NO " : "") << "esta ordenado por DFS Ascendentemente" << endl;

    bool ordenadoDFSDesc = recorridoDFS(g, 0, -1);
    cout << "El grafo " << (!ordenadoDFSDesc ? "NO " : "") << "esta ordenado por DFS Descendentemente" << endl;

    return 0;
}