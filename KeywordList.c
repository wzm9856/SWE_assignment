// Keyword List 实现方式 2：静态定义
#include"ATOMDEF.H"


static const char KeywordList[][15+1] =
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
		if (IsEqual(KeywordList[i], pKeywordStr)) return (KEYWORD_ID)i;
	return 0;
}

