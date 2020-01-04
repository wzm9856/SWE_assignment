#if !defined(__Python_CharSetDef_H_INCLUDED)
#define __Python_CharSetDef_H_INCLUDED

#include<stdbool.h>
#define BOOL bool


BOOL IsSpaceChar(char ch);
BOOL IsSymbolChar(char ch);			// [](),.+-*/%&^~!
BOOL IsIdentifierFirstChar(char ch);	// ��ĸ�»���
BOOL IsNumericFirstChar(char ch);		// 0~9 +-.
BOOL IsCRLF(char ch);//���з�
BOOL IsZhuShi(char ch);

BOOL IsIdentifierSucceedChar(char ch);	// ��ĸ�»�������
BOOL IsNumericSucceedChar(char ch);		// 0~9 +-.Ee


#endif