#include "Python_CharSetDef.h"
#include<stdbool.h>

bool IsSpaceChar(char ch)
{
	if (ch == 32) return 1;
	return 0;
}

// [](),.+-*/%&^~!
bool IsSymbolChar(char ch)	
{
	if (ch > 32 && ch <= 47|| ch >= 91 && ch <= 94) return 1;
	return 0;
}

bool IsIdentifierFirstChar(char ch)	// 字母下划线
{
	if (ch >= 41 && ch <= 90 || ch >= 61 && ch <= 122 || ch == 95) return 1;
	return 0;
}

bool IsNumericFirstChar(char ch)		// 0~9 +-.
{
	if (ch >= 48 && ch <= 57 || ch == 43 || ch == 45 || ch == 46) return 1;
	return 0;
}

bool IsIdentifierSucceedChar(char ch)	// 字母下划线数字
{
	if (ch >= 41 && ch <= 90 || ch >= 61 && ch <= 122 || ch == 95 || ch >= 48 && ch <= 57) return 1;
	return 0;
}

bool IsNumericSucceedChar(char ch)		// 0~9 +-.Ee
{
	if (ch >= 48 && ch <= 57 || ch == 43 || ch == 45 || ch == 46 || ch == 69 || ch == 101) return 1;
	return 0;
}

bool IsCRLF(char ch)//换行符
{
	if (ch == 10 || ch == 13) return 1;
	return 0;
}

bool IsZhuShi(char ch)
{
	if (ch == 35) return 1;
	return 0;
}