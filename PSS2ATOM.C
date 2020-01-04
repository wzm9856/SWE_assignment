//#include "GSCAN.H"
#include"ATOMDEF.H"
#include <stdlib.h>
#include <stdio.h>


void PSS2Atom(PGSTRC str, PATOMLIST List,IdList IdList)
{
	char temp[100] = { 0 };
	char ch;
	int i = 0;
	int m = 0;
	for (i = 0; i < 100; i++)
	{
		ch = str[i];
		if (IsSpaceChar(ch))
		{
			//TODO
			m++;
			AppendSpace(List, m);
			continue;
		}
		else if (IsCRLF(ch))
		{
			AppendCRLF(List);
			break;
		}
		else if (IsNumericFirstChar(ch))
		{
			temp[0] = ch;
			int j = 1;
			int n = i + 1;
			while (IsNumericSucceedChar(str[n]))
			{
				temp[j++] = str[n++];
			}
			ch = str[n];
			temp[j] = 0;
			if (IsSpaceChar(ch))continue;
			else if (IsCRLF(ch))break;
			//TODO:123
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
		else if (IsSymbolChar(ch))
		{
			if (IsZhuShi(ch))
				break;
			char NextCh = str[i + 1];
			SPECIALSYMBOL_ID SpecialSymbolId = SearchSpecialSymbol(ch, NextCh);
			if (SpecialSymbolId)	// ���������ַ�������������
				AppendSymbol(List, SpecialSymbolId);
			else
			{
				SYMBOL_ID SymbolId = SearchSymbol(ch);
				AppendSymbol(List, SymbolId);
			}
			if (IsSpaceChar(ch))continue;
			else if (IsCRLF(ch))break;
		}
	}

}


	
//for every ch in pss				  		// ѭ������Դ�����е�ÿ���ַ�
//	if(IsSpaceChar(ch))					// �ո��Ʊ���
//		seek to first non-space char
//		for(i=i+1; i<N; i++)
//			ch = GetChar(i)
//			if(!IsSpaceChar(ch))
//				break;
//	else if(isCRLF(ch))					// ���з�
//		�������������Ļ��з�
//		AtomList.Append_NewLine()
//	else if(IsNumericFirstChar(ch))		// ��ֵ���ַ�
//		�� IsNumericSucceedChar ������¼��������������ֵ�ַ�
//		����һ�ε������ַ����Ƴ������õ�����ֵ Value
//		AtomList.AppendValue(Value)
//	else if(IsIdentifierFirstChar(ch))	// ��ʶ�� OR �ؼ���
//		// �� IsIdentifierSucceedChar ������¼�����������ı�ʶ���ַ�
//		// ����һ�ε������ַ����Ƴ������õ�һ�����ַ��� IdStr
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
//		KeywordId = KeywordList.Search(IdStr) // �����ؼ���
//		if(KeywordId)					// ��� Id ��ʵ�ǹؼ���
//			AtomList.AppendKeyword(KeywordId)
//		else
//			IdId = IdStrList.Search(IdStr)	// ���Ѷ��� Id �б�������
//			if(IdId)
//				AtomList.AppendOldId(IdId)
//			else
//				IdId = IdStrList.AppendStr(IdStr)
//				AtomList.AppendNewId(IdId)
//			end if
//		end if
//	else if(IsSymbolChar(ch)) // �����/�ָ����ַ�
//		NextCh = ��һ���ַ�
//		SymbolId = SpecialSymbolList.Search2ch(ch, NextCh)
//		if(SymbolId)	// ���������ַ�������������
//			AtomList.Append_Symbol(SymbolId)
//		else
//			SymbolId = SpecialSymbolList.Search1ch(ch)
//			AtomList.Append_Symbol(SymbolId)
//		end if
//	end if
//end for
//}


//for every ch in pss						// ѭ������Դ�����е�ÿ���ַ�
//// ����ȡ�� every ch ?
//for(i=0; i<N; i++)
//	ch = pss.GetChar(i);
//
//for(i=0; i<N; )
//	ch = pss.GetChar(i);
//�����ڱ�Ҫ������ i++