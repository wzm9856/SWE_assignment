#include"ATOMDEF.H"

static const char SymbolList[][3] =
{
	"(", ")",
	"[", "]",
	"{", "}",
	"<", ">",
	"+", 
	"-", 
	",", 
	";",
	".", 
	":",
	"=", 
	"%", 
};

SYMBOL_ID SearchSymbol(char* str)
{
	int i;
	int SYMBOL_LIST_LENGTH = 16;
	for (i = 1; i < SYMBOL_LIST_LENGTH; i++)
		if (IsEqual(SymbolList[i], str)) 
			return (SYMBOL_ID)i;
	return 0;
}

