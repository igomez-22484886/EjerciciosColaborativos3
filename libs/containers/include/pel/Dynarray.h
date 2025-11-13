#ifndef EJERCICIOSCOLABORATIVOS3_DYNARRAY_H
#define EJERCICIOSCOLABORATIVOS3_DYNARRAY_H

#include <cstddef>
#include <stdexcept>

template<typename T>
class Dynarray {
private:
    T* data_;              // Puntero al array dinámico
    std::size_t size_;     // Número de elementos usados
    std::size_t capacity_; // Capacidad total reservada

    // Función interna que aumenta la capacidad cuando el array está lleno
    void grow() {
        if (capacity_ == 0) {
            // Si no hay memoria reservada, reservamos espacio para 2 elementos
            capacity_ = 2;
            data_ = new T[capacity_];
        } else {
            // Si ya existe memoria, duplicamos la capacidad
            capacity_ *= 2;
            T* temp = new T[capacity_];

            // Copiamos todos los elementos al nuevo array ampliado
            for (std::size_t i = 0; i < size_; ++i) {
                temp[i] = data_[i];
            }

            // Borramos el array antiguo
            delete[] data_;
            data_ = temp;
        }
    }

public:
    // Constructor por defecto: array vacío
    Dynarray()
        : data_{nullptr}, size_{0}, capacity_{0} {}

    // Constructor de copia (copia profunda)
    Dynarray(const Dynarray& other)
        : data_{nullptr}, size_{other.size_}, capacity_{other.capacity_} {
        if (capacity_ > 0) {
            data_ = new T[capacity_];
            for (std::size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
    }

    // Constructor de movimiento
    Dynarray(Dynarray&& other) noexcept
        : data_{other.data_}, size_{other.size_}, capacity_{other.capacity_} {
        // Dejamos el objeto origen en estado válido pero vacío
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    // Operador de asignación por copia (copia profunda)
    Dynarray& operator=(const Dynarray& other) {
        if (this != &other) {
            // Reservamos nueva memoria si es necesario
            T* newData = nullptr;
            if (other.capacity_ > 0) {
                newData = new T[other.capacity_];
                for (std::size_t i = 0; i < other.size_; ++i) {
                    newData[i] = other.data_[i];
                }
            }

            // Liberamos la memoria antigua
            delete[] data_;

            // Actualizamos los miembros
            data_ = newData;
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
        return *this;
    }

    // Operador de asignación por movimiento
    Dynarray& operator=(Dynarray&& other) noexcept {
        if (this != &other) {
            // Liberamos nuestra memoria actual
            delete[] data_;

            // Robamos los recursos del otro objeto
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;

            // Dejamos el otro en estado válido pero vacío
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    // Destructor: libera memoria reservada
    ~Dynarray() {
        delete[] data_;
    }

    // Inserta un elemento al final del array
    void insertAtEnd(const T& value) {
        if (size_ == capacity_) {
            grow(); // Ampliamos si no hay espacio disponible
        }
        data_[size_] = value;
        ++size_;
    }

    // Inserta un elemento al principio del array
    void insertAtBeginning(const T& value) {
        if (size_ == capacity_) {
            grow(); // Ampliamos si está lleno
        }

        // Movemos todos los elementos una posición a la derecha
        for (std::size_t i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }

        // Insertamos en la posición 0
        data_[0] = value;
        ++size_;
    }

    // Inserta un elemento en una posición concreta
    void insertAtAnyPosition(const T& value, std::size_t index) {
        if (index > size_) {
            throw std::out_of_range("Index out of range in insertAtAnyPosition");
        }

        if (size_ == capacity_) {
            grow();
        }

        // Movemos elementos desde 'size_' hacia 'index' una posición a la derecha
        for (std::size_t i = size_; i > index; --i) {
            data_[i] = data_[i - 1];
        }

        data_[index] = value;
        ++size_;
    }

    // Extrae el último elemento del array
    T extractAtEnd() {
        if (size_ == 0) {
            throw std::out_of_range("Cannot extract from empty Dynarray");
        }

        T temp = data_[size_ - 1];
        --size_;
        return temp;
    }

    // Extrae el primer elemento del array
    T extractBeginning() {
        if (size_ == 0) {
            throw std::out_of_range("Cannot extract from empty Dynarray");
        }

        T temp = data_[0];

        // Movemos todos los elementos una posición hacia la izquierda
        for (std::size_t i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }

        --size_;
        return temp;
    }

    // Devuelve el elemento en una posición concreta (con comprobación de rango)
    T at(std::size_t position) const {
        if (position >= size_) {
            throw std::out_of_range("The position you are trying to access is unavailable");
        }
        return data_[position];
    }

    // Operador [] sin comprobación de rango
    T& operator[](std::size_t position) {
        return data_[position];
    }

    const T& operator[](std::size_t position) const {
        return data_[position];
    }

    // Devuelve el número de elementos almacenados actualmente
    std::size_t getSize() const {
        return size_;
    }

    // Devuelve la capacidad reservada
    std::size_t getCapacity() const {
        return capacity_;
    }

    // Indica si el array está vacío
    bool empty() const {
        return size_ == 0;
    }
};

#endif // EJERCICIOSCOLABORATIVOS3_DYNARRAY_H