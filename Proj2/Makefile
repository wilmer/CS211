all: testDeck testPlayer playGame clean

testDeck: testDeck.o card.o crazy8card.o
	g++ testDeck.o card.o crazy8card.o -o testDeck

testDeck.o: testDeck.cpp deck.h crazy8card.h  card.h
	g++ -c testDeck.cpp

testPlayer: testPlayer.o card.o crazy8card.o player.o
	g++ testPlayer.o card.o crazy8card.o player.o -o testPlayer

testPlayer.o: testPlayer.cpp deck.h crazy8card.h card.h player.h
	g++ -c testPlayer.cpp

playGame: playGame.o card.o crazy8card.o player.o game.o
	g++  playGame.o game.o card.o crazy8card.o player.o -o playGame

playGame.o: playGame.cpp deck.h crazy8card.h card.h player.h game.h
	g++ -c playGame.cpp

game.o: game.h game.cpp
	g++ -c game.cpp

player.o: player.h player.cpp
	g++ -c player.cpp

card.o: card.h card.cpp
	g++ -c card.cpp

crazy8card.o: crazy8card.cpp crazy8card.h card.h
	g++ -c crazy8card.cpp

EXPENDABLES = testDeck.o card.o crazy8card.o testPlayer.o playGame.o player.o game.o

clean: 
	rm -f $(EXPENDABLES)
