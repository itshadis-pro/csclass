//Name: Hadi ALmarzooq
//Project2F Due 10/31/2025


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char *s)
{
    /* Return the length of string s using the C convention of
     * being terminated by the NULL character.
     * Do not call any other functions whatsoever.
     * Even my_strlen -- no solutions involving recursion. */

	int sum = 0;
	// itterating through s and stop at null character
	for(int i = 0; s[i] != '\0'; i++)
	// set a counter
	  sum += 1;
	return sum;

    return -1;
}

void str_reverse(char *str)
{
    /* Modify s to be the reverse string.
     * If s is "hello" when the function is called, then it
     * should be "olleh" when the function is completed.
     * Do not call any other functions whatsoever. */

	// we devide the array by 2 to only look at the half of the array and swap it, so we don't swap character more than one time.
	for(int i = 0; i < my_strlen(str)/2; i++){
	// index the character that we are swapping
	  int rev = my_strlen(str) - i - 1;
	  // storing the i in a character
	   char r = str[i];
	   str[i] = str[rev];
	   str[rev] = r;
	}


}

int main()
{
    char *str = malloc(strlen("hello world")+1);
    char *str2 = malloc(strlen("cs 212")+1);
    strcpy(str, "hello world");
    strcpy(str2, "cs 212");
    str_reverse(str);
    str_reverse(str2);
    if (strcmp(str, "dlrow olleh") == 0)
    {
        if (strcmp(str2, "212 sc") == 0)
        {
            printf("Congrats!  You have successfully reversed \"hello world\" to \"%s\"\n", str);
            exit(EXIT_SUCCESS);
        }
    }

    printf("Project does not work yet.  You reversed \"hello world\" to \"%s\" and \"cs 212\" to \"%s\"\n", str, str2);
    exit(EXIT_FAILURE);
}
