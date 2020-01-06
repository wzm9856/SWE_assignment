#include"VisualizeDef.h"

void VisualizeAtom(PATOMLIST AtomList, FILE* fp)
{
	PATOMLIST pThis = AtomList->next;
	char AtomType[10] = { 0 };
	char AtomContent[20] = { 0 };
	while (pThis)
	{
		ATOM atom = pThis->atom;
		switch (atom.atom_type)
		{
		case _ATOM_NULL:
			fprintf(fp, "%s\t%s\n", "NULL", "NULL");
		case _ATOM_KEYWORD:
			fprintf(fp, "%s\t%s\n", "¹Ø¼ü×Ö", atom.atom_keyword);
		default:
			break;
		}

	}

	
}