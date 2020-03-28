main:testAP.cpp fVector.o
	g++ testAP.cpp fVector.o -o testAP.o

fVector.o:fVector.cpp
	g++ -c fVector.cpp

clean:
	rm -f *.o