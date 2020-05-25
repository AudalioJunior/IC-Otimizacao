#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 9


typedef struct t{
	int custo;
	int pred[2];
}tarefa;

//Programa
int main(void){
	tarefa proj[MAX];
	int op = 4;
	
	while(op != 0){
	printf("------------Menu de operacoes------------ \n");
	printf("1 Inserir proj \n");
	printf("2 Otimizar \n");
	printf("3 Gerar arquivo \n");
	printf("0 Sair \n");
	printf("Digite a operacao: \n");
	scanf("%d", &op);
	
	if(op == 1){
		proj[0].pred[0] = 0;
		proj[0].pred[1] = 0;
		proj[0].pred[2] = 0;
		proj[0].custo = 4;

		proj[1].pred[0] = 0;
		proj[1].pred[1] = 0;
		proj[1].pred[2] = 0;	
		proj[1].custo = 10;

		proj[2].pred[0] = 0;
		proj[2].pred[1] = 0;
		proj[2].pred[2] = 0;
		proj[2].custo = 5;

		proj[3].pred[0] = 1;
		proj[3].pred[1] = 0;
		proj[3].pred[2] = 0;
		proj[3].custo = 1;

		proj[4].pred[0] = 1;
		proj[4].pred[1] = 0;
		proj[4].pred[2] = 0;
		proj[4].custo = 5;

		proj[5].pred[0] = 2;
		proj[5].pred[1] = 0;
		proj[5].pred[2] = 0;
		proj[5].custo = 7;

		proj[6].pred[0] = 2;
		proj[6].pred[1] = 0;
		proj[6].pred[2] = 0;
		proj[6].custo = 4;

		proj[7].pred[0] = 2;
		proj[7].pred[1] = 0;
		proj[7].pred[2] = 0;
		proj[7].custo = 3;

		proj[8].pred[0] = 4;
		proj[8].pred[1] = 6;
		proj[8].pred[2] = 0;
		proj[8].custo = 2;

		proj[9].pred[0] = 5;
		proj[9].pred[1] = 7;
		proj[9].pred[2] = 9;
		proj[9].custo = 2;
		}
	if(op == 2){
		printf("%d", proj[9].custo);
	}
	}
}

