#ifndef TORUS_H
#define TORUS_H
#include "Shape.h"

class Torus : public Shape
{

public:
   double small_radius;
   double big_radius;

   Torus(std::string , double, double);
   double getArea() const override;                                // get the surface area
   double getVolume() const override;                              // get the volume
   bool test(const std::vector<std::string> &cond) const override; // test if the conditions are statisfied
   std::string getInfo() const override;                           // get all the info in a string
};

#endif