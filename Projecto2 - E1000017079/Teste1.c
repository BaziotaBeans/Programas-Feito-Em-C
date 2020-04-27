/******************************************************
	Autor: F�bio Arist�teles Fernando Baziota
	Data: 10/05/2017
	Id: 1000017079
	Ficheiro: FolhaDeSalarios
	Objectivo: Imprimir o a folha de salario 
	Entrada: Dados do trabalhador
	Sa�da: A respectiva folha de s�lario
******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define SENTINELA 0
#define TAM 45                                         
#define ACCESS 1
#define FEMENINO 'F'
#define MASCULINO 'M'
/**************************************************/
int main()
{
	setlocale(LC_ALL, "Portuguese");
	/*****************************DECLARA��ES DAS VARI�VEIS*********************************************************/
	int codTrab, num_horas_mes, amamentar, num_pro_r, access, horasExtra = 0, idade_Filho, horasFalta = 0, amam=0;
	const int HORALEI = 176;
	const float SALMINIMO = 30000.00;
	char nomeTrab[TAM], sexo, categoria, turno;
	float salario_base = 0.0, salario_bruto = 0.0, salario_liquido = 0.0, subsidio = 0.0;
	float valor_hora_trabalho = 0.0, faltas = 0.0, desconto_seg_social = 0.0, parte_frac = 0.0, desconto_hora = 0.0;
	int parte_inteira = 0, salario_liquido_novo = 0, nova_hora_lei = 0;
	/*****************************FIM DAS DECLARA��ES***************************************************************/
	printf("\t\t\t\t UCANSOFT 1.0\n");
	printf("\n Digite 1 - Para acessar: "); scanf("%d", &access);
	
	while(access == ACCESS)
	{
		system("cls");
		printf("\n Digite o C�digo do trabalhador: "); scanf("%d", &codTrab);
		setbuf(stdin, NULL);
		//fflush(stdin);
		printf("\n Digite o nome do trabalhador/a: "); gets(nomeTrab);
		setbuf(stdin, NULL);
		printf("\n Digite o N�mero de horas trabalhadas no m�s: "); scanf("%d", &num_horas_mes);
		while(num_horas_mes <= 0)
		{
			printf("\n ERRO: Campo Hora invalida\n Digite o N�mero de horas trabalhadas no m�s: "); scanf("%d", &num_horas_mes);
		}
		setbuf(stdin, NULL);
		printf("\n  ___________________");
		printf("\n |Digite T para Tarde| ");
		printf("\n |Digite N para Noite| ");
		printf("\n |Digite M para Manh�| ");
		printf("\n |Digite o turno: ");scanf("%c", &turno);
		printf("\n  -------------------");
		setbuf(stdin, NULL);
		printf("\n  _________________________");
		printf("\n |Digite T para T�cnico    | ");
		printf("\n |Digite P para Programador| ");
		printf("\n |Digite A para Analista   | ");
		printf("\n |Digite G para Gestor     | ");
		printf("\n |Digite a categoria: "); scanf("%c", &categoria);
		printf("\n  -------------------");
		setbuf(stdin, NULL);
		printf("\n  ____________________________");
		printf("\n |Digite F para sexo Femenino | ");
		printf("\n |Digite M para sexo Masculino| ");
		printf("\n |Digite o Sexo: "); scanf("%c", &sexo);
		printf("\n  -------------------");
		setbuf(stdin, NULL);
		printf("\n  _____________________________");
		printf("\n |Vai amamentar                |");
		printf("\n |Digite 1(SIM) ou 0(N�o):     |"); scanf("%d", &amamentar);
		printf("\n  ----------------------------");
		while(amam == 0)
		{
			if(amamentar == 1)
				amam = 1;
			else if(amamentar == 0)
				amam = 1;
			else
			{
				system("cls");
				printf("\n ERRO: Op��o Invalida\n Digite Novamente \n Vai Amamentar");
				printf("\n |Digite 1(SIM) ou 0(N�o):     |"); scanf("%d", &amamentar);	
			}
		}
		setbuf(stdin, NULL);
		printf("\n Digite o n�meros de projectos realizados: "); scanf("%d", &num_pro_r);
		setbuf(stdin, NULL);
		while(num_pro_r < 0)
		{
			printf("\n ERRO: N�mero invalido!!");
			printf("\n Digite novamente o n�meros de projectos realizados: "); scanf("%d", &num_pro_r);
			setbuf(stdin, NULL);
		}

		if(toupper(categoria) == 'G')
		{
			if(toupper(turno) == 'N')
			{
					valor_hora_trabalho = (SALMINIMO * num_horas_mes)/HORALEI;
					salario_base = (8*SALMINIMO)/num_horas_mes;
			}

			if(toupper(turno) == 'M')
			{
					valor_hora_trabalho = (SALMINIMO * num_horas_mes)/HORALEI;
					//salario_base = ///////////////////////////
			}
			
			if(toupper(turno) == 'N')
			{
					valor_hora_trabalho = (SALMINIMO * num_horas_mes)/HORALEI;
					//salario_base = ///////////////////////////
			}

			subsidio = 7.5 * valor_hora_trabalho; //f�rmula para calcular subs�dio de chefia
			if(num_horas_mes > HORALEI)
				horasExtra = num_horas_mes - HORALEI; //f�rmula para calcular horas extras
			if(num_horas_mes < HORALEI)
			{
				horasFalta = HORALEI - num_horas_mes; //f�rmula para calcular horas em falta
				desconto_hora = (horasFalta*300000)/HORALEI;
			}
			
			faltas = (horasFalta*100)/176; //f�rmula para calcular as falta em percentagem
			
			if(faltas <= 0.02)
			{
				subsidio = num_pro_r *(valor_hora_trabalho* 0.3); //f�rmula para calcular o subs�dio por cada projecto
			}
			
			salario_bruto = salario_base + subsidio - faltas; //f�rmula para calcular o s�lario bruto
			desconto_seg_social = 0.5 * salario_bruto; //f�rmula para calculaf o desconto de seguran�a social
			salario_liquido = salario_bruto - desconto_seg_social; //f�rmula para calcular o s�lario liquido
			
			parte_inteira = (int)salario_liquido;
			parte_frac = salario_liquido - parte_inteira;
			if(parte_frac >= 5)
				salario_liquido_novo = salario_liquido + parte_frac;
			else 
				salario_liquido_novo = parte_inteira;
			
		}
		else if(toupper(categoria) == 'A')
		{
			if(toupper(sexo) == FEMENINO)
			{
				if(amamentar == 1)
				{
					nova_hora_lei = HORALEI - 2;
				}
			}
		}
		printf("\n Digite 1 - Para acessar: "); scanf("%d", &access);
	}
	/*************************************************************************************/
	
	/*************************************************************************************/
	
	///////////////////
	system("pause");//
	return 0;////////
	////////////////
}
