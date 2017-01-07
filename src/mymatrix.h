#ifndef MYMATRIX_H
#define MYMATRIX_H

#include "myvector.h"

template <class type>
class MyMatrix
{
    int rows;
    MyVector<type> *mVect;
public:
    MyMatrix()
    {
        rows = 0;
        mVect = NULL;
    }

    ~MyMatrix()
    {
        if (mVect)
            delete [] mVect;
    }

    MyMatrix (int r, int c)
    {
        rows = r;
        mVect = new MyVector<type>[r];
        for(int i = 0; i < r; ++i)
            mVect[i] = c;
    }

    MyMatrix (const MyMatrix& anotherMatr)
    {
        rows = anotherMatr.rows;

        mVect = new MyVector<type>[rows];
        for (int i = 0; i < rows; ++i)
            mVect[i] = anotherMatr.mVect[i];
    }

    MyMatrix& operator = (const MyMatrix &anotherMatr)
    {
        if (mVect)
            delete [] mVect;
        rows = anotherMatr.rows;

        mVect = new MyVector<type>[rows];
        int col = mVect->getSize();
        for (int i = 0; i < rows; ++i)
            mVect[i] = anotherMatr.mVect[i];

        return *this;
    }

    const MyMatrix operator+ (const MyMatrix& right)
    {
        int col = mVect->getSize();
        if (rows == right.rows &&
                col == right.mVect->getSize())
        {
            MyMatrix res(*this);
            for (int i = 0; i < rows; ++i)
                res.mVect[i] = mVect[i] + right.mVect[i];
            return res;
        }
        return *this;
    }

    MyVector<type> operator [](int r)
    {
        if (r <= rows)
            return mVect[r];
        return -1;
    }

    friend std::ostream& operator<< (
            std::ostream& out, const MyMatrix<type>& m)
    {
        for(int i = 0; i < m.rows; ++i)
            out << m.mVect[i] << std::endl;
        return out;
    }

};

#endif // MYMATRIX_H
