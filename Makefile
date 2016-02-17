all: prim.c heap.c
	gcc -o prim prim.c heap.c
	clang randmst.c -o randmst
