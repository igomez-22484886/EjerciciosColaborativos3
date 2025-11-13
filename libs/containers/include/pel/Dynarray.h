//
// Created by Israel on 11/11/2025.
//

#ifndef EJERCICIOSCOLABORATIVOS3_DYNARRAY_H
#define EJERCICIOSCOLABORATIVOS3_DYNARRAY_H

#include <cstddef>
#include <stdexcept>

// Clase plantilla Dynarray

template<typename T>

class Dynarray {
private:
    T* datos;
    int capacidad;
    int cantidad;

    void redimensionar() {
        int nuevaCapacidad = capacidad * 2;
        T* nuevoArray = new T[nuevaCapacidad];
        for (int i = 0; i < cantidad; ++i)
            nuevoArray[i] = datos[i];
        delete[] datos;
        datos = nuevoArray;
        capacidad = nuevaCapacidad;
    }

public:
    Dynarray(int cap = 10) : capacidad(cap), cantidad(0) {
        datos = new T[capacidad];
    }

    ~Dynarray() {
        delete[] datos;
    }

    void push_back(const T& elemento) {
        if (cantidad == capacidad)
            redimensionar();
        datos[cantidad++] = elemento;
    }

    int size() const {
        return cantidad;
    }

    T& operator[](int idx) {
        if (idx < 0 || idx >= cantidad)
            throw std::out_of_range("Índice fuera de rango");
        return datos[idx];
    }

    const T& operator[](int idx) const {
        if (idx < 0 || idx >= cantidad)
            throw std::out_of_range("Índice fuera de rango");
        return datos[idx];
    }
};

#endif //EJERCICIOSCOLABORATIVOS3_DYNARRAY_H
