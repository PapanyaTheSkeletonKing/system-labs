all: test

test: main.o Hotel.o Hotel.h
	g++ main.o Hotel.o -o test

main.o: main.cpp
	g++ -c main.cpp 


Hotel.o: Hotel.cpp
	g++ -c Hotel.cpp

clear: 
	rm -rf *.o test

