

main: main.o BubbleSort.o  \
			 BucketSort.o \
			 CountingSort.o \
			 HeapSort.o \
			 InsertionSort.o \
			 MergeSort.o \
			 QuickSort.o \
			 RadixSort.o \
			 SelectionSort.o \
			 ShellSort.o
	gcc -g -o main main.o BubbleSort.o \
						 BucketSort.o \
						 CountingSort.o \
						 HeapSort.o \
						 InsertionSort.o \
						 MergeSort.o \
						 QuickSort.o \
						 RadixSort.o \
						 SelectionSort.o \
						 ShellSort.o
main.o: main.c \
	./BubbleSort/BubbleSort.h \
	./BucketSort/BucketSort.h \
	./CountingSort/CountingSort.h \
	./HeapSort/HeapSort.h \
	./InsertionSort/InsertionSort.h \
	./MergeSort/MergeSort.h \
	./QuickSort/QuickSort.h \
	./RadixSort/RadixSort.h \
	./SelectionSort/SelectionSort.h \
	./ShellSort/ShellSort.h
	gcc -g -c main.c
BubbleSort.o: ./BubbleSort/BubbleSort.c ./BubbleSort/BubbleSort.h
	gcc -g -c ./BubbleSort/BubbleSort.c
BucketSort.o: ./BucketSort/BucketSort.c ./BucketSort/BucketSort.h
	gcc -g -c ./BucketSort/BucketSort.c
CountingSort.o: ./CountingSort/CountingSort.c ./CountingSort/CountingSort.h
	gcc -g -c ./CountingSort/CountingSort.c
HeapSort.o:./HeapSort/HeapSort.c ./HeapSort/HeapSort.h
	gcc -g -c ./HeapSort/HeapSort.c
InsertionSort.o: ./InsertionSort/InsertionSort.c ./InsertionSort/InsertionSort.h
	gcc -g -c ./InsertionSort/InsertionSort.c 
MergeSort.o: ./MergeSort/MergeSort.c ./MergeSort/MergeSort.h
	gcc -g -c ./MergeSort/MergeSort.c 
QuickSort.o: ./QuickSort/QuickSort.c ./QuickSort/QuickSort.h
	gcc -g -c ./QuickSort/QuickSort.c 
RadixSort.o: ./RadixSort/RadixSort.c ./RadixSort/RadixSort.h
	gcc -g -c ./RadixSort/RadixSort.c 
SelectionSort.o: ./SelectionSort/SelectionSort.c ./SelectionSort/SelectionSort.h
	gcc -g -c ./SelectionSort/SelectionSort.c 
ShellSort.o: ./ShellSort/ShellSort.c ./ShellSort/ShellSort.h
	gcc -g -c ./ShellSort/ShellSort.c 
clean:
	rm *.o





