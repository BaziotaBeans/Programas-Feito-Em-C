/******************************************************
*******************************************************
**	Autor: F�bio Arist�teles Fernando Baziota		 **
**	Data: 10/05/2017                                 **
**	Id: 1000017079									 **
**	Ficheiro: FolhaDeSalarios                        **
**	Objectivo: Imprimir o a folha de salario         **
**	Entrada: Dados do trabalhador                    **
**	Sa�da: A respectiva folha de s�lario             **
/*****************************************************/
/*****************************************************/
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
	/*****************************DECLARA��ES DAS VARI�VEIS********************************************************************************/
	int codTrab, num_horas_mes, amamentar, num_pro_r, access, horasExtra = 0, idade_Filho, horasFalta = 0, amam = 0, cat = 0, sex = 0, tur=0;
	const int HORALEI = 176;
	const float SALMINIMO = 30000.00;
	char nomeTrab[TAM], sexo, categoria, turno;
	float salario_base = 0.0, salario_bruto = 0.0, salario_liquido = 0.0, subsidio = 0.0, subsidio_amamentacao = 0.0, salario_inicial = 0.0;
	float valor_hora_trabalho = 0.0, faltas = 0.0, desconto_seg_social = 0.0, parte_frac = 0.0, desconto_hora = 0.0;
	int parte_inteira = 0, salario_liquido_novo = 0, nova_hora_lei = 174, salario_por_hora = 0.0;
	
	/*****************************FIM DAS DECLARA��ES**************************************************************************************/
	printf("\t\t\t\t UCANSOFT 1.0\n");
	printf("\n Digite 1 - Para acessar: "); scanf("%d", &access);
	
	while(access == ACCESS) //condi��o respons�vel pelo acesso do programa
	{
		/*                                                                                             LEITURA dos dados                                                       */
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
		printf("\n  _________________________");
		printf("\n |Digite T para T�cnico    | ");
		printf("\n |Digite P para Programador| ");
		printf("\n |Digite A para Analista   | ");
		printf("\n |Digite G para Gestor     | ");
		printf("\n |Digite a categoria: "); scanf("%c", &categoria);
		printf("\n  -------------------");
		setbuf(stdin, NULL);
		///////////////////////////////Condi��o para avaliar as categorias//////////////////////////////////////
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
				printf("\n |Digite T para T�cnico    | ");
				printf("\n |Digite P para Programador| ");
				printf("\n |Digite A para Analista   | ");
				printf("\n |Digite G para Gestor     | ");
				printf("\n |Digite a categoria: "); scanf("%c", &categoria);
				setbuf(stdin, NULL);
				printf("\n  -------------------");	
				setbuf(stdin, NULL);
			}	
		}/////////////////////////////// FIM da Condi��o para avaliar as categorias//////////////////////////////////////
		printf("\n  ____________________________");
		printf("\n |Digite F para sexo Femenino | ");
		printf("\n |Digite M para sexo Masculino| ");
		printf("\n |Digite o Sexo: "); scanf("%c", &sexo);
		printf("\n  -------------------");
		setbuf(stdin, NULL);
		while(sex == 0)/////////////////////////////// Condi��o para avaliar o sexo //////////////////////////////////////
		{
			if(toupper(sexo) == FEMENINO)
					sex = 1;
			else if(toupper(sexo) == MASCULINO)
					sex = 1;
			else
			{
				printf("\n  ____________________________");
				printf("\n |Digite F para sexo Femenino | ");
				printf("\n |Digite M para sexo Masculino| ");
				printf("\n |Digite o Sexo: "); scanf("%c", &sexo);
				printf("\n  -------------------");
				setbuf(stdin, NULL);	
			}
		}/////////////////////////////// FIM da Condi��o para avaliar o sexo //////////////////////////////////////
		
		printf("\n Digite o n�meros de projectos realizados: "); scanf("%d", &num_pro_r);
		setbuf(stdin, NULL);
		while(num_pro_r < 0) /////////////////////////////// Condi��o para avaliar os projectos realizados com sucesso //////////////////////////////////////
		{
			printf("\n ERRO: N�mero invalido!!");
			printf("\n Digite novamente o n�meros de projectos realizados: "); scanf("%d", &num_pro_r);
			setbuf(stdin, NULL);
		}  /////////////////////////////// FIM da Condi��o para avaliar os projectos realizados com sucesso //////////////////////////////////////
		
		/*                                                                               fim da entrada de dados                                                                                 */
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if(toupper(categoria) == 'G') //avali��o da categoria Gestor de Projectos
		{
			salario_inicial = 8*SALMINIMO;
			if(toupper(sexo) == FEMENINO)
			{
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
						printf("\n  ________________________________________________________");
						printf("\n |ERRO: Op��o Invalida\n Digite Novamente \n Vai Amamentar|");
						printf("\n |Digite 1(SIM) ou 0(N�o):     "); scanf("%d", &amamentar);	
					}
				}
				if(amamentar == 1)
				{
					//salario_base = salario_inicial*num_horas_mes;
					salario_por_hora = (salario_inicial*num_horas_mes)/nova_hora_lei;
					salario_base = salario_por_hora/nova_hora_lei;
					subsidio = salario_por_hora * 7.5;
					if(num_horas_mes < nova_hora_lei)
					{
						horasFalta = nova_hora_lei - num_horas_mes;
						desconto_hora = (salario_inicial*horasFalta)/nova_hora_lei;
						salario_base -= desconto_hora;
						salario_por_hora -= desconto_hora;
					}
					if(salario_inicial <= 30000)
							subsidio_amamentacao = 0.06*salario_base; 
					else if(salario_inicial >= 30000)
					if(salario_inicial <= 60000)
							subsidio_amamentacao = salario_base * 0.05;
					else if(salario_inicial >= 60000)
					if(salario_inicial <= 90000)
							subsidio_amamentacao = salario_base * 0.04;
					else 
						subsidio_amamentacao = salario_base * 0.03;
						
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
				if(amamentar == 0)
				{
					//salario_base = salario_inicial*num_horas_mes;
					salario_por_hora = (salario_inicial*num_horas_mes)/HORALEI;
					salario_base = salario_por_hora/nova_hora_lei;
					if(num_horas_mes < HORALEI)
					{
						horasFalta = HORALEI - num_horas_mes;
						desconto_hora = (salario_inicial*horasFalta)/nova_hora_lei;
						salario_base -= desconto_hora;
						salario_por_hora -= desconto_hora;
					}
					
					if(num_horas_mes > HORALEI) 
					{
						horasExtra = num_horas_mes - HORALEI;
						desconto_hora = (salario_inicial*horasExtra)/nova_hora_lei;
						salario_base += desconto_hora;
						salario_por_hora += desconto_hora;
					}
					subsidio = salario_por_hora * 7.5; //f�rmula para calcular subs�dio de chefia
					
					faltas = (horasFalta*100)/176; //f�rmula para calcular as falta em percentagem
				
					if(faltas <= 0.02)
						subsidio = num_pro_r *(valor_hora_trabalho* 0.3); //f�rmula para calcular o subs�dio por cada projecto
		
					subsidio = num_pro_r *(salario_por_hora* 0.3); //f�rmula para calcular o subs�dio por cada projecto
					
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
			}
			if(toupper(sexo) == MASCULINO)
			{
				//salario_base = salario_inicial*num_horas_mes;
				salario_por_hora = (salario_inicial*num_horas_mes)/HORALEI;
				salario_base = salario_por_hora/nova_hora_lei;
				if(num_horas_mes < HORALEI)
				{
					horasFalta = HORALEI - num_horas_mes;
					desconto_hora = (salario_inicial*horasFalta)/nova_hora_lei;
					salario_base -= desconto_hora;
					salario_por_hora -= desconto_hora;
				}
				
				if(num_horas_mes > HORALEI) 
				{
					horasExtra = num_horas_mes - HORALEI;
					desconto_hora = (salario_inicial*horasExtra)/nova_hora_lei;
					salario_base += desconto_hora;
					salario_por_hora += desconto_hora;
				}
				subsidio = salario_por_hora * 7.5; //f�rmula para calcular subs�dio de chefia
				
				faltas = (horasFalta*100)/176; //f�rmula para calcular as falta em percentagem
			
				if(faltas <= 0.02)
					subsidio = num_pro_r *(valor_hora_trabalho* 0.3); //f�rmula para calcular o subs�dio por cada projecto
	
				subsidio = num_pro_r *(salario_por_hora* 0.3); //f�rmula para calcular o subs�dio por cada projecto
				
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
		}
		else if(toupper(categoria) == 'A') //avali��o da categoria Analista de Sistemas
		{
			if(toupper(sexo) == FEMENINO)
			{
				////////////IMPLEMENTA��O/////////////////
			}
			if(toupper(sexo) == MASCULINO)
			{
				////////////IMPLEMENTA��O///////////////
			}
		}
		
		else if(toupper(categoria) == 'P') //avali��o da categoria Programador de Aplica��es
		{
			printf("\n  ____________________________");
			printf("\n |Digite T para Tarde			| ");
			printf("\n |Digite N para Noite			| ");
			printf("\n |Digite M para Manh�			| ");
			printf("\n |Digite M para Manh�         | ");
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
					printf("\n |Digite M para Manh�			| ");
					printf("\n |Digite M para Manh�         | ");
					printf("\n |Digite I para Tempo Integral| ");
					printf("\n |Digite o turno: ");scanf("%c", &turno);
					setbuf(stdin, NULL); 
					printf("\n  -------------------");
					setbuf(stdin, NULL);
				}
				
			}
			
			if(toupper(turno) == 'T')
			{
				salario_por_hora = 0.95*((salario_inicial*num_horas_mes)/HORALEI); //Duvida
				salario_base = salario_por_hora/nova_hora_lei;
			}
			if(toupper(turno) == 'N')
			{
				salario_por_hora = 1*((salario_inicial*num_horas_mes)/HORALEI); //Duvida
				salario_base = salario_por_hora/nova_hora_lei;
			}
			if(toupper(turno) == 'M')
			{
				salario_por_hora = 0.95*((salario_inicial*num_horas_mes)/HORALEI); //Duvida
				salario_base = salario_por_hora/nova_hora_lei;
			}
			if(toupper(turno) == 'I')
			{
				salario_por_hora = 1*((salario_inicial*num_horas_mes)/HORALEI); //Duvida
				salario_base = salario_por_hora/nova_hora_lei;
			}
			
			if(toupper(sexo) == FEMENINO)
			{
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
						printf("\n  ________________________________________________________");
						printf("\n |ERRO: Op��o Invalida\n Digite Novamente \n Vai Amamentar|");
						printf("\n |Digite 1(SIM) ou 0(N�o):     "); scanf("%d", &amamentar);	
					}
					
				}
				if(amamentar == 1)
				{
						//salario_base = salario_inicial*num_horas_mes;
						salario_por_hora = (salario_inicial*num_horas_mes)/nova_hora_lei;
						salario_base = salario_por_hora/nova_hora_lei;
						if(num_horas_mes < nova_hora_lei)
						{
							horasFalta = nova_hora_lei - num_horas_mes;
							desconto_hora = (salario_inicial*horasFalta)/nova_hora_lei;
							salario_base -= desconto_hora;
							salario_por_hora -= desconto_hora;
						}
						if(salario_inicial <= 30000)
								subsidio_amamentacao = 0.06*salario_base; 
						else if(salario_inicial >= 30000)
						if(salario_inicial <= 60000)
								subsidio_amamentacao = salario_base * 0.05;
						else if(salario_inicial >= 60000)
						if(salario_inicial <= 90000)
								subsidio_amamentacao = salario_base * 0.04;
						else 
							subsidio_amamentacao = salario_base * 0.03;
							
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
				if(amamentar == 0)
				{
					//salario_base = salario_inicial*num_horas_mes;
					salario_por_hora = (salario_inicial*num_horas_mes)/HORALEI;
					salario_base = salario_por_hora/nova_hora_lei;
					if(num_horas_mes < HORALEI)
					{
						horasFalta = HORALEI - num_horas_mes;
						desconto_hora = (salario_inicial*horasFalta)/nova_hora_lei;
						salario_base -= desconto_hora;
						salario_por_hora -= desconto_hora;
					}
					
					if(num_horas_mes > HORALEI) 
					{
						horasExtra = num_horas_mes - HORALEI;
						desconto_hora = (salario_inicial*horasExtra)/nova_hora_lei;
						salario_base += desconto_hora;
						salario_por_hora += desconto_hora;
					}
					
					faltas = (horasFalta*100)/176; //f�rmula para calcular as falta em percentagem
				
					if(faltas <= 0.02)
						subsidio = num_pro_r *(valor_hora_trabalho* 0.3); //f�rmula para calcular o subs�dio por cada projecto
		
					subsidio = num_pro_r *(salario_por_hora* 0.3); //f�rmula para calcular o subs�dio por cada projecto
					
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
			}
			if(toupper(sexo) == MASCULINO)
			{
				////////////IMPLEMENTA��O///////////////
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(toupper(categoria) == 'T') //avali��o da categoria T�CNICO DE SUPORTE
		{
			
			salario_inicial = 3*SALMINIMO;
			/////////////////////////////////////////////////////////////////////////
			printf("\n  ___________________");
			printf("\n |Digite T para Tarde| ");
			printf("\n |Digite N para Noite| ");
			printf("\n |Digite M para Manh�| ");
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
				else
				{
					system("cls");
					printf("\n  ERRO: Categoria Invalida\n");
					printf("\n  ___________________");
					printf("\n |Digite T para Tarde| ");
					printf("\n |Digite N para Noite| ");
					printf("\n |Digite M para Manh�| ");
					printf("\n |Digite o turno: ");scanf("%c", &turno);
					setbuf(stdin, NULL); 
					printf("\n  -------------------");
					setbuf(stdin, NULL);
				}	
			}
			
			////////////////////////////////////////////////////////////////////////////////
			if(toupper(turno) == 'T')
			{
				salario_por_hora = 0.95*((salario_inicial*num_horas_mes)/HORALEI); //Duvida
				salario_base = salario_por_hora/nova_hora_lei;
			}
			if(toupper(turno) == 'N')
			{
				salario_por_hora = 1*((salario_inicial*num_horas_mes)/HORALEI); //Duvida
				salario_base = salario_por_hora/nova_hora_lei;
			}
			if(toupper(turno) == 'M')
			{
				salario_por_hora = 0.95*((salario_inicial*num_horas_mes)/HORALEI); //Duvida
				salario_base = salario_por_hora/nova_hora_lei;
			}
								
			if(toupper(sexo) == FEMENINO)
			{
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
						printf("\n  ________________________________________________________");
						printf("\n |ERRO: Op��o Invalida\n Digite Novamente \n Vai Amamentar|");
						printf("\n |Digite 1(SIM) ou 0(N�o):     "); scanf("%d", &amamentar);	
					}
					
				}
				if(amamentar == 1)
				{
						//salario_base = salario_inicial*num_horas_mes;
						salario_por_hora = (salario_inicial*num_horas_mes)/nova_hora_lei;
						salario_base = salario_por_hora/nova_hora_lei;
						if(num_horas_mes < nova_hora_lei)
						{
							horasFalta = nova_hora_lei - num_horas_mes;
							desconto_hora = (salario_inicial*horasFalta)/nova_hora_lei;
							salario_base -= desconto_hora;
							salario_por_hora -= desconto_hora;
						}
						if(salario_inicial <= 30000)
								subsidio_amamentacao = 0.06*salario_base; 
						else if(salario_inicial >= 30000)
						if(salario_inicial <= 60000)
								subsidio_amamentacao = salario_base * 0.05;
						else if(salario_inicial >= 60000)
						if(salario_inicial <= 90000)
								subsidio_amamentacao = salario_base * 0.04;
						else 
							subsidio_amamentacao = salario_base * 0.03;
							
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
				if(amamentar == 0)
				{
					//salario_base = salario_inicial*num_horas_mes;
					salario_por_hora = (salario_inicial*num_horas_mes)/HORALEI;
					salario_base = salario_por_hora/nova_hora_lei;
					if(num_horas_mes < HORALEI)
					{
						horasFalta = HORALEI - num_horas_mes;
						desconto_hora = (salario_inicial*horasFalta)/nova_hora_lei;
						salario_base -= desconto_hora;
						salario_por_hora -= desconto_hora;
					}
					
					if(num_horas_mes > HORALEI) 
					{
						horasExtra = num_horas_mes - HORALEI;
						desconto_hora = (salario_inicial*horasExtra)/nova_hora_lei;
						salario_base += desconto_hora;
						salario_por_hora += desconto_hora;
					}
					
					faltas = (horasFalta*100)/176; //f�rmula para calcular as falta em percentagem
				
					if(faltas <= 0.02)
						subsidio = num_pro_r *(valor_hora_trabalho* 0.3); //f�rmula para calcular o subs�dio por cada projecto
		
					subsidio = num_pro_r *(salario_por_hora* 0.3); //f�rmula para calcular o subs�dio por cada projecto
					
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
			}//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(toupper(sexo) == MASCULINO)
			{
				////////////IMPLEMENTA��O///////////////
			}
		} 
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		/*                                                       AREA Respons�vel pela impress�o da folha do salario                                        */
		
		system("cls");
		printf(" _______________________________________________________________________\n");
		printf("|\t\t\tFOLHA DE SAL�RIOS                                                ");
		printf("\n|NOME: %s                                                             ", nomeTrab);
		printf("\n|C�DIGO: %d                                                           ", codTrab);
		printf("\n|SAL�RIO BASE: %.2f AKZ                                               ", salario_base);
		printf("\n|SAL�RIO POR HORA: %.2f AKZ                                           ", salario_por_hora);
		printf("\n|SUBS�DIO: %.2f AKZ                                                   ", subsidio);
		printf("\n|SUBS�DIO DE AMAMENTA��O: %.2f AKZ                                    ", subsidio_amamentacao);
		printf("\n|SAL�RIO BRUTO: %.2f AKZ                                              ", salario_bruto);
		printf("\n|DESCONTO DA SEGURAN�A SOCIAL: %.2f AKZ                               ", desconto_seg_social);
		printf("\n|SAL�RIO LIQUIDO: %d AKZ                               	 			", salario_liquido_novo);
		printf("\n _____________________________________________________________________");
		
		/*                                                        FIM da AREA Respons�vel pela impress�o da folha do salario                                */
		printf("\n Digite 1 - Para acessar: "); scanf("%d", &access);
	}
	/*************************************************************************************/
	
	/*************************************************************************************/
	
	///////////////////              
	system("pause");//
	return 0;////////
	////////////////
}
