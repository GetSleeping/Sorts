#include <stdio.h>
#include <stdlib.h>





#define LEFT(node)  ((node)<<1)
#define RIGHT(node) (((node)<<1)+1)

static void swap(int *dataA,int *dataB) 
{
	int temp = *dataA;
	*dataA = *dataB;
	*dataB = temp;
}


static void maxHeapAdjust(int *Array,int node,int ArrayLength)
{
	int largestNode;
	if(LEFT(node) < ArrayLength && 
       Array[LEFT(node)] > Array[node]) {
		largestNode = LEFT(node);	
	}
	else {
		largestNode = node;
	}

	if(RIGHT(node) < ArrayLength && 
       Array[RIGHT(node)] > Array[largestNode]) {
		largestNode = RIGHT(node);	
	}

	if (largestNode != node) {
		swap(&(Array[largestNode]),&(Array[node]));
		maxHeapAdjust(Array,node,ArrayLength);
	}

}

static void buildMaxHeap(int *Array,int ArrayLength) {
	int node;

	for(node = (ArrayLength >> 1) - 1;node >= 0;node--) {
		maxHeapAdjust(Array,node,ArrayLength);
	}
}



void HeapSort(int *Array,int ArrayLength)
{
	int heapSize = ArrayLength;
	int i;
	printf("enter %s\n",__FUNCTION__);
	
	buildMaxHeap(Array,ArrayLength);
	
	for(i = (ArrayLength >> 1) - 1;i >= 1;i--) {
		swap(&(Array[0]),&(Array[i]));
		maxHeapAdjust(Array,1,--heapSize);
	}
}

