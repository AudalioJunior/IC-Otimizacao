#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct w
{
    int id;
    int cost;
    int pred[2];
    int add;
}Work;

typedef struct s
{
    int id;
    int begin;
    int end;
}Solution;

void generate(Work *proj);

//Main Program
int main(void){
    
    Work proj[MAX];

    proj[0].id = 0;
    proj[0].cost = -1;

    proj[1].id = 1;
    proj[1].cost = 3;
    proj[1].pred[0] = 0;
    proj[1].pred[1] = -1;
    proj[1].pred[2] = -1;

    proj[2].id = 2;
    proj[2].cost = 5;
    proj[2].pred[0] = 0;
    proj[2].pred[1] = -1;
    proj[2].pred[2] = -1;

    proj[3].id = 3;
    proj[3].cost = 2;
    proj[3].pred[0] = 2;
    proj[3].pred[1] = -1;
    proj[3].pred[2] = -1;

    proj[4].id = 4;
    proj[4].cost = 2;
    proj[4].pred[0] = 1;
    proj[4].pred[1] = -1;
    proj[4].pred[2] = -1;

    proj[5].id = 5;
    proj[5].cost = 7;
    proj[5].pred[0] = 3;
    proj[5].pred[1] = 4;
    proj[5].pred[2] = -1;

    proj[6].id = -99;
    proj[6].cost = -1;
    proj[6].pred[0] = 5;
    proj[6].pred[1] = -1;
    proj[6].pred[2] = -1;

    generate(&proj);
}

//Function generate of solution

void generate(Work *proj){

    Work available[MAX];
    Solution result[MAX];
    int i, aux1;

    // Initial variables
    i = 0;
    while (i < MAX)
    {
        available[i].id = -1;
        i++;
        printf("Acabou \n");
    }
    
    // First cases Begin and End (verify 'B' and 'E')

};