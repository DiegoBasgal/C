#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int a = 1;
    int *p = &a;
    int b = (*p)++;

    printf("Valor de a: %d\nValor do ponteiro p: %d\nValor de b: %d\nEndereço de a: %d\nConteúdo do ponteiro p: %d\nEndereço de b: %d\n", a, p, b, &a, *p, &b);

    /*
    "a" recebe 1
    "*p" aponta para o endereço de "a"
    "b" recebe o conteúdo do ponteiro "p"
    conteúdo do ponteiro "p" recebe + 1
    */
    return 0;
}
