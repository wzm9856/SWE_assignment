#include"ATOMDEF.H"


////////////////关键字相关函数//////////////////
static const char KeywordList[][15 + 1] =
{
	"NULL",
	"def",
	"for",
	"in",
	"return",
	"while",
	"if",
	"else",
};

KEYWORD_ID SearchKeyword(PGSTRC pKeywordStr)
{
	int i = 0;
	int KEYWORD_LIST_LENGTH = 8;
	for (i = 1; i < KEYWORD_LIST_LENGTH; i++)
		if (IsEqual(KeywordList[i], pKeywordStr))
			return (KEYWORD_ID)i;
	return 0;
}