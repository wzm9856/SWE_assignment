#include"ATOMDEF.H"

int main()
{
	FILE* fp = NULL;//fpΪtxt�ļ�ָ�� 	
	char str[100] = { 0 };//�����������Ů�޹�
	PATOMLIST patomList = AtomListInit();
	IdList IdentifierList = IdentifierStrList_Init();
	fp = fopen("python.txt", "r");//�������ļ� 
	while (fgets(str, 100, fp) != NULL)
	{
		PSS2Atom(str, patomList, IdentifierList);
	}
	fclose(fp);//�ر��ļ�
	return 0;
}