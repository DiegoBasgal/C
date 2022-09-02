#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void le_vetor(float *V, int n){
    int i;
    for (i = 0; i < n; i++){
        printf("V[%d]= ", i);
        scanf("%f", &V[i]);
    }
}

float media(float *V, int n){
    int i;
    float s = 0.0;
    for(i = 0; i < n; i++){
        s += V[i];
    }
    return s/n;
}

int main(){
    float *V[MAX];
    float m;
    int n;
    printf("Tamanho da turma:");
    scanf("%d", &n);
    V = (float*)malloc(n*sizeof(float));
    if(V == NULL){
        printf("Memoria insuficiente");
        exit(1);
    }
    le_vetor(V, n);
    m = media(V, n);
    printf("media= %.1f\n", m);
    free(V);
    return 0;
}
