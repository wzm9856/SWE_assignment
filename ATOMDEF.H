// ATOMDEF.H
// Atom definition

#if !defined(__ATOMDEF_H_INCLUDED)
#define __ATOMDEF_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Python_ElementDef.H"		// Python 语法元素定义
#include "Python_CharSetDef.H"		// Python 字符集定义


typedef enum {//用于定义ATOM类型的枚举类型，包括NULL, KEYWORD, SYMBOL, IDENTIFIER, NUMERIC, CHARC, STRINGC, INDENT, NEWLINE
	_ATOM_NULL,			// 空
	_ATOM_KEYWORD,		// 关键字
	_ATOM_SYMBOL,		// 符号
	_ATOM_IDENTIFIER,	// 标识符
	_ATOM_NUMERIC,		// 数值
	_ATOM_CHARC,		// 字符常量
	_ATOM_STRINGC,		// 字符串常量
	_ATOM_INDENT,		// 缩进
	_ATOM_NEWLINE
} ATOM_TYPE;

typedef struct {	//包含KEYWORD_ID
	KEYWORD_ID			keyword_id;
} ATOM_KEYWORD;

typedef struct {	//包含SIMBOL_ID
	SYMBOL_ID			symbol_id;
} ATOM_SYMBOL;

typedef struct {	//包含IDENTIFIER_ID和是否为新标识符的BOOL
	IDENTIFIER_ID		identifier_id;
	BOOL				is_new;
} ATOM_IDENTIFIER;

typedef struct {	//包含空格个数的int
	int		space_n;
} ATOM_INDENT;

typedef struct {	//包含新行个数的int
	int		newline_n;
} ATOM_NEWLINE;

typedef struct {	//包含NUMERIC_TYPE，表示值的结构体，表示值的NUMERIC_VAL
	NUMERIC_TYPE		numeric_type;
	union {
		int				int_value;
		double			double_value;
		signed long		signed_long_value;
	};
} ATOM_NUMERIC;

typedef struct {	//char_value
	char				char_value;
} ATOM_CHARC;

typedef struct {	//string_value
	PGSTRC				string_value;
} ATOM_STRINGC;

typedef struct {	//定义了基本元素ATOM的结构，包含ATOM_TYPE枚举类型和表示ATOM内容的union
	ATOM_TYPE			atom_type;//这是定义了一个enum枚举型 里面包含了上面的所有类型

	union {//union只能保存里面的一个数据
		ATOM_KEYWORD	atom_keyword;
		ATOM_IDENTIFIER	atom_identifier;
		ATOM_SYMBOL		atom_symbol;
		ATOM_NUMERIC	atom_numeric;
		ATOM_CHARC		atom_charc;
		ATOM_STRINGC	atom_stringc;
		ATOM_INDENT		atom_indent;
		ATOM_NEWLINE	atom_newline;
	};
} ATOM;

typedef struct PAtomList
{
	ATOM atom;
	struct PAtomList* next;
}*PATOMLIST;


PATOMLIST AtomListInit();
void AppendKeyword(PATOMLIST List, KEYWORD_ID KeywordId);
void AppendSymbol(PATOMLIST List, SYMBOL_ID SymbolId);
void AppendNumber(PATOMLIST List, NUMERIC_TYPE NumericType, char* number);
void AppendIdentifier(PATOMLIST List, IDENTIFIER_ID IdId, BOOL IsNew);
void AppendSpace(PATOMLIST List, int n);
void AppendCRLF(PATOMLIST List);
void ListAppend(PATOMLIST List, ATOM Atom);
void PSS2Atom(PGSTRC str, PATOMLIST List, IdList IdList);
void VisualizeAtom(PATOMLIST AtomList, IdList IdentifierList, FILE* fp);

#endif
