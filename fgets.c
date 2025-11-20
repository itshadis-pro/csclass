#include <stdio.h>

int main(){

	char greetings[50];
	int n = 10;

	printf("Enter a greeting: \n");
	fgets(greetings, n, stdin);

	printf("You Enter: %s", greetings);

	

	return 0;

}
