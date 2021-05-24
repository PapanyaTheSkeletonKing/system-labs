
all: test

test: main.o DataStaticLib.a WriterDynamicLib.so
	g++ -o binary main.o DataStaticLib.a -L -l: WriterDynamicLib.so -Wl,--rpath -Wl,.

main.o : main.cpp
	g++ -c main.cpp

WriterDynamicLib.so: Writer.o
	g++ -shared -o WriterDynamicLib.so Writer.o

DataStaticLib.a: HotelStubDatabase.o Hotel.o
	ar cr DataStaticLib.a HotelStubDatabase.o Hotel.o

HotelStubDatabase.o: HotelStubDatabase.cpp
	g++ -c HotelStubDatabase.cpp 

Hotel.o: Hotel.cpp
	g++ -c Hotel.cpp

Writer.o: Writer.cpp
	g++ -c -fPIC Writer.cpp

clear: 
	rm -rf *.o *.so *.a test
