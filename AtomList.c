#include "ATOMDEF.H"

#define  GSTR_MAXSIZE		1023

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

	ListAppend(List, Atom);
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

void VisualizeAtom(PATOMLIST AtomList, IdList IdentiferList, FILE* fp)
{
	PATOMLIST pThis = AtomList->next;
	char type[10] = { 0 };
	char content[10] = { 0 };
	while (pThis)
	{
		ATOM atom = pThis->atom;
		switch (atom.atom_type)
		{
		case _ATOM_NULL:
			StrCpy(type, "NULL");
			StrCpy(content, "NULL");
			break;
		case _ATOM_KEYWORD:
			StrCpy(type, "关键字");
			ReturnKeyword(atom.atom_keyword.keyword_id, content);
			break;
		case _ATOM_SYMBOL:
			StrCpy(type, "符号");
			ReturnSymbol(atom.atom_symbol.symbol_id, content);
			break;
		case _ATOM_IDENTIFIER:
			if(atom.atom_identifier.is_new) StrCpy(type, "新标识符");
			else StrCpy(type, "旧标识符");
			ReturnIdentifier(IdentiferList, atom.atom_identifier.identifier_id, content);
			break;
		case _ATOM_NUMERIC:
			StrCpy(type, "数值");
			if (atom.atom_numeric.numeric_type == NUMERIC_int)
				_itoa(atom.atom_numeric.int_value, content, 10);
			else if (atom.atom_numeric.numeric_type == NUMERIC_double)
				sprintf(content, "%f", atom.atom_numeric.double_value);
			break;
		case _ATOM_INDENT:
			StrCpy(type, "缩进");
			_itoa(atom.atom_indent.space_n, content, 10);
			break;
		case _ATOM_NEWLINE:
			StrCpy(type, "换行");
			StrCpy(content, "");
			break;
		default:
			StrCpy(type, "字符或字符串");
			StrCpy(content, "未识别");
			break;
		}
		fprintf(fp, "%s,%s\n", type, content);
		pThis = pThis->next;
	}
}