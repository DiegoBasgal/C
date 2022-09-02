#include <stdio.h>

void main(void){
    int base, a, espaco, temp, bola, i;
    printf("Insira o comprimento da base: ");
    scanf("%i", &base);
    a = (base / 2) + 1;
    espaco = a - 1;
    if (base % 2 != 0)
        bola = 1;
    else
        bola = 0;
        printf("\n");
    for (i = a; i > 0; i--){
            temp = espaco;
        while (temp != 0){
            printf("%c", 32);
            temp--;
        }
        temp = bola;
        while (temp != 0) {
            printf("o", 42);
            temp--;
        }
        bola += 2;
        espaco--;
        printf("\n");
    }
}
