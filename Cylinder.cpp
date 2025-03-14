#include "Cylinder.h"
#include "cmath"
#define PI 3.14159265358979323846
#include <sstream>
#include <functional>
#include <map>
#include <iomanip>




Cylinder::Cylinder(std::string name, double radius, double height):Shape(name) { // Shape does not have a default constructor, so need to call the parameterized constructor here
    this->radius = radius;
    this->height = height;
}


double Cylinder::getArea() const{
	return round((2*PI*radius*height + 2* PI * pow(radius,2))*100)/100;
}
double Cylinder::getVolume() const{
	return round(PI * pow(radius,2) * height*100)/100;
}

std::string Cylinder::getInfo() const{
    std::stringstream ss;
    ss << "Cylinder: " << this->getName()<< std::fixed << std::setprecision(2) << ", Radius=" << this->radius << ", Height=" << this->height << "\n\tSurface Area: "
    << this->getArea() << ", Volume: " << this->getVolume() << "\n";
    std::string output = ss.str();
    ss.str("");
    ss.clear();
    return output;
}

bool Cylinder::test(const std::vector<std::string> &cond) const{
    //map of operators as keys, and lambdas as value 
    // map of operators as keys, and lambdas as value
    std::map<std::string, std::function<bool(std::string, std::string)>> stringComparison = {
        {"==", [](std::string a, std::string b)
         { return a == b; }},
        {">=", [](std::string a, std::string b)
         { return a >= b; }},
        {"<=", [](std::string a, std::string b)
         { return a <= b; }},
        {"!=", [](std::string a, std::string b)
         { return a != b; }},
        {">", [](std::string a, std::string b)
         { return a >= b; }},
        {"<", [](std::string a, std::string b)
         { return a < b; }},
    };
    std::map<std::string, std::function<bool(double, double)>> numComparison = {
        {"==", [](double a, double b)
         { return a == b; }},
        {">=", [](double a, double b)
         { return a >= b; }},
        {"<=", [](double a, double b)
         { return a <= b; }},
        {"!=", [](double a, double b)
         { return a != b; }},
        {">", [](double a, double b)
         { return a >= b; }},
        {"<", [](double a, double b)
         { return a < b; }},
    };    bool flag = true;
    for (long long unsigned int i = 0; i < cond.size(); i += 3)
    {
        if (cond[i] == "type")
        {
            flag = stringComparison[cond[i + 1]]("cyl", cond[i + 2]);
        }
        else if (cond[i] == "area")
        {
            flag = numComparison[cond[i + 1]](this->getArea(), std::stod(cond[i + 2]));
        }
        else if (cond[i] == "volume")
        {
            flag = numComparison[cond[i + 1]](this->getVolume(), std::stod(cond[i + 2]));
        }
        else
        {
            return false;
        }
        if(!flag)
        {
            return false;
        }
    }    
    return flag;
}