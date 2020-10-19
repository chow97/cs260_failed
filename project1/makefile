output: main.o SongLibrary.o
	g++ -g main.o SongLibrary.o -o app

main.o: main.cpp
	g++ -c -g main.cpp

SongLibrary.o: SongLibrary.cpp SongLibrary.h
	g++ -c -g SongLibrary.cpp

run: all
	app

clean: 
	rm *.o app
