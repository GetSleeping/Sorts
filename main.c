#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
//#include 

#define ARRAY_MAX_LENGTH     128
#define ARRAY_MAX_VALUE      1000

int main(void) {
	int *Array;
	unsigned char ArrayLength;
	unsigned char i = 0;

	struct timeval tv;
	unsigned int TimeDiff,TimePoint;

	ArrayLength = rand() % ARRAY_MAX_LENGTH;
	printf("The array length is %d\n",ArrayLength);

	Array = (int *)malloc(ArrayLength * sizeof(int));
	if(NULL == Array) {
		printf("array malloc failed!\n");
		return 0;
	}

	for(i = 0;i < ArrayLength;) {
		Array[i] = (rand() % ARRAY_MAX_VALUE) - (ARRAY_MAX_VALUE >> 1);
		printf("%5d,",Array[i++]);
		if (!(i % 5)) {
			printf("\n");
		}
	}
	printf("\n");

	//1.
	gettimeofday(&tv,NULL);
	TimePoint = tv.tv_usec;
	//code here
	sleep(1);
	gettimeofday(&tv,NULL);
	TimeDiff = tv.tv_usec - TimePoint;
	printf("The time cost is %d\n",TimeDiff);

	free(Array);
	printf("Hello world\n");
	return 0;
}



