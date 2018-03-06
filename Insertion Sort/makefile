#### MAKEFILE INSERTION_SORT#####


main:	main.o insertion_sort.o
	gcc main.o insertion_sort.o	-o main

main.o:	main.c
	gcc -c main.c

selection_sort.o:	insertion_sort.c	insertion_sort.h
	gcc -c insertion_sort.c

clean:
	rm *.o
