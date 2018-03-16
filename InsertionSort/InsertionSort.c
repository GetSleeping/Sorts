#include <stdio.h>



void InsertSort(int *Array,unsigned char ArrayLength) {
	unsigned char i;
	short PreIndex;
	int DataTemp;

	for(i = 1;i < ArrayLength;++i) {
		PreIndex = i - 1;
		DataTemp = Array[i];
		while((PreIndex >= 0) && (DataTemp < Array[PreIndex])) {
			Array[PreIndex+1] = Array[PreIndex];
			PreIndex--;
		}

		Array[PreIndex+1] = DataTemp;
	}

	for(i = 0;i < ArrayLength;++i) {
		printf("%5d,",Array[i]);
		if(!(i%5)) {
			printf("\n");
		}
	}

}
