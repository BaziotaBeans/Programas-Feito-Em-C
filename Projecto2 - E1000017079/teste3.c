#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Portuguese");
	char categoria, cat=0;
	printf("\n  _________________________");
	printf("\n |Digite T para Técnico    | ");
	printf("\n |Digite P para Programador| ");
	printf("\n |Digite A para Analista   | ");
	printf("\n |Digite G para Gestor     | ");
	printf("\n |Digite a categoria: "); scanf("%c", &categoria);
	printf("\n  -------------------");
	setbuf(stdin, NULL);
	while(cat == 0)
	{
		if(toupper(categoria) == 'T')
			cat = 1;
		else if(toupper(categoria) == 'P')
			cat = 1;
		else if(toupper(categoria) == 'A')
			cat = 1;
		else if(toupper(categoria) == 'G')
			cat = 1;
		else
		{
			system("cls");
			printf("\n  ERRO: Categoria Invalida\n");
			printf("\n  _________________________");
			printf("\n |Digite T para Técnico    | ");
			printf("\n |Digite P para Programador| ");
			printf("\n |Digite A para Analista   | ");
			printf("\n |Digite G para Gestor     | ");
			printf("\n |Digite a categoria: "); scanf("%c", &categoria);
			setbuf(stdin, NULL);
			printf("\n  -------------------");	
			setbuf(stdin, NULL);
		}	
	}
	
	return 0;
}
