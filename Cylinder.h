#ifndef CYLINDER_H
#define CYLINDER_H
#include "Shape.h"


class Cylinder : public Shape
{

public:
   double radius;
   double height;
   Cylinder(std::string name, double radius, double height);
   double getArea() const override;                                // get the surface area
   double getVolume() const override;                              // get the volume
   bool test(const std::vector<std::string> &cond) const override; // test if the conditions are statisfied
   std::string getInfo() const override;                           // get all the info in a string
};

#endif