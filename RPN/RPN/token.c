// TOKEN.C [181003]
// Code to retrieve the next token from stdin input.

#include <stdio.h>

//#define DEBUG
#define _HEADER

#ifdef _HEADER

// Define symbols for return value and result
enum TokenValues {EndOfLine, Value, Operator, Error};
enum Operators	{Add, Subtract, Multiply, Divide, Modulus};

// Return value will depend on what kind of token found
union Token	{
		int				intvalue;
		enum Operators	op;
		};

#endif _HEADER


static int isbinop (int ch)
{
	return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%');
}

static int isdigit (int ch)
{
	return (ch >= '0' && ch <= '9');
}

enum TokenValue next_token (union Token *tkn)
// process input characters from stdin, recognizing operators
// (+, -, * and /), numbers [+|-]digit(s), and end-of-line.
// Returns type of token found.  If token has a value - operator
// type or integer value, then token value returned in location
// pointed to by parameter.
{
	int	ch;
	int	doing_number = 0;
	int	number = 0;

	// Keep reading characters and then figuring out what to do
	while ((ch = getchar()) > -1)	{
		if (ch == ' ')	{
			// blanks separate one token from the next - which means
			// it might be the end of a number
			if (doing_number)	{
				doing_number = 0;
				// number accumulated needs to be returned
				tkn->intvalue = number;
				return Value;
				}
			// otherwise blanks are just ignored
			continue;
			}
		if (ch == '\n')	{
			// found end of line - we're done with this input.
			// check first to see if we were accumulating digits in a
			// number
			if (doing_number)	{
				doing_number = 0;
				tkn->intvalue = number;
				// Now we cannot return two different token values,
				// so we'll put the newline back and pick it up next go.
				ungetc (ch, stdin);
				return Value;
				}
			return EndOfLine;
			}
		if (isdigit(ch))	{
			// character read was a digit
			if (doing_number)	{
				// yet another digit in an ongoing number
				number = number * 10 + (ch-'0');
			} else	{
				// this must be the start of a new number
				doing_number = 1;
				number = ch - '0';
				}
			continue;
			}
		if (isbinop(ch))	{
			// found character that could be a binary operator
			switch (ch)	{
			case '+':	// Add operator
				tkn->op = Add;
				return Operator;
			case '*':	// Multiply
				tkn->op = Multiply;
				return Operator;
			case '/':	// Divide
				tkn->op = Divide;
				return Operator;
			case '%':	// Modulus
				tkn->op = Modulus;
				return Operator;
			case '-':	// Could be subtract operator or lead-in to
						// negative number.
				{
				int		tmp = getchar();
				if (isdigit(tmp))	{
					// negative followed immediately by digit
					doing_number = 1;
					number = -(tmp-'0');
					continue;
					}
				// next character not digit - put it back
				ungetc (tmp, stdin);
				}
				tkn->op = Subtract;
				return Operator;
				}//endswitch
			}//endif
		
		}//endwhile
	// if we get here, means it was an invalid character
	return Error;
}//next_token()

	


#ifdef DEBUG

int main (void)
{
	union Token			tkn;
	enum TokenValues	tval;

	for (;;)	{
		tval = next_token (&tkn);
		switch (tval)	{
		case Error:
			printf ("ERROR FOUND\n");
			return -1;
		case EndOfLine:
			printf ("End of line found\n");
			return 0;
		case Value:
			printf ("Number %d found\n", tkn.intvalue);
			break;
		case Operator:
			printf ("Operator found - ");
			switch (tkn.op)	{
			case Add:		printf (" ADD");		break;
			case Subtract:	printf (" SUBTRACT");	break;
			case Multiply:	printf (" MULTIPLY");	break;
			case Divide:	printf (" DIVIDE");		break;
			case Modulus:	printf (" MODULUS");	break;
				}
			printf ("\n");
			break;
			}
		}
	return 0;
}//main()
		
#endif
