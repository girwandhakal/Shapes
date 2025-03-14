// #include <sstream>
#include "Shape.h"
#include "cmath"
#define PI 3.14159265358979323846

using namespace std;

Shape::Shape(const string& name)
   : name(name)
{
}

void Shape::setName(const string& name)
{
	this->name = name;
}

string Shape::getName() const
{
	return name;
}
