main:testAP.cpp fVector.o fMatrix.o
	g++ testAP.cpp fVector.o fMatrix.o -o testAP.o

fVector.o:fVector.cpp
	g++ -c fVector.cpp

fMatrix.o:fMatrix.cpp
	g++ -c fMatrix.cpp

clean:
	rm -f *.o