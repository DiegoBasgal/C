#include <stdio.h>
#include <locale.h>

void recebe_vetor(int* vetor){

    printf("Tamanho do vetor recebido na fun��o: %d\nSeu endere�o: %d\n", sizeof(vetor), &vetor);

}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int vet[5] = {0,1,2,3,4};

    printf("Tamanho do vetor na fun��o main: %d\nSeu endere�o: %d\n\n", sizeof(vet), &vet);
    recebe_vetor(&vet);
    return 0;
}
