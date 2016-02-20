all: randmst.c  prim.c heap.c
	gcc -std=c99 -g -o randmst randmst.c prim.c heap.c -lm 

