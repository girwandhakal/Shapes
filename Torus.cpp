#include "cmath"
#include "Torus.h"
#define PI 3.14159265358979323846
#include <sstream>
#include <iomanip>
#include <functional>
#include <map>
#include <iomanip>
#include <iostream>

Torus::Torus(std::string name, double smallRadius, double bigRadius):Shape(name) { // Shape does not have a default constructor, so need to call the parameterized constructor here
    this->small_radius = smallRadius;
    this->big_radius = bigRadius;
}

double Torus::getArea() const{
	return round(4*pow(PI,2)*small_radius*big_radius*100)/100;
}
double Torus::getVolume() const{
	return round(PI * pow(small_radius,2) * 2 * PI * big_radius*100)/100;
}

std::string Torus::getInfo() const{
    std::stringstream ss;
    ss << "Torus: " << this->getName()<< std::fixed << std::setprecision(2) << ", Small Radius=" << this->small_radius << ", Big Radius=" << this->big_radius <<"\n\tSurface Area: "
    << this->getArea() << ", Volume: " << this->getVolume() << "\n";
    std::string output = ss.str();
    ss.str("");
    ss.clear();
    return output;
}

bool Torus::test(const std::vector<std::string> &cond) const{
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
            flag = stringComparison[cond[i + 1]]("torus", cond[i + 2]);
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
        if(!flag) //if any test condition returns false, function returns false
        {
            return false;
        }
    }
    return flag;
}