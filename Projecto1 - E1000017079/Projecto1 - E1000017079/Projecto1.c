/******************************************************************************************************************************************************************8/
Autor: Fabio Aristoteles Fernando Baziota
Id: 1000017079
Descrição: Trabalho número 1
Ficheiro:Projecto1.c
Data: 11/04/2017
Objectivo: Mostrar os trocos em notas minimas
Entrada: Valor da compra e o total a pagar
Saida: o troco em notas minimas
*****************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/***************************************************************************************************************************************************************/
int main()
{
	setlocale(LC_ALL,"Portuguese");
	int valC, totP, troco, nota1, nota2, nota3, moeda1, moeda2, moeda3, moeda4, cem, cin, vin, moeD, auxC, auxCin, auxV, auxMD, auxMC, auxMDD, nC, nCin, nV, mD, mDD, mCin, mU;
	
	printf("\t\t\t\t************************\n");
	printf("\t\t\t\tKERO Virtual Machine 2.5\n");
	printf("\t\t\t\t************************\n");
	printf("\n Digite o valor da compra: "); scanf("%d", &valC);
	printf("\n DIgite o total a pagar: "); scanf("%d", &totP);
	if(valC <= totP)
	{
		//Para calcular o troco
		troco = totP - valC;
		/*************Para obter as notas minimas********************/
		nC = troco/100;
		auxC = troco%100;
		/*****************/
		nCin = auxC/50;
		auxCin = auxC%50;
		/*****************/
		nV = auxCin/20;
		auxV = auxCin%20;
		/*****************/
		mD = auxV/10;
		auxMD = auxV%10;
		/*****************/
		mCin = auxMD/5;
		auxC = auxMD%5;
		/*****************/
		mDD = auxC/2;
		auxMDD = auxC%2;
		/*****************/
		mU = auxMDD/1;
		/*************************************************/
		printf("\n ***********************");
		printf("\n Troco para %d,00 Kz é :\n", troco);
		printf("\n ***********************");
		if(nC != 0)
			printf("\n %d Notas de 100 Kz\n", nC);
		if(nCin != 0)
			printf("\n e %d Notas de 50 Kz\n", nCin);
		if(nV != 0)
			printf("\n e %d Notas de 20 Kz\n", nV);
		if(mD != 0)
			printf("\n e %d Notas de 10 Kz\n", mD);
		if(mCin != 0)
			printf("\n e %d Notas de 5 Kz\n", mCin);
		if(mDD != 0)
			printf("\n e %d Notas de 2 Kz\n", mDD);
		if(mDD != 0)
			printf("\n e %d Notas de 2 Kz\n", mDD);
		if(mU != 0)
			printf("\n e %d Notas de 1 Kz\n", mU);
		printf("\n\n");
	}
	else
	{
		printf("\n ERRO: O valor da compra é maior que o total a pagar\n\n");
		printf("\n Feche a Janela e execute novamente o Programa\n Caso queira continuar...\n\n");
	}
		
	system("pause");
	return 0;
}

