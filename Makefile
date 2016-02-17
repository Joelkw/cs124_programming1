all: randmst.c  prim.c heap.c
	gcc -o randmst randmst.c prim.c heap.c

