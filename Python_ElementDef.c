#include "Python_ElementDef.H"


////////////////关键字相关函数//////////////////
static const char KeywordList[][8] =
{
	"NULL",
	"def",
	"for",
	"in",
	"return",
	"while",
	"if",
	"else",
	"range",
	"print"
};

KEYWORD_ID SearchKeyword(PGSTRC pKeywordStr)
{
	int i = 0;
	int KEYWORD_LIST_LENGTH = 10;
	for (i = 0; i < KEYWORD_LIST_LENGTH; i++)
		if (IsEqual(KeywordList[i], pKeywordStr))
			return (KEYWORD_ID)i;
	return 0;
}

//////////////////////////符号相关函数////////////////////////////

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
	"++",
	"--",
	"==",
};

SYMBOL_ID SearchSymbol(char ch, char nextch)
{
	int i;
	char combine[] = { ch, nextch, 0 };
	for (i = 16; i < 19; i++)
		if (IsEqual(SymbolList[i], combine))
			return (SYMBOL_ID)i;
	for (i = 0; i < 16; i++)
		if (*SymbolList[i] == ch)
			return (SYMBOL_ID)i;
	return 0;
}

////////////////////////标识符相关函数////////////////////////////

typedef struct IdentifierStrList
{
	char data[63];
	struct IdentifierStrList* next;
};

IdList IdentifierStrList_Init()
{
	IdList L;
	L = (IdList)malloc(sizeof(struct IdentifierStrList));
	if (L == NULL)
	{
		printf("申请内存空间失败\n");
		return NULL;
	}
	L->next = NULL;
	return L;
}

IDENTIFIER_ID SearchIdentifierStr(IdList List, const char* sub)
{
	IdList pThis = List->next;
	int Idid = 0;
	while (pThis)
	{
		Idid++;		//当前检查的是第Idid个标识符，如果匹配则直接返回Idid
		if (IsEqual(pThis->data, sub))
			return Idid;
		else pThis = pThis->next;
	}
	return 0;
}

IDENTIFIER_ID IdentifierStrListAppend(IdList List, PGSTRC sub)
{
	IdList pThis = List;
	IDENTIFIER_ID Idid = 0;
	while (pThis->next)
	{
		pThis = pThis->next;
		Idid++;		//Idid代表pThis当前指向的结点序号
	}				//退出while时pThis指向最后一节点
	IdList pNew = (IdList)malloc(sizeof(struct IdentifierStrList));
	pThis->next = pNew;
	pNew->next = NULL;
	StrCpy(pNew->data, sub);
	return Idid + 1;
}

//////////////////////用于返回字符串的函数////////////////////////

void ReturnSymbol(SYMBOL_ID id, char* str)
{
	sprintf(str, "\"%s\"", SymbolList[id]);
}

void ReturnKeyword(KEYWORD_ID id, char* str)
{
	sprintf(str, "\"%s\"", KeywordList[id]);
}

void ReturnIdentifier(IdList List, IDENTIFIER_ID id, char* str)
{
	IdList pThis = List;
	for (; id != 0; id--)
		pThis = pThis->next;
	sprintf(str, "\"%s\"", pThis->data);
}

