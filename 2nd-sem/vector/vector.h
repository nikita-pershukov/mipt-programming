#ifndef VECTOR_H
#define VECTOR_H

template<class T>
class Vector
{
    T* Data;
    int Size;
    int Capacity;

public:
    Vector();
    Vector(int n, T val=T());
    Vector(const Vector<T>& v);
    ~Vector();
    void push_back(T val);
    void pop_back();
    void reserve(int n);
    T Get(int i) const;
    T operator [](int i);
    int mysize() const;
    int capasity() const;
    void resize(int n);
    void Print() const;
    T& at(int i);
    T front()const;
    T back()const;
    Vector<T>& operator = (const Vector<T> &B);
    void clear();

    template <class T1>
    class Iterator
    {
        T* pointer;
    public:
        Iterator(T* p)
        {
            pointer = p;
        }
        T& operator*()
        {
            return *pointer;
        }
        Iterator& operator = (Iterator p)
        {
            pointer = &(*p);
            return *this;
        }
        bool operator ==(Iterator p)
        {
            return pointer == &(*p);
        }
        bool operator !=(Iterator p)
        {
            return pointer != &(*p);
        }
        Iterator& operator++ ()
        {
            ++pointer;
            return *this;
        }
        Iterator& operator++(int)
        {
            ++pointer;
            return *this;
        }
        Iterator& operator-- ()
        {
            --pointer;
            return *this;
        }
        Iterator& operator--(int)
        {
            --pointer;
            return *this;
        }
    };

    Iterator<T> begin()
    {
        return Iterator<T> (Data);
    }

    Iterator<T> end()
    {
        return Iterator<T> (Data + Capacity);
    }

    Iterator<T> rbegin()
    {
        return Iterator<T> (Data + Capacity);
    }

    Iterator<T> rend()
    {
        return Iterator<T> (Data);
    }
};

#endif // VECTOR_H
