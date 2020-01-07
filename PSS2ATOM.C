#include "ATOMDEF.H"


void PSS2Atom(PGSTRC str, PATOMLIST List,IdList IdList)
{
	int indentLength = 0;
	while (*str == ' ')
	{
		indentLength++;
		str++;
	}
	if (indentLength != 0) 
		AppendSpace(List, indentLength);			//计算每行开头的空格个数，除开头空格作为ATOM存入列表外
															//其余空格不计入ATOM，仅作为分割其他ATOM的标志
	char temp[20] = { 0 }; 
	for (; *str != 0; str++)
	{
		char* ptemp = temp;
		char ch = *str;
		if (IsSpaceChar(ch))						//判断空格：除开头空格外其余空格均不作为ATOM存储，直接进入下一次for循环
		{
			str++;
			continue;	
		}
		else if (IsCRLF(ch) || IsAnnotation(ch))	//判断换行或注释：换行或注释说明已经读到字符串结尾，应返回main函数读取下一行
		{
			AppendCRLF(List);
			break;
		}
		else if (IsNumericFirstChar(ch) && (IsNumericSucceedChar(*(str+1)) || (ch!='+' && ch != '-')))
		{//判断数字：需要首字符为数字类首字符，同时（第二字符为数字类后续字符或首字符不为+/-）（因为可能是仅个位数或++/--）
			while (IsNumericSucceedChar(*str))
			{
				*ptemp = *str;
				ptemp++; str++;		//退出while时str指向非numeric的第一位，退出if时无需再对其进行操作
			}
			*ptemp = 0;				//将连续的数字存入temp数组，并将结尾置0
			if (IsCharExist(temp, '.')) 
				AppendNumber(List, NUMERIC_double, temp);
			else if (atol(temp) > 2147483647) 
				AppendNumber(List, NUMERIC_signed_long, temp);
			else 
				AppendNumber(List, NUMERIC_int, temp);
		}
		else if (IsSymbolChar(ch))					//判断符号
		{
			char NextCh = *(str++);
			SYMBOL_ID SymbolId = SearchSymbol(ch, NextCh);
			AppendSymbol(List, SymbolId);
			if(SymbolId >= 15)
				str++;				//因为将两个字符加入了list，因此str要++两次，下面只向list加入一个字符，无需再++
		}
		else if (IsIdentifierFirstChar(ch))
		{
			while (IsIdentifierSucceedChar(*str))
			{
				*ptemp = *str;
				ptemp++; str++;		//退出while时str指向非numeric的第一位，退出if时无需再对其进行操作
			}
			*ptemp = 0;				//将连续的关键字/标识符存入temp数组，并将结尾置0
			KEYWORD_ID KeywordId = SearchKeyword(temp);	//关键字字符同时也是标识符字符，所以前面identifier这里keyword也没有问题
			if (KeywordId) 
				AppendKeyword(List, KeywordId);
			else
			{						//temp中存的一堆字母如果不是关键字就一定是标识符了
				IDENTIFIER_ID IdId = SearchIdentifierStr(IdList, temp);
				//TODO
				if (IdId)
					AppendIdentifier(List, IdId, 0);
				else
				{
					IdId = IdentifierStrListAppend(IdList, temp);
					AppendIdentifier(List, IdId, 1);
				}
			}
		}
	}

}

