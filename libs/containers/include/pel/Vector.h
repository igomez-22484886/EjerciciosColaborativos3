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
    T* v_;
    T* space_;
    T* last_;

public:
    Vector() : v_(nullptr), space_(nullptr), last_(nullptr) {}

    ~Vector() {
        delete[] v_;
    }

    void pushBack(const T& data) {
        if (v_ == nullptr) {
            v_ = new T[2];
            v_[0] = data;
            space_ = v_ + 1;
            last_ = v_ + 2;
            return;
        }

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
        return size() == 0;
    }
};

#endif //EJERCICIOSCOLABORATIVOS3_VECTOR_H