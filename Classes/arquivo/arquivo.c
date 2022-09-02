#include <stdio.h>

int main (){
    float p1, p2, p3, media;
    FILE* in;
    FILE* out;
    in = fopen("notas.txt", "r");
    if(!in){
        printf("Erro ao abrir notas.txt\n");
        return 1;
    }
    out = fopen("relatorio.txt", "w");
    if(!out){
        printf("Erro ao abrir relatorio.txt\n");
        fclose(in);
        return 2;
    }
    while(fscanf(in,"%f,%f,%f", &p1, &p2, &p3)==3){
        media = (p1 + p2 + p3)/3;
        fprintf(out,"%.0f\n", media);
        if(media >= 5){
            fprintf(out,"Aprovado\n");
        }
        else{
            fprintf(out,"Reprovado\n");
        }
    }
}
