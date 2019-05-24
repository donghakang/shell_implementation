all: shell.c util.o build
	gcc shell.c -o shell util.o

util.o: util.c util.h
	gcc -c util.c

build: grep du
	echo "Build completed"

grep: grep.c
	gcc grep.c -o grep

du: du.c
	gcc du.c -o du

clean:
	rm -f *.o shell grep du
