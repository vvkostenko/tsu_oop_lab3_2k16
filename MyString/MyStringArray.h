#include "MyString.h"

class MyStringArray
{
    MyString *mas;
    int size;
public:
    MyStringArray(int len);
    ~MyStringArray();
    void lenSort(int l, int r);
    void strSort();
    bool strSortTest();
    bool lenSortTest();
    MyString& operator [] (int num);
    friend std::ostream& operator<< (std::ostream& out, const MyStringArray& arr);
};



