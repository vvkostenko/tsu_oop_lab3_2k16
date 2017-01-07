#include "MyString.h"
#include <random>
#include <cstring>

char* MyString::createRandomString (int len)
{
    char* randomStr = new char [len+1];
    for (int i = 0; i < len; ++i)
        randomStr[i] = 'a' + (rand() % 26);
    randomStr[len] = '\0';
    return randomStr;
}

MyString::MyString()
{
    len = 0;
    str = 0;
}

MyString::MyString(const char* str)
{
    len = std::strlen(str);
    this->str = new char [len+1];
    std::strcpy(this->str, str);
}

MyString::MyString(int len)
{
    if (len <= 20 && len >= 0)
    {
        this->len = len;
        this->str = createRandomString(len);
    }
    else
    {
        std::cout << "Error! len > 20 or len < 0";
        this->len = 0;
        this->str = 0;
    }
}

MyString::MyString(const MyString& anotherString)
{
    this->len = anotherString.len;
    this->str = new char [len+1];
    for (int i = 0; i < this->len; ++i)
        this->str[i] = anotherString.str[i];
    this->str[len] = '\0';
}

MyString& MyString::operator = (const MyString& anotherString)
{
    if (str)
        delete [] str;
    this->len = anotherString.len;
    this->str = new char [this->len + 1];
        strcpy(str, anotherString.str);
    return *this;
}

MyString::~MyString()
{
    if (str)
        delete [] str;
    //len = 0;
    //std::cout << "MS_D\n";
}

int MyString::getLen() const&
{
    return len;
}

bool MyString::operator < (MyString& anotherString)
{
    return (strcmp(this->str, anotherString.str) >= 0) ? 0 : 1;
}

bool MyString::operator > (MyString& anotherString)
{
    return (strcmp(this->str, anotherString.str) <= 0) ? 0 : 1;
}

const MyString MyString::operator+ (const MyString& anotherString)
{
    MyString res;
    res.len = this->getLen() + anotherString.getLen();
    res.str = new char [res.len + 1];
    std::strcpy(res.str, str);
    std::strcat(res.str, anotherString.str);
    res.str[res.len] = '\0';
    return res;
}

std::ostream& operator<< (std::ostream& out, const MyString& st)
{
    out << st.str << std::endl;
    return out;
}
