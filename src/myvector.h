#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <random>

template <class type>
class MyVector
{
    type *vect;
    int size;
public:
    MyVector()
    { size = 0; vect = NULL; }

    MyVector(const MyVector &anotherVect)
    {
        size = anotherVect.size;
        vect = new type [size];
        for (int i = 0; i < size; ++i)
            vect[i] = anotherVect.vect[i];
    }

    MyVector(int size)
    {
        this->size = size;
        vect = new type [size];
        for (int i = 0; i < size; ++i)
            vect[i] = random() % 20;
    }

    ~MyVector()
    {
        if (vect)
            delete [] vect;
    }

    MyVector& operator = (const MyVector &anotherVect)
    {
        if (vect)
            delete [] vect;
        size = anotherVect.size;
        vect = new type [size];

        for (int i = 0; i < size; ++i)
            vect[i] = anotherVect.vect[i];

        return *this;
    }

    const MyVector operator + (const MyVector& right)
    {
        if (size != right.size)
            return -1;

        MyVector v;
        v.size = size;
        v.vect = new type [size];
            for (int i = 0; i < size; ++i)
                v.vect[i] = vect[i] + right.vect[i];
        return v;
    }

    type operator [] (int index)
    {
        if(index < size)
            return vect[index];
        return -1;
    }

    int getSize()
    { return size; }

    friend std::ostream& operator<< (
            std::ostream& out, const MyVector<type>& v)
    {
        for(int i = 0; i < v.size; ++i)
            out << v.vect[i] << " ";
        return out;
    }
};

//template class MyVector <MyString>;
//template class MyVector <std::string>;
//template std::ostream& operator<< (std::ostream& out, const MyVector<int>& v);

#endif // MYVECTOR_H
