#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
private:
    char* str;
    int len;
    char* createRandomString (int len);
public:
    MyString();
    MyString(const char* str);
    MyString(int len);
    MyString(const MyString& anotherString);
    MyString& operator = (const MyString& anotherString);
    ~MyString();
    int getLen() const&;
    bool operator < (MyString& anotherString);
    bool operator > (MyString& anotherString);
    const MyString operator + (const MyString& anotherString);
    friend std::ostream& operator<< (std::ostream& out, const MyString& st);
};

#endif // MYSTING_H
