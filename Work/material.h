#ifndef MATERIAL_H
#define MATERIAL_H

#include <QVector>

class Material
{
public:
    Material();
    enum Composition {Sinetic, Wool, Mixed} composition;
    int size = 0;
    Material(Composition,int);
};

#endif // MATERIALS_H
