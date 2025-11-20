#include <stdio.h>
#include <stdlib.h>


int main(){

	char** arr = malloc(5*sizeof(char*));

	arr[0] = "Hello";
	arr[1] = "Welcome";
	arr[2] = "Howdy";
	arr[3] = "Hey";
	arr[4] = "Hi";

	for(int i = 0; i < 5; i++){
	printf("%s\n", arr[i]);
}
	return 0;
}


