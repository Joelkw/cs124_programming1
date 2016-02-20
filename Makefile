all: randmst.c  prim.c heap.c
	gcc -g -o randmst randmst.c prim.c heap.c

