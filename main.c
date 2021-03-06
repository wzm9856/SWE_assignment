#include "ATOMDEF.H"

int main()
{
	FILE* fp = fopen("python.py", "r");
	char str[100] = { 0 };
	PATOMLIST patomList = AtomListInit();
	IdList IdentifierList = IdentifierStrList_Init();
	while (fgets(str, 100, fp) != NULL)
		PSS2Atom(str, patomList, IdentifierList);
	fclose(fp);
	FILE* fp_out = fopen("output.csv", "w");
	VisualizeAtom(patomList, IdentifierList, fp_out);
	fclose(fp_out);
	return 0;
}