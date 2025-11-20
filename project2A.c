
#include <stdio.h>


int main(){
//We have to set this main function to include all the code we write
int print_factor = 0;
int i, j;
int the_number = i;
int num_factors = 0;
// this is a copy from python code, do not need it
for (int i = 2; i < 1000; i++){
// outter loop that goes from 2 in the range of 2 to 1000 (inclusive) inrement i by 1 each time
	the_number = i;
// Assign current i to the_number so we can modify it or check it without losing i
	 num_factors = 0;
// counter variable to count the numbers of distinct factors

	for(int j = 2; j < i - 1; j++){
// inner loop starting 2 up to i -1, check each possible divisor
		if (the_number % j == 0){
// if the_number is divisable by j( no remainder )
		 num_factors ++;
// increment 1 distinct factor to the counter num_factor
		while(the_number % j == 0){
// while the_number still divisable by j, divide it completely
			the_number = the_number/j;
			}
		}
	}

// while the above statements true, devide the number by j to check how many factors
		 if(num_factors == 3){
// if the number has factors is exactly 3 true
		  printf("%d has three factors\n", i);
// print the statment with the number
					}
				}
	return 0;
			}
