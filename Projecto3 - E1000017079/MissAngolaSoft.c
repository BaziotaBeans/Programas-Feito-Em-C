/*********************************************************************************************\
*____________________________________________________________________________________________*|
*|	Autor: F�bio Arist�teles Fernando Baziota		 										 ||
*|	Data: 10/05/2017                                 										 ||
*|	Id: 1000017079									 										 ||
*|	Ficheiro: MissAngolaSoft.c                                                               ||
*|  Data de Cria��o: 31/05/2017                                                              ||  
*|  Data de Modifica��o:                         										     ||
*|	Objectivo: selecionar as candidatas que ir�o participar nos concursos Municipais         ||
*|	Entrada: Dados das candidatas                    										 ||
*|	Sa�da: AS tr�s selecionadas                                                              ||
/|___________________________________________________________________________________________||
/*********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define TAM 30
#define TRUE 1
#define FALSE 0
#define SENTINELA 0
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------
Prot�tipos de fun��es
----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int lerIdentificacaoCandidato();
int lerRequisitosCandidato(int *rep);
int validarRequisitosCandidato(float altura, int habLit, int nacionalidade, int idade, float peso, int *rep);
float lerNotasCandidato(char nota[]);
float calcularMedia();
int lerFactoresPadrao();
int calcularMinimosQuadrados(int corpo_ideal, int cultura_geral, int educacao, int boasManeiras, int amorProximo, int passarela);
int calcularTresSelecionadas();
void imprimirTresSelecionadas();
void linhaBranca();
float lerAltura();
int lerHabil();
void converterM(char texto[TAM]);	
int lerNacionalidade();
int lerIdade();
int pot(int result);
float lerPeso();
int lerFactor();
void imprimir();
void lerNome(char nome[]);
int diferencaPadrao(int corpo_ideal, int cultura_geral, int educacao, int boasManeiras, int amorProximo, int passarela);
void classificacao(int clasf, int *max, int *media, int *min);
int validar(int *flag);
//void numero(int id, int *max, int *media, int *min);
float calcularPerc(int ref, int tot);
void numero(int id, int *max, int *media, int *min, char nome[], char nomeA[], char nomeB[], char nomeC[]);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
float calcularPerc(int ref, int tot)
{
	return ((ref*100)/tot);
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/********************************************FUN��O Ler e Validar Nome*********************************************************************************/
void lerNome(char nome[])
{
	int i;
	fflush(stdin); printf(" Digite o nome: "); gets(nome); fflush(stdin);
	for(i=TAM; i>=0; i--)
	{
		while(isdigit(nome[i]) == 1)
		{
			fflush(stdin); printf("\n ERRO: Nome invalido\n Digite o nome: "); gets(nome); fflush(stdin);
		}
	}
}
/********************************************FUN��O CALCULAR MINIMOS QUADRADOS*********************************************************************************/
int calcularMinimosQuadrados(int corpo_ideal, int cultura_geral, int educacao, int boasManeiras, int amorProximo, int passarela)
{
	return (pot(4 - corpo_ideal) + pot(5 - cultura_geral) + pot(4 - educacao) + pot(4 - boasManeiras) + pot(5 - amorProximo) + pot(3 - passarela));
}
/********************************************FUN��O VALIDAR FACTOR*********************************************************************************/
int lerFactor(char factor[])
{
	int factor1, flag = 0;
	while(flag == 0)
	{
		printf("\n Digite a classifica��o para o %s: ",factor); scanf("%d", &factor1);
		if(factor1 >= 1)
		{
			if(factor1 <= 5)
				flag = 1;
		}
	}
	return factor1;
}
/*********************************************FUN��O LER PESO****************************************************************************************/
float lerPeso()
{
	float peso;
	printf("\n Digite o peso: "); scanf("%f", &peso);
	while(peso <= 0)
	{
		printf("\n ERRO: peso invalido\n Digite o peso: "); scanf("%f", &peso);
	}
	return peso;
}
/********************************CALCULAR POT�NCIA***************************************************************************************************/
int pot(int result)
{
	int i, pot = 1;
	for(i=0; i<2; i++)
		pot*=result;

	return pot;
}
/********************************PARA LERFACTORES PADR�O**********************************************************************************************/
int lerFactoresPadrao()
{
	
	int corpo_ideal, cultura_geral, educacao, boasManeiras, amorProximo, passarela, padrao, diferenca;
	
	corpo_ideal = lerFactor("Corpo ideal");
	cultura_geral = lerFactor("Cultara Geral");
	educacao = lerFactor("Educa��o"); 
	boasManeiras = lerFactor("Boas Maneiras"); 
	amorProximo = lerFactor("Amor ao pr�ximo");  
	passarela = lerFactor("Passarela");
	diferenca = diferencaPadrao(corpo_ideal, cultura_geral, educacao, boasManeiras, amorProximo, passarela);
	if(diferenca > 2) return -1;
	else
		padrao = calcularMinimosQuadrados(corpo_ideal, cultura_geral, educacao, boasManeiras, amorProximo, passarela);
	return padrao; 
}
/************************************FUN��O Calcular M�dia**********************************************************************************************/
float calcularMedia()
{
	float media, perc, exame1, exame2;
	exame1 = lerNotasCandidato("Lingua Portuguesa");
	exame2 = lerNotasCandidato("Lingua Inglesa");
	media = (exame1 + exame2)/2;
	perc = (100*media)/20;
	
	return perc;
}
/************************************FUN��O Para ler AS notas*******************************************************************************************/
float lerNotasCandidato(char nota[])
{
	float exame;
	int flag = 0;
	while(flag == 0)
	{
		printf("\n Digite a nota do exame %s: ", nota); scanf("%f", &exame);
		if(exame >= 0)
		{
			if(exame <= 20)
				flag = 1;
		}
	}
	return exame;
}
/************************************FUN��O Para Validar os Requisitos do candidato*******************************************************************/
int validarRequisitosCandidato(float altura, int habLit, int nacionalidade, int idade, float peso, int *rep)
{
	if(altura < 1.70) return FALSE;
	if(altura > 1.80) return FALSE;
	if(habLit < 3) return FALSE;
	if(habLit == 3)
	{
		if(calcularMedia() < 14)
		{
			*rep = 2;
			return FALSE;
			printf("\n Candidata exclu�da\n");
		}
	}
	if(idade < 18) return FALSE;
	if(idade > 27) return FALSE;
	if(peso < 55) return FALSE;
	if(peso > 68) return FALSE;
	if(nacionalidade != 1) return FALSE;
	
	return TRUE;
}
/************************************FUN��O Para Ler as Identifica��es******************************************************************************************************/
int lerIdentificacaoCandidato()
{
	int id;
	printf("\n Digite o n�mero: "); scanf("%d", &id);
	while(id <0)
	{
		printf("\n ERRO: Digite o n�mero: "); scanf("%d", &id);
	}
	return id;
}
/************************************FUN��O Para Ler a idade****************************************************************************************************************/
int lerIdade()
{
	int idade, flag = 1;
	printf("\n Digite a idade: "); scanf("%d", &idade);
	while(flag == 0)
	{
		if(idade > 14)
		{
			if(idade < 30)
				flag = 1;
		}
		else 
		{
			printf("\n ERRO: Idade invalida\n Digite a idade: "); scanf("%d", &idade);
		}
	}
	return idade;
}
/************************************FUN��O Para Ler a Nacionalidade***************************************************************/
int lerNacionalidade()
{
	int nacionalidade, flag = 2;
	while(flag == 2)
	{
		printf("\n Digite a sua nacionalidade\n Digite 1(sim) - se �s Angolana\n Digite 0(n�o) caso o contrario: "); scanf("%d", &nacionalidade);
		if(nacionalidade == 0) return nacionalidade;
		{
			if(nacionalidade == 1) return nacionalidade;
		}	
	}	
}
/************************************FUN��O VALIDAR HABILITA��O lIT�RARIA*********************************************************************************************************************************************************************************/
int lerHabil()
{
	int hab=0, habLit;
	printf("\n Habilita��o Liter�ria\n Digite 1 - para: Primeiro\n Digite 2 - para: Secund�rio\n Digite 3 - para: M�dio\n Digite 4 - para Universit�rio\n Digite [AQUI]: "); scanf("%d", &habLit);
	while(hab==0)
	{
		if(habLit == 1)
			hab = 1;
		else if(habLit == 2)
			hab = 2;
		else if(habLit == 3)
			hab = 3;
		else if(habLit == 4)
			hab = 4;
		else
		{
			printf("\n Habilita��o Liter�ria\n Digite 1 - para: Primeiro\n Digite 2 - para: Secund�rio\n Digite 3 - para: M�dio\n Digite 4 - para Universit�rio\n Digite [AQUI]: "); scanf("%d", &habLit);
		}
					
	}
	return habLit;
}
/*******************************************FUN��O VALIDAR ALTURA****************************************************************************************************/
float lerAltura()
{
	float altura; 
	int flag = 0;
	//printf("\n Digite a altura: "); scanf("%f", &altura);
	while(flag == 0)
	{
		printf("\n Digite a altura: "); scanf("%f", &altura);
		if(altura >= 1.40)
		{
			if(altura <= 2) 
				flag = 1;
		}
	}
	return altura;
}
/************************************FUN��O PRINCIPAL*****************************************************************************************************************/
int main()
{
	setlocale(LC_ALL, "Portuguese");
	imprimir();
	return 0;
}
/*******************************FUN��O LER REQUISITOS*****************************************************************************************************************/
int lerRequisitosCandidato(int *rep)
{
	return validarRequisitosCandidato(lerAltura(), lerHabil(), lerNacionalidade(), lerIdade(), lerPeso(), rep); 
}
/********************************PROCEDIMENTO IMPRIMIR LINHA BRANCA****************************************************************************************************/
void linhaBranca()
{
	printf("\n");
}
/***********************************PROCEDIMENTO IMPRIMIR ************************************************************************************************************/
void imprimir()
{
	int classif, id, flag, reprovM=0, reprovados_T=0, reprovP=0, maximo = 0, minimo=0, media=0, idMaximo=0, idMinimo=0, idMedia=0, aprovados = 0, totalGeral = 0, reprovados_padrao = 0, num=0, parar = 0;   
	char nome[TAM], nomeA[TAM], nomeB[TAM], nomeC[TAM];
	float total_excluida_triagem = 0.0, total_excluida_prova = 0.0, total_excluida_padrao = 0.0, total_aprovados =  0.0;
	linhaBranca();
	id = lerIdentificacaoCandidato(); 
	if(id == 0)
		id = 0;
	else
	{
		lerNome(nome); 
		parar = 1;	
	}
	while(id != SENTINELA)
	{	
		if (lerRequisitosCandidato(&flag) == TRUE)
		{
			linhaBranca();
			classif = lerFactoresPadrao();
			if(classif == -1) 
			{
				reprovados_padrao++;
				printf("\n Candidata exclu�da por falta de padr�o\n");
				linhaBranca();	
			}
			else
			{
				numero(id, &idMaximo, &idMedia, &idMinimo, nome, nomeA, nomeB, nomeC);
				aprovados++;
			}	
		}
		else
		{
			if(flag == 2)
			{
				reprovM++;	
				system("cls");
				printf("\n Candidata n�o domina l�nguas");
			}
			else
			{
				printf("\n Excluida na triagem ");	
				reprovados_T++; 
				linhaBranca();	
			}
			//printf("\n Excluida na triagem ");	reprovT++;
		}
		id = lerIdentificacaoCandidato(); 
		if(id == 0)
			id = 0;
		else
		{
			lerNome(nome); 
			parar = 1;	
		}
			
		totalGeral++;
	}
	if(parar == 1)
	{
		total_excluida_triagem = calcularPerc(reprovados_T, totalGeral);
		total_excluida_prova = calcularPerc(reprovM, totalGeral);
		total_excluida_padrao = calcularPerc(reprovados_padrao, totalGeral);
		total_aprovados = calcularPerc(aprovados, totalGeral);	
	}
	linhaBranca();
	printf("\n-----------------------------------------------------------------------------------------------");
	printf("\n A candidata que mais se aproxima � %s n�mero: %d",nomeA, idMaximo);
	printf("\n A outra Candidata que mais se aproxima � %s n�mero: %d",nomeB, idMedia);
	printf("\n-----------------------------------------------------------------------------------------------");
	printf("\n A precentagem de Total exclu�das na triagem � %.2f", total_excluida_triagem);
	printf("\n A precentagem de Total exclu�das na prova � %.2f", total_excluida_prova);
	printf("\n A precentagem de Total exclu�das pelo padr�o � %.2f", total_excluida_padrao);
	printf("\n A precentagem de Total aprovados � %.2f", total_aprovados);
	printf("\n Total geral de candidatas � %d", totalGeral);
	 
}
/********************************************Fun��o calcular Diferen�a*************************************************************************************************/
int diferencaPadrao(int corpo_ideal, int cultura_geral, int educacao, int boasManeiras, int amorProximo, int passarela)
{
	int difer = 0;
	if(4 - corpo_ideal >= 2) difer++;
	if(5 - cultura_geral >= 2) difer++;
	if(4 - educacao >= 2) difer++;
	if(4 - boasManeiras >= 2) difer++;
	if(5 - amorProximo >= 2) difer++;
	if(3 - passarela >= 2) difer++;
	return difer;
}
/*****************************************Fun��o Seleccionar as candidatas que mais se aproximam**********************************************************************************/
void numero(int id, int *max, int *media, int *min, char nome[], char nomeA[], char nomeB[], char nomeC[])
{
	char nomeAux[TAM], nomeAux2[TAM];
	int aux, aux2;
	if(id > *max)
	{
		aux = *max;
		strcpy(nomeAux,nomeA);
		aux2 = *media;
		strcpy(nomeAux2,nomeB);
		*max = id;
		strcpy(nomeA,nome);
		*media = aux;
		strcpy(nomeB,nomeAux);
		*min = aux2;
		strcpy(nomeC, nomeAux2);
	}
	else if(id > *media)
	{
		aux = *media;
		strcpy(nomeAux, nomeB);
		*media = id;
		strcpy(nomeB, nome);
		*min = aux;
		strcpy(nomeC, nomeAux);
	}
}
/**********************************************************************************************************************************************************************/
