#include <stdio.h>
#include <stdlib.h>

/**
 * @function:Merge
 * @parameter:array address,start index,middle index,end index
 * @des:merge two child gather
 */
static void Merge(int *Array,int startIndex,int midIndex,int endIndex)
{
	int startIndexLeft = startIndex,endIndexLeft = midIndex;
	int startIndexRight = midIndex + 1,endIndexRight = endIndex;
	int index = 0,i;
	int *ArrayTemp = NULL;

    ArrayTemp = (int *)malloc((endIndex - startIndex + 1) * sizeof(int));
	if(NULL == ArrayTemp) {
		printf("malloc failed!\n");
		return;
	}
	
	/** @des: compare two element and put the smaller element to the buffer*/
	while(startIndexLeft <= endIndexLeft && 
			startIndexRight <= endIndexRight) {

		if(Array[startIndexLeft] < Array[startIndexRight]) {
			ArrayTemp[index++] = Array[startIndexLeft++];
		}
		else {
			ArrayTemp[index++] = Array[startIndexRight++];
		}
	}

	/** @des:check the remaining element of left child gather */
	while(startIndexLeft <= endIndexLeft) {
		ArrayTemp[index++] = Array[startIndexLeft++];
	}

	/** @des:check the remaining element of right child gather */
	while(startIndexRight <= endIndexRight)	{
		ArrayTemp[index++] = Array[startIndexRight++];
	}

	/** @des:copy to the main array */
	for(i = 0;i < (endIndex - startIndex) + 1;i++) {
		Array[startIndex + i] = ArrayTemp[i];
	}

	free(ArrayTemp);
}

/**
 * @function:mainMergeSorts
 * @parameter:array address ,start index ,end index
 * @des:recursive funtion
 */
static void mainMergeSorts(int *Array,int startIndex,int endIndex)
{
	int midIndex = (startIndex + endIndex) >> 1;
	
	if(startIndex < endIndex)
	{
		mainMergeSorts(Array,startIndex,midIndex);//left child gather
		mainMergeSorts(Array,midIndex+1,endIndex);//right child gather
		Merge(Array,startIndex,midIndex,endIndex);//merge them
	}
}


void MergeSort(int *Array,int ArrayLength)
{
	printf("enter %s\n",__FUNCTION__);
	mainMergeSorts(Array,0,ArrayLength-1);	

}

