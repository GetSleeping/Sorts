#include <stdio.h>




void BubbleSort(int *Array,unsigned char ArrayLength) {
	unsigned char i,j;
	int DataTemp;
	

	printf("Enter %s\n",__FUNCTION__);
	for(i = 0;i < ArrayLength;++i) {
		for(j = 0;j < ArrayLength - 1 - j;++j) {
			if (Array[j] > Array[j + 1]) {
				DataTemp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = DataTemp;
			}
		}	
	}

	for(i = 0;i < ArrayLength;) {
		printf("%d,",Array[i++]);
		if(!(i % 5)) {
			printf("\n");
		}
	}
}
