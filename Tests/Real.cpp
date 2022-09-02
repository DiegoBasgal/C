#include <stdio.h>
#include <stdlib.h>

int main() {
	float x;
	printf("Digite um valor real");
	scanf("%f", &x);
	if (x>0)
         printf("Metade de %f eh %f\n", x, x/2);
	else
         printf("Um quarto de %f eh %f\n", x, x/4);
//  system("pause");
    return 0;
}
