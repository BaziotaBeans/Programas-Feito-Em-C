/**********************************************************************************************
*____________________________________________________________________________________________*|
*|	Autor: Fábio Aristóteles Fernando Baziota		 										 ||                               										 
*|	Id: 1000017079									 										 ||
*|	Ficheiro: main.c                                                        				 ||
*|  Data de Criação: 22/07/2017                                                              ||  
*|  Data de Modificação:                         										     ||
*|	Objectivo: Manipulação de Sistem de Navegação       							 		 ||
/|___________________________________________________________________________________________||
/*********************************************************************************************/
/********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define MAX 6
#define TRUE 1
#define FALSE 0
/*------------------------------PROTOTIPO DE FUNÇÃO---------------------------------------------------------------------------------------*/
void menu();
void menu2();
int carregar(int k[][MAX]);
void imprimir(int k[][MAX]);
void md();
int lerDistancia(int posI, int posJ);
int aceder(int matriz[][MAX], int lin, int col);
void cidadesAdjacentes(int k[][MAX]);
void cidadesIsoladas(int k[][MAX]);
int verificar(int k[][MAX], int num);
void funcao();
void zerar(int k[][MAX]);
int verificarVazia(int k[][MAX]);
void acederInformacoes(int k[][MAX]);
void ambosSentidos(int k[][MAX]);
int cidadeProximas(int k[][MAX]);
int cidadeDistante(int K[][MAX]);
int verficarCidade(int cidade);
void cidadeFonte(int k[][MAX]);
int verificarFonte(int k[][MAX], int num);
int verificarSorvedouros(int k[][MAX], int num);
void cidadeSorvedouros(int k[][MAX]);
int verificarCidade1();
void percurso(int k[][MAX]);
int lerN();
void percurso2(int k[][MAX]);
/*------------------------------FIM PROTOTIPO DE FUNÇÃO------------------------------------------------------------------------------------------

Objectivo: Aceder ao menu Secundario ou as informaÇões da Matriz
Recebe: A Matriz K
Devolve: Nada
--------------------------------------------------------------------------------------------------------*/
void acederInformacoes(int k[][MAX])
{
	int opc, flag = 0;
	menu2();
	printf("\n Escolha a opção: "); scanf("%d", &opc);
	while(flag == 0)
	{
		if(opc == 1)
		{
			system("cls"); 
			cidadesAdjacentes(k); system("pause"); 	
		}
		else if(opc == 2)
		{
			system("cls"); 
			ambosSentidos(k); md(); system("pause"); 
		}
		else if(opc == 3)
		{
			system("cls"); 
			cidadesIsoladas(k); system("pause");
		}
		else if(opc == 4)
		{
			system("cls");
			cidadeFonte(k); system("pause");
		}
		else if(opc == 5)
		{
			system("cls"); 
			cidadeSorvedouros(k); system("pause");
		}
		else if(opc == 6)
		{
			system("cls");
			percurso(k); system("pause");
		}
		else if(opc == 7)
		{
			system("cls");
			percurso2(k); system("pause");
		}
		else if(opc == 8)
		{
			system("cls"); 
			imprimir(k); 
			system("pause");		
		}
		else if(opc == 9)
			flag = 1;
		else
			{
				system("cls"); printf("\n Opção invalida\n"); system("pause");	
			}
		if(flag == 0)
		{
			system("cls");
			menu2();
			printf("\n Escolha a opção: "); scanf("%d", &opc);	
		}	 
	}
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Verficar se a Matriz está vazia
Recebe: A Matriz K
Devolve: TRUE(Sim) caso esteja FALSE(Não) caso contrario
--------------------------------------------------------------------------------------------------------*/
int verificarVazia(int k[][MAX])
{
	int i, j;
	for(i = 0; i < MAX; i++)
		for(j = 0; j < MAX; j++)
		{
			if(k[i][j] != 0) return FALSE;
		}
	return TRUE;		
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Zerar a Matriz K
Recebe: A Matriz K
Devolve: Nada
--------------------------------------------------------------------------------------------------------*/
void zerar(int k[][MAX])
{
	int i, j;
	for(i = 0; i < MAX; i++)
		for(j = 0; j < MAX; j++)
			k[i][j] = 0;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Aceder ao menu principal
Recebe: Nada
Devolve: Nada
--------------------------------------------------------------------------------------------------------*/
void funcao()
{
	int opc, flag = 0, carregado = FALSE, k[MAX][MAX];
	/*int k[MAX][MAX] = {{0, 2, 0, 0, 0, 3, 2, 0, 7, 0, 0, 0, 0, 0, 0},
			 {0, 0, 0, 7, 0, 4, 3, 4, 3, 0, 6, 0, 0, 0, 0},
			 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			 {0, 8, 0, 0, 5, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0},
			 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			 {5, 3, 0, 0, 0, 0, 0, 2, 0, 9, 0, 0, 0, 5, 0},
			 {1, 2, 0, 0, 0, 0, 0, 0, 5, 0, 8, 0, 0, 7, 7},
			 {0, 0, 0, 9, 9, 1, 0, 0, 0, 3, 0, 6, 0, 0, 0},
			 {0, 0, 0, 5, 0, 0, 0, 9, 0, 0, 2, 0, 0, 0, 0},
			 {0, 0, 0, 2, 9, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0},
			 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 2},
			 {0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0},
			 {0, 0, 0, 3, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 5},
			 {0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 4, 0, 0, 0},
			 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			};*/
	zerar(k);
	menu();
	printf("\n Escolha a opção: "); scanf("%d", &opc);
	while(flag == 0)
	{
		if(opc == 0)
		{
			system("cls"); flag = 1; 	
		}
		else if(opc == 1) 
		{
			system("cls"); 
			zerar(k);
			carregado = carregar(k);
			flag = 0;	
		}
		else if(opc == 2) 
		{
			system("cls"); 
			//if(verificarVazia(k) == TRUE)
			if(carregado == TRUE)
				acederInformacoes(k);
			else
			{
				printf("\n ERRO: A Matriz não foi carregada\n"); system("pause");	
			}
			flag = 0;	
		}
		else
		{
			system("cls"); printf("\n Opção invalida\n"); system("pause");	
		}
		if(flag == 0)
		{
			system("cls");
			menu();
			printf("\n Escolha a opção: "); scanf("%d", &opc);	
		}
	}	
}
/*---------------------------------------------------------------------------------------------*/
void menu()
{
	printf("\n\t\t\tBEM VINDO AO SISTEMA DE NAVEGAÇÃO VERSÃO 1.2\n");
	printf("\n  ________________________________________________");
	printf("\n |DIGITE 0 - PARA SAIR DO PROGRAMA                |");
	printf("\n |DIGITE 1 - PARA CARREGAR MATRIZ                 |");
	printf("\n |DIGITE 2 - PARA ACESSAR AS INFORMAÇÕES DA MATRIZ|");
	printf("\n  ------------------------------------------------");
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Carregar Matriz K
Recebe: A Matriz K
Devolve: Verdadeiro
--------------------------------------------------------------------------------------------------------*/
int carregar(int k[][MAX])
{
	int i, j;
	for(i = 0; i < MAX; i++)
		for(j = 0; j < MAX; j++)
		{
			if(i == j)
				k[i][j] = 0;
			else
				k[i][j] = lerDistancia(i + 1, j + 1);
		}
	return TRUE;	
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Imprimir a Matriz K
Recebe: A Matriz K
Devolve: A Matriz K
--------------------------------------------------------------------------------------------------------*/
void imprimir(int k[][MAX])
{
	int i, j;
	for(i = 0; i < MAX; i++)
	{
		for(j = 0; j < MAX; j++)
		{
			printf("\t%d", aceder(k,i,j)); 		
		}
		md();
	}	
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Ler e Validar Distancia
Recebe: posição I e posição J 
Devolve: A distãncia
--------------------------------------------------------------------------------------------------------*/
int lerDistancia(int posI, int posJ)
{
	int dist;
	printf("\n Digite a Distância da cidade %d para cidade %d: ", posI, posJ); scanf("%d", &dist);
	while(dist < 0)
	{
		printf("\n ERRO: Distância invalida\n Digite novamente a Distância da cidade %d para cidade %d: ", posI, posJ); scanf("%d", &dist);
	}
	return dist;
}
/*---------------------------------------------------------------------------------------------*/
void md()
{
	printf("\n");
}
/*---------------------------------------------------------------------------------------------*/
int aceder(int matriz[][MAX], int lin, int col)
{
	return matriz[lin][col];
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Determinar Cidades Adjacentes
Recebe: A Matriz K
Devolve: Nada
--------------------------------------------------------------------------------------------------------*/
void cidadesAdjacentes(int k[][MAX])
{
	int total = 0, cidade, menor = 0, valor = 0, j;
	cidade = lerN();
	for(j = 0; j < MAX; j++)
	{
		if(k[cidade][j] > 0)
		{
			printf("\n Distância da cidade %d para a cidade %d é: %d Km", cidade+1, j+1, k[cidade][j]);
			if(menor == FALSE)
			{
				menor = k[cidade][j];
				valor = j;	
			}
			if(k[cidade][j] < menor)
			{
				menor = k[cidade][j];
				valor = j;
			}
			total++;
		}
	}
	printf("\n\n Existem %d Cidades Adjacentes\n", total);
	if(total > 0) printf("\n A cidade mais proxima é %d\n", valor + 1);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Determinar Cidades Isoladas
Recebe: A Matriz K
Devolve: Nada
--------------------------------------------------------------------------------------------------------*/
void cidadesIsoladas(int k[][MAX])
{
	int total = 0, validar, i, j, num = 0;
	
	for(j = 0; j < MAX; j++, num++)
	{
		if(verificar(k, num) == TRUE)
			total++;	
	}
	printf("\n Existem %d Cidades isoladas\n", total);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Verificar Cidades Isoladas
Recebe: A Matriz K
Devolve: Verdadeiro ou Falso
--------------------------------------------------------------------------------------------------------*/
int verificar(int k[][MAX], int num)
{
	int i, j;
	for(i = 0; i < MAX; i++)
	{
		if(k[i][num]) return FALSE;
	}
	for(j = 0; j < MAX; j++)
	{
		if(k[num][j]) return FALSE;	
	}
	return TRUE;		
}
/*-------------------------------------------------------------------------------------------------*/
int cidadeProximas(int k[][MAX])
{
	int proximo;	
}
/*--------------------------------------------------------------------------------------------------*/
void menu2()
{
	printf("\n  _________________________________________________________________________________________");
	printf("\n |Digite 1 - Para Determinar cidades Adjacentes                                            |");
	printf("\n |Digite 2 - Para Veficar se existe cidades que podem ser percorridos nos dois sentidos    |");
	printf("\n |Digite 3 - Para Determinar Cidades Isoladas                                              |");
	printf("\n |Digite 4 - Para Determinar cidades Fontes                                                |");
	printf("\n |Digite 5 - Para Determinar cidades Sorvedouros                                           |");
	printf("\n |Digite 6 - Para Determinar percurso entre várias cidades                                 |");
	printf("\n |Digite 7 - Para Determinar se existe percurso entre duas cidades                         |");
	printf("\n |Digite 8 - Para Imprimir a Matriz                                                        |");
	printf("\n |Digite 9 - Para Voltar no Menu Principal                                                 |");
	printf("\n -------------------------------------------------------------------------------------------");
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Determinar Cidades Fonte
Recebe: A Matriz K
Devolve: Nada
--------------------------------------------------------------------------------------------------------*/
void cidadeFonte(int k[][MAX])
{
	int i, total = 0, num = 0, j, menor = 0, id = 0; //menor = k[num][0];
	for(i = 0; i < MAX; i++, num++)
	{
		if(verificar(k, num) != TRUE)
		{
			if(verificarFonte(k, num) == TRUE)
			{
				printf("\n Cidade %d\n", num+1);
			   	total ++;
				for(j = 0; j < MAX; j++)
				{
					if(menor == FALSE)
					{
						id = j;
						menor = k[num][j];	
					} 
					if(k[num][j] > 0)
					{
						printf("\n A distância de %d para %d é: %d km ", num + 1, j + 1, k[num][j]);	
						if(k[num][j] < menor)
						{
							menor = k[num][j]; 
							id = j;	
						}		
					} 
				}	
			}
		}
	}
	printf("\n Existem %d cidades Fonte", total);
	if(total > 0) printf("\n A cidade mais proxima é %d\n", id + 1);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Verificar Se existe cidades Fonte
Recebe: A Matriz K e um número do tipo inteiro
Devolve: Verdadeiro ou False
--------------------------------------------------------------------------------------------------------*/
int verificarFonte(int k[][MAX], int num)
{
	int i, j, id= 0, total = 0;
	for(i = 0; i < MAX; i++)
	{
		if(k[i][num] != 0) return FALSE;
	}
	return TRUE;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Verificar Se existe cidades Sorvedouros
Recebe: A Matriz K e um número do tipo inteiro
Devolve: Verdadeiro ou False
--------------------------------------------------------------------------------------------------------*/
int verificarSorvedouros(int k[][MAX], int num)
{
	int i, j, id= 0, total = 0;
	for(j = 0; j < MAX; j++)
	{
		if(k[num][j] != 0) return FALSE;
	}
	return TRUE;
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Determinar Cidades Sorvedouros
Recebe: A Matriz K
Devolve: Nada
--------------------------------------------------------------------------------------------------------*/
void cidadeSorvedouros(int k[][MAX])
{
	int i, total = 0, num = 0, j, maior = 0, id = 0;
	for(i = 0; i < MAX; i++, num++)
	{
		if(verificar(k, num) != TRUE)
		{
			if(verificarSorvedouros(k, num) == TRUE)
			{
				printf("\n Cidade %d\n", num+1);
				total ++;
				for(j = 0; j < MAX; j++)
				{
					if(k[j][num] > 0)
					{
						printf("\n A distância de %d para %d é: %d km ", j + 1, num + 1, k[j][num]);
						if(k[j][num] > maior)
						{
							maior = k[j][num];
							id = j;	         
						}		
					} 
				}	
			}
		}
	}
	printf("\n\n Existem %d cidades Sorvedouros\n", total); 
	if(total > 0) printf("\n A cidade mais distante é %d\n", id + 1);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Determinar Cidades que podem ser percoridos em ambos sentidos
Recebe: A Matriz K
Devolve: Nada
--------------------------------------------------------------------------------------------------------*/
void ambosSentidos(int k[][MAX])
{
	int maior=0, i, j;
	printf("\n Cidades que podem ser percorridas em ambos sentidos:\n");
	for(i = 0; i < MAX; i++)
		for(j = 0; j < MAX; j++)
			if(k[i][j] != 0)
				if(k[j][i] != 0)
				{
					if(k[i][j] > maior) maior = k[i][j];
					printf("\n %d para %d é %d Km", i+1, j+1, k[i][j]);
				}
				
	printf("\n Maior distância = %d Km\n", maior);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Determinar percurso entre varias cidades
Recebe: A matriz K
Devolve: Nada
--------------------------------------------------------------------------------------------------------*/
void percurso(int k[][MAX])
{
	int percurso1, percurso2, totalKm = 0, flag = 0, acess = 0;
	percurso1 = lerN();
	percurso2 = lerN();
	while(acess == 0)
	{
		if(percurso1 <= -1)
		{
			acess = 1;
			system("pause");
		}
		else if(percurso2 <= -1)
		{
			acess = 1;
			system("pause");
		}
		else if(k[percurso1][percurso2] == 0)
		{
			printf("\n ERRO: percurso inexistente!!!\n"); flag = 0; acess = 1;
			system("pause");
		}
		else
		{
			totalKm = totalKm + k[percurso1][percurso2];
			percurso1 = percurso2;
			percurso2 = lerN();
			flag = 1;
		}
		
	}
	if(flag == 1)
		printf("\n Tootal = %d \n", totalKm);
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Verificar se a cidade digitada está no intervalo
Recebe: Nada
Devolve: cidade - 1
--------------------------------------------------------------------------------------------------------*/
int lerN()
{
	int num;
	printf("\n Entre com o número da cidade: "); scanf("%d",&num);
	while(1)
	{
		if(num >= 0)
		{
			if(num<=MAX) return num - 1;	
		}
		printf("\n ERRO: número invalido\n Entre com o número da cidade: "); scanf("%d",&num);
	}
}
/*-------------------------------------------------------------------------------------------------------
Objectivo: Determinar um percurso que inicia em i e termina em j
Recebe: Nada
Devolve: Nada
--------------------------------------------------------------------------------------------------------*/
void percurso2(int k[][MAX])
{
	int perc,perc2,flag=0,i,j,vetor[MAX],ultPos=-1;
	perc=lerN();
	perc2=lerN();
		if(k[perc][perc2]==0)
			printf("\n Percurso invalido");
		else
		{
			printf("\n Percurso:\n %d -> %d\n", perc+1, perc2+1);
			for(i=0;i<MAX;i++)
			{
				if(k[perc][i]!=0)
					if(k[i][perc2]!=0)
					{
						ultPos++; vetor[ultPos] = i; 
						printf(" %d ->",perc+1);
						for(j=0;j<=ultPos;j++) printf(" %d ->",vetor[j]+1); 
						printf(" %d\n",perc2+1);
					}
			}
		}
}
/*--------------------------------------------------------------------------------------------------------------------------------------------
Função principal
--------------------------------------------------------------------------------------------------------------------------------------------*/
int main(int argc, char *argv[]) 
{
	setlocale(LC_ALL, "Portuguese");
	funcao();
	return 0;
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
