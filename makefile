main:Complex.cpp tool.o
	g++ Complex.cpp tool.o -o Complex.o

tool.o:tool.cpp
	g++ -c tool.cpp

clean:
	rm -f Complex.o tool.o
