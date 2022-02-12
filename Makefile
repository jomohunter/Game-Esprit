prog:main.c
	gcc -c main.c
	gcc main.o -o prog -lSDL
	./prog
