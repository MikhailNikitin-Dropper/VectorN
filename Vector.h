//
// Created by mike0 on 20.10.2023.
//

#ifndef VECTORN_VECTOR_H
#define VECTORN_VECTOR_H
#include <iostream>
#include <assert.h>
#include <sstream>
template <typename T, int N>
class Vector {

private:
    T data[N];

public:
    Vector() {
        for (int i = 0; i < N; i++) {
            data[i] = T();
        }
    }

    Vector(const T* arr) {
        for (int i = 0; i < N; i++) {
            data[i] = *arr+i;
        }
    }

    Vector<T, N> operator+(const Vector<T, N>& other) const {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    T operator*(const Vector<T, N>& other) const {
        T result = T();
        for (int i = 0; i < N; i++) {
            result += data[i] * other.data[i];
        }
        return result;
    }

    Vector<T, N> operator*(const T& scalar) const {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    bool operator==(const Vector<T, N>& other) const {
        for (int i = 0; i < N; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    Vector<T, N>& operator=(const Vector<T, N>& other) {
        if (this != &other) {
            for (int i = 0; i < N; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    Vector<T, N> operator+() const {
        return *this;
    }

    Vector<T, N> operator-() const {
        Vector<T, N> result;
        for (int i = 0; i < N; i++) {
            result.data[i] = -data[i];
        }
        return result;
    }

    T norm() const {
        T result = T();
        for (int i = 0; i < N; i++) {
            result += data[i] * data[i];
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector<T, N>& vec) {
        os << "(";
        for (int i = 0; i < N; i++) {
            os << vec.data[i];
            if (i < N - 1) {
                os << ", ";
            }
        }
        os << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector<T, N>& vec) {
        for (int i = 0; i < N; i++) {
            is >> vec.data[i];
        }
        return is;
    }

    void testVector()
    {
        Vector<T, N> v1;
        for (int i = 0; i < N; i++) {
            assert(v1.data[i] == T());
        }

        T arr[N];
        for (int i = 0; i < N; i++) {
            arr[i] = i + 1;
        }
        Vector<T, N> v2(arr);
        for (int i = 0; i < N; i++) {
            assert(v2.data[i] == arr[i]);
        }

        Vector<T, N> v3 = v1 + v2;
        for (int i = 0; i < N; i++) {
            assert(v3.data[i] == v1.data[i] + v2.data[i]);
        }

        T dotProduct = v1 * v2;
        T expectedDotProduct = T();
        for (int i = 0; i < N; i++) {
            expectedDotProduct += v1.data[i] * v2.data[i];
        }
        assert(dotProduct == expectedDotProduct);

        T scalar = 2;
        Vector<T, N> v4 = v1 * scalar;
        for (int i = 0; i < N; i++) {
            assert(v4.data[i] == v1.data[i] * scalar);
        }

        assert(v1 == v1);
        assert(!(v1 == v2));

        Vector<T, N> v5 = v1;
        assert(v5 == v1);
        v5 = v2;
        assert(v5 == v2);

        Vector<T, N> v6 = +v1;
        assert(v6 == v1);

        Vector<T, N> v7 = -v1;
        for (int i = 0; i < N; i++) {
            assert(v7.data[i] == -v1.data[i]);
        }

        T norm = v1.norm();
        T expectedNorm = T();
        for (int i = 0; i < N; i++) {
            expectedNorm += v1.data[i] * v1.data[i];
        }
        assert(norm == expectedNorm);
    }
};


#endif //VECTORN_VECTOR_H
