#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int gorila_montanha = 85, gorila_planice = 160, i=1;
	
	/*printf("\n Digite o número de gorilas de montanha: "); scanf("%d", &gorila_montanha);
	printf("\n Digite o número de gorilas de planice: "); scanf("%d", &gorila_planice);*/
	
	while(gorila_montanha <= gorila_planice)
	{
		gorila_montanha +=(gorila_montanha*0.05);
		gorila_planice +=(gorila_planice*0.03);
		i++;
	}
	printf("\n É necessario %d anos para que a gorila da montanha ultrapasse as gorilas da planice\n\n\n", i);
	system("pause");
	return 0;
}
