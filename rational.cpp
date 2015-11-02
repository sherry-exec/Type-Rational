    
    #include <iostream> 
    #include <string> 
    #include <exception> 
    #include <cstdlib> 
    #include <cstdio> 
    #include <new>
    
    #include "rational.h"
    
    using namespace std;
    
    rational::rational()                                //default constructor
    : numerator(0), denominator(1)
    {}
 
    rational::rational(int32_t num)                     //constructor for numerator only, simple numbers
    : numerator(num), denominator(1)
    {}
 
    rational::rational(int32_t num, int32_t den)        //
    : numerator(num)
    {
        den!=0 ? denominator=den : denominator=1;
 
        if(numerator < 0 && denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
        if(denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
        simplify();
    }
 
    rational::rational(int32_t whole, int32_t num, int32_t den) //constructor for whole number rationals
    {
        den!=0 ? denominator=den : denominator=1;
 
        numerator = (den*whole)+num;
        simplify();
    }
 
    rational::rational(const char *s)                               //constructor for string input
    {
        sscanf(s, "%d%*c%d",&numerator,&denominator);
        if(denominator == 0)
            denominator = 1;
 
        simplify();
    }
 
    rational::rational(double num)
    {
        *this = doubletofraction(num);
    }
 
    rational::rational(const rational &f)
    {
        numerator = f.numerator;
        denominator = f.denominator;
        simplify();
    }
 
    rational::operator double()                 //convertion function
    { return quotient; }
 
    void rational::c_display()                  //display function
    {
        simplify();
        if(denominator != 1)
            cout << numerator << "/" << denominator ;
        else
            cout << numerator ;
    }
 
    char* rational::c_string()
    {
        char *s = NULL;
        if(denominator == 1)
            sprintf(s, "%d", numerator);
        else
            sprintf(s, "%d/%d", numerator,denominator);
        return s;
    }
 
    double rational::real_quotient()
    {
        return quotient;
    }
 
    int32_t rational::int_quotient()
    {
        return (int32_t)quotient;
    }
 
    rational rational::reciprocal()
    {
        rational temp(denominator, numerator);
        return temp;
    }
 
    rational rational::doubletofraction(double d)
    {
        int32_t num = d;
        int32_t den = 1;
        if( d-(double)num != 0 )
        {
            do
            {
                d *= 10;
                num = d;
                den *= 10;
            }while(d != double(num));
            rational temp(num,den);
            return temp;
        }
        rational temp2(num);
        return temp2;
    }
 
    /*simplification of a rational*/
inline void rational::simplify()
{
    register int32_t i;
    for(i=2; i<=denominator; i++)
    {
        if(numerator%i == 0)
        {
            if(denominator%i == 0)
            {
                numerator /= i;
                denominator /= i;
                i=1;
            }
        }
    }
 
    if(denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
    if(numerator<0 && denominator<0)
    {
        numerator *= -1;
        denominator *= -1;
    }
    if(denominator == 0)
        denominator = 1;
 
    quotient = (double)numerator / (double)denominator;
}
/*Arithmetic Operators with rationals*/
rational rational::operator*(rational f)
{
    rational temp;
    temp.numerator = numerator * f.numerator;
    temp.denominator = denominator * f.denominator;
    return temp;
}
rational rational::operator/(rational f)
{
    rational temp;
    temp.numerator = numerator * f.denominator;
    temp.denominator = denominator * f.numerator;
    return temp;
}
rational rational::operator+(rational f)
{
    rational temp;
    register int32_t dummy1, dummy2, LCM=1;
    register int32_t i=2;
    dummy1 = denominator;
    dummy2 = f.denominator;
    do  //loop for LCM
    {
        if(dummy1%i == 0 || dummy2%i == 0)
        {
            if(dummy1%i == 0)
            {   dummy1 /= i;    }
            if(dummy2%i == 0)
            {   dummy2 /= i;    }
            LCM *= i;
            i=1;
        }
        i++;
    }while((dummy1 != 1) || (dummy2 != 1));
    temp.denominator = LCM;
    temp.numerator = ((LCM/denominator)*numerator) + ((LCM/f.denominator)*f.numerator);
    return temp;
}
rational rational::operator-(rational f)
{
    rational temp;
    register int32_t dummy1, dummy2, LCM=1;
    register int32_t i=2;
    dummy1 = denominator;
    dummy2 = f.denominator;
    do  //loop for LCM
    {
        if(dummy1%i == 0 || dummy2%i == 0)
        {
            if(dummy1%i == 0)
            {   dummy1 /= i;    }
            if(dummy2%i == 0)
            {   dummy2 /= i;    }
            LCM *= i;
            i=1;
        }
        i++;
    }while((dummy1 != 1) || (dummy2 != 1));
    temp.denominator = LCM;
    temp.numerator = ((LCM/denominator)*numerator) - ((LCM/f.denominator)*f.numerator);
    return temp;
}
/*Compound Assignment via rationals*/
rational rational::operator+=(rational f)
{
    rational &temp = *this;
    temp = temp + f;
    temp.simplify();
    return (temp);
}
rational rational::operator-=(rational f)
{
    rational &temp = *this;
    temp = temp - f;
    temp.simplify();
    return (temp);
}
rational rational::operator*=(rational f)
{
    rational &temp = *this;
    temp = temp * f;
    temp.simplify();
    return (temp);
}
rational rational::operator/=(rational f)
{
    rational &temp = *this;
    temp = temp / f;
    temp.simplify();
    return (temp);
}
/*Comparision Operators*/
bool rational::operator==(rational f)
{
    if(numerator == f.numerator)
        if(denominator == f.denominator)
            return true;
        else return false;
    else return false;
}
bool rational::operator!=(rational f)
{
    if(numerator == f.numerator)
        if(denominator == f.denominator)
            return false;
        else return true;
    else return true;
}
bool rational::operator< (rational f)
{
    if(denominator == f.denominator)
    {
        if(numerator < f.numerator)
            return true;
        else return false;
    }
    int32_t num1 = numerator * f.denominator ;
    int32_t num2 = f.numerator * denominator;
    if(num1 < num2)
        return true;
    else return false;
}
bool rational::operator<=(rational f)
{
    if(denominator == f.denominator)
    {
        if(numerator <= f.numerator)
            return true;
        else return false;
    }
    int32_t num1 = numerator * f.denominator ;
    int32_t num2 = f.numerator * denominator;
    if(num1 <= num2)
        return true;
    else return false;
}
bool rational::operator> (rational f)
{
    if(denominator == f.denominator)
    {
        if(numerator > f.numerator)
            return true;
        else return false;
    }
    int32_t num1 = numerator * f.denominator ;
    int32_t num2 = f.numerator * denominator;
    if(num1 > num2)
        return true;
    else return false;
}
bool rational::operator>=(rational f)
{
    if(denominator == f.denominator)
    {
        if(numerator >= f.numerator)
            return true;
        else return false;
    }
    int32_t num1 = numerator * f.denominator ;
    int32_t num2 = f.numerator * denominator;
    if(num1 >= num2)
        return true;
    else return false;
}
//non-member comparison operators with integers
bool operator!=(rational f, int32_t num)
{
    if(f.quotient != (double)num)
        return true;
    else
        return false;
}
bool operator==(rational f, int32_t num)
{
    if(f.quotient == (double)num)
        return true;
    else
        return false;
}
bool operator<(rational f, int32_t num)
{
    if(f.quotient < (double)num)
        return true;
    else
        return false;
}
bool operator<=(rational f, int32_t num)
{
    if(f.quotient <= (double)num)
        return true;
    else
        return false;
}
bool operator>(rational f, int32_t num)
{
    if(f.quotient > (double)num)
        return true;
    else
        return false;
}
bool operator>=(rational f, int32_t num)
{
    if(f.quotient >= (double)num)
        return true;
    else
        return false;
}
 
//Arithmetic Operators with integers
rational operator*(rational f, int32_t num)
{
    rational temp;
    temp.numerator = f.numerator * num ;
    temp.denominator = f.denominator;
    return temp;
}
rational operator*(int32_t num, rational f)
{
    rational temp;
    temp.numerator = f.numerator * num ;
    temp.denominator = f.denominator;
    return temp;
}
rational operator/(rational f, int32_t num)
{
    rational temp;
    temp.numerator = f.numerator;
    temp.denominator = f.denominator * num ;
    return temp;
}
rational operator/(int32_t num, rational f)
{
    rational temp;
    temp.numerator = f.denominator * num;
    temp.denominator = f.numerator;
    return temp;
}
rational operator+(rational f, int32_t num)
{
    if(num!=0)
    {
        rational temp(num);
        temp = temp + f;
        return temp;
    }
    return (f);
}
rational operator+(int32_t num, rational f)
{
    if(num!=0)
    {
        rational temp(num);
        temp = temp + f;
        return temp;
    }
    return (f);
}
rational operator-(rational f, int32_t num)
{
    if(num!=0)
    {
        rational temp(num);
        temp = f - temp;
        return temp;
    }
    return (f);
}
rational operator-(int32_t num, rational f)
{
    if(num!=0)
    {
        rational temp(num);
        temp = temp - f;
        return temp;
    }
    return (f);
}
//Compound Arithmetic Assignment operator with integers
void operator+=(rational &f, int32_t num)
{
    if(num!=0)
    {
        rational temp(num);
        f = temp + f;
        f.simplify();
    }
}
void operator+=(int32_t &num, rational f)
{
    if(f!=0)
    {
        num = num + f;
    }
}
void operator-=(rational &f, int32_t num)
{
    if(num!=0)
    {
        rational temp(num);
        f = f - temp;
        f.simplify();
    }
}
void operator-=(int32_t &num, rational f)
{
    if(f!=0)
    {
        num = num - f;
    }
}
void operator*=(rational &f, int32_t num)
{
    if(num!=1)
    {
        rational temp(num);
        f = temp * f;
        f.simplify();
    }
}
void operator*=(int32_t &num, rational f)
{
    if(f!=1)
    {
        num = num * f;
    }
}
void operator/=(rational &f, int32_t num)
{
    if(num!=1)
    {
        rational temp(num);
        f = f / temp;
        f.simplify();
    }
}
void operator/=(int32_t num, rational &f)
{
    if(f!=1)
    {
        num = num / f;
    }
}
//non-member comparision operators with doubles
bool operator!=(rational f, double d)
{
    if(f.quotient != d)
        return true;
    else
        return false;
}
bool operator==(rational f, double d)
{
    if(f.quotient == d)
        return true;
    else
        return false;
}
bool operator< (rational f, double d)
{
    if(f.quotient < d)
        return true;
    else
        return false;
}
bool operator<=(rational f, double d)
{
    if(f.quotient <= d)
        return true;
    else
        return false;
}
bool operator> (rational f, double d)
{
    if(f.quotient > d)
        return true;
    else
        return false;
}
bool operator>=(rational f, double d)
{
    if(f.quotient >= d)
        return true;
    else
        return false;
}
//non-member arithmetic operators with doubles
rational operator*(rational f, double num)
{
    rational op2;
    op2 = op2.doubletofraction(num);
    rational temp;
    temp = f * op2;
    return temp;
}
rational operator*(double num , rational f)
{
    rational op2;
    op2 = op2.doubletofraction(num);
    rational temp;
    temp = f * op2;
    return temp;
}
rational operator/(rational f, double num )
{
    rational op2;
    op2 = op2.doubletofraction(num);
    rational temp;
    temp = f / op2;
    return temp;
}
rational operator/(double num , rational f)
{
    rational op2;
    op2 = op2.doubletofraction(num);
    rational temp;
    temp = op2 / f;
    return temp;
}
rational operator+(rational f, double num )
{
    rational op2;
    op2 = op2.doubletofraction(num);
    rational temp;
    temp = f + op2;
    return temp;
}
rational operator+(double num , rational f)
{
    rational op2;
    op2 = op2.doubletofraction(num);
    rational temp;
    temp = f + op2;
    return temp;
}
rational operator-(rational f, double num )
{
    rational op2;
    op2 = op2.doubletofraction(num);
    rational temp;
    temp = f - op2;
    return temp;
}
rational operator-(double num , rational f)
{
    rational op2;
    op2 = op2.doubletofraction(num);
    rational temp;
    temp = op2 - f;
    return temp;
}
void operator+=(rational &f, double num )   //non-member compound arithmetic with double numS
{
    rational temp ;
    temp = temp.doubletofraction(num);
    f += temp;
}
void operator+=(double &num, rational f)
{
    if(f != 0)
    {
        num = num + f;
    }
}
void operator-=(rational &f, double num )
{
    rational temp ;
    temp = temp.doubletofraction(num);
    f -= temp;
}
void operator-=(double &num, rational f)
{
    if(f != 0)
    {
        num = num - f;
    }
}
void operator*=(rational &f, double num )
{
    rational temp ;
    temp = temp.doubletofraction(num);
    f *= temp;
}
void operator*=(double &num, rational f)
{
    if(f != 1)
    {
        num = num * f;
    }
}
void operator/=(rational &f, double num )
{
    rational temp ;
    temp = temp.doubletofraction(num);
    f /= temp;
}
void operator/=(double &num, rational f)
{
    if(f != 1)
    {
        num = num / f;
    }
}
 
/*INC and DEC Operators*/
rational rational::operator++()
{
    *this = *this + 1;
    return (*this);
}
rational rational::operator++(int32_t x)
{
    *this = *this + 1;
    return (*this);
}
rational rational::operator--()
{
    *this = *this - 1;
    return (*this);
}
rational rational::operator--(int32_t x)
{
    *this = *this - 1;
    return (*this);
}
 
/*Assignment Operator*/
rational rational::operator=(const rational f)  //assignment operator
{
    numerator = f.numerator;
    denominator = f.denominator;
    simplify();
    return (*this);
}
rational rational::operator=(int32_t num)
{
    numerator = num;
    denominator = 1;
    return (*this);
}
rational rational::operator=(double num)
{
    *this = doubletofraction(num);
    return (*this);
}
rational rational::operator=(char *s)
{
    sscanf(s, "%d%*c%d", &numerator,&denominator);
    if(denominator == 0)
        denominator = 1;
    simplify();
    return (*this);
}
 
/*() Operator for assigning rational*/
void rational::operator()(int32_t num)
{ numerator=num; denominator=1; }
 
void rational::operator()(int32_t num, int32_t den)
{
    numerator=num;
    if(den!=0)
        denominator=den;
    else denominator=1;
    simplify();
}
 
void rational::operator()(int32_t whole, int32_t num, int32_t den)
{
    if(den!=0)
        denominator = den;
    else denominator = 1;
    numerator = (den*whole)+num;
    simplify();
}
 
void rational::operator()(double num)
{
    *this = doubletofraction(num);
}
 
bool rational::operator()(char *s)
{
    uint8_t slashCount = 0;
    char *startOfstring = s;
    do
    {
        if(*s == '/' || *s == '\\' || *s == ',' || *s == ' ')
            slashCount++;
        s++;
    }while(*s);
    s = startOfstring;
 
    if(slashCount == 0)     //simple number: goes to numerator
    {
        double temp = 0;
        sscanf(s, "%lf", &temp);
        numerator = (int)temp;
        if(temp == (double)numerator)
        {
            numerator = temp;
            denominator = 1;
        }
        else
            *this = doubletofraction(temp);
    }
    else if(slashCount == 1)    //fraction in p/q form
    {
        sscanf(s, "%d%*c%d", &numerator, &denominator);
        if(denominator == 0)
            denominator = 1;
    }
    else if(slashCount == 2)    //whole number for w/p/q
    {
        int32_t whole = 0;
        sscanf(s, "%d%*c%d%*c%d", &whole,&numerator,&denominator);
        if(denominator == 0)
            denominator = 1;
        numerator = (denominator*whole) + numerator;
    }
    else
    {
        numerator = 0;
        denominator = 1;
        return false;
    }
    simplify();
    return true;
}
