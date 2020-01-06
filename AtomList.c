#include"ATOMDEF.H"
#include <stdio.h>
#include <stdlib.h>

#define  GSTR_MAXSIZE		1023

//数据域 List：以 ATOM 为元素的通用 LIST （GLIST）

PATOMLIST AtomListInit()//单链表初始化 
{
	PATOMLIST L;
	L = (PATOMLIST)malloc(sizeof(struct PAtomList));
	if (L == NULL)
	{
		printf("申请内存空间失败\n");
		return NULL;
	}
	L->next = NULL;
	return L;
}

void AppendKeyword(PATOMLIST List, KEYWORD_ID KeywordId)
{
	ATOM_KEYWORD AtomKeyword;
	AtomKeyword.keyword_id = KeywordId;

	ATOM Atom;
	Atom.atom_type     = _ATOM_KEYWORD;//它的枚举类型是关键字
	Atom.atom_keyword  = AtomKeyword;

	ListAppend(List, Atom);
}

void AppendSymbol(PATOMLIST List, SYMBOL_ID SymbolId)
{
	ATOM_SYMBOL AtomSymbol;
	AtomSymbol.symbol_id = SymbolId;

	ATOM Atom;
	Atom.atom_type = _ATOM_SYMBOL;//它的枚举类型是关键字
	Atom.atom_symbol = AtomSymbol;

	ListAppend(List, Atom);
}

void AppendIdentifier(PATOMLIST List, IDENTIFIER_ID IdId, BOOL IsNew)
{
	ATOM_IDENTIFIER AtomIdentifier;
	AtomIdentifier.identifier_id = IdId;
	AtomIdentifier.is_new = IsNew;

	ATOM Atom;
	Atom.atom_type = _ATOM_IDENTIFIER;//它的枚举类型是关键字
	Atom.atom_identifier = AtomIdentifier;

	ListAppend(List, Atom);
}

void AppendSpace(PATOMLIST List, int n)
{
	ATOM_INDENT AtomIndent;
	AtomIndent.space_n = n;

	ATOM Atom;
	Atom.atom_type = _ATOM_INDENT;//它的枚举类型是关键字
	Atom.atom_indent = AtomIndent;

	ListAppend(List, Atom);
}

void AppendCRLF(PATOMLIST List)
{
	ATOM_NEWLINE AtomNeline;
	AtomNeline.newline_n = 0;

	ATOM Atom;
	Atom.atom_type = _ATOM_NEWLINE;//它的枚举类型是关键字
	Atom.atom_newline = AtomNeline;

	ListAppend(List, Atom);
}

void AppendNumber(PATOMLIST List, NUMERIC_TYPE NumericType, char* number)
{
	ATOM_NUMERIC AtomNumeric;
	AtomNumeric.numeric_type = NumericType;
	if (NumericType == NUMERIC_int) AtomNumeric.int_value = atoi(number);
	else if (NumericType == NUMERIC_double) AtomNumeric.double_value = atof(number);
	else if (NumericType == NUMERIC_signed_long) AtomNumeric.signed_long_value = atol(number);

	ATOM Atom;
	Atom.atom_type = _ATOM_NUMERIC;
	Atom.atom_numeric = AtomNumeric;
}

void ListAppend(PATOMLIST List, ATOM Atom)
{
	PATOMLIST pThis = List;
	while (pThis->next)
		pThis = pThis->next;
	PATOMLIST pNew = (PATOMLIST)malloc(sizeof(struct PAtomList));
	pThis->next = pNew;
	pNew->atom = Atom;
	pNew->next = NULL;
}

