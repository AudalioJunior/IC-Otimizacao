#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 10

//Estrutura do problema
typedef struct t
{
	int id;
	int custo;
	int pred[2];
} tarefa;

//Estrutura da solução
typedef struct s
{
	int id;
	int custo;
	int pred[2];
	int tl;
} solucao;

//Cadidatos e solução
void gerar(tarefa *proj){
	
	tarefa candidatos[MAX];
	int aux = 0;
			while (aux != MAX)
			{
				if(proj[aux].pred[0] == -1){
					candidatos[aux].id = proj[aux].id;
					candidatos[aux].pred[0] = proj[aux].pred[0];
					candidatos[aux].pred[1] = proj[aux].pred[1];
					candidatos[aux].pred[2] = proj[aux].pred[2];
					printf("%d", candidatos[aux].id);
				}
				aux++;
			}
}

//Programa
int main(void)
{
	tarefa proj[MAX];
	int op = 4;

	while (op != 0)
	{
		printf("------------Menu de operacoes------------ \n");
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
			proj[1].pred[0] = -1;
			proj[1].pred[1] = -1;
			proj[1].pred[2] = -1;
			proj[1].custo = 4;

			proj[2].id = 2;
			proj[2].pred[0] = -1;
			proj[2].pred[1] = -1;
			proj[2].pred[2] = -1;
			proj[2].custo = 10;

			proj[3].id = 3;
			proj[3].pred[0] = -1;
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
			proj[7].pred[2] = 0;
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
