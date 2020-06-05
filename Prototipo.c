#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 10


typedef struct t{
	int id;
	int custo;
	int pred[2];
}tarefa;

typedef struct s{
	int custo;
	int pred [2];
	int tf;
}

void alimentar(*solution){
	i = 0
	while (i <= 10)
	{
		solution[i] = -1;
		i++;
	}
	
}

//Programa
int main(void){
	tarefa proj[MAX];
	int op = 4;

	
	while(op != 0){
	printf("------------Menu de operacoes------------ \n");
	printf("1 Inserir proj \n");
	printf("2 Testar \n");
	printf("3 Gerar arquivo \n");
	printf("0 Sair \n");
	printf("Digite a operacao: \n");
	scanf("%d", &op);
	
	if(op == 1){
		proj[0].pred[0] = -1;
		proj[0].pred[1] = -1;
		proj[0].pred[2] = -1;
		proj[0].custo = -1;

		proj[1].pred[0] = 0;
		proj[1].pred[1] = 0;
		proj[1].pred[2] = 0;
		proj[1].custo = 4;

		proj[2].pred[0] = 0;
		proj[2].pred[1] = 0;
		proj[2].pred[2] = 0;	
		proj[2].custo = 10;

		proj[3].pred[0] = 0;
		proj[3].pred[1] = 0;
		proj[3].pred[2] = 0;
		proj[3].custo = 5;

		proj[4].pred[0] = 1;
		proj[4].pred[1] = 0;
		proj[4].pred[2] = 0;
		proj[4].custo = 1;

		proj[5].pred[0] = 1;
		proj[5].pred[1] = 0;
		proj[5].pred[2] = 0;
		proj[5].custo = 5;

		proj[6].pred[0] = 2;
		proj[6].pred[1] = 0;
		proj[6].pred[2] = 0;
		proj[6].custo = 7;

		proj[7].pred[0] = 2;
		proj[7].pred[1] = 0;
		proj[7].pred[2] = 0;
		proj[7].custo = 4;

		proj[8].pred[0] = 2;
		proj[8].pred[1] = 0;
		proj[8].pred[2] = 0;
		proj[8].custo = 3;

		proj[9].pred[0] = 4;
		proj[9].pred[1] = 6;
		proj[9].pred[2] = 0;
		proj[9].custo = 2;

		proj[10].pred[0] = 5;
		proj[10].pred[1] = 7;
		proj[10].pred[2] = 9;
		proj[10].custo = 2;
		}
	if(op == 2){
		printf("%d", proj[9].custo);
	}
	}
}

