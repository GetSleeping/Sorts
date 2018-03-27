#include <stdio.h>
#include <stdlib.h>


#define LEFT(node)  (((node)<<1)+1)
#define RIGHT(node) ((node+1)<<1)


/**
 * @function:swap
 * @parameter:data A & data B
 * @des
 */
static void swap(int *dataA,int *dataB) 
{
	int temp = *dataA;
	*dataA = *dataB;
	*dataB = temp;
}

/**
 * @function:maHeapAdjust
 * @parameter:Array address,the node,Array length
 *
 */
static void maxHeapAdjust(int *Array,int node,int ArrayLength)
{
	int largestNode;
	int leftNode = LEFT(node);
	int rightNode = RIGHT(node);
	if(leftNode < ArrayLength && 
       Array[leftNode] > Array[node]) {
		largestNode = leftNode;	
	}
	else {
		largestNode = node;
	}

	if(rightNode < ArrayLength && 
       Array[rightNode] > Array[largestNode]) {
		largestNode = rightNode;	
	}

	if (largestNode != node) {
		swap(&(Array[largestNode]),&(Array[node]));
		maxHeapAdjust(Array,largestNode,ArrayLength);
	}

}

/**
 * @function:buildMaxHeap
 * @parameter:Array adress ,array length
 *
 */
static void buildMaxHeap(int *Array,int ArrayLength) {
	int node;

	for(node = ((ArrayLength - 1) >> 1);node >= 0;node--) {
		maxHeapAdjust(Array,node,ArrayLength);
	}
}

/**
 * @function:buildMaxHeap
 * @parameter:Array adress ,array length
 *
 */
void HeapSort(int *Array,int ArrayLength)
{
	int heapSize = ArrayLength;
	int i;
	printf("enter %s\n",__FUNCTION__);
	
	buildMaxHeap(Array,ArrayLength);
	
	for(i = ArrayLength - 1;i >= 1;i--) {
		swap(&(Array[0]),&(Array[i]));
		maxHeapAdjust(Array,0,--heapSize);
	}
}

