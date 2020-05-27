#Makefile case 2
OBJECTS = test.o fVector.o fMatrix.o 
myprogram : $(OBJECTS)
	g++ -o myprogram $(OBJECTS)
test.o : fVector.h fMatrix.h
fVector.o :  fVector.h 
fMatrix.o : fMatrix.h

clean : rm myprogram \
	$(OBJECTS)