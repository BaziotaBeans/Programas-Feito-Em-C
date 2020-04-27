/******************************************************
*******************************************************
**	Autor: Fábio Aristóteles Fernando Baziota		 **
**	Data: 10/05/2017                                 **
**	Id: 1000017079									 **
**	Ficheiro: FolhaDeSalarios                        **
**	Objectivo: Imprimir o a folha de salario         **
**	Entrada: Dados do trabalhador                    **
**	Saída: A respectiva folha de sálario             **
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
	/*****************************DECLARAÇÕES DAS VARIÁVEIS********************************************************************************/
	int codTrab, num_horas_mes, amamentar, num_pro_r, access, horasExtra = 0, idade_Filho, horasFalta = 0, amam = 0, cat = 0, sex = 0, tur=0;
	const int HORALEI = 176;
	const float SALMINIMO = 30000.00;
	char nomeTrab[TAM], sexo, categoria, turno;
	float salario_base = 0.0, salario_bruto = 0.0, salario_liquido = 0.0, subsidio = 0.0, subsidio_amamentacao = 0.0, salario_inicial = 0.0;
	float valor_hora_trabalho = 0.0, faltas = 0.0, desconto_seg_social = 0.0, parte_frac = 0.0, desconto_hora = 0.0;
	int parte_inteira = 0, salario_liquido_novo = 0, nova_hora_lei = 174, salario_por_hora = 0.0;
	
	/*****************************FIM DAS DECLARAÇÕES**************************************************************************************/
	printf("\t\t\t\t UCANSOFT 1.0\n");
	printf("\n Digite 1 - Para acessar: "); scanf("%d", &access);
	
	while(access == ACCESS) //condição responsável pelo acesso do programa
	{
		/*                                                                                             LEITURA dos dados                                                       */
		system("cls");
		printf("\n Digite o Código do trabalhador: "); scanf("%d", &codTrab);
		setbuf(stdin, NULL);
		//fflush(stdin);
		printf("\n Digite o nome do trabalhador/a: "); gets(nomeTrab);
		setbuf(stdin, NULL);
		
		printf("\n Digite o Número de horas trabalhadas no mês: "); scanf("%d", &num_horas_mes);
		while(num_horas_mes <= 0)
		{
			printf("\n ERRO: Campo Hora invalida\n Digite o Número de horas trabalhadas no mês: "); scanf("%d", &num_horas_mes);
		}
		setbuf(stdin, NULL);
		printf("\n  _________________________");
		printf("\n |Digite T para Técnico    | ");
		printf("\n |Digite P para Programador| ");
		printf("\n |Digite A para Analista   | ");
		printf("\n |Digite G para Gestor     | ");
		printf("\n |Digite a categoria: "); scanf("%c", &categoria);
		printf("\n  -------------------");
		setbuf(stdin, NULL);
		///////////////////////////////Condição para avaliar as categorias//////////////////////////////////////
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
		}/////////////////////////////// FIM da Condição para avaliar as categorias//////////////////////////////////////
		printf("\n  ____________________________");
		printf("\n |Digite F para sexo Femenino | ");
		printf("\n |Digite M para sexo Masculino| ");
		printf("\n |Digite o Sexo: "); scanf("%c", &sexo);
		printf("\n  -------------------");
		setbuf(stdin, NULL);
		while(sex == 0)/////////////////////////////// Condição para avaliar o sexo //////////////////////////////////////
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
		}/////////////////////////////// FIM da Condição para avaliar o sexo //////////////////////////////////////
		
		printf("\n Digite o números de projectos realizados: "); scanf("%d", &num_pro_r);
		setbuf(stdin, NULL);
		while(num_pro_r < 0) /////////////////////////////// Condição para avaliar os projectos realizados com sucesso //////////////////////////////////////
		{
			printf("\n ERRO: Número invalido!!");
			printf("\n Digite novamente o números de projectos realizados: "); scanf("%d", &num_pro_r);
			setbuf(stdin, NULL);
		}  /////////////////////////////// FIM da Condição para avaliar os projectos realizados com sucesso //////////////////////////////////////
		
		/*                                                                               fim da entrada de dados                                                                                 */
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if(toupper(categoria) == 'G') //avalição da categoria Gestor de Projectos
		{
			salario_inicial = 8*SALMINIMO;
			if(toupper(sexo) == FEMENINO)
			{
				printf("\n  _____________________________");
				printf("\n |Vai amamentar                |");
				printf("\n |Digite 1(SIM) ou 0(Não):     |"); scanf("%d", &amamentar);
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
						printf("\n |ERRO: Opção Invalida\n Digite Novamente \n Vai Amamentar|");
						printf("\n |Digite 1(SIM) ou 0(Não):     "); scanf("%d", &amamentar);	
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
						
					salario_bruto = salario_base + subsidio - faltas; //fórmula para calcular o sálario bruto
					desconto_seg_social = 0.5 * salario_bruto; //fórmula para calculaf o desconto de segurança social
					salario_liquido = salario_bruto - desconto_seg_social; //fórmula para calcular o sálario liquido
					
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
					subsidio = salario_por_hora * 7.5; //fórmula para calcular subsídio de chefia
					
					faltas = (horasFalta*100)/176; //fórmula para calcular as falta em percentagem
				
					if(faltas <= 0.02)
						subsidio = num_pro_r *(valor_hora_trabalho* 0.3); //fórmula para calcular o subsídio por cada projecto
		
					subsidio = num_pro_r *(salario_por_hora* 0.3); //fórmula para calcular o subsídio por cada projecto
					
					salario_bruto = salario_base + subsidio - faltas; //fórmula para calcular o sálario bruto
					desconto_seg_social = 0.5 * salario_bruto; //fórmula para calculaf o desconto de segurança social
					salario_liquido = salario_bruto - desconto_seg_social; //fórmula para calcular o sálario liquido
					
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
				subsidio = salario_por_hora * 7.5; //fórmula para calcular subsídio de chefia
				
				faltas = (horasFalta*100)/176; //fórmula para calcular as falta em percentagem
			
				if(faltas <= 0.02)
					subsidio = num_pro_r *(valor_hora_trabalho* 0.3); //fórmula para calcular o subsídio por cada projecto
	
				subsidio = num_pro_r *(salario_por_hora* 0.3); //fórmula para calcular o subsídio por cada projecto
				
				salario_bruto = salario_base + subsidio - faltas; //fórmula para calcular o sálario bruto
				desconto_seg_social = 0.5 * salario_bruto; //fórmula para calculaf o desconto de segurança social
				salario_liquido = salario_bruto - desconto_seg_social; //fórmula para calcular o sálario liquido
				
				parte_inteira = (int)salario_liquido;
				parte_frac = salario_liquido - parte_inteira;
				if(parte_frac >= 5)
					salario_liquido_novo = salario_liquido + parte_frac;
				else                                                    
					salario_liquido_novo = parte_inteira;
				
			}
		}
		else if(toupper(categoria) == 'A') //avalição da categoria Analista de Sistemas
		{
			if(toupper(sexo) == FEMENINO)
			{
				////////////IMPLEMENTAÇÃO/////////////////
			}
			if(toupper(sexo) == MASCULINO)
			{
				////////////IMPLEMENTAÇÃO///////////////
			}
		}
		
		else if(toupper(categoria) == 'P') //avalição da categoria Programador de Aplicações
		{
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
				printf("\n |Digite 1(SIM) ou 0(Não):     |"); scanf("%d", &amamentar);
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
						printf("\n |ERRO: Opção Invalida\n Digite Novamente \n Vai Amamentar|");
						printf("\n |Digite 1(SIM) ou 0(Não):     "); scanf("%d", &amamentar);	
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
							
						salario_bruto = salario_base + subsidio - faltas; //fórmula para calcular o sálario bruto
						desconto_seg_social = 0.5 * salario_bruto; //fórmula para calculaf o desconto de segurança social
						salario_liquido = salario_bruto - desconto_seg_social; //fórmula para calcular o sálario liquido
						
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
					
					faltas = (horasFalta*100)/176; //fórmula para calcular as falta em percentagem
				
					if(faltas <= 0.02)
						subsidio = num_pro_r *(valor_hora_trabalho* 0.3); //fórmula para calcular o subsídio por cada projecto
		
					subsidio = num_pro_r *(salario_por_hora* 0.3); //fórmula para calcular o subsídio por cada projecto
					
					salario_bruto = salario_base + subsidio - faltas; //fórmula para calcular o sálario bruto
					desconto_seg_social = 0.5 * salario_bruto; //fórmula para calculaf o desconto de segurança social
					salario_liquido = salario_bruto - desconto_seg_social; //fórmula para calcular o sálario liquido
					
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
				////////////IMPLEMENTAÇÃO///////////////
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(toupper(categoria) == 'T') //avalição da categoria TÉCNICO DE SUPORTE
		{
			
			salario_inicial = 3*SALMINIMO;
			/////////////////////////////////////////////////////////////////////////
			printf("\n  ___________________");
			printf("\n |Digite T para Tarde| ");
			printf("\n |Digite N para Noite| ");
			printf("\n |Digite M para Manhã| ");
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
					printf("\n |Digite M para Manhã| ");
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
				printf("\n |Digite 1(SIM) ou 0(Não):     |"); scanf("%d", &amamentar);
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
						printf("\n |ERRO: Opção Invalida\n Digite Novamente \n Vai Amamentar|");
						printf("\n |Digite 1(SIM) ou 0(Não):     "); scanf("%d", &amamentar);	
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
							
						salario_bruto = salario_base + subsidio - faltas; //fórmula para calcular o sálario bruto
						desconto_seg_social = 0.5 * salario_bruto; //fórmula para calculaf o desconto de segurança social
						salario_liquido = salario_bruto - desconto_seg_social; //fórmula para calcular o sálario liquido
						
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
					
					faltas = (horasFalta*100)/176; //fórmula para calcular as falta em percentagem
				
					if(faltas <= 0.02)
						subsidio = num_pro_r *(valor_hora_trabalho* 0.3); //fórmula para calcular o subsídio por cada projecto
		
					subsidio = num_pro_r *(salario_por_hora* 0.3); //fórmula para calcular o subsídio por cada projecto
					
					salario_bruto = salario_base + subsidio - faltas; //fórmula para calcular o sálario bruto
					desconto_seg_social = 0.5 * salario_bruto; //fórmula para calculaf o desconto de segurança social
					salario_liquido = salario_bruto - desconto_seg_social; //fórmula para calcular o sálario liquido
					
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
				////////////IMPLEMENTAÇÃO///////////////
			}
		} 
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		/*                                                       AREA Responsável pela impressão da folha do salario                                        */
		
		system("cls");
		printf(" _______________________________________________________________________\n");
		printf("|\t\t\tFOLHA DE SALÁRIOS                                                ");
		printf("\n|NOME: %s                                                             ", nomeTrab);
		printf("\n|CÓDIGO: %d                                                           ", codTrab);
		printf("\n|SALÁRIO BASE: %.2f AKZ                                               ", salario_base);
		printf("\n|SALÁRIO POR HORA: %.2f AKZ                                           ", salario_por_hora);
		printf("\n|SUBSÍDIO: %.2f AKZ                                                   ", subsidio);
		printf("\n|SUBSÍDIO DE AMAMENTAÇÃO: %.2f AKZ                                    ", subsidio_amamentacao);
		printf("\n|SALÁRIO BRUTO: %.2f AKZ                                              ", salario_bruto);
		printf("\n|DESCONTO DA SEGURANÇA SOCIAL: %.2f AKZ                               ", desconto_seg_social);
		printf("\n|SALÁRIO LIQUIDO: %d AKZ                               	 			", salario_liquido_novo);
		printf("\n _____________________________________________________________________");
		
		/*                                                        FIM da AREA Responsável pela impressão da folha do salario                                */
		printf("\n Digite 1 - Para acessar: "); scanf("%d", &access);
	}
	/*************************************************************************************/
	
	/*************************************************************************************/
	
	///////////////////              
	system("pause");//
	return 0;////////
	////////////////
}
