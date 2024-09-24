all				:	DRIVER

DRIVER			:	testDriver.o Park.o Ride.o Cart.o
					g++ -o Driver.exe testDriver.o Park.o Ride.o Cart.o

testDriver.o	:	testDriver.cpp
					g++ -I ./ -c testDriver.cpp

Park.o			:	Park.cpp Park.h
					g++ -I ./ -c Park.cpp

Ride.o			:	Ride.cpp Ride.h
					g++ -I ./ -c Ride.cpp

Cart.o			:	Cart.cpp Cart.h
					g++ -I ./ -c Cart.cpp

clean			:	Driver.exe
					rm *.o
					del *.o
					rm Driver.exe
					del Driver.exe