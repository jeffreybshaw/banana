all: lib banana

lib:
	gcc -c -Werror -Wall -O2 -fPIC -I. libbanana.c -o libbanana.o
	gcc -shared -o libbanana.so libbanana.o

banana: lib
	gcc -Werror -Wall -O2 -L. -I. -o banana banana.c -lbanana

.PHONY: clean
clean:
	rm -f *.o *.so
	rm -f banana
