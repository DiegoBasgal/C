#include <stdio.h>
#define MAX 5

void le_vetor(int*vet, int n){
    int i;
    for(i=0; i<n; i++){
        printf("vet[%d] =", i);
        scanf("%d", &vet[i]);
    }
}

void imprime_vetor(int*vet, int n){
    int i;
    printf("[");
    for(i=0; i<n-1; i++){
        printf("%d,", vet[i]);
    }
    printf("%d]\n", vet[i]);
}

int soma(int*vet, int n){
    int i;
    int s=0;
    for(i=0; i<n; i++){
        s+=vet[i];
    }
    return s;
}

int busca(int*vet, int n, int v){
    int i;
    for(i=0; i<n; i++){
        if(vet[i]==v)
            return i;
    }
    return -1;
}







