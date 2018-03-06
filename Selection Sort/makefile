#### MAKEFILE SELECTION_SORT#####


main:	main.o selection_sort.o
	gcc main.o selection_sort.o	-o main

main.o:	main.c
	gcc -c main.c

selection_sort.o:	selection_sort.c	selection_sort.h
	gcc -c selection_sort.c

clean:
	rm *.o
