output: main.o songLibrary.o
	g++ -g main.o songLibrary.o -o app

main.o: main.cpp
	g++ -c -g main.cpp

songLibrary.o: songLibrary.cpp songLibrary.h
	g++ -c -g songLibrary.cpp

run: all
	app

clean: 
	rm *.o app
