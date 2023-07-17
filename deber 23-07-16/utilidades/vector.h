
#ifndef VECTOR2_H

class Vector
{
private:
    Tipo vec[EXT];

public:
    Vector();
    void setVector(int i, Tipo dato);
    Tipo getVector(int i);
};

void Vector::setVector(int i, Tipo dato)
{
    vec[i] = dato;
}

Tipo Vector::getVector(int i)
{
    return vec[i];
}

Vector::Vector() {}

#endif
