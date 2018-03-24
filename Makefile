

main: main.o MergeSort.o
	gcc -g -o main main.o MergeSort.o
main.o: main.c ./MergeSort/MergeSort.h
	gcc -g -c main.c
MergeSort.o: ./MergeSort/MergeSort.c ./MergeSort/MergeSort.h
	gcc -g -c ./MergeSort/MergeSort.c
clean:
	rm *.o





