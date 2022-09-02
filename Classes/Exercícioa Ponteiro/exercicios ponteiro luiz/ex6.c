#include <stdio.h>
#include <locale.h>

void recebe_vetor(int* vetor){

    printf("Tamanho do vetor recebido na função: %d\nSeu endereço: %d\n", sizeof(vetor), &vetor);

}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int vet[5] = {0,1,2,3,4};

    printf("Tamanho do vetor na função main: %d\nSeu endereço: %d\n\n", sizeof(vet), &vet);
    recebe_vetor(&vet);
    return 0;
}
