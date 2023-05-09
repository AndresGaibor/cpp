
typedef int Tipo; // crear un tipo base de datos para el arreglo
#define EXT 15

class vector {
private:
    Tipo v[EXT];
    int nElementos;

public:
    vector();
    void setV(Tipo val, int pos);
    void setNEl(int numeroElementos);
    Tipo getV(int pos);
    int getNumeroEl();
};

vector::vector() {}
void vector::setV(Tipo val, int pos) {
    v[pos] = val;
}

void vector::setNEl(int numeroElementos) {
    this->nElementos = numeroElementos;
}

Tipo vector::getV(int pos) {
    return v[pos];
}

int vector::getNumeroEl() {
    return nElementos;
}
