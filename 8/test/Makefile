all:
	gcc -DDEBUG -g -c $(shell find ../src/bist/ -name '*.c')
	gcc -DDEBUG -g -c test.c 
esercizio2: ../src/esercizio2.c
	gcc -DDEBUG -g -rdynamic *.o ../src/esercizio2.c -o esercizio2

clean:
	rm *.o
	find . -type f -executable -exec rm {} +

test_bist: ./test_bist.c
	gcc -DDEBUG -g -rdynamic *.o test_bist.c -o test_bist

test_item: test_item.c
	gcc -g -o test_item test_item.c ../src/bist/bit/item/item.c
