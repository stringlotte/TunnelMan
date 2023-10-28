output: main.o Actor.o GameController.o GameWorld.o StudentWorld.o
	g++ main.o Actor.o GameController.o GameWorld.o StudentWorld.o

main.o: main.cpp
	g++ -c main.cpp

Actor.o: Actor.cpp
	g++ -c Actor.cpp

GameController.o: GameController.cpp
	g++ -c GameController.cpp

GameWorld.o: GameWorld.cpp
	g++ -c GameWorld.cpp

StudentWorld.o: StudentWorld.cpp
	g++ -c StudentWorld.cpp

clean:
	rm *.o output
