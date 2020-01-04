#include"ATOMDEF.H"
#include <stdio.h>
#include <stdlib.h>

#define  GSTR_MAXSIZE		65535

typedef struct PAtomList
{
	ATOM atom;
	struct PAtomList* next;
};

//数据域 List：以 ATOM 为元素的通用 LIST （GLIST）

PATOMLIST AtomListInit()//单链表初始化 
{
	PATOMLIST L;
	L = (PATOMLIST)malloc(sizeof(struct PAtomList));
	if (L == NULL)
		printf("申请内存空间失败\n");
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


void AppendNewIdentifier(PATOMLIST List, IDENTIFIER_ID IdId)
{
	ATOM_IDENTIFIER AtomIdentifier;
	AtomIdentifier.identifier_id = IdId;
	AtomIdentifier.is_new = 1;

	ATOM Atom;
	Atom.atom_type = _ATOM_IDENTIFIER;//它的枚举类型是关键字
	Atom.atom_identifier = AtomIdentifier;

	ListAppend(List, Atom);
}

void AppendOldIdentifier(PATOMLIST List, IDENTIFIER_ID IdId)
{
	ATOM_IDENTIFIER AtomIdentifier;
	AtomIdentifier.identifier_id = IdId;
	AtomIdentifier.is_new = 0;

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

void ListAppend(PATOMLIST List, ATOM Atom)
{
	PATOMLIST pThis = List->next;
	while (pThis)
		pThis = pThis->next;
	PATOMLIST pThat = (PATOMLIST)malloc(sizeof(struct PAtomList));
	pThis->next = pThat;
	pThat->atom = Atom;
	pThat->next = NULL;
}


//AppendIdentifier(IdId, IsNew)
//{
//	ATOM_IDENTIFIER AtomIdentifier;
//	AtomIdentifier.identifier_id = IdId;
//	AtomIdentifier.is_new = 1;
//
//	ATOM Atom;
//	Atom.atom_type = _ATOM_IDENTIFIER;//它的枚举类型是关键字
//	Atom.atom_identifier = AtomIdentifier;
//
//	ListAppend(Atom);
//}
