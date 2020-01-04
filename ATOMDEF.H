// ATOMDEF.H
// Atom definition
// Copyleft XingWeiwei, 2018-2019

#if !defined(__ATOMDEF_H_INCLUDED)
#define __ATOMDEF_H_INCLUDED

// "Python ���﷨��������������" ����
#include "Python_CharSetDef.H"		// Python �ַ�������
#include "Python_ElementDef.H"		// Python �﷨Ԫ�ض���

//#if __ID_USE_MACRO
//typedef int ATOMTYPE;
//#define _ATOM_NULL			0
//#define _ATOM_KEYWORD		1
//#define _ATOM_SYMBOL		2
//#define _ATOM_IDENTIFIER	3
//#define _ATOM_NUMERIC		4
//#define _ATOM_CHARC			5
//#define _ATOM_STRINGC		6
//#define _ATOM_INDENT		7
//#define _ATOM_NEWLINE		8
//#else


typedef enum {//���ڶ���ATOM���͵�ö�����ͣ�����NULL, KEYWORD, SYMBOL, IDENTIFIER, NUMERIC, CHARC, STRINGC, INDENT, NEWLINE
	_ATOM_NULL,			// ��
	_ATOM_KEYWORD,		// �ؼ���
	_ATOM_SYMBOL,		// ����
	_ATOM_IDENTIFIER,	// ��ʶ��
	_ATOM_NUMERIC,		// ��ֵ
	_ATOM_CHARC,		// �ַ�����
	_ATOM_STRINGC,		// �ַ�������
	_ATOM_INDENT,		// ����
	_ATOM_NEWLINE
} ATOM_TYPE;//������ ����������ö�ٱ��� Ӧ����ÿ�ζ���һ����������������Щ����
//#endif

#define BOOL char

struct PAtomList;
typedef  struct PAtomList* PATOMLIST;
struct IdentifierStrList;
typedef struct IdentifierStrList* IdList;

typedef struct {	//����KEYWORD_ID
	KEYWORD_ID			keyword_id;
} ATOM_KEYWORD;

typedef struct {	//����SIMBOL_ID
	SYMBOL_ID			symbol_id;
} ATOM_SYMBOL;

typedef struct {	//����IDENTIFIER_ID���Ƿ�Ϊ�±�ʶ����BOOL
	IDENTIFIER_ID		identifier_id;
	BOOL				is_new;
} ATOM_IDENTIFIER;

typedef struct {	//�����ո������int
	int		space_n;
} ATOM_INDENT;

typedef struct {	//�������и���
	int		newline_n;
}ATOM_NEWLINE;

typedef struct {	//����NUMERIC_TYPE����ʾֵ�Ľṹ�壬��ʾֵ��NUMERIC_VAL
	NUMERIC_TYPE		numeric_type;
	union {
		int				int_value;
		//float			float_value;
		double			double_value;
		signed long		signed_long_value;
		//unsigned long	unsigned_long_value;
	};
	// NUMERIC_VAL			numeric_value;
} ATOM_NUMERIC;

typedef struct {	//char_value
	char				char_value;
} ATOM_CHARC;

typedef struct {	//string_value
	PGSTRC				string_value;
} ATOM_STRINGC;

typedef struct {	//�����˻���Ԫ��ATOM�Ľṹ������ATOM_TYPEö�����ͺͱ�ʾATOM���ݵ�union
	ATOM_TYPE			atom_type;//���Ƕ�����һ��enumö���� ����������������������

	union {//unionֻ�ܱ��������һ������
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


typedef struct {	//str:char[]
	char			str[KEYWORD_MAXLEN];
} KEYWORD_STR;

typedef struct {	//str:char[]
	char			str[SYMBOL_MAXLEN];
} SYMBOL_STR;

typedef struct {	//str:char[]
	char			str[IDENTIFIER_MAXLEN];
} IDENTIFIER_STR;

//��ʼ��һ��ATOM
PATOMLIST AtomListInit();
void AppendKeyword(PATOMLIST List, KEYWORD_ID KeywordId);
void AppendSymbol(PATOMLIST List, SYMBOL_ID SymbolId);
void AppendNewIdentifier(PATOMLIST List, IDENTIFIER_ID IdId);
void AppendOldIdentifier(PATOMLIST List, IDENTIFIER_ID IdId);
void AppendSpace(PATOMLIST List, int n);
void AppendCRLF(PATOMLIST List);
void ListAppend(PATOMLIST List, ATOM Atom);

#endif