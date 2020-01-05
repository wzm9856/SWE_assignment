#if !defined(__Python_ElementDef_H_INCLUDED)
#define __Python_ElementDef_H_INCLUDED
#include"Python_CharSetDef.H"

#define KEYWORD_MAXLEN		1023
#define SYMBOL_MAXLEN		1023
#define IDENTIFIER_MAXLEN	1023


typedef int IDENTIFIER_ID;

typedef char* PGSTRC;
struct IdentifierStrList;
typedef struct IdentifierStrList* IdList;	//是IdentifierStrList结构体的指针
//NULL def for in return while if else
typedef enum
{ 
	KEYWORD_NULL,  
	KEYWORD_def, 
	KEYWORD_for,
	KEYWORD_in,
	KEYWORD_return,
	KEYWORD_while,
	KEYWORD_if,
	KEYWORD_else,
} KEYWORD_ID;

//NULL[](),.+-*/%&^~!
typedef enum 
{ 
	SYMBOL_NULL,
	SYMBOL_KUOHAOL,
	SYMBOL_KUOHAOR,
	SYMBOL_FKHL,
	SYMBOL_FKHR,
	//SYMBOL_DKHL,
	//SYMBOL_DKHR,
	SYMBOL_XIAOYU,
	SYMBOL_DAYU,
	SYMBOL_ADD,
	SYMBOL_SUB,
	SYMBOL_DOUHAO,
	SYMBOL_FENHAO,
	SYMBOL_DIAN,
	SYMBOL_MAOHAO,
	SYMBOL_DENGHAO,
	SYMBOL_BAIFENHAO,
} SYMBOL_ID;

//NULL ++ -- ==
typedef enum
{
	SPECIALSYMBOL_NULL,
	SPECIALSYMBOL_ADDADD,
	SPECIALSYMBOL_SUBSUB,
	SPECIALSYMBOL_SDENGHAO,
}SPECIALSYMBOL_ID;

//NULL int double singedLong
typedef enum 
{ 
	NUMERIC_NULL,
	NUMERIC_int,
	//NUMERIC_float,
	NUMERIC_double,
	NUMERIC_signed_long,
	//NUMERIC_unsigned_long,
} NUMERIC_TYPE;

//typedef union
//{
//	signed long		l;
//	double			d;
//} NUMERIC_VAL;

SYMBOL_ID SearchSymbol(const char* str);
SPECIALSYMBOL_ID SearchSpecialSymbol(const char sh, const char ch);
KEYWORD_ID SearchKeyword(PGSTRC pKeywordStr);

//搜索该标识符是否为已经出现的标识符
//	输入：
//		List：IdentifierList的链表头结点
//		sub：要查找的字符串指针
//	输出：
//		IDENTIFIER_ID：为被查找的标识符的编号，0则为未找到
IDENTIFIER_ID SearchIdentifierStr(IdList List, const char* sub);
IDENTIFIER_ID IdentifierStrListAppend(IdList List, PGSTRC sub);
IdList IdentifierStrList_Init();

#endif