// Hadi Almarzooq 
// Class : CS 212 
// Assigment: Project2E
// Due: 10/27/2025

#include<stdio.h>


int main(int argc, char **argv){

	// accessing binary file and output file;
	FILE* in = fopen(argv[1],"r");
	FILE* out = fopen(argv[2], "w");

	// look for 5x5 block
	// loop over 5x5 and  look for 0-4, 10-14, 20-24, 30-34, 40-44
	int i;
	for (i = 0; i < 5; i++){
	int A[5];
	fread(A, sizeof(int), 5, in);
	fseek(in, 5*sizeof(int), SEEK_CUR);

	// writing the numbers into output file
	int j;
	for (j = 0; j < 5; j++){

		fprintf(out, "%d\n", A[j]);


		}
	}

 }
