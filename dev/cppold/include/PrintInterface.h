#ifndef PRINT_INTERFACE_H
#define PRINT_INTERFACE_H
// Contains the printable interface

#include <iostream>

class Printable
{
public:
// Meant to implement a method that prints useful debug info and format to stdout.
virtual void debugInfo(void) const
{
}
// Prints the runtime representation of the object.
virtual void print(void) const
{
}
};

#endif // PRINT_INTERFACE_H
