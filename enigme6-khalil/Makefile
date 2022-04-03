prog: main.o enigme1.o enigme3.o 
	gcc main.o enigme1.o enigme3.o -o prog -lSDL -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g 
enigme1.o:enigme1.c 
	gcc -c enigme1.c -lSDL -lSDL_image -lSDL_mixer -g
enigme3.o:enigme3.c
	gcc -c enigme3.c -lSDL -lSDL_image -lSDL_mixer -g

