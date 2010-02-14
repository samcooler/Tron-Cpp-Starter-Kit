# The Makefile
#
# If you're using Windows and you don't know what this file is,
# don't worry about it. Just use Visual C++ Express Edition or
# Dev-C++ to work on your code. Mac users can use Xcode.

MyTronBot: MyTronBot.o Map.o Point.o Direction.o
	g++ -02 -o MyTronBot MyTronBot.o Map.o Point.o Direction.o

MyTronBot.o: MyTronBot.cpp
	g++ -02 -c -o MyTronBot.o MyTronBot.cpp

Map.o: Map.cpp
	g++ -02 -c -o Map.o Map.cpp
	
Point.o: Point.cpp
	g++ -02 -c -o Point.o Point.cpp

Direction.o: Direction.cpp
	g++ -02 -c -o Direction.o Direction.cpp
	
clean:
	rm Map.o Point.o Direction.o MyTronBot.o MyTronBot