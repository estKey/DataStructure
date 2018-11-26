///Author : Nalsen
///Date : 2018-9-19
/**/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RPNMAIN
#ifdef RPNMAIN
typedef struct Node
{
	char value;
	struct Node *next;
}Node;

typedef struct Stack {
	int size;
	Node *top;
}Stack;

#define ERR -999

Stack *initStack();
void Push(Stack *stack, int value);
void PushValue(Stack *stack);
int  Pop(Stack *stack);
void PopValue(Stack *stack);
int	 *Tos(Stack *stack);
void Sub(Stack *stack);
void Div(Stack *stack);
void operate(Stack *stack, int a, int b, char o);

char *getEqn();
void printStack(Stack * stack);
int	 isEmpty(Stack* top);

int main(int argc, char *argv[])
{
	getEqn();
	printf("Compiled Successfully\n");


	getchar();
	return 0;
}

Stack *initStack()
{
	Stack *newStack = (Stack *)malloc(sizeof(Stack));
	newStack->size = 0;
	newStack->top = NULL;
	return newStack;
}

void Push(Stack *stack, int value)
{
	if (stack != NULL)
	{
		Node *node = (Node *)malloc(sizeof(Stack));
		node->value = value;
		node->next = stack->top;
		stack->top = node;
		stack->size++;
	}
}

int Pop(Stack *stack)
{
	if (stack != NULL)
	{
		if (stack->size > 0)
		{
			Node *delNode;
			delNode = stack->top;
			int value = delNode->value;
			stack->top = stack->top->next;
			free(delNode);
			stack->size--;
			return value;
		}
	}
	return NULL;
}

int *Tos(Stack *stack)
{
	return stack->top->value;
}

void Sub(Stack *stack)
{
	int right = Pop(stack);
	int left = Pop(stack);
	Push(stack, (left - right));
}

void Div(Stack *stack)
{
	int divisor = Pop(stack);
	int dividend = Pop(stack);
	Push(stack, (dividend / divisor));
}

void Mod(Stack *stack)
{
	int divisor = Pop(stack);
	int dividend = Pop(stack);
	Push(stack, (dividend % divisor));
}

void PushValue(Stack *stack)
{
	printf("Push Value into the Stack, press -999 to quit\n");
	do
	{
		int v;
		scanf("%d", &v);
		if (v == -999) break;
		Push(stack, v);
	} while (1);
}

void PopValue(Stack *stack)
{
	printf("\nPop Value into the Stack, press q to quit");
	while (getchar() != '\n');
	do
	{
		char flag = getchar();
		if (flag == 'q' || stack->size == 0) break;
		int v, i = stack->size;
		v = Pop(stack);
		printf("|| Poped Value: %d ||", i--, v);
	} while (1);
}

void manage(Stack *stack)
{
	while (1)
	{
		printf("Please Enter the Command Code");
		enum Flag
		{
			PushValue,
			PopValue,
			SortStack,
			DecayStack
		}flag;
		switch (flag)
		{
		case PushValue: continue;
		case PopValue: continue;
		default:

			break;
		}
	}
}

char *getEqn()
{
	char eqn[50];
	scanf("%s", eqn);
	printf("Input:%s\n", eqn);
	if (isInfix(eqn) == 1) {
		printf("Infix, Start Converting\n");
		//char *postfix = itop(eqn);
		//printf("Convertion Complete\n%s", postfix);
		return eqn;
	}
	else if (isInfix(eqn) == -1)
		printf("Not an equation\n");
	else
		printf("Postfix\n");
	return eqn;
}

int itop(char *equation)
{
	Stack *operatorStack = initStack();
	char *buffer;
	for (int i = 0; equation[i]; i++)
	{
		if (isNumber(equation[i]))
			fprintf(buffer, "%s", equation[i]);
		else if (isOperator(equation[i]))
		{
			if (priority(equation[i], equation[i + 1]))
				Push(operatorStack, equation[i]);
		}
	}
	return equation;
}

void rpnCalculate(Stack *stack)
{
	enum Operators { Add, Subtract, Multiply, Divide, Modulus };
	enum Operators op;
	enum TokenValues { EndOfLine, Value, Operator, Error };
	enum TokenValues tval;

	while (1) {
		
		switch (tval) {
		case Error:

		}
	}
}

int calculate(char *postfix)
{
	Stack *calculator = initStack();
	for (int i = 0; toNumber(postfix[i]); i++)
	{
		if (isNumber(postfix[i]))
			Push(calculator, toNumber(postfix[i]));
		if (isOperator(postfix[i]))
		{
			operate(calculator, Pop(calculator), Pop(calculator), postfix[i]);
		}
	}
}

void operate(Stack *stack, int a, int b, char o)
{
	switch (o)
	{
	case '+': Push(stack, a + b);
	case '-': Push(stack, a - b);
	case '*': Push(stack, a*b);
	case '/': Push(stack, a / b);
	case '^': Push(stack, pow(a, b));
	default:
		printf("Error! Can not compute\n");
	}
}

int toNumber(char ch)
{
	if (isNumber(ch))
	{
		int i = ch - '\0';
		return i;
	}
}

int priority(char a, char b)
{
	return (getPriority(a) <= getPriority(b));
}

int getPriority(char o)
{
	if (o)
	{
		switch (o)
		{
		case '(':
		case ')': return 0;
		case '+':
		case '-': return 1;
		case '*':
		case '/':
		case '%': return 2;
		case '^': return 3;
		}
	}
	return -1;
}

void printStack(Stack * stack)
{
	if (stack != NULL)
	{
		if (stack->size > 0)
		{
			printf("\nPrint Linked Stack\n");
			int level = stack->size;
			Node *node = stack->top;
			for (int i = stack->size; node != NULL; i--)
			{
				printf("|| \tLevel: %d\t Value: %d\t ||\n", i, node->value);
				node = node->next;
			}
		}
		else printf("|| \tEMPTY\t  ||\n");
	}
}

int isInfix(char *equation)
{
	if (strlen(equation) >= 3) {
		if ((isNumber(equation[0]) || (equation[0] == '(')) && ((isNumber(equation[strlen(equation) - 1])) || (equation[strlen(equation) - 1] == ')')))
		{
			for (int i = 0; equation[i]; i++) {
				if (!isOperator(equation[i]) && !isNumber(equation[i]))
					return -1;
			}
			return 1;

		}
		else if (isOperator(equation[strlen(equation) - 1]))
		{

			return 0;
		}
	}
	return -1;
}

int isNumber(char ch)
{
	if ((ch >= 48) && (ch <= 57))
		return 1;
	else
		return 0;
}

int isOperator(char o)
{
	switch (o)
	{
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '^': return 1;
	default:  return 0;
	}
}

int isEmpty(Stack* stack)
{
	return (stack->top == 0);
}
#endif // RPNMAIN

