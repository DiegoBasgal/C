#include <stdio.h>
#include <stdlib.h>

#define MAXCONTAS 10
#define MAXCHARS 81

int main (){
    FILE* in;
    FILE* out;
    int conta, n = 0, i;
    char nome[MAXCHARS];
    float saldo;
    int V_conta[MAXCONTAS];
    char V_nome[MAXCONTAS][MAXCHARS];
    float V_saldo[MAXCONTAS];
    in = fopen("banco.csv", "r");
    if(!in){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    while(fscanf(in,"%d;%80[^;];%f\n", &conta, nome, &saldo)== 3){
        if(saldo < 0){
            if(n < MAXCONTAS){
                V_conta[n] = conta;
                strncpy(V_nome[n], nome, MAXCHARS);
                V_saldo[n] = saldo;
                n++;
            }
            else{
                printf("Não foi possível incluir conta %d\n", conta);

            }
        }
    }
    fclose (in);
    out = fopen("Relatório.txt","w");
    if(!out){
        printf("Erro ao abrir relatório.txt\n");
        return 2;
    }
    fprintf(out,"Contas no vermelho: %d\n", n);
    for(i = 0; i < n; i++){
        fprintf(out,"%s deve %.2f\n", V_nome[i], V_saldo[i]);
    }
    printf("\nEssa aplicacao tem como funcao analisar arquivos.\n");
    fclose(out);
    return 0;
}
