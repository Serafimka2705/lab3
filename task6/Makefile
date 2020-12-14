filter: filter.o bmp_io.o sharpen.o
	gcc -o filter filter.o bmp_io.o sharpen.o

filter.o: filter.c bmp.h
	gcc -c -Wall -Wextra -std=c89 filter.c
sharpen.o: sharpen.c
	gcc -c -Wall -Wextra -std=c89 sharpen.c
bmp_io.o: bmp_io.c bmp.h
	gcc -c -Wall -Wextra -std=c89 bmp_io.c	
clean:
	rm -rf *.o filter
krasivo:
	indent -kr -nut -ts4 *.c
