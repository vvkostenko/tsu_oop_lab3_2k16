#include "MyStringArray.h"

    MyStringArray::MyStringArray(int size)
    {
        srand(time(0));
        this->size = size;
        this->mas = new MyString[size];
        for (int i = 0; i < size; i++)
        {
            int num = (rand() % 20) + 1;
            this->mas[i] = MyString(num);
        }
    }

    MyStringArray::~MyStringArray()
    {
        delete [] mas;
        //this->size = 0;
        //std::cout << "MSA_D\n";
    }

    MyString& MyStringArray::operator [] (int num)
    {
        return this->mas[num];
    }

    void MyStringArray::lenSort(int l, int r)
    {
        MyString x = mas[(l + r)/ 2];
        int i = l;
        int j = r;
        while (i <= j)
        {
            while (mas[i].getLen() < x.getLen())
                i++;
            while (mas[j].getLen() > x.getLen())
                j--;
            if (i <= j)
            {
                std::swap(mas[i], mas[j]);
                i++;
                j--;
            }
        }
        if (i < r)
            lenSort(i, r);

        if (l < j)
            lenSort(l, j);
}

   void MyStringArray::strSort()
   {
       for (int i = 0; i < size; ++i)
       {
            if (i & 1)
                for (int j = 2; j < size; j += 2)
                {
                    if (mas[j] < mas[j - 1])
                        std::swap (mas[j - 1], mas[j]);
                }
           else
           {
               for (int j = 1; j < size; j += 2)
               {
                   if (mas[j] < mas[j - 1])
                    std::swap(mas[j - 1], mas[j]);
               }
           }
       }
    }

    bool MyStringArray::strSortTest()
    {
        for (int i = 1; i < size; ++i)
            if (mas[i] < mas[i-1])
                return 1;
        return 0;
    }

    bool MyStringArray::lenSortTest()
    {
        bool test = 0;
        for (int i = 1; i < size; ++i)
            if (mas[i].getLen() < mas[i-1].getLen())
                test++;
        return test;
    }


    std::ostream& operator<< (std::ostream& out, const MyStringArray& arr)
    {
        for (int i = 0; i < arr.size; ++i)
        {
            if (arr.mas->getLen() <= 50)
            {
                out << arr.mas[i];
            }
            else std::cout << "ERROR! Mas > 50!";
        }
        return out;
    }

