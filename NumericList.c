// Keyword List 实现方式 2：静态定义
#include"ATOMDEF.H"


static const char NumericList[][20] =
{
	"int",
	"float",
	"double",
	"signed long",
	"unsigned long",
};

extern NUMERIC_TYPE SearchNumeric(PGSTRC pNumeric)
{
	int i = 0;
	int NUMERIC_LIST_LENGTH = 5;
	for (i = 1; i < NUMERIC_LIST_LENGTH; i++)
		if (strcmp(NumericList[i], pNumeric) == 0) return (NUMERIC_TYPE)i;
		else return 0;
}

