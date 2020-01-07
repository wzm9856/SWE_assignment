#include "ATOMDEF.H"

#define  GSTR_MAXSIZE		1023

PATOMLIST AtomListInit()//�������ʼ�� 
{
	PATOMLIST L;
	L = (PATOMLIST)malloc(sizeof(struct PAtomList));
	if (L == NULL)
	{
		printf("�����ڴ�ռ�ʧ��\n");
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

void AppendIdentifier(PATOMLIST List, IDENTIFIER_ID IdId, BOOL IsNew)
{
	ATOM_IDENTIFIER AtomIdentifier;
	AtomIdentifier.identifier_id = IdId;
	AtomIdentifier.is_new = IsNew;

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
			StrCpy(type, "�ؼ���");
			ReturnKeyword(atom.atom_keyword.keyword_id, content);
			break;
		case _ATOM_SYMBOL:
			StrCpy(type, "����");
			ReturnSymbol(atom.atom_symbol.symbol_id, content);
			break;
		case _ATOM_IDENTIFIER:
			if(atom.atom_identifier.is_new) StrCpy(type, "�±�ʶ��");
			else StrCpy(type, "�ɱ�ʶ��");
			ReturnIdentifier(IdentiferList, atom.atom_identifier.identifier_id, content);
			break;
		case _ATOM_NUMERIC:
			StrCpy(type, "��ֵ");
			if (atom.atom_numeric.numeric_type == NUMERIC_int)
				_itoa(atom.atom_numeric.int_value, content, 10);
			else if (atom.atom_numeric.numeric_type == NUMERIC_double)
				sprintf(content, "%f", atom.atom_numeric.double_value);
			break;
		case _ATOM_INDENT:
			StrCpy(type, "����");
			_itoa(atom.atom_indent.space_n, content, 10);
			break;
		case _ATOM_NEWLINE:
			StrCpy(type, "����");
			StrCpy(content, "");
			break;
		default:
			StrCpy(type, "�ַ����ַ���");
			StrCpy(content, "δʶ��");
			break;
		}
		fprintf(fp, "%s,%s\n", type, content);
		pThis = pThis->next;
	}
}