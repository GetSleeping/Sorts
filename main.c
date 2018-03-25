#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "./BubbleSort/BubbleSort.h"
#include "./BucketSort/BucketSort.h"
#include "./CountingSort/CountingSort.h"
#include "./HeapSort/HeapSort.h"
#include "./InsertionSort/InsertionSort.h"
#include "./MergeSort/MergeSort.h"
#include "./QuickSort/QuickSort.h"
#include "./RadixSort/RadixSort.h"
#include "./SelectionSort/SelectionSort.h"
#include "./ShellSort/ShellSort.h"

#define ARRAY_MAX_LENGTH     20
#define ARRAY_MAX_VALUE      100

/**
* @variable:callBackSortFunc array
* @parameter:null
* @des:the elements are sorts function calback address
*/
void (*callBackSortFunc[])(int *,int ) = {
	&BubbleSort,
	&BucketSort,
	&CountingSort,
	&HeapSort,
	&InsertionSort,
	&MergeSort,
	&QuickSort,
	&RadixSort,
	&SelectionSort,
	&ShellSort,
	
	//add new sort function here
	NULL
};

/**
* @function:printArray
* @parameter:array address ,array length
* @des:printf the array element
*/
void printArray(int *Array,int ArrayLength){
	int i;
	for(i = 0;i < ArrayLength;) { 
		printf("%3d,",Array[i]);
		if(!(++i%5)){
			printf("\n");
		} 
	}
}

/**
* @function:main
* @parameter:void
* @des:
*/
int main(void) {
	int *Array = NULL;
	int ArrayLength = 0;
	int i = 0,j = 0;

	struct timeval tv;
	unsigned int TimeDiff,TimePoint;
	
	/** @des:init the array parameter*/
	ArrayLength = ARRAY_MAX_VALUE;
	printf("The array length is %d\n",ArrayLength);
	Array = (int *)malloc(ArrayLength * sizeof(int));
	if(NULL == Array) {
		printf("array malloc failed!\n");
		return 0;
	}	
	
	/** @des:call the sort functions */
	while(NULL != callBackSortFunc[j]) {

    	for(i = 0;i < ArrayLength;i++) {
            Array[i] =  (rand() % ARRAY_MAX_VALUE) - (ARRAY_MAX_VALUE >> 1);
	    }
        printf("Before sort\n");
        printArray(Array,ArrayLength);

		gettimeofday(&tv,NULL);
		TimePoint = tv.tv_usec;

		(callBackSortFunc[j++])(Array,ArrayLength);

		gettimeofday(&tv,NULL);
		TimeDiff = tv.tv_usec - TimePoint;

	#if 1
        printf("After sort\n");
		printArray(Array,ArrayLength);
	#endif

		printf("Time cost is %d\n\n",TimeDiff);
	}
	
	free(Array);
	printf("exit main\n");
	return 0;
}



