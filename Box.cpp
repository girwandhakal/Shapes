#include "Box.h"
#include "cmath"
#define PI 3.14159265358979323846
#include <sstream>
#include <map>
#include <functional>
#include <iomanip>
#include <iostream>


Box::Box(std::string name, double length, double width, double height) : Shape(name)
{ // Shape does not have a default constructor, so need to call the parameterized constructor here
    this->length = length;
    this->width = width;
    this->height = height;
}

double Box::getArea() const
{
    return round((2 * length * width + 2 * length * height + 2 * width * height) * 100) / 100; // rounds to 2 decimal places
}
double Box::getVolume() const
{
    return round(length * width * height * 100) / 100; // rounds to 2 decimal places
}

std::string Box::getInfo() const
{
    std::stringstream ss;
    ss << "Box: " << this->getName() << ", Length=" << std::fixed << std::setprecision(2) << this->length << ", Width=" << this->width << ", Height=" << this->height << "\n\tSurface Area: "
       << this->getArea() << ", Volume: " << this->getVolume() << "\n";
    std::string output = ss.str();
    ss.str("");
    ss.clear();
    return output;
}

bool Box::test(const std::vector<std::string> &cond) const
{
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
            flag = stringComparison[cond[i + 1]]("box", cond[i + 2]);
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