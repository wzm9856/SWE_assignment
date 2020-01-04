#include"ATOMDEF.H"
#include <stdio.h>
#include <stdlib.h>

#define  GSTR_MAXSIZE		65535

typedef struct PAtomList
{
	ATOM atom;
	struct PAtomList* next;
};

//������ List���� ATOM ΪԪ�ص�ͨ�� LIST ��GLIST��

PATOMLIST AtomListInit()//�������ʼ�� 
{
	PATOMLIST L;
	L = (PATOMLIST)malloc(sizeof(struct PAtomList));
	if (L == NULL)
		printf("�����ڴ�ռ�ʧ��\n");
	L->next = NULL;
	return L;
}



void AppendKeyword(PATOMLIST List, KEYWORD_ID KeywordId)
{
	ATOM_KEYWORD AtomKeyword;
	AtomKeyword.keyword_id = KeywordId;

	ATOM Atom;
	Atom.atom_type     = _ATOM_KEYWORD;//����ö�������ǹؼ���
	Atom.atom_keyword  = AtomKeyword;

	ListAppend(List, Atom);
}

void AppendSymbol(PATOMLIST List, SYMBOL_ID SymbolId)
{
	ATOM_SYMBOL AtomSymbol;
	AtomSymbol.symbol_id = SymbolId;

	ATOM Atom;
	Atom.atom_type = _ATOM_SYMBOL;//����ö�������ǹؼ���
	Atom.atom_symbol = AtomSymbol;

	ListAppend(List, Atom);
}


void AppendNewIdentifier(PATOMLIST List, IDENTIFIER_ID IdId)
{
	ATOM_IDENTIFIER AtomIdentifier;
	AtomIdentifier.identifier_id = IdId;
	AtomIdentifier.is_new = 1;

	ATOM Atom;
	Atom.atom_type = _ATOM_IDENTIFIER;//����ö�������ǹؼ���
	Atom.atom_identifier = AtomIdentifier;

	ListAppend(List, Atom);
}

void AppendOldIdentifier(PATOMLIST List, IDENTIFIER_ID IdId)
{
	ATOM_IDENTIFIER AtomIdentifier;
	AtomIdentifier.identifier_id = IdId;
	AtomIdentifier.is_new = 0;

	ATOM Atom;
	Atom.atom_type = _ATOM_IDENTIFIER;//����ö�������ǹؼ���
	Atom.atom_identifier = AtomIdentifier;

	ListAppend(List, Atom);
}


void AppendSpace(PATOMLIST List, int n)
{
	ATOM_INDENT AtomIndent;
	AtomIndent.space_n = n;

	ATOM Atom;
	Atom.atom_type = _ATOM_INDENT;//����ö�������ǹؼ���
	Atom.atom_indent = AtomIndent;

	ListAppend(List, Atom);
}

void AppendCRLF(PATOMLIST List)
{
	ATOM_NEWLINE AtomNeline;
	AtomNeline.newline_n = 0;

	ATOM Atom;
	Atom.atom_type = _ATOM_NEWLINE;//����ö�������ǹؼ���
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
//	Atom.atom_type = _ATOM_IDENTIFIER;//����ö�������ǹؼ���
//	Atom.atom_identifier = AtomIdentifier;
//
//	ListAppend(Atom);
//}
