main:Complex.cpp tool.o
	g++ Complex.cpp tool.o -o Complex.out

tool.o:tool.cpp
	g++ -c tool.cpp

clean:
	rm -f Complex.out
