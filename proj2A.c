// Hadi AlmarzooqS 
// proj2A Due 10/13/2025
// CS 212 

#include <stdio.h>

int main() {
	int print_factors = 0; // 1 = print factors, 0 = only show count
	int i, j;
        int the_number = i;
        int num_factors = 0;

	// Loop through numbers 2 to 999
	for (i = 2; i< 1000; i++) {
		the_number = i;
		num_factors = 0;

	// Check for distinct factors
	for (j = 2; j < i - 1; j++) { // ++ is the increment operator
		if (the_number % j == 0) {
			num_factors++;
	// Divide out all instances of this factor

		while (the_number % j == 0) {
		the_number = the_number/j;
			}
		}
	}
	// if number has exactly 3 distinct factors
	if (num_factors == 3) {
	printf("%d has three factors\n", i);
			}
		}
	return 0;
	}
