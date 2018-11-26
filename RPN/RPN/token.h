// TOKEN.C [181003]

// Define symbols for return value and result
enum TokenValues {EndOfLine, Value, Operator, Error};
enum Operators	{Add, Subtract, Multiply, Divide, Modulus};

// Return value will depend on what kind of token found
union Token	{
		int				intvalue;
		enum Operators	op;
		};
