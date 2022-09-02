#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int a = 1;
    int *p = &a;
    int b = (*p)++;

    printf("Valor de a: %d\nValor do ponteiro p: %d\nValor de b: %d\nEndere�o de a: %d\nConte�do do ponteiro p: %d\nEndere�o de b: %d\n", a, p, b, &a, *p, &b);

    /*
    "a" recebe 1
    "*p" aponta para o endere�o de "a"
    "b" recebe o conte�do do ponteiro "p"
    conte�do do ponteiro "p" recebe + 1
    */
    return 0;
}
