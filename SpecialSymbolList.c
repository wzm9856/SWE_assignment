#include"ATOMDEF.H"

static const char SpecialSymbolList[][3] =
{
	"++",
	"--",
	"==",
};

extern SPECIALSYMBOL_ID SearchSpecialSymbol(const char sh, const char ch)
{
	char str[2] = { sh,ch };
	int i;
	int SYMBOL_LIST_LENGTH = 3;
	for (i = 1; i < SYMBOL_LIST_LENGTH; i++)
		if (strcmp(SpecialSymbolList[i], str[2]) == 0) return (SPECIALSYMBOL_ID)i;
	return 0;
}

