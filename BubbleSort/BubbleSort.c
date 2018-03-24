#include <stdio.h>



/**
 * @function:BubbleSort
 * @parameter:array address ,array length
 */
void BubbleSort(int *Array,int ArrayLength) {
	int i,j;
	int DataTemp;
	
	printf("enter %s\n",__FUNCTION__);

	for(i = 0;i < ArrayLength;++i) {
		for(j = 0;j < ArrayLength - 1 - j;++j) {
			if (Array[j] > Array[j + 1]) {
				DataTemp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = DataTemp;
			}
		}	
	}
}
