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
	NULL,
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
	for(i = 0;i < ArrayLength;i++) { 
		printf("%3d,",Array[i]);
		if(!(i%5)){
			printf("\n");
		} 
	}
	printf("\n");
}

/**
* @function:main
* @parameter:void
* @des:
*/
int main(void) {
	int *Array;
	int ArrayLength;
	int i = 0;

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
	for(i = 0;i < ArrayLength;i++) {
		Array[i] =  (rand() % ARRAY_MAX_VALUE) - (ARRAY_MAX_VALUE >> 1);
	}

	printArray(Array,ArrayLength);
	
	/** @des:call the sort functions */
	i = 0;
	while(NULL != callBackSortFunc[i++]) {
		gettimeofday(&tv,NULL);
		TimePoint = tv.tv_usec;
		callBackSortFunc[i](Array,ArrayLength);
		gettimeofday(&tv,NULL);
		TimeDiff = tv.tv_usec - TimePoint;
	#if 0
		printArray(Array,ArrayLength);
	#endif
		printf("Time cost is %d\n",TimeDiff);
	}
	
#if 0
	/** @des:BubbleSort time cost test*/
	gettimeofday(&tv,NULL);
	TimePoint = tv.tv_usec;
	BubbleSort(Array,ArrayLength);
	gettimeofday(&tv,NULL);
	TimeDiff = tv.tv_usec - TimePoint;
#if 0
	printArray(Array,ArrayLength);
#endif
	printf("BubbleSort time cost is %d\n",TimeDiff);

	/** @des:BucketSort time cost test*/
	gettimeofday(&tv,NULL);
	TimePoint = tv.tv_usec;
	BucketSort(Array,ArrayLength);
	gettimeofday(&tv,NULL);
	TimeDiff = tv.tv_usec - TimePoint;
#if 0
	printArray(Array,ArrayLength);
#endif
	printf("BucketSort time cost is %d\n",TimeDiff);
	
	/** @des:CountingSort time cost test*/
	gettimeofday(&tv,NULL);
	TimePoint = tv.tv_usec;
	CountingSort(Array,ArrayLength);
	gettimeofday(&tv,NULL);
	TimeDiff = tv.tv_usec - TimePoint;
#if 0
	printArray(Array,ArrayLength);
#endif
	printf("CountingSort time cost is %d\n",TimeDiff);
	
	/** @des:HeapSort time cost test*/
	gettimeofday(&tv,NULL);
	TimePoint = tv.tv_usec;
	HeapSort(Array,ArrayLength);
	gettimeofday(&tv,NULL);
	TimeDiff = tv.tv_usec - TimePoint;
#if 0
	printArray(Array,ArrayLength);
#endif
	printf("HeapSort time cost is %d\n",TimeDiff);
	
	/** @des:InsertionSort time cost test*/
	gettimeofday(&tv,NULL);
	TimePoint = tv.tv_usec;
	InsertionSort(Array,ArrayLength);
	gettimeofday(&tv,NULL);
	TimeDiff = tv.tv_usec - TimePoint;
#if 0
	printArray(Array,ArrayLength);
#endif
	printf("InsertionSort time cost is %d\n",TimeDiff);
	
	/** @des:MergeSort time cost test*/
	gettimeofday(&tv,NULL);
	TimePoint = tv.tv_usec;
	MergeSort(Array,ArrayLength);
	gettimeofday(&tv,NULL);
	TimeDiff = tv.tv_usec - TimePoint;
#if 0
	printArray(Array,ArrayLength);
#endif
	printf("MergeSort time cost is %d\n",TimeDiff);
	
	/** @des:QuickSort time cost test*/
	gettimeofday(&tv,NULL);
	TimePoint = tv.tv_usec;
	QuickSort(Array,ArrayLength);
	gettimeofday(&tv,NULL);
	TimeDiff = tv.tv_usec - TimePoint;
#if 0
	printArray(Array,ArrayLength);
#endif
	printf("QuickSort time cost is %d\n",TimeDiff);
	
	/** @des:RadixSort time cost test*/
	gettimeofday(&tv,NULL);
	TimePoint = tv.tv_usec;
	RadixSort(Array,ArrayLength);
	gettimeofday(&tv,NULL);
	TimeDiff = tv.tv_usec - TimePoint;
#if 0
	printArray(Array,ArrayLength);
#endif
	printf("RadixSort time cost is %d\n",TimeDiff);
	
	/** @des:SelectionSort time cost test*/
	gettimeofday(&tv,NULL);
	TimePoint = tv.tv_usec;
	SelectionSort(Array,ArrayLength);
	gettimeofday(&tv,NULL);
	TimeDiff = tv.tv_usec - TimePoint;
#if 0
	printArray(Array,ArrayLength);
#endif
	printf("SelectionSort time cost is %d\n",TimeDiff);
	
	/** @des:ShellSort time cost test*/
	gettimeofday(&tv,NULL);
	TimePoint = tv.tv_usec;
	ShellSort(Array,ArrayLength);
	gettimeofday(&tv,NULL);
	TimeDiff = tv.tv_usec - TimePoint;
#if 0
	printArray(Array,ArrayLength);
#endif
	printf("ShellSort time cost is %d\n",TimeDiff);
	
#endif
	free(Array);
	printf("exit main\n");
	return 0;
}



