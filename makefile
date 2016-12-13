
CC = g++
CFLAGS = -g 
COPTFLAGS = 
LIBFLAGS = -lglut -lGLU -lGL -lm
HEADERS = prototypes.h
OBJECTS = display.o menu.o

all : pristine house clean

house : main.o $(OBJECTS)
	$(CC) main.o $(OBJECTS) -o house $(LIBFLAGS)

main.o : main.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c main.cpp

display.o : display.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c display.cpp

menu.o : menu.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c menu.cpp

clean :
	rm *.o

pristine :
	rm -f *.o 
	touch *.cpp

ctags :
	ctags *.cpp
