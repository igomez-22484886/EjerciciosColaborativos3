//
// Created by Israel on 11/11/2025.
//

#ifndef EJERCICIOSCOLABORATIVOS3_VECTOR_H
#define EJERCICIOSCOLABORATIVOS3_VECTOR_H

#pragma once
#include <cstddef>

template<typename T>
class Vector {
private:
    T* v_;       // beginning
    T* space_;   // next free slot
    T* last_;    // end of allocated memory

public:
    Vector() : v_(nullptr), space_(nullptr), last_(nullptr) {}

    ~Vector() {
        delete[] v_;
    }

    void pushBack(const T& data) {
        // empty vector
        if (v_ == nullptr) {
            v_ = new T[2];
            v_[0] = data;
            space_ = v_ + 1;
            last_ = v_ + 2;
            return;
        }

        // full vector
        if (space_ == last_) {
            size_t oldSize = size();
            size_t newCap = capacity() * 2;
            T* temp = new T[newCap];

            for (size_t i = 0; i < oldSize; i++)
                temp[i] = v_[i];

            delete[] v_;
            v_ = temp;
            space_ = v_ + oldSize;
            last_ = v_ + newCap;
        }

        *space_ = data;
        ++space_;
    }

    size_t size() const {
        return (space_ - v_);
    }

    size_t capacity() const {
        return (last_ - v_);
    }

    T& operator[](size_t i) {
        return v_[i];
    }

    const T& operator[](size_t i) const {
        return v_[i];
    }

    T* begin() { return v_; }
    T* end()   { return space_; }

    const T* begin() const { return v_; }
    const T* end()   const { return space_; }
    // Si son iguales, indica que no hay contendores almacenados
    bool empty() const {
        return space_ == last_;

    };
};

#endif //EJERCICIOSCOLABORATIVOS3_VECTOR_H