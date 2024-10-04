all				:	DRIVER

DRIVER			:	Driver.o Park.o Ride.o Cart.o
					g++ -o Driver.exe Driver.o Park.o Ride.o Cart.o

Driver.o		:	Driver.cpp
					g++ -I ./ -c Driver.cpp

Park.o			:	Park.cpp Park.h
					g++ -I ./ -c Park.cpp

Ride.o			:	Ride.cpp Ride.h
					g++ -I ./ -c Ride.cpp

Cart.o			:	Cart.cpp Cart.h
					g++ -I ./ -c Cart.cpp

clean			:	Driver.exe
					rm *.o *.exe
					del *.o *.exe