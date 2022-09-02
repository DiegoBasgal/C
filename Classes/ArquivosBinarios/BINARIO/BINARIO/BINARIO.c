#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
    float x, y ,z;
}Ponto;

void imprime_ponto(Ponto *p){
    printf("x=%.1f, y=%.1f, z=%.1f\n", p->x, p->y, p->z);
}

void le_ponto(char *arq, Ponto *p){
    FILE* fp;
    fp = fopen(arq, "r");
    if(!fp){
        printf("Erro ao abrir %s\n", arq);
        exit(1);
    }
    fscanf(fp,"%f;%f;%f", &p->x, &p->y, &p->z);
    fclose(fp);
}

void salva_ponto(char *arq, int n, Ponto *buf){
    FILE* fp = fopen(arq, "wb");
    if(!fp){
        printf("Erro ao abrir%s\n", arq);
        exit(2);
    }
    fwrite(buf, sizeof(Ponto), n, fp);
    fclose (fp);
}

void carrega_ponto(char *arq, int n, Ponto *buf){
    FILE* fp;
    fp = fopen(arq, "rb");
    if(!fp){
        printf("Erro ao abrir%s\n", arq);
        exit(3);
    }
    fread(buf, sizeof(Ponto), n, fp);
    fclose(fp);
}

int main (){
    Ponto p1;
    Ponto p2;
    le_ponto("ponto.csv", &p1);
    imprime_ponto(&p1);
    salva_ponto("ponto.dat", 1, &p1);
    carrega_ponto("ponto.dat", 1, &p2);
    imprime_ponto(&p2);
    return 0;
}
