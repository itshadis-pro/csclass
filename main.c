#include <stdio.h>
#include <stdlib.h>


int main(){

	int stackArr[5];
	int *dynamicArr = malloc(5 * sizeof(int));

	int *ptr
	ptr = dynamicArr;
	for (int i = 0; i < 5; i++){
	*ptr = i;
	ptr++;

	}
	for (int i = 0; i < 5; i++){
	printf("%d\n", *ptr);
	ptr++;
	}

}
