#include <stdio.h>
#include <locale.h>

void troca (int* p1, int* p2){
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int main () {
    setlocale(LC_ALL, "Portuguese");
    int x = 10;
    int y = 20;

    //Inverte os valores via referência
    troca(&x, &y);

    //Deve imprimir x = 20 e y = 10
    printf("x = %d, y = %d\n", x, y);
    return 0;
}

