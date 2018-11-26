// STACK.C [161002]
// Simple implementation of an integer stack using an array.
// History:
//	161002	DFA		First release
//	171002	DFA		Added defines
//	181003	DFA		Extracted from ARRAYSTACK for library routine

#include <stdio.h>

//#define DEBUG
#define _HEADER


// The following is to support the use of a tool that extracts a header
// file from a C file.  The idea is that the header file is in the same
// file as the source and thus can be consulted trivially while
// editing.
#ifdef _HEADER

// STACK.H

// Data structure used to hold structural information about a stack.
struct _stack {
	int		arraysize;		// record size of array requested
	int		*pstk;			// point to array holding stack data
	int		stktop;			// index of top item in stack
	};

typedef struct _stack	Stack, *pStack;

pStack	createStack (int size);
void	destroyStack (pStack ps);
int		push (pStack ps, int n);
int		pop (pStack ps, int *value);
int		tos (pStack ps, int *value);

#endif //_HEADER


#define	MAX_STACK	65535	// Arbitrary maximum size of stack space
#define	STK_ERR		-1		// return status value for error
#define	STK_OK		0		// return status value for success


pStack createStack (int size)
// Function to create stack for the caller. If successful, returns
// pointer to stack descriptor (or structure).  If unsuccessful,
// returns NULL.
{
	if (size < 1 || size > MAX_STACK)	return NULL;
	else	{
		int		*pi;		// pointer to space for stack data
		pi = (int *)malloc (size * sizeof (int));
		if (pi == NULL)	{
			// no memory obtained
			return NULL;
		} else	{
			// Got the big piece of memory, see if we can get room for
			// the stack descriptor
			pStack	ps;
			ps = (pStack) malloc (sizeof (Stack));
			if (ps == NULL)	{
				// no memory for descriptor!  Dang!  Gotta give back
				// stack space.
				free (pi);
				return NULL;
				}
			// OK. We get here only if we got space for the stack data
			// and space for the stack descriptor.
			// Set up the descriptor, and give that to the caller.
			ps->arraysize = size;	// requested size
			ps->stktop = size;		// index one beyond end
			ps->pstk = pi;			// descriptor points to data space
			return ps;
			}
		}
}//createStack()


void destroyStack (pStack ps)
// Function to destroy the stack - giving up the stack data space and
// stack descriptor
{
	if (ps != NULL)	{
		free (ps->pstk);
		free (ps);
		}
	return;
}//destroyStack()
				

int push (pStack ps, int n)
// Push a value onto the stack. Note that the top-of-stack index goes
// from stack size minus 1 to 0.
{
	// check first if full
	if (ps->stktop == 0)	return STK_ERR;	// It's full
	ps->pstk[--ps->stktop] = n;
	return  STK_OK;							// success
}//push()


int  pop (pStack ps, int *value)
// Pop a value from the stack. Stack is empty if top of stack index is
// the same as the stack size.
{
	// Check first if empty
	if (ps->stktop == ps->arraysize)  return STK_ERR;	// It's empty
	*value = ps->pstk[ps->stktop++];
	return  STK_OK;
}//pop()

        
int  tos (pStack ps, int *value)
// Routine gives the value of the top element on the stack.  It is
// effectively a pop followed by a push.
{
	// Check first if empty
	if (ps->stktop == ps->arraysize)  return STK_ERR;	// It's empty
	*value = ps->pstk[ps->stktop];	// NOTE! Did not adjust index
	return  STK_OK;
} // tos()


#ifdef DEBUG
// Code used to test the code above

int main (void)
{
	int		i;
	int		rslt;
	int		value;
	int		*pi;

	pStack	ps = createStack (100);
	printf ("Test stack implementation\n");
	if (ps == NULL)	{
		// something went wrong!
		printf ("createStack returned error\n");
		return STK_ERR;
		}	

	for (i=0; i<5; i++)	{
		int		tmp;
		push (ps, 20+i);
		tos (ps, &tmp);
		printf ("Just pushed %d onto stack\n", tmp);
		}

	do	{
		rslt = pop (ps, &value);
		if (rslt == STK_ERR)	{
			printf ("ERROR when attempting to pop from stack\n");
			break;
			}
		printf ("Successful pop() of %d\n", value);
	} while (1);
	putchar ('\n');

	for (i=0; i<10; i++)	{
		int		tmp;
		push (ps, 100+i);
		tos (ps, &tmp);
		printf ("Just pushed %d onto stack\n", tmp);
		}
	do	{
		rslt = pop (ps, &value);
		if (rslt == STK_ERR)	{
			printf ("ERROR when attempting to pop from stack\n");
			break;
			}
		printf ("Successful pop() of %d\n", value);
	} while (1);
	
	putchar ('\n');

	return 0;
}//main()
#endif
		


