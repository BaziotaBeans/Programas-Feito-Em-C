#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Portuguese");
	char turno, tur=0;
	printf("\n  ____________________________");
	printf("\n |Digite T para Tarde			| ");
	printf("\n |Digite N para Noite			| ");
	printf("\n |Digite M para Manhã			| ");
	printf("\n |Digite M para Manhã         | ");
	printf("\n |Digite I para Tempo Integral| ");
	printf("\n |Digite o turno: ");scanf("%c", &turno);
	printf("\n  -------------------");
	setbuf(stdin, NULL);
	while(tur == 0)
	{
		if(toupper(turno) == 'T')
			tur = 1;
		else if(toupper(turno) == 'N')
			tur = 1;
		else if(toupper(turno) == 'M')
			tur = 1;
		else if(toupper(turno) == 'I')
			tur = 1;
		else
		{
			system("cls");
			printf("\n  ERRO: Categoria Invalida\n");
			printf("\n  ____________________________");
			printf("\n |Digite T para Tarde			| ");
			printf("\n |Digite N para Noite			| ");
			printf("\n |Digite M para Manhã			| ");
			printf("\n |Digite M para Manhã         | ");
			printf("\n |Digite I para Tempo Integral| ");
			printf("\n |Digite o turno: ");scanf("%c", &turno);
			setbuf(stdin, NULL); 
			printf("\n  -------------------");
			setbuf(stdin, NULL);
		}	
	}
	
	return 0;
}
