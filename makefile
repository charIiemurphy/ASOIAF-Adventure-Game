#Based on "Make help" video under resources in canvas

asoiaf: main.o Dragonstone.o Game.o intValidationRange.o IsleOfFaces.o KingsLanding.o LandOfAlwaysWinter.o NorthOfWall.o Space.o TheTwins.o Winterfell.o
	g++ -std=c++11 main.o Dragonstone.o Game.o intValidationRange.o IsleOfFaces.o KingsLanding.o LandOfAlwaysWinter.o NorthOfWall.o Space.o TheTwins.o Winterfell.o -o asoiaf

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Dragonstone.o: Dragonstone.cpp Dragonstone.hpp
	g++ -std=c++11 -c Dragonstone.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

intValidationRange.o: intValidationRange.cpp intValidationRange.hpp
	g++ -std=c++11 -c intValidationRange.cpp

IsleOfFaces.o: IsleOfFaces.cpp IsleOfFaces.hpp
	g++ -std=c++11 -c IsleOfFaces.cpp

KingsLanding.o: KingsLanding.cpp KingsLanding.hpp
	g++ -std=c++11 -c KingsLanding.cpp

LandOfAlwaysWinter.o: LandOfAlwaysWinter.cpp LandOfAlwaysWinter.hpp
	g++ -std=c++11 -c LandOfAlwaysWinter.cpp

NorthOfWall.o: NorthOfWall.cpp NorthOfWall.hpp
	g++ -std=c++11 -c NorthOfWall.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++11 -c Space.cpp

TheTwins.o: TheTwins.cpp TheTwins.hpp
	g++ -std=c++11 -c TheTwins.cpp

Winterfell.o: Winterfell.cpp Winterfell.hpp
	g++ -std=c++11 -c Winterfell.cpp

clean:
	rm *.o asoiaf
