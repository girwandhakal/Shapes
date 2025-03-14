#include "reading.h"
#include <sstream>
#include "Shape.h"
#include <fstream>
#include "Box.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Torus.h"
#include <iostream>

std::vector<Shape*>* readFrom(std::string fileName){
    std::vector<Shape*>* output = new std::vector<Shape*>();
    std::string line;
    std::vector<std::string> temp;

    std::ifstream fileStream(fileName);

    if(!fileStream)
    {
        return output;
    }

    while(std::getline(fileStream,line))
    {
        std::stringstream ss(line);
        std::string text;
        while(ss>>text)
        {
            temp.push_back(text);
        }
        //now temp contains all the words in a single line
        Shape* myShape;

        if(temp[1] == "box")
        {
            myShape = new Box(temp[0], std::stod(temp[2]), std::stod(temp[3]), std::stod(temp[4]));
        }
        else if(temp[1] == "cylinder")
        {
            myShape = new Cylinder(temp[0], std::stod(temp[2]), std::stod(temp[3]));
        }
        else if(temp[1] == "sphere")
        {
            myShape = new Sphere(temp[0], std::stod(temp[2]));
        }
        else if(temp[1] == "torus")
        {
            myShape = new Torus(temp[0], std::stod(temp[2]), std::stod(temp[3]));
        }

        output->push_back(myShape);

        temp.clear();

    }
    fileStream.close();
    return output;
}