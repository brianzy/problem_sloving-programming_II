#ifndef FRACTIONTYPE_H_INCLUDED
#define FRACTIONTYPE_H_INCLUDED
#include <iostream>
#include <iomanip>
using namespace std;
class fractionType
{
    int numerator, denominator;
    public:
    fractionType()
    {
        numerator = 0;
        denominator = 1;
    }
    fractionType(int n,int d)
    {
        numerator=n;
        denominator=d;
    }
    fractionType operator+(fractionType otherfraction);
    fractionType operator-(fractionType otherfraction);
    fractionType operator*(fractionType otherfraction);
    fractionType operator/(fractionType otherfraction);
    fractionType operator=(fractionType otherfraction);

    bool operator<=(fractionType otherfraction);
    bool operator==(fractionType otherfraction);
    bool operator>=(fractionType otherfraction);
    bool operator!=(fractionType otherfraction);
    bool operator>(fractionType otherfraction);
    bool operator<(fractionType otherfraction);

    friend ostream & operator<<(ostream& os,fractionType otherFraction);
    friend istream & operator>>(istream& is,fractionType& otherFraction);
};

fractionType fractionType::operator+(fractionType otherFraction)
{
    int n = numerator*otherFraction.denominator+otherFraction.numerator*denominator;
    int d = denominator*otherFraction.denominator;
    fractionType temp(n,d);

    return temp;
}
fractionType fractionType::operator-(fractionType otherFraction)
{
    int n =  numerator*otherFraction.denominator-otherFraction.numerator*denominator;
    int d = denominator*otherFraction.denominator;
    fractionType temp(n,d);

    return temp;
}
fractionType fractionType::operator*(fractionType otherFraction)
{
    int n=numerator*otherFraction.numerator;
    int d=denominator*otherFraction.denominator;
    fractionType temp(n,d);

    return temp;

}
fractionType fractionType::operator/(fractionType otherFraction)
{
    int n=numerator*otherFraction.denominator;
    int d=denominator*otherFraction.numerator;
    fractionType temp(n,d);

    return temp;
}
fractionType fractionType::operator=(fractionType otherfraction)
{
    numerator=otherfraction.numerator;
    denominator=otherfraction.denominator;
    fractionType temp(numerator,denominator);

    return temp;
}

bool fractionType::operator<=(fractionType otherfraction)
{
    if(numerator*otherfraction.denominator<=denominator*otherfraction.numerator)
        return true;
    else
        return false;
}
bool fractionType::operator==(fractionType otherfraction)
{
    if(numerator*otherfraction.denominator==denominator*otherfraction.numerator)
        return true;
    else
        return false;
}
bool fractionType::operator>=(fractionType otherfraction)
{
    if(numerator*otherfraction.denominator>=denominator*otherfraction.numerator)
        return true;
    else
        return false;
}
bool fractionType::operator!=(fractionType otherfraction)
{
    if(numerator*otherfraction.denominator!=denominator*otherfraction.numerator)
        return true;
    else
        return false;
}
bool fractionType::operator>(fractionType otherfraction)
{
    if(numerator*otherfraction.denominator>denominator*otherfraction.numerator)
        return true;
    else
        return false;
}
bool fractionType::operator<(fractionType otherfraction)
{
    if(numerator*otherfraction.denominator<denominator*otherfraction.numerator)
        return true;
    else
        return false;
}
ostream& operator<<(ostream& os,fractionType otherFraction)
{

           os << otherFraction.numerator << "/" << otherFraction.denominator << endl;
            return os;
}
istream& operator>>(istream& is,fractionType& otherFraction)
{
    char c;
    is>> otherFraction.numerator>>c>>otherFraction.denominator;
    return is;
}

#endif // FRACTIONTYPE_H_INCLUDED
