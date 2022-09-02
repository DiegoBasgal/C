#include <stdio.h>
#include <locale.h>

void ordem_crescente(int *vetor, int tamanho){
    int i, j, menor, aux;

    for(i = 0; i < tamanho - 1; ++i){
            menor = i;
    for(j = i + 1; j < tamanho; ++j){
            if(vetor[j] < vetor[menor])
            menor = j;
    }
    aux = vetor[i];
    vetor[i] = vetor[menor];
    vetor[menor] = aux;
    }
}
int terceiro(int *vetor, int tamanho){
    if(tamanho >= 3)
        return vetor[2];
    else
        return 0;
}

int maior(int *vetor, int tamanho){
    int maior = vetor[0];
    int i;

    for(i = 1; i<tamanho; i++){
        if(vetor[i] > maior)
            maior = vetor[i];
    }

    return maior;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int vet[3];
    int tam = 3;
    int i;
    int j = 0;

    //Alimenta o vetor
    for (i = 2; i >= 0; i--){
        vet[j] = i;
        j++;
    }

    printf("Vetor inicial:\n");

    //Printa o vetor inicial
    for (i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }

    ordem_crescente(vet, tam);

    printf("\n\nVetor ordenado:\n");

    //Printa o vetor ordenado
    for (i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }

    printf("\n\nTerceiro elemento: %d", terceiro(vet, tam));

    printf("\n\nMaior valor: %d", maior(vet, tam));





    return 0;
}
