#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	int amamentar = 1, val;
	
	while(amamentar == 1)
	{
		scanf("%d", &val);
		if(val == 1)
			amamentar = 0;
		else if(val == 0)
			amamentar = 0;
		else
			printf("\n ERRO\n");
	}
	
	return 0;
}
