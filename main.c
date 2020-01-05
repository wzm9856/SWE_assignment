#include"ATOMDEF.H"

int main()
{
	FILE* fp = fopen("python.txt", "r");
	char str[100] = { 0 };
	PATOMLIST patomList = AtomListInit();
	IdList IdentifierList = IdentifierStrList_Init();
	while (fgets(str, 100, fp) != NULL)
		PSS2Atom(str, patomList, IdentifierList);
	fclose(fp);
	return 0;
}