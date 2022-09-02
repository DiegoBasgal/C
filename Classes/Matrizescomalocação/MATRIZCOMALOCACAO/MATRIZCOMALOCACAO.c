#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float** aloca_m(int l, int c){
    int i;
    float** m;
    m = (float**)malloc(l*sizeof(float*));
    if(!m){
        return NULL;
    }
    for(i = 0; i < l; i++){
        m[i] = (float*) malloc(c*sizeof(float));
        if(!m[i]){
            return NULL;
        }
    }
    return m;
}

void libera_m(float** m, int l){
    int i;
    for (i = 0; i < l; i++){
        free(m[i]);
    }
    free(m);
}

void imprime_m(float** m, int l, int c){
    int i, j;
    for(i = 0; i < l; i++){
        printf("[");
        for(j = 0; j < c; j++){
            printf("%f", m[i][j]);
        }
        printf("]\n");
    }
}

void le_m(float** m, int l, int c){
    int i, j;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("m[%d][%d]=", i, j);
            scanf("%f", &m[i][j]);
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    float** a;
    a = aloca_m(3, 2);
    if(!a){
        printf("Memória insuficiente!\n");
        return 1;
    }
    le_m(a, 3, 2);
    imprime_m(a, 3, 2);
    libera_m(a, 3);
    return 0;
}
