#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

// Se desea implementar un sistema de gestión de biblioteca, de acuerdo a lo establecido en los siguientes puntos:

// Se debe definir una estructura llamada Libro que contenga los siguientes campos:
// Título
// Autor
// Género
// Número de páginas
// Disponibilidad (un valor booleano que indique si el libro está disponible o prestado)
struct Libro
{
    string titulo;
    string autor;
    string genero;
    int numPaginas;
    bool disponibilidad = true;
};

void agregarLibro(Libro libros[], int &contador);
void mostrarLibro(Libro libro);
int obtenerCriterioBusqueda();
int buscarLibro(Libro libros[], int cantidad_libros);
int prestarLibro(Libro libros[], int cantidad_libros);
int devolverLibro(Libro libros[], int cantidad_libros);
int orderLibros(Libro libros[], int cantidad_libros);
int menu();


int main()
{
    Libro libros[100];
    int cantidad_libros = 0;

    int opcion = menu();

    while(opcion != 6) {
        switch(opcion) {
            case 1:
                agregarLibro(libros, cantidad_libros);
                // pausar
                system("pause");
                cout << "Presiona Enter para continuar..." << endl;
                cin.get();
                return 0;
                break;
            case 2:
                buscarLibro(libros, cantidad_libros);
                // pausar
                system("pause");
                cout << "Presiona Enter para continuar..." << endl;
                cin.get();
                return 0;
                
                break;
            case 3:
                prestarLibro(libros, cantidad_libros);
                system("pause");
                cout << "Presiona Enter para continuar..." << endl;
                cin.get();
                return 0;
                break;
            case 4:
                devolverLibro(libros, cantidad_libros);
                system("pause");
                cout << "Presiona Enter para continuar..." << endl;
                cin.get();
                return 0;
                break;
            case 5:
                orderLibros(libros, cantidad_libros);
                system("pause");
                cout << "Presiona Enter para continuar..." << endl;
                cin.get();
                return 0;
                break;
        }

        opcion = menu();
    }

}

void agregarLibro(Libro libros[], int &contador)
{
    cout << "Ingrese el título del libro: ";
    getline(cin, libros[contador].titulo);
    cout << "Ingrese el autor del libro: ";
    getline(cin, libros[contador].autor);
    cout << "Ingrese el género del libro: ";
    getline(cin, libros[contador].genero);
    cout << "Ingrese el número de páginas del libro: ";
    cin >> libros[contador].numPaginas;
    contador++;

}

void mostrarLibro(Libro libro) {
    cout << "Título: " << libro.titulo << endl;
    cout << "Autor: " << libro.autor << endl;
    cout << "Género: " << libro.genero << endl;
    cout << "Número de páginas: " << libro.numPaginas << endl;
    cout << "Disponibilidad: " << (libro.disponibilidad ? "Disponible" : "Prestado") << endl;
}

int obtenerCriterioBusqueda() {
    int criterio = 0;

    do {
        cout << "Seleccione el criterio de búsqueda:" << endl;
        cout << "1. Título" << endl;
        cout << "2. Autor" << endl;
        cout << "3. Género" << endl;
        cout << "4. Salir y volver al menu anterior" << endl; 
        cout << "Ingrese el número correspondiente al criterio de búsqueda: ";
        cin >> criterio;
    } while(criterio == 0);

    if(criterio == 4) {
        return -1;
    }

    return criterio;
}

int buscarLibro(Libro libros[], int cantidad_libros)
{
    int criterio = obtenerCriterioBusqueda();
    if(criterio == -1) { return -1; }

    cout << "Ingrese el término de búsqueda: ";
    string busqueda;
    cin >> busqueda;

    int pos_encontrado = -1;
    int e = 0;
    
    while(pos_encontrado == -1 && e < cantidad_libros) {
        Libro libro = libros[e];

        if(criterio == 1 && libro.titulo == busqueda) { pos_encontrado = e; }

        if(criterio == 2 && libro.autor == busqueda) { pos_encontrado = e; } 
        
        if(criterio == 3 && libro.genero == busqueda) { pos_encontrado = e; }

        e++;
    }

    if(pos_encontrado == -1) {
        cout << "No se encontraron libros que coincidan con la búsqueda." << endl;
    } else {
        Libro libro = libros[pos_encontrado];

        mostrarLibro(libro);
    }

    return pos_encontrado;
}


// Implementar una función que permita prestar un libro. Esta función debe modificar la disponibilidad del libro seleccionado.
int prestarLibro(Libro libros[], int cantidad_libros) {
    int pos_libro = buscarLibro(libros, cantidad_libros);

    if(pos_libro == -1) {
        return -1;
    }

    libros[pos_libro].disponibilidad = false;

    cout << "El libro ha sido prestado exitosamente." << endl;
}


// Implementar una función que permita devolver un libro prestado. Esta función debe modificar la disponibilidad del libro.
int devolverLibro(Libro libros[], int cantidad_libros) {
    int pos_libro = buscarLibro(libros, cantidad_libros);

    if(pos_libro == -1) {
        return -1;
    }

    libros[pos_libro].disponibilidad = true;

    cout << "El libro ha sido devuelto exitosamente." << endl;
}

// Implementar una función para ordenar los libros por algún criterio, como título, autor o género.
int orderLibros(Libro libros[], int cantidad_libros) {
    int criterio = obtenerCriterioBusqueda();
    if(criterio == -1) { return -1; }

    for(int i = 0; i < cantidad_libros; i++) {
        for(int j = 0; j < cantidad_libros - 1; j++) {
            Libro libro1 = libros[j];
            Libro libro2 = libros[j + 1];

            if(criterio == 1 && libro1.titulo > libro2.titulo) {
                Libro temp = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = temp;
            }

            if(criterio == 2 && libro1.autor > libro2.autor) {
                Libro temp = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = temp;
            }

            if(criterio == 3 && libro1.genero > libro2.genero) {
                Libro temp = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = temp;
            }
        }
    }

    cout << "Los libros han sido ordenados exitosamente." << endl;
}

int menu() {
    int opcion = 0;
    cout << "Bienvenido al sistema de gestión de biblioteca." << endl << endl;

    do {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Buscar libro" << endl;
        cout << "3. Prestar libro" << endl;
        cout << "4. Devolver libro" << endl;
        cout << "5. Ordenar libros" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese el número correspondiente a la opción: ";
        cin >> opcion;
    } while(opcion < 1 || opcion > 6);

    return opcion;
}
