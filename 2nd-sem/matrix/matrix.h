#ifndef MATRIX_H
#define MATRIX_H

#include "All_include.h"

template<class T>
class matrix;

template<class T>
ostream& operator << (ostream&, const matrix<T>&);

template<class T>
istream& operator >> (istream&, const matrix<T>&);

template <class T>
class matrix
{
protected:
    int M, N;
//        matrix_line<T>* Data;
    T** Data;

public:

    matrix(int m = 0, int n = 0);
    matrix(const matrix<T> &a);

    T Get(int i, int j) const;
    int Get_M() const;
    int Get_N() const;
    T Get_sled() const;
    double Get_det() const;
    matrix Get_trans() const;

    void Set(int i, int j, T value) const;
    void Set_M(int m = 0);
    void Set_N(int n = 0);
    void Set_all_rand(int mod) const;
    void Swap(int i, int j);

    T* operator [](int i) const;
    matrix operator +(const matrix& a) const;
    matrix operator -(const matrix& a) const;
    matrix operator *(const matrix& a) const;
    matrix& operator =(const matrix &a);

    friend ostream& operator << <>(ostream&, const matrix<T>&);
    friend istream& operator >> <>(istream&, const matrix<T>&);

    ~matrix();

};

#include "matrix.h.impl"

#endif // MATRIX_H
