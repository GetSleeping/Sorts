#include <stdio.h>


/**
* @function:InsertionSort
* @parameter:the array address,the array length
* @des:
*/
void InsertionSort(int *Array,int ArrayLength) {
	int i;
	short PreIndex;
	int DataTemp;

	printf("enter %s\n",__FUNCTION__);

	for(i = 1;i < ArrayLength;++i) {
		PreIndex = i - 1;
		DataTemp = Array[i];
		while((PreIndex >= 0) && (DataTemp < Array[PreIndex])) {
			Array[PreIndex+1] = Array[PreIndex];
			PreIndex--;
		}

		Array[PreIndex+1] = DataTemp;
	}
}
