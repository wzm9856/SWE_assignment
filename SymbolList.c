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

extern SYMBOL_ID SearchSymbol(const char* str)
{
	int i;
	int SYMBOL_LIST_LENGTH = 16;
	for (i = 1; i < SYMBOL_LIST_LENGTH; i++)
		if (strcmp(SymbolList[i], str) == 0) return (SYMBOL_ID)i;
	return 0;
}

