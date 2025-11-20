#include <stdio.h>
#include <string.h>

int main(){

	char* student_info = "Hadi CS 3.23";

	char name[10], major[20];
	float gpa;

	sscanf(student_info, " %s %s %f", name, major, &gpa);
	printf("Name:  %s\n", name);
	printf("Major:  %s\n", major);
	printf("GPA:  %.2f\n", gpa);

	return 0;

}
