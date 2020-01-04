#include"ATOMDEF.H"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE* fp = NULL;//fp为txt文件指针 	
	char str[100] = { 0 };//数组操作，玉女无瓜
	PATOMLIST patomList = AtomListInit();
	IdList List = IdentifierStrList_Init();
	fp = fopen("python.txt", "r");//打开数据文件 
	while (fgets(str, 100, fp) != NULL)
	{
		PSS2Atom(str, patomList);
	}
	fclose(fp);//关闭文件
	return 0;
}