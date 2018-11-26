// RPN.C [181003]
// Code to evaluate RPN expression.

#include <stdio.h>
#include "stack.h"
#include "token.h"

//#define MAIN
#ifdef MAIN
int main(void)
{
	union Token			tkn;
	enum TokenValues	tval;
	int					value, x, y;
	pStack	ps = createStack(100);

	printf("Enter expression in RPN\n");
	for (;;) {
		tval = next_token(&tkn);
		switch (tval) {
		case Error:
			printf("ERROR FOUND - Evaluation terminated\n");
			return -1;
		case EndOfLine:
			pop(ps, &value);
			printf("Answer is: %d\n", value);
			return 0;
		case Value:
			push(ps, tkn.intvalue);
			break;
		case Operator:
			//printf ("Operator found - ");
			switch (tkn.op) {
			case Add:
				pop(ps, &x);
				pop(ps, &y);
				value = x + y;
				push(ps, value);
				break;
			case Subtract:
				pop(ps, &x);
				pop(ps, &y);
				value = x - y;
				push(ps, value);
				break;
			case Multiply:
				pop(ps, &x);
				pop(ps, &y);
				value = y * x;
				push(ps, value);
				break;
			case Divide:
				pop(ps, &x);
				pop(ps, &y);
				value = x / y;
				push(ps, value);
				break;
			case Modulus:
				pop(ps, &x);
				pop(ps, &y);
				value = y % x;
				push(ps, value);
				break;
			}
			break;
		}
	}
	return 0;
}//main()

#endif // MAIN

