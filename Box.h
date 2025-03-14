#ifndef BOX_H
#define BOX_H
#include "Shape.h"

class Box : public Shape
{
private:
   double length;
   double width;
   double height;

public:
   Box(std::string name, double length, double width, double height);
   double getArea() const override;                                // get the surface area
   double getVolume() const override;                              // get the volume
   bool test(const std::vector<std::string> &cond) const override; // test if the conditions are statisfied
   std::string getInfo() const override;                           // get all the info in a string
};

#endif