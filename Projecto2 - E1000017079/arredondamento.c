#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int parte_int = 0, novo_valor = 0;
	float parte_frac = 0.0, valor;
	
	scanf("%f", &valor);
	
	parte_int = (int)valor;
	
	parte_frac = valor - parte_int;
	
	if(parte_frac >= 0.5)
	
		novo_valor = valor + parte_frac;
		
	else
		novo_valor = parte_int;
		
	printf("\n O valor � %d\n", novo_valor);
	printf("\n O valor � %f\n", parte_frac);
	system("pause");
	return 0;
}
