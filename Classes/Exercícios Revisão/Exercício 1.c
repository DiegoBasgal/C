#include <stdio.h>

int main(){
    int din=0 ,notas=0;
    printf("Digite o valor: \n");
    scanf("%d", &din);
        notas = din / 100;
        din= din %100;
        printf("Numero de notas de 100: %d\n",notas);
        notas = din / 50;
        din= din %50;
        printf("Numero de notas de 50: %d\n",notas);
        notas = din / 20;
        din= din %20;
        printf("Numero de notas de 20: %d\n",notas);
        notas = din / 10;
        din= din %10;
        printf("Numero de notas de 10: %d\n",notas);
        notas = din / 5;
        din= din %5;
        printf("Numero de notas de 5: %d\n",notas);
        notas = din / 2;
        din= din %2;
        printf("Numero de notas de 2: %d\n",notas);
        notas = din / 1;
        din= din %notas;
        printf("Numero de notas de 1: %d\n",notas);
    return 0;
}
