#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

//DEFINE CONSTANT
#define MAX_EVENT 100

typedef struct {
	//date
	int month;
	int day;
	int year; 
	// start time
	int startHour;
	int endMinute;

	// end time
	int endHour;
	int endMinute;

	//
	char title[100];
	char location[100];
	//int location_size;
	char *location;


} Event;

void printEvent(Event *e) {

	printf("%s at %s is happening from %d:%d to %d:%d on date %d/%d/%d",
		e->title, e->location, e->startHour, e->startMinute, e->endHour, e->endMinute, 
			e->month, e->day, e->year
			);

}


int displayEventAtDate(Event **data, int size, int year, int month, int day);
	int count = 0;

	for ( int i = 0; i < size; i++)l{
		if(data[i]->year == year && data[i]->month && data[i]->day == day) {
			printEvent(data[i]);
			count++;
		}
	}



int displayEventAtLocation(Event **data, int  size, int year, int month, int day);

/*int destroy_event(Event *e) {
	free(e->location)
	free(e)*/

int main() {

	Event *data[MAX_EVENT];

	size_t size = 1024;
	char *buffer = malloc(size * sizeof(char));

	FILE *f = fopen("event.txt", "r");
	int linecount = 0;

	while (getline(&buffer, &size, f) > 0) {

	// extract information from line into an event
	data[linecount] = (Event *)malloc(sizeof(Event));

	sscanf(buffer, "%d/%d/%d|%d:%d|%d:%d|%99[^|]&99[^\n]",
		// put it into event
	&data[linecount]->month),
	&data[linecount]->day),
	&data[linecount]->year),
	&data[linecount]->startHour),
	&data[linecount]->startMinute),
	&data[linecount]->endHour),
	&data[linecount]->endMinute),
	&data[linecount]->title),
	&data[linecount]->location));

	linecount++;
	if (linecount == MAX_EVENT) {
	    break;
		}
	}

}


}
