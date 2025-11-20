#include <stdio.h>

// without typedef


	struct student{

	int id;
	char* name;
	int year;
	int age;
	float gpa;

};


// with typedef

	typedef struct{
	int id;
	char* name;
	int age;
	int year;
	float gpa;

}student; 	// the shortcut name student instead of struct student


	int main(){

	struct student s1;	// note we need to write struct here

	s1.id = 952052623;
	s1.name = "Hadi";
	s1.year = 2024;
	s1.age = 28;
	s1.gpa = 3.23;

	printf("Name: %s\nGPA: %.2f\nID: %d\nYear: %d\nAge: %d\n",
			 s1.name, s1.gpa, s1.id, s1.year, s1.age);



	printf("\n\n");

	student s2;

	s2.name = "Hawra";
	s2.id = 1113911182;
	s2.age = 24;
	s2.year = 2026;
	s2.gpa = 4.01;


	printf("Name: %s\nID: %d\nAge: %d\nYear: %d\nGpa: %.2f\n",
		s2.name, s2.id, s2.age, s2.year,s2.gpa);

	return 0;


}
