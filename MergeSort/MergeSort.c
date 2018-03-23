#include <stdio.h>
#include <stdlib.h>





static void Merge(int *Array,int startIndex,int midIndex,int endIndex)
{
	int startIndexLeft = startIndex,endIndexLeft = midIndex;
	int startIndexRight = midIndex + 1,endIndexRight = endIndex;
	int index = 0,i;
	int *ArrayTemp = (int *)malloc((endIndex - startIndex + 1) * sizeof(int));
	if(NULL == ArrayTemp)
	{
		printf("malloc failed!\n");
		return;
	}
	
	while(startIndexLeft <= endIndexLeft && 
			startIndexRight <= endIndexRight)
	{
		if(Array[startIndexLeft] < Array[startIndexRight])
		{
			ArrayTemp[index++] = Array[startIndexLeft++];
		}
		else
		{
			ArrayTemp[index++] = Array[startIndexRight++];
		}
	}

	while(startIndexLeft <= endIndexLeft)
	{
		ArrayTemp[index++] = Array[startIndexLeft++];
	}

	while(startIndexRight <= endIndexRight)
	{
		ArrayTemp[index++] = Array[startIndexRight];
	}

	for(i = 0;i < (endIndex - startIndex) + 1;i++)
	{
		Array[startIndex + i] = ArrayTemp[i];
	}

	free(ArrayTemp);
}


static void mainMergeSorts(int *Array,int startIndex,int endIndex)
{
	int midIndex = (startIndex + endIndex) >> 1;

	if(startIndex < endIndex)
	{
		mainMerge(Array,startIndex,midIndex);
		mainMerge(Array,midIndex+1,endIndex);
		Merge(Array,startIndex,midIndex,endIndex);
	}
}


void MergeSorts(int *Array,int ArrayLength)
{
	int startIndex = 0,endIndex = ArrayLength - 1;

	mainMergeSorts(Array,startIndex,endIndex);	
}

