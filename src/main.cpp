#include <iostream>
#include <MyString.h>
#include "mymatrix.h"

int main()
{
    srand(time(NULL));

//    MyMatrix<int> ms(5, 5);
//    int j = ms[2][2];

//    std::cout << j << std::endl << ms;
//    MyVector<int> v(5), v1(5), v3;

//    MyVector<int> asd(3);
//    std::cout << asd[1] << std::endl
//                 << asd << std::endl;

//    std::cout << v << std::endl;


//    v3 = v + v1;

//    std::cout << v3 << std::endl
//              << v1 << std::endl
//              << v << std::endl;

    MyMatrix<MyString> m1(3, 3), m2 (3, 3), m;

    std::cout << m1 << std::endl << std::endl
              << m2 << std::endl;

    m = m1 + m2;

    std::cout << "==================\n" << m << std::endl;

//    std::cout << asdf;

    return 0;
}
