all: lib

lib:
	gcc -c -Werror -Wall -O2 -fPIC -I. libbanana.c -o libbanana.o
	gcc -shared -o libbanana.so libbanana.o

.PHONY: clean
clean:
	rm -f *.o *.so
