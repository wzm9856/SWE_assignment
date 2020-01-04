#if !defined(__Python_CharSetDef_H_INCLUDED)
#define __Python_CharSetDef_H_INCLUDED

#include<stdbool.h>
#define BOOL bool


BOOL IsSpaceChar(char ch);
BOOL IsSymbolChar(char ch);			// [](),.+-*/%&^~!
BOOL IsIdentifierFirstChar(char ch);	// 字母下划线
BOOL IsNumericFirstChar(char ch);		// 0~9 +-.
BOOL IsCRLF(char ch);//换行符
BOOL IsZhuShi(char ch);

BOOL IsIdentifierSucceedChar(char ch);	// 字母下划线数字
BOOL IsNumericSucceedChar(char ch);		// 0~9 +-.Ee


#endif