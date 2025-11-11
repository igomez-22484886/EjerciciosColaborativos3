//
// Created by Israel on 11/11/2025.
//

#ifndef EJERCICIOSCOLABORATIVOS3_DYNARRAY_H
#define EJERCICIOSCOLABORATIVOS3_DYNARRAY_H

class DinArray {
private:
    Cancion *canciones;
    int capacidad;
    int cantidad;

    void redimensionar() {
        int nuevaCapacidad = capacidad * 2;
        Cancion *nuevoArray = new Cancion[nuevaCapacidad];
        for (int i = 0; i < cantidad; ++i)
            nuevoArray[i] = canciones[i];
        delete[] canciones;
        canciones = nuevoArray;
        capacidad = nuevaCapacidad;
    }

public:
    DinArray(int cap = 10) : capacidad(cap), cantidad(0) {
        canciones = new Cancion[capacidad];
    }

    ~DinArray() {
        delete[] canciones;
    }

    void agregar(const Cancion &c) {
        if (cantidad == capacidad)
            redimensionar();
        canciones[cantidad++] = c;
    }
};

#endif //EJERCICIOSCOLABORATIVOS3_DYNARRAY_H
