#include <iostream>
#include "MyStringArray.h"

int main()
{
    const int masSize = 40;
    MyStringArray a(masSize);
    a.lenSort(0, masSize - 1);
    std::cout << a << a.lenSortTest() << std::endl << std::endl;
    a.strSort();
    std::cout << a << a.strSortTest() << std::endl;

    MyString x(10), y(5);
    MyString z = x + y;
    std::cout << std::endl << x << y << z << std::endl;
    return 0;
}
