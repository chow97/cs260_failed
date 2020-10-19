output: main.o SongList.o
	g++ -g main.o SongList.o -o app

main.o: main.cpp
	g++ -c -g main.cpp

SongList.o: SongList.cpp SongList.h
	g++ -c -g SongList.cpp

run: all
	app

clean: 
	rm *.o app
