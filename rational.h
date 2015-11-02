/*
**  C++ Rational Class : to deal with rational numbers, including quotient and fraction
**  which are capable of interacting with primitive integer and double type
**
**  Author: Mohammad Shaharyar Siddiqui
**  Date:   July - 2015
**  Type:   Library
*/
 
#ifndef RATIONAL_H_
#define RATIONAL_H_
 
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <cstdio>
#include <new>
 
using namespace std;
 
  class rational
    {
    private:
        int32_t numerator, denominator;
        double quotient;
 
        void simplify();
        rational doubletofraction(double );
 
    public:
        rational();                         //default constructor
        rational(int32_t );                 //constructor with only numerator
        rational(int32_t , int32_t );           //constructor with numerator and denominator
        rational(int32_t , int32_t , int32_t);  //constructor for whole number rationals
        rational(double );                  //constructor for converting double int32_to rational
        rational(const char *);             //constructor via string
        rational(const rational &);         //from existing rational type object
 
        operator double();                  //quotient source
 
        void c_display();                   //display of rational
        char* c_string();                   //puts in a string format
        double real_quotient();             //real quotient
        int32_t int_quotient();             //celling rounded-off integer quotient
        rational reciprocal();              //return reciprocal of this object
 
        //////OPERATORS FOR TYPE RATIONAL
        rational operator*(rational );  //member arithmetic operators with FRACTIONS
        rational operator/(rational );
        rational operator+(rational );
        rational operator-(rational );
        rational operator+=(rational ); //compound assignment with FRACTIONS
        rational operator-=(rational );
        rational operator*=(rational );
        rational operator/=(rational );
        bool operator==(rational );     //comparison operators with FRACTIONS
        bool operator!=(rational );
        bool operator< (rational );
        bool operator<=(rational );
        bool operator> (rational );
        bool operator>=(rational );
 
        //////OPERATORS FOR INTEGERS
        friend rational operator*(rational , int32_t ); //non-member arithmetic operators with INTS
        friend rational operator*(int32_t , rational );
        friend rational operator/(rational , int32_t );
        friend rational operator/(int32_t , rational );
        friend rational operator+(rational , int32_t );
        friend rational operator+(int32_t , rational );
        friend rational operator-(rational , int32_t );
        friend rational operator-(int32_t , rational );
        friend void operator+=(rational &, int32_t );   //non-member compound arithmetic with INTS
        friend void operator+=(int32_t &, rational );
        friend void operator-=(rational &, int32_t );
        friend void operator-=(int32_t &, rational );
        friend void operator*=(rational &, int32_t );
        friend void operator*=(int32_t &, rational );
        friend void operator/=(rational &, int32_t );
        friend void operator/=(int32_t &, rational );
        friend bool operator!=(rational , int32_t);     //comparison operators with INTS
        friend bool operator==(rational , int32_t);
        friend bool operator< (rational , int32_t);
        friend bool operator<=(rational , int32_t);
        friend bool operator> (rational , int32_t);
        friend bool operator>=(rational , int32_t);
 
        //////OPERATORS FOR DOUBLES
        friend rational operator*(rational , double );  //non-member arithmetic operators with DOUBLES
        friend rational operator*(double , rational );
        friend rational operator/(rational , double );
        friend rational operator/(double , rational );
        friend rational operator+(rational , double );
        friend rational operator+(double , rational );
        friend rational operator-(rational , double );
        friend rational operator-(double , rational );
        friend void operator+=(rational &, double );    //non-member compound arithmetic with DOUBLES
        friend void operator+=(double &, rational);
        friend void operator-=(rational &, double );
        friend void operator-=(double &, rational);
        friend void operator*=(rational &, double );
        friend void operator*=(double &, rational);
        friend void operator/=(rational &, double );
        friend void operator/=(double &, rational);
        friend bool operator!=(rational , double);      //comparison operators with DOUBLES
        friend bool operator==(rational , double);
        friend bool operator< (rational , double);
        friend bool operator<=(rational , double);
        friend bool operator> (rational , double);
        friend bool operator>=(rational , double);
 
        ////Increment and Decrement Operators
        rational operator++();
        rational operator++(int32_t );
        rational operator--();
        rational operator--(int32_t );
 
        ////Assignment Operator
        rational operator=(rational );
        rational operator=(int32_t );
        rational operator=(double );
        rational operator=(char *);
 
        ////() Operator for object assignment
        void operator()(int32_t );
        void operator()(int32_t , int32_t );
        void operator()(int32_t , int32_t , int32_t );
        bool operator()(char *);
        void operator()(double );
    };
 
 #endif RATIONAL_H_
