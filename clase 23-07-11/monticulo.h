typedef int Clave;

#ifndef MONTICULO_H
#define MONTICULO_H

class Monticulo {
private:
    Clave *v;
    int nDatosMax;
    int nDatosActual;
public:
    Monticulo();
    Monticulo(int cantidadDatos);
    void setNdatosMax(int cantidadDatos);
    void setNdatosActual(int cantidadDatos);

    int getNdatosMax();
    int getNdatosActual();
};

void Monticulo::setNdatosMax(int cantidadDatos) {
    nDatosMax = cantidadDatos;
}

void Monticulo::setNdatosActual(int cantidadDatos) {
    nDatosActual = cantidadDatos;
}

Monticulo::Monticulo() {
    setNdatosMax(0);
    setNdatosActual(0);
}

Monticulo::Monticulo(int cantidadDatos) {
    setNdatosMax(cantidadDatos);
    setNdatosActual(0);
}


#endif