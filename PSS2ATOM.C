//#include "GSCAN.H"
#include"ATOMDEF.H"
#include <stdlib.h>
#include <stdio.h>


void PSS2Atom(PGSTRC str, PATOMLIST List,IdList IdList)
{
	int indentLength = 0;
	while (*str = ' ')
	{
		indentLength++;
		str++;
	}
	if (indentLength != 0) AppendSpace(List, indentLength); //计算每行开头的空格个数，除开头空格作为ATOM存入列表外
															//其余空格不计入ATOM，仅作为分割其他ATOM的标志
	char temp[100] = { 0 }; char* ptemp = temp;
	for (; *str == 0; str++) //TODO:判断条件是否应该加上回车符？应该是不用加的因为中间判断的条件已经有IsCRLF了
	{
		char ch = *str;
		if (IsSpaceChar(ch))				//判断空格：除开头空格外其余空格均不作为ATOM存储，直接进入下一次for循环
		{
			str++;
			continue;	
		}
		else if (IsCRLF(ch))				//判断换行：换行说明已经读到字符串结尾，应返回main函数读取下一行
		{
			AppendCRLF(List);
			break;
		}
		else if (IsNumericFirstChar(ch))	//判断数字首字符
		{
			while (IsNumericSucceedChar(*str))
			{
				*ptemp = *str;
				ptemp++; str++;
			}
			*ptemp = 0;		//将连续的数字存入temp数组，并将结尾置0

			//TODO:123
		}
		else if (IsSymbolChar(ch))
		{
			if (IsZhuShi(ch))
				break;
			char NextCh = str[i + 1];
			SPECIALSYMBOL_ID SpecialSymbolId = SearchSpecialSymbol(ch, NextCh);
			if (SpecialSymbolId)	// 两个相邻字符组成了特殊符号
				AppendSymbol(List, SpecialSymbolId);
			else
			{
				SYMBOL_ID SymbolId = SearchSymbol(ch);
				AppendSymbol(List, SymbolId);
			}
			if (IsSpaceChar(ch))continue;
			else if (IsCRLF(ch))break;
		}
		else if (IsIdentifierFirstChar(ch))
		{
			temp[0] = ch;
			int j = 1;
			int n = i + 1;
			while (IsIdentifierSucceedChar(str[n]))
			{
				temp[j++] = str[n++];
			}
			ch = str[n];
			temp[j] = 0;
			KEYWORD_ID KeywordId = SearchKeyword(temp);
			if (KeywordId)
				AppendKeyword(List,KeywordId);
			else
			{
				IDENTIFIER_ID IdId = SearchIdentifierStr(IdList, temp);
				//TODO
				if (IdId)
					AppendOldIdentifier(List,IdId);
				else
				{
					IdId = IdentifierStrListAppend(IdList, temp);
					AppendNewIdentifier(List, IdId);
				}
			}
			if (IsSpaceChar(ch))continue;
			else if (IsCRLF(ch))break;
		}
	}

}


	
//for every ch in pss				  		// 循环处理源代码中的每个字符
//	if(IsSpaceChar(ch))					// 空格、制表符
//		seek to first non-space char
//		for(i=i+1; i<N; i++)
//			ch = GetChar(i)
//			if(!IsSpaceChar(ch))
//				break;
//	else if(isCRLF(ch))					// 换行符
//		跳过所有连续的换行符
//		AtomList.Append_NewLine()
//	else if(IsNumericFirstChar(ch))		// 数值首字符
//		用 IsNumericSucceedChar 搜索记录下所有连续的数值字符
//		将这一段的所有字符复制出来，得到其数值 Value
//		AtomList.AppendValue(Value)
//	else if(IsIdentifierFirstChar(ch))	// 标识符 OR 关键字
//		// 用 IsIdentifierSucceedChar 搜索记录下所有连续的标识符字符
//		// 将这一段的所有字符复制出来，得到一个子字符串 IdStr
//		cursor0 = current cursor	// A
//		i0 = i+1;
//		countlength = 1;			// A

		//for every ch from current pos in pss
		//	if(IsIdentifierSucceedChar(ch))
		//		countlength++;		// A
		//		i++;
		//	else
		//		IdStr = pss.SubStr(cursor0, countlength);	// A
		//		break & keep current ch
		//	end if
//		end for
//		KeywordId = KeywordList.Search(IdStr) // 搜索关键字
//		if(KeywordId)					// 这个 Id 其实是关键字
//			AtomList.AppendKeyword(KeywordId)
//		else
//			IdId = IdStrList.Search(IdStr)	// 在已定义 Id 列表中搜索
//			if(IdId)
//				AtomList.AppendOldId(IdId)
//			else
//				IdId = IdStrList.AppendStr(IdStr)
//				AtomList.AppendNewId(IdId)
//			end if
//		end if
//	else if(IsSymbolChar(ch)) // 运算符/分隔符字符
//		NextCh = 下一个字符
//		SymbolId = SpecialSymbolList.Search2ch(ch, NextCh)
//		if(SymbolId)	// 两个相邻字符组成了特殊符号
//			AtomList.Append_Symbol(SymbolId)
//		else
//			SymbolId = SpecialSymbolList.Search1ch(ch)
//			AtomList.Append_Symbol(SymbolId)
//		end if
//	end if
//end for
//}


//for every ch in pss						// 循环处理源代码中的每个字符
//// 怎样取出 every ch ?
//for(i=0; i<N; i++)
//	ch = pss.GetChar(i);
//
//for(i=0; i<N; )
//	ch = pss.GetChar(i);
//后面在必要处进行 i++
