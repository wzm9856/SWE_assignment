//Python_CharSetDef.H
//Python字符集定义

#if !defined(__Python_CharSetDef_H_INCLUDED)
#define __Python_CharSetDef_H_INCLUDED

#include <stdbool.h>
#define BOOL bool

//检查字符是否为空格
BOOL IsSpaceChar(char ch);

//检查字符是否为[](),.+-*/%&^~!
BOOL IsSymbolChar(char ch);

//检查是否为标识符首字符（字母下划线）
BOOL IsIdentifierFirstChar(char ch);

//检查是否为标识符后续字符（字母下划线和数字）
BOOL IsIdentifierSucceedChar(char ch);

//检查是否为数字字符（0-9 .）
BOOL IsNumericChar(char ch);

//检查是否为换行符（CR/LF)
BOOL IsCRLF(char ch);

//检查是否为注释字符（#）
BOOL IsAnnotation(char ch);

//检查字符串里有没有指定字符
BOOL IsCharExist(const char str[], char ch);

//判断两字符串是否相等
BOOL IsEqual(const char s1[], const char s2[]);

//将src字符串内容复制到dest字符串中
void StrCpy(char dest[], char src[]);

#endif