#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void le_vetor(float *v, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("v[%d]=", i);
        scanf("%f", &v[i]);
    }
}

float media(float *v, int n){
    int i;
    float s = 0.0;
    for(i = 0; i < n; i++){
        s += v[i];
    }
    return s/n;
}

int main(){
    float *v[MAX];
    float m;
    int n;
    printf("Tamanho da turma");
    scanf("%d", &n);
    v = (float*)malloc(n*sizeof(float));
    if(v == NULL){
        printf("Memoria insuficiente");
        exit(1);
    }
    le_vetor(*v, n);
    m = media(*v, n);
    printf("media= %1f\n", m);
    free(v);
    return 0;
}









