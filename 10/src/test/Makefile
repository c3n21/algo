all:
	gcc -DDEBUG -g -c $(shell find ../ -name '*.c')

test_pqueue: ./test_pqueue.c
	rm test_pqueue.o
	gcc -DDEBUG -g *.o test_pqueue.c -o test_pqueue 

clean:
	rm *.o
	find . -type f -executable -exec rm {} +
