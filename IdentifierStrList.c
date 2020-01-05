#include <stdio.h>
#include <stdlib.h>
#include"ATOMDEF.H"

typedef struct IdentifierStrList
{
	char data[1023];
	struct IdentifierStrList* next;
};

IdList IdentifierStrList_Init()
{
	IdList L;
	L = (IdList)malloc(sizeof(struct IdentifierStrList));
	if (L == NULL)
		printf("申请内存空间失败\n");
	L->next = NULL;
	return L;
}

IDENTIFIER_ID SearchIdentifierStr(IdList List, const char* sub)
{
	IdList pThis = List->next;
	int Idid = 0; 
	while (pThis)
	{
		Idid++;		//当前检查的是第Idid个标识符，如果匹配则直接返回Idid
		if (IsEqual(pThis->data, sub))
			return Idid;
		else pThis = pThis->next;
	}
	return 0;
}

IDENTIFIER_ID IdentifierStrListAppend(IdList List, PGSTRC sub)
{
	IdList pThis = List;
	IDENTIFIER_ID Idid = 0;
	while (pThis->next)
	{
		pThis = pThis->next;
		Idid++;		//Idid代表pThis当前指向的结点序号
	}				//退出while时pThis指向最后一节点
	IdList pNew = (IdList)malloc(sizeof(struct IdentifierStrList));
	pThis->next = pNew;
	pNew->next = NULL;
	StrCpy(sub, pNew->data);
	return Idid + 1;
}