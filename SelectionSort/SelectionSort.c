#include <stdio.h>



void SelectionSort(int *Array,unsigned char ArrayLength) {
	unsigned char i,j,MinIndex = 0;
	int DataTemp;

	for(i = 0;i < ArrayLength;++i) {
		for(j = i + 1;j < ArrayLength;++j) {
			if (Array[j] < Array[MinIndex]) {
				MinIndex = j;
			}
		}
		
		DataTemp = Array[i];
		Array[i] = Array[MinIndex];
		Array[MinIndex] = Array[i];
	}


	for(i = 0;i < ArrayLength;) {
		printf("%5d,",Array[i++]);
		if(!(i%5)) {
			printf("\n");
		}
	}
}
