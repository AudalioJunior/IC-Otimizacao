#include <stdio.h>
#include <stdlib.h>

#define MAX 10

//Estrutura do problema
typedef struct t
{
	int id;
	int custo;
	int pred[2];
	int add;
	int verificar;
} tarefa;

//Estrutura da solução
typedef struct s
{
	int id;
	int inicio;
	int fim;
} Solucao;

//Menor custo
int menor(int custo1, int custo2)
{
	if (custo1 > custo2)
	{
		return custo1;
	}
	else
	{
		return custo2;
	}
}

//Cadidatos e solução
void gerar(tarefa *proj)
{
	int i;
	int j;
	int k, m, n, l, dec, test;
	tarefa candidatos[MAX];
	Solucao solucao[MAX];

	

	//Incializar tarefas

	k = 0;
	while (k < MAX)
	{
		candidatos[k].id = -1;
		solucao[k].id = -1;
		k++;
	}

	// posicao 0
	i = 0;
	candidatos[0].id = 0;
	candidatos[0].add = 0;

	// preenchendo os verificados (auxilio na atualizacao dos candidatos)
	j = 0;
	while (j <= MAX)
	{
		proj[j].verificar = 0;
		j++;
	}
	
	j = 0;
	k = 0;
	while (j <= MAX)
	{
		k = 0;
		if (proj[j].pred[k] == -1)
		{
			proj[j].verificar = 0;
		}else
		{
			while (k <= 2)
			{
				if (proj[j].pred[k] != -1)
				{
					proj[j].verificar++;
					k++;
				}else
				{
					k++;
				}
			}
			
		}
		j++;
	}
	

	//Candidatos nulos
	while (i <= MAX)
	{
		if (proj[i].pred[0] == 0)
		{
			candidatos[i].id = proj[i].id;
			candidatos[i].pred[0] = proj[i].pred[0];
			candidatos[i].pred[1] = proj[i].pred[1];
			candidatos[i].pred[2] = proj[i].pred[2];
			candidatos[i].custo = proj[i].custo;
			candidatos[i].add = 0;
			i++;
		}
		else
		{
			i++;
		}
	}

	//Resolução dos candidatos
	i = 0;
	n = 0;
	while (i <= MAX)
	{
		
		
		//Verifica se está na lista
		if (candidatos[i].id != -1)
		{
			//Verifica se é nulo (O caso só ocorrerá uma vez)
			if (candidatos[i].add == 0)
			{
				if (candidatos[i].id == 0)
				{
					solucao[i].id = 0;
					solucao[i].inicio = 0;
					solucao[i].fim = 0;
					candidatos[i].add = 1;
					i++;
				}
				else
				{
					
					//Garante que meu [n], será uma pos de comparação
					while (candidatos[n].add != 0)
					{
						n++;
					}
			
					//Verifica quem possui o menor custo
					if (candidatos[i].custo <= candidatos[n].custo)
					{
						n = candidatos[i].id;
						i++;
						
						
					}
					else
					{
						i++;
					}
				}
			}
			else
			{
				i++;
			}

		}
		else
		{
			
			// Não permite repições na minha solução
			if (candidatos[n].add == 0)
			{

				// Deixa sempre na ultima posicao
				k = 0;
				while (solucao[k].id != -1)
				{
					k++;
				}

				//Alimentando a solucao
				solucao[k].id = candidatos[n].id;
				solucao[k].inicio = solucao[k - 1].fim; // resolver esse problema
				solucao[k].fim = solucao[k].inicio + candidatos[n].custo;
				candidatos[n].add = 1;

				////////Atualização os candidatos/////////

				m = 0;
				dec = 0;
				while (m <= MAX)
				{	
					//Projeto já add na lista de candidatos
					if (proj[m].id == candidatos[m].id)
					{
						m++;
					}else
					{
						if (proj[m].verificar != 0)
						{
							
							//Processo de decisão
							j = 0;
							
							while (j <= 2)
							{
								l = 0;
								while (solucao[l].id != -1)
								{
									
									if (proj[m].pred[j] == solucao[l].id)
									{
										
										dec++;
										l++;
									}else
									{
										l++;
									}
								}
								j++;
							}
							
							
							//adicao a lista de candidatos
							if (dec == proj[m].verificar)
							{
							
								candidatos[m].id = proj[m].id;
								candidatos[m].pred[0] = proj[m].pred[0];
								candidatos[m].pred[1] = proj[m].pred[0];
								candidatos[m].pred[2] = proj[m].pred[0];
								candidatos[m].custo = proj[m].custo;
								candidatos[m].add = 0;
							}

							
							m++;
							dec = 0;
							
						}else
						{
							m++;
						}
												
					}
				}
					
		
				// FIM
				i = 0;
			}
			else
			{
				i++;
			}
		}
	}
	

	k = 0;
	while (k <= MAX)
	{
		printf("%d ", solucao[k].id);
		k++;
	}
	
}

//Programa
int main(void)
{
	tarefa proj[MAX];
	int op = 4;

	while (op != 0)
	{
		printf("\n------------Menu de operacoes------------\n");
		printf("1 Inserir proj \n");
		printf("2 Testar \n");
		printf("3 Gerar arquivo \n");
		printf("0 Sair \n");
		printf("Digite a operacao: \n");
		scanf("%d", &op);

		if (op == 1)
		{
			proj[0].id = 0;
			proj[0].pred[0] = -1;
			proj[0].pred[1] = -1;
			proj[0].pred[2] = -1;
			proj[0].custo = -1;

			proj[1].id = 1;
			proj[1].pred[0] = 0;
			proj[1].pred[1] = -1;
			proj[1].pred[2] = -1;
			proj[1].custo = 4;

			proj[2].id = 2;
			proj[2].pred[0] = 0;
			proj[2].pred[1] = -1;
			proj[2].pred[2] = -1;
			proj[2].custo = 10;

			proj[3].id = 3;
			proj[3].pred[0] = 0;
			proj[3].pred[1] = -1;
			proj[3].pred[2] = -1;
			proj[3].custo = 5;

			proj[4].id = 4;
			proj[4].pred[0] = 1;
			proj[4].pred[1] = -1;
			proj[4].pred[2] = -1;
			proj[4].custo = 1;

			proj[5].id = 5;
			proj[5].pred[0] = 1;
			proj[5].pred[1] = -1;
			proj[5].pred[2] = -1;
			proj[5].custo = 5;

			proj[6].id = 6;
			proj[6].pred[0] = 2;
			proj[6].pred[1] = -1;
			proj[6].pred[2] = -1;
			proj[6].custo = 7;

			proj[7].id = 7;
			proj[7].pred[0] = 2;
			proj[7].pred[1] = -1;
			proj[7].pred[2] = -1;
			proj[7].custo = 4;

			proj[8].id = 8;
			proj[8].pred[0] = 2;
			proj[8].pred[1] = -1;
			proj[8].pred[2] = -1;
			proj[8].custo = 3;

			proj[9].id = 9;
			proj[9].pred[0] = 4;
			proj[9].pred[1] = 6;
			proj[9].pred[2] = -1;
			proj[9].custo = 2;

			proj[10].id = 10;
			proj[10].pred[0] = 5;
			proj[10].pred[1] = 7;
			proj[10].pred[2] = 9;
			proj[10].custo = 2;
		}

		if (op == 2)
		{
			gerar(proj);
		}
	}
}
