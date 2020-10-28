CC = g++
CPPFLAGS = -Wall -g -std=c++11

main:			main.o supplied.o dlist.o

main.o:			dlist.h

linkedlist.o:		dlist.h

.PHONY: clean	
clean:			# clean the directory
			$(info -- cleaning the directory --)
			rm -f *.o
			rm -f main
