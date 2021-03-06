//Python_ElementDef.H
//Python语法元素定义

#if !defined(__Python_ElementDef_H_INCLUDED)
#define __Python_ElementDef_H_INCLUDED
#include"Python_CharSetDef.H"
#include <stdlib.h>
#include <stdio.h>

#define KEYWORD_MAXLEN		127
#define SYMBOL_MAXLEN		127
#define IDENTIFIER_MAXLEN	127

typedef int IDENTIFIER_ID;

typedef char* PGSTRC;
struct IdentifierStrList;
typedef struct IdentifierStrList* IdList;	//是IdentifierStrList结构体的指针

//NULL def for in return while if else range print
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
	KEYWORD_range,
	KEYWORD_print
} KEYWORD_ID;

//NULL[](),.+-*/%&^~! ++ -- ==
typedef enum 
{ 
	SYMBOL_NULL,
	SYMBOL_KUOHAOL,
	SYMBOL_KUOHAOR,
	SYMBOL_FKHL,
	SYMBOL_FKHR,
	SYMBOL_DKHL,
	SYMBOL_DKHY,
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
	SPECIALSYMBOL_ADDADD,
	SPECIALSYMBOL_SUBSUB,
	SPECIALSYMBOL_SDENGHAO,
} SYMBOL_ID;

//NULL int double singedLong
typedef enum 
{ 
	NUMERIC_NULL,
	NUMERIC_int,
	NUMERIC_double,
	NUMERIC_signed_long,
} NUMERIC_TYPE;

//搜索该字符是否为符号(+ - * / ...)
//	输入：
//		ch：要查找的首个字符
//		nextch：要查找的第二个字符
//	输出：
//		SYMBOL_ID：为被查找的符号编号，0则为未找到
SYMBOL_ID SearchSymbol(char ch, char nextch);

//搜索该字符串是否为关键字（NULL def for if ...)
//	输入：
//		pKeywordStr：要搜索的字符串指针
//	输出：
//		KEYWORD_ID：为被查找的关键字编号，0则为未找到
KEYWORD_ID SearchKeyword(PGSTRC pKeywordStr);

//搜索该标识符是否为已经出现的标识符（如变量名）
//	输入：
//		List：IdentifierList的链表头结点
//		sub：要查找的字符串指针
//	输出：
//		IDENTIFIER_ID：为被查找的标识符的编号，0则为未找到
IDENTIFIER_ID SearchIdentifierStr(IdList List, const char* sub);

//向Identifier List加入新的标识符（如新变量名）
//	输入：
//		List：IdentifierList的链表头结点
//		sub：要添加的字符串指针
//	输出：
//		IDENTIFIER_ID：为新标识符的编号
IDENTIFIER_ID IdentifierStrListAppend(IdList List, PGSTRC sub);

//创建新的IdentifierList结点
//	输出：
//		IdList：新的结点
IdList IdentifierStrList_Init();

//返回符号的字符
//	输入：
//		id：符号的编号
//		str：存放返回字符的指针
void ReturnSymbol(SYMBOL_ID id, char* str);

//返回关键字的字符串
//	输入：
//		id：关键字的编号
//		str：存放返回字符串的指针
void ReturnKeyword(KEYWORD_ID id, char* str);

//返回标识符的字符串
//	输入：
//		List：标识符链表头指针
//		id：标识符的编号
//		str：存放返回字符串的指针
void ReturnIdentifier(IdList List, IDENTIFIER_ID id, char* str);

#endif