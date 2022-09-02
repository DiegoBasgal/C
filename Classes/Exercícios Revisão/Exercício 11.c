#include <stdio.h>
#include <stdlib.h>

void ordena(int *numero) {
     int i, j, aux;
     for( i=0; i<5; i++ ){
        for( j=i+1; j<5; j++ ){
           if( numero > numero[j] ){
              aux = numero;
              numero = numero[j];
              numero[j] = aux;
           }
        }
     }
     printf("\nOrdenado com sucesso!");
}

int main(){
    int i, vet[5];
    printf("Digite os numeros para ordenar: \n");
    for (i=0; i<5; i++)
        scanf("%i", &vet);
        ordena(vet);
    for (i=0; i<5; i++)
        printf("%i ", vet);
        fflush(stdin); getchar();
    return 0;
}
