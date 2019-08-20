// STACK.H [161002]

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


