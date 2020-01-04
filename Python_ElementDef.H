#if !defined(__Python_ElementDef_H_INCLUDED)
#define __Python_ElementDef_H_INCLUDED


#define KEYWORD_MAXLEN		65535
#define SYMBOL_MAXLEN		65535
#define IDENTIFIER_MAXLEN	65535


typedef int IDENTIFIER_ID;

typedef char* PGSTRC;

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

typedef enum 
{ 
	SYMBOL_NULL,
	SYMBOL_KUOHAOL,
	SYMBOL_KUOHAOR,
	SYMBOL_FKHL,
	SYMBOL_FKHR,
	SYMBOL_DKHL,
	SYMBOL_DKHR,
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

typedef enum
{
	SPECIALSYMBOL_NULL,
	SPECIALSYMBOL_ADDADD,
	SPECIALSYMBOL_SUBSUB,
	SPECIALSYMBOL_SDENGHAO,
}SPECIALSYMBOL_ID;


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

extern SYMBOL_ID SearchSymbol(const char* str);
extern SPECIALSYMBOL_ID SearchSpecialSymbol(const char sh, const char ch);
extern KEYWORD_ID SearchKeyword(PGSTRC pKeywordStr);
extern NUMERIC_TYPE SearchNumeric(PGSTRC pNumeric);
extern IDENTIFIER_ID SearchIdentifierStr(const char* sub);
extern IDENTIFIER_ID IdentifierStrListAppend(IdList List, PGSTRC sub);

#endif