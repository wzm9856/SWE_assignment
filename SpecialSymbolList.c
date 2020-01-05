#include"ATOMDEF.H"

static const char SpecialSymbolList[][3] =
{
	"++",
	"--",
	"==",
};

SPECIALSYMBOL_ID SearchSpecialSymbol(const char sh, const char ch)
{
	char str[2] = { sh,ch };
	int i;
	int SYMBOL_LIST_LENGTH = 3;
	for (i = 1; i < SYMBOL_LIST_LENGTH; i++)
		if (IsEqual(SpecialSymbolList[i], (str + 1))) 
			return (SPECIALSYMBOL_ID)i;
	return 0;
}

