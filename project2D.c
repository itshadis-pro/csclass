// Name: Hadi Almarzooq
// Class: CS 212
// Assignment: Project2D
//Due: 10/24/2025

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
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
else if (op[0] == '/')
	return DIV;
else if (op[0] == 'x'|| op[0] == 'X')
	return MULT;
else
	IssueBadOperationError(); // print message then exit
}


double StringToDouble(char *str)
{
    double result = 0.0;
	double fraction = 0.0;
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
	double place = 0.1;
	while (str[i] != '\0'){
	  if(str[i] < '0' || str[i] > '9')
	    IssueBadNumberError();
	 result += (str[i] - '0') * place;
	 place /= 10;
	 i++;
	}

    }

    return sign * (result + fraction);

  }

int main(int argc, char *argv[])
{
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
    switch (op)
    {
       case ADD:
         result = v+v2;
         break;

	case SUBTRACT:
	  result = v - v2;
	  break;
	case MULT:
	  result = v * v2;
	  break;
	case DIV:
	  if(v2 == 0)
	   IssueBadNumberError();
	  result = v / v2;
	  break;

	default:
	   IssueBadOperationError();

    }
    printf("%d\n", (int) result);

    return 0;
}
