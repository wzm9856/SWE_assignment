// Keyword List ʵ�ַ�ʽ 2����̬����
#include <stdio.h>
#include <stdlib.h>
#include"ATOMDEF.H"

typedef struct IdentifierStrList
{
	unsigned char data[65535];
	struct IdentifierStrList* next;
};


//������ List���� ATOM ΪԪ�ص�ͨ�� LIST ��GLIST��

IdList IdentifierStrList_Init()
{
	IdList L;
	L = (IdList)malloc(sizeof(struct IdentifierStrList));
	if (L == NULL)
		printf("�����ڴ�ռ�ʧ��\n");
	L->next = NULL;
	return L;
}


extern IDENTIFIER_ID SearchIdentifierStr(IdList List, const char* sub)
{
	IdList pThis;
	pThis = List->next;
	if (sub[0] == 0) return NULL;
	int i = 0; 
	while (pThis)
	{
		int n = 0;
		int j = 0;
		while (pThis->data[n] == sub[n])//�ҵ����Ӵ���һ��һ���ģ�����ѭ��
		{
			if (pThis->data[n]==0&&sub[n] == 0)
				return i;
			n++;//ÿ��һλ i����
		}
		i++;
		pThis = List->next;
		for (j = 0; j < i; j++)//�ܵ��ϴ��Ѿ��ܵ���λ��
			pThis = pThis->next;
	}
	return 0;
}

extern IDENTIFIER_ID IdentifierStrListAppend(IdList List, PGSTRC sub)
{
	IdList pThis = List->next;
	int i = 1;
	while (pThis)
	{
		pThis = pThis->next;
		i++;
	}
	IdList pThat = (IdList)malloc(sizeof(struct IdentifierStrList));
	pThis->next = pThat;
	int j = 0;
	while (sub[j])
	{
		pThat->data[j] = sub[j];
		j++;
	}
	pThat->next = NULL;
	return i;
}