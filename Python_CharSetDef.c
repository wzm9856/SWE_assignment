#include "Python_CharSetDef.H"

//本页函数用于将指定字符分类

bool IsSpaceChar(char ch)
{
	if (ch == 32) return 1;
	else return 0;
}


bool IsSymbolChar(char ch)	
{
	// [](),.+-*/%&^~!
	if (ch >= 33 && ch <= 47|| ch >= 91 && ch <= 94) return 1;
	else return 0;
}

bool IsIdentifierFirstChar(char ch)		// 字母下划线
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_') return 1;
	else return 0;
}

bool IsIdentifierSucceedChar(char ch)	// 字母下划线数字
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_' || (ch >= '0' && ch <= '9')) return 1;
	return 0;
}

bool IsNumericFirstChar(char ch)		// 0~9 +-.
{
	if ((ch >= '0' && ch <= '9') || ch == '+' || ch == '-' || ch == '.') return 1;
	return 0;
}

bool IsNumericSucceedChar(char ch)		// 0~9 .Ee
{
	if ((ch >= '0' && ch <= '9') || ch == '.' || ch == 'e' || ch == 'E') return 1;
	return 0;
}

bool IsCRLF(char ch)//换行符
{
	if (ch == 10 || ch == 13) return 1;
	return 0;
}

bool IsAnnotation(char ch)
{
	if (ch == '#') return 1;
	return 0;
}

bool IsCharExist(const char str[], char ch) {
	int i = 0;
	while (str[i] != 0 && str[i] != ch)i++;
	return str[i] == ch ? str + i : 0;
}

bool IsEqual(const char s1[], const char s2[]) {
	int i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i]) i++;
	return s1[i] == s2[i] ? 1 : 0;
}

void StrCpy(char dest[], char src[]) {
	while (*src != 0)
	{
		*dest = *src;
		dest++; src++;
	}
	*dest = 0;
}
