#include <stdio.h>

/**
* @function:SelectionSort
* @parameter:the array address, array length
* @des:
*/
void SelectionSort(int *Array,int ArrayLength) {
	int i,j,MinIndex = 0;
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
}
