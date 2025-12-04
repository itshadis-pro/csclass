// Name: Hadi Almarzooq
// Class: CS 212
// Assignment: Proj3E
//Due: 12/06/2025

#include <stdio.h>
#include <stdlib.h>


float stack[10];
int top = 0;

void push(float value)
{
	stack[top] = value;
	top++;

}

float pop()
{

	top--;
	return stack[top];

}


typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
  // DIV,
   UNSUPPORTED
} MathOperation;

void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

MathOperation GetOperation(char *op)
{

	//Make sure operator is exactly one valid symbol


   if(op[1] != '\0') // more than one character ++ +- etc
	IssueBadOperationError();

    if (op[0] == '+')
	return ADD;
else if (op[0] == '-')
	return SUBTRACT;
//else if (op[0] == '/')
//	return DIV;
else if (op[0] == 'x'|| op[0] == 'X')
	return MULT;
else
	IssueBadOperationError(); // print message then exit
}


float StringToFloat(char *str)
{
    float result = 0.0;
	//float fraction = 0.0;
	int sign = 1;
	int i = 0;

	// Handle negative sign
	if (str[i] == '-'){
	sign = -1;
	i++;
	}

	// integer part

	while (str[i] != '\0' && str[i] != '.'){
	    if(str[i] < '0' || str[i] > '9')
		IssueBadNumberError();
	result = result * 10 + (str[i] - '0');
	i++;
	}

	// Fraction Part

	if (str[i] == '.'){
	i++;
	float place = 0.1;
	while (str[i] != '\0'){
	  if(str[i] < '0' || str[i] > '9')
	    IssueBadNumberError();
	 result += (str[i] - '0') * place;
	 place /= 10;
	 i++;
	}

    }

    return sign * result;

  }

int main(int argc, char *argv[])
{

	// check if enough arguments exist (at least one number/operator)
	if (argc < 2){
		return 0;
	}

	//Sart the loop from i = 1 skipping the program name
	for (int i = 1; i < argc; i++) {

		char *token = argv[i];

		//Assume it is not a number until confirmed to be (x + -)
		int is_operator = 0;

		//is it an operator? check if itsa single character string and is  + - *
		if (token[1] == '\0'){

		// Handle addition RPN logic
			if (token[0] == '+'){
			is_operator = 1;

			// RPN Logic 

			float B = pop();
			float A = pop();

			float result = A + B;
			push(result);
			// Handle substraction 
			}else if (token[0] == '-'){
			is_operator = 1;

			// RPM LOGIC
			float B = pop();
			float A = pop();

			float result = A - B;
			push(result);
			//Handle Multipkication
			}else if (token[0] == 'x'){


			float B = pop();
			float A = pop();

			float result = A * B;
			push(result);
			is_operator = 1;

		}

	}

	// if it is a number? if it was not confirmed if it is an operator, treat it as number
	if (is_operator ==  0){
	// convert the string to a float and push it
	float num = StringToFloat(token);
	push(num);

		}

	}

	float answer = pop();

	printf("The total is %d\n", (int)answer);

	return 0;

}



/* float v1 =  StringToFloat("12.34");
printf("Test 1 (Integer part of 12.34): %f\n", v1);

float v2 = StringToFloat("12.34");
int fractional_part = (int)(v2 * 100) - ((int)v2 * 100);
printf("Test 2 (Fractional Part of 12.34): %d\n", fractional_part); // Should print 34

float v3  = StringToFloat("45");
printf("Test 3 (Integer) %d\n", (int)v3); // should print 45


float v4 = StringToFloat("0.0");
printf("Test 4 (zero) %d\n", (int)v4);*/

