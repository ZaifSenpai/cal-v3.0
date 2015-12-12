/*------------------------------------------------

Cal v3.0
Afcorx there are some unsetisfying things. But
I'll upload new version soon ;)

------------------------------------------------*/

#include <stdio.h>
#include "conio.h"

int is_a_num(char A);
void pi(int a);
void pc(char A);

int main() {
	int is_in_dec = 0;
	char input, opr;
	float i, j = 1, ans = 0, num1 = 0, num2 = 0;

	start:

	printf("Enter your expression and then press Enter\nOnly +, -, *, / and %c (remainder) is allowed:\n\nExpression: ", '%');

	// To input 1st Operand and Operator
	for (;;) {
		input = getch();

		if (is_a_num(input) == 0) {
			if (input == '+' || input == '-' || input == '*'
				|| input == '/' || input == '%') {
				opr = input;
				pc(input);
				goto stop1;
			}
			else if (input == '.' && is_in_dec == 0) {
				is_in_dec = 1;
				pc(input);
			}
			else if (input == 32) pc(input);
		}

		else {
			pc(input);
			i = input-48;
			if (is_in_dec == 1)
			{
				j /= 10;
				i *= j;
			}
			else if (is_in_dec == 0) {
				num1 *= 10;
			}
			num1 += i;
		}
	}

	stop1:

	// To input 2nd Operand
	j = 1;
	is_in_dec = 0;
	for (;;) {
		input = getch();

		if (is_a_num(input) == 0) {
			if (input == 10) {
				pc(input);
				goto stop2;
			}
			else if (input == '.' && is_in_dec == 0) {
				is_in_dec = 1;
				pc(input);
			}
			else if (input == '.') is_in_dec = 1;
		}
		
		else {
			pc(input);
			i = input-48;
			if (is_in_dec == 1)
			{
				j /= 10;
				i = j*i;
			}
			else if (is_in_dec == 0) {
				num2 *= 10;
			}
			num2 += i;
		}
	}
	stop2:

	switch(opr)
		{
		case '+':
			printf("\nResult = %f\n", num1+num2);
		break;

		case '-':
			printf("\nResult = %f\n", num1-num2);
		break;

		case '*':
			printf("\nResult = %.2f\n", num1*num2);
		break;

		case '/':
			ans = num1/num2;
			printf("\nResult = %.2f\n", ans);
		break;

		case '%':
			printf("\nResult = %d\n", (int)num1%(int)num2);
		break;

		default:
			printf("\nWrong Input, try again\n");
			goto start;
		break;
	}

	return 0;
}

int is_a_num(char A) {
	int ret;
	if (A != '0' && A != '1' && A != '2' && A != '3' && A != '4' && A != '5' && A != '6' && A != '7' && A != '8' && A != '9') {
		ret = 0;
	}
	else ret = 1;
	return ret;
}

void pi(int a) {
	printf("%d", a);
}

void pc(char A) {
	printf("%c", A);
}
