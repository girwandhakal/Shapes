
a.out: main.o Box.o Sphere.o Torus.o Cylinder.o reading.o Shape.o
	g++ main.o Box.o Sphere.o Torus.o Cylinder.o reading.o Shape.o -o a.out

Box.o: Box.cpp Box.h
	g++ -c Box.cpp

Sphere.o: Sphere.cpp Sphere.h
	g++ -c Sphere.cpp

Torus.o: Torus.cpp Torus.h
	g++ -c Torus.cpp

Cylinder.o: Cylinder.cpp Cylinder.h
	g++ -c Cylinder.cpp

reading.o: reading.cpp reading.h
	g++ -c reading.cpp
	
Shape.o: Shape.cpp Shape.h
	g++ -c Shape.cpp

clean:
	rm *.o a.out