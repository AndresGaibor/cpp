#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#define EXT 10
using namespace std;
struct biblioteca
{
    string Titulo;
    char Autor[30];
    string Genero;
    int NumeroPag;
    bool Disponibilidad = true;
};
int leerN(int li, int ls);
int GestionInformacionLibro(biblioteca Libro[], int N);
int RevisarInformacionLibro(biblioteca Libro[], int N);

int main()
{
    cout << "BIBLIOTECA - GESTION LIBROS" << endl;
    int VectCodigos[EXT];
    int n, cl = 0;
    biblioteca Libro[50]; // creo un vector de structs predefininidos
    fflush(stdin);
    do
    {
        cout << "SELECCIONE UNA OPCION" << endl;
        cout << "1. GESTIONAR INFORMACION LIBROS" << endl;
        cout << "2. REVISAR INFORMACION LIBROS" << endl;
        cout << "3. SALIR DEL SISTEMA" << endl;
        fflush(stdin);
        n = leerN(1, 3);
        switch (n)
        {
        case 1:                                      // GESTIONAR INFORMACION ESTUDIANTES
            cl = GestionInformacionLibro(Libro, cl); //

            break;
        case 2: // REVISAR INFORMACION ESTUDIANTES
            RevisarInformacionLibro(Libro, cl);
            break;
        case 3:
            break;
        };
    } while (n != 3);
    cout << "SALIO DEL SISTEMA" << endl;
    return 0;
}

int leerN(int li, int ls)
{
    int n;
    do
    {
        cout << endl
             << "Ingrese un valor compredido entre [" << li << ".." << ls << "]: ";
        cin >> n; // lectura
    } while ((n < li) || (n > ls)); // repetir miestras se ingresan valores negativos
    return n;
}
int EliminarInformacionLibro(biblioteca Libro[], int cl, string tb)
{
    for (int i = 0; i < cl; i++)
    {
        if (Libro[i].Titulo == tb)
        {
            for (int j = i; j < cl - 1; j++)
            {
                Libro[j].Titulo = Libro[j + 1].Titulo;
                //strcpy(Libro[j].Autor, Libro[j + 1].Autor);
                Libro[j].Genero = Libro[j + 1].Genero;
                Libro[j].NumeroPag = Libro[j + 1].NumeroPag;
                Libro[j].Disponibilidad = Libro[j + 1].Disponibilidad;
            }

            cl = cl - 1;
            cout << "eliminacion exitosa" << endl;
            return cl;
        }
    }
    cout << "codigo no encontrado, el libro no consta en los registros" << endl;
    return cl;
}
int RevisarInformacionLibro(biblioteca Libro[], int N)
{
    cout << "Nº. Titulo" << "  Autor " << "Genero " << " NumeroPaginas" << " Disponibilidad" << endl;
    cout << "------------------------------------" << endl;
    for (int k = 0; k < N; k++)
    {
        cout << "No." << k + 1 << "   " << Libro[k].Titulo << " " << Libro[k].Autor << "  " << Libro[k].Genero << "  " << Libro[k].NumeroPag << "   " << Libro[k].Disponibilidad << endl;
    }
    return N;
}

int AgregarLibro(biblioteca Libro[], int cl)
{
    cout << "CUANTOS LIBROS DESEA INGRESAR : ";
    int n, cli = 0;
    n = leerN(1, EXT);
    cli = cl + n;
    for (int i = cl; i < cli; i++)
    {
        cout << "INGRESE EL TITULO DEL LIBRO";
        cin >> Libro[i].Titulo;
        cout << "INGRESE EL NOMBRE DEL LIBRO:";
        cin >> Libro[i].Autor;
        cout << "INGRESE EL GENERO DEL LIBRO:";
        cin >> Libro[i].Genero;
        cout << "INGRESE NUMERO DE PAGINAS:";
        cin >> Libro[i].NumeroPag;
        cout << "INGRESE DISPONIBILIDAD:";
        cin >> Libro[i].Disponibilidad;
    }
    return cli;
}
int ModificarInformacionLibro(biblioteca Libro[], int cl, string lm, int k)
{
    if (k < cl)
    {
        if (Libro[k].Titulo == lm)
        {
            cout << "INGRESE EL TITULO DEL LIBRO";
            cin >> Libro[k].Titulo;
            cout << "INGRESE EL NOMBRE DEL LIBRO:";
            cin >> Libro[k].Autor;
            cout << "INGRESE EL GENERO DEL LIBRO:";
            cin >> Libro[k].Genero;
            cout << "INGRESE NUMERO DE PAGINAS:";
            cin >> Libro[k].NumeroPag;
            cout << "INGRESE DISPONIBILIDAD:";
            cin >> Libro[k].Disponibilidad;
            return 1;
        }
        return ModificarInformacionLibro(Libro, cl, lm, k + 1);
    }
    return 0;
}

int GestionInformacionLibro(biblioteca Libro[], int cl)
{
    int o;
    do
    {
        cout << "SELECCIONE UNA OPCION" << endl;
        cout << "1. AGREGAR LIBRO" << endl;
        cout << "2. ELIMINAR LIBRO" << endl;
        cout << "3. MODIFICAR INFORMACION DE LIBRO" << endl;
        cout << "4. REGRESAR A SECCION ANTERIOR" << endl;
        o = leerN(1, 4);

        switch (o)
        {
        case 1: {
            cout << "AGREGAR LIBRO" << endl;
             cl = AgregarLibro(Libro, cl);
            break;
        }
        case 2: {
            cout << "ELIMINAR LIBRO" << endl;
            string tb2;
            // lee tb2 desde el teclado
            // getline(cin, tb2);
            cin >> tb2;
        


            cl = EliminarInformacionLibro(Libro, cl, tb2);
            break;
        }
        case 3: {
            cout << "MODIFICAR INFORMACION DE LIBRO" << endl;
            string lm;
            int k = 0;
            cin >> lm;
            cl = ModificarInformacionLibro(Libro, cl, lm, k);
            break;
        }
        default:
            break;
        }
    } while (o != 4);
    return cl;
}
