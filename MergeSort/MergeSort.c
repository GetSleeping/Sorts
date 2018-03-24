#include <stdio.h>
#include <stdlib.h>

static void Merge(int *Array,int startIndex,int midIndex,int endIndex)
{
	int startIndexLeft = startIndex,endIndexLeft = midIndex;
	int startIndexRight = midIndex + 1,endIndexRight = endIndex;
	int index = 0,i;
	int *ArrayTemp;


	printf("enter %s\n",__FUNCTION__);
    ArrayTemp = (int *)malloc((endIndex - startIndex + 1) * sizeof(int));
	printf("%s:%d",__FILE__,__LINE__);
	if(NULL == ArrayTemp)
	{
		printf("malloc failed!\n");
		return;
	}
	printf("%s:%d",__FILE__,__LINE__);
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
		ArrayTemp[index++] = Array[startIndexRight++];
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
	
	printf("enter %s\n",__FUNCTION__);
	if(startIndex < endIndex)
	{
		mainMergeSorts(Array,startIndex,midIndex);
		mainMergeSorts(Array,midIndex+1,endIndex);
		Merge(Array,startIndex,midIndex,endIndex);
	}
}


void MergeSorts(int *Array,int ArrayLength)
{
	//int startIndex = 0,endIndex = ArrayLength - 1;
	int i = 0;
	printf("enter %s\n",__FUNCTION__);
	mainMergeSorts(Array,0,ArrayLength-1);	
	for(i = 0;i < ArrayLength;i++)
	{
		printf("%d:%3d\n",i,Array[i]);
	}
}

