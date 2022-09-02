#include <stdio.h>

int main () {

    int n, i;
    double fat;
    printf("Digite um inteiro: ");
    scanf("%d", &n);
        if(n<0)
        printf("fat nao existe\n");
            else {  fat=1;
            for(i=2; i<=n; i++)
            fat=fat*i;
            printf("Fatorial= %e\n", fat);
        }
	return 0;
}
