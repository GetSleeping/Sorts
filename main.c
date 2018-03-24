#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "./MergeSort/MergeSort.h"

#define ARRAY_MAX_LENGTH     20
#define ARRAY_MAX_VALUE      100

int main(void) {
	int *Array;
	int ArrayLength;
	int i = 0;

	struct timeval tv;
	unsigned int TimeDiff,TimePoint;

	ArrayLength = ARRAY_MAX_VALUE;//rand() % ARRAY_MAX_LENGTH;
	printf("The array length is %d\n",ArrayLength);

	Array = (int *)malloc(ArrayLength * sizeof(int));
	if(NULL == Array) {
		printf("array malloc failed!\n");
		return 0;
	}

	for(i = 0;i < ArrayLength;i++) {
		Array[i] =  (rand() % ARRAY_MAX_VALUE) - (ARRAY_MAX_VALUE >> 1);

		printf("%d:%d\n",i,Array[i]);
#if 0
		Array[i] = (rand() % ARRAY_MAX_VALUE) - (ARRAY_MAX_VALUE >> 1);
		printf("%5d,",Array[i++]);
		if (!(i % 5)) {
			printf("\n");
		}
#endif
	}
	printf("\n");

	//1.
	//gettimeofday(&tv,NULL);
	//TimePoint = tv.tv_usec;
	//code here
	//sleep(1);
	//printf();
	MergeSorts(Array,ArrayLength);
	//gettimeofday(&tv,NULL);
	//TimeDiff = tv.tv_usec - TimePoint;
	//printf("The time cost is %d\n",TimeDiff);

	free(Array);
	printf("Hello world\n");
	return 0;
}



