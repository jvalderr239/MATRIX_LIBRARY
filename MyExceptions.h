#ifndef EXCEPT_H
#define EXCEPT_H

#include <iostream>
#include <exception>


class MismatchSizeException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Sorry, there is a dimension mismatch!";
    }
} dimEx;

class MemberException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Cannot make matrix of this shape!";
    }
} shapeEx;

#endif