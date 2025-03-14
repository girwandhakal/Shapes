#include "cmath"
#define PI 3.14159265358979323846
#include "Sphere.h"
#include <sstream>
#include <functional>
#include <map>
#include <iomanip>

Sphere::Sphere(std::string name, double radius):Shape(name) { // Shape does not have a default constructor, so need to call the parameterized constructor here
    this->radius = radius;
}


double Sphere::getArea() const{
	return round(4 * PI * radius * radius*100)/100;
}
double Sphere::getVolume() const{
	return round(4.0/3.0 * PI * pow(radius, 3)*100)/100;
}

std::string Sphere::getInfo() const{
    std::stringstream ss;
    ss << "Sphere: " << this->getName()<< std::fixed << std::setprecision(2) << ", Radius=" << this->radius <<"\n\tSurface Area: "
    << this->getArea() << ", Volume: " << this->getVolume() << "\n";
    std::string output = ss.str();
    return output;
}


bool Sphere::test(const std::vector<std::string> &cond) const{
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
    };
    
    bool flag = true;
    for (long long unsigned int i = 0; i < cond.size(); i += 3)
    {
        if (cond[i] == "type")
        {
            flag = stringComparison[cond[i + 1]]("sphere", cond[i + 2]);
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