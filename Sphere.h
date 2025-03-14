#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape
{
public:
   double radius;
   Sphere(std::string , double);
   double getArea() const override;                                // get the surface area
   double getVolume() const override;                              // get the volume
   bool test(const std::vector<std::string> &cond) const override; // test if the conditions are statisfied
   std::string getInfo() const override;                           // get all the info in a string
};

#endif