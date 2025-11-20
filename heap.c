#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int id;
	char* name;
	int age;
	int year;
	float gpa;
}student;
	int main(){
	// stack
	student s_stack = {952052623, "Hadi", 25, 2025, 3.25f};
	// heap
	student *s_heap = malloc(sizeof*s_heap);

	s_heap->id = 1113911182;
	s_heap->name = "Hawra";
	s_heap->age = 24;
	s_heap->year = 2025;
	s_heap->gpa = 5.99;

	printf("Stack student Information: \nStudent ID: %d\nName: %s\nAGE: %d\nYear: %d\nGPA: %.2f\n\n",
			s_stack.id, s_stack.name, s_stack.age, s_stack.year, s_stack.gpa);
	printf("Heap student ID: \nStudent ID: %d\nName: %s\nAGE: %d\nYEAR: %d\nGPA: %.2f\n",
		 s_heap->id, s_heap->name, s_heap->age, s_heap->year, s_heap->gpa);

	return 0;

}
