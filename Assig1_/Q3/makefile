all: main

libmandelbrot.so: mandelbrot_lib.c mandelbrot_lib.h
	gcc -fPIC -shared -o libmandelbrot.so mandelbrot_lib.c -lm

main: main.c libmandelbrot.so
	gcc -g main.c -L. -lmandelbrot -o main -lm

run:
	LD_LIBRARY_PATH=. ./main

clean:
	rm -f main libmandelbrot.so
