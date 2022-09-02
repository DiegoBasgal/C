#include <stdio.h>

int main () {
	
    int n, i;
    double fat;
    printf("Digite um inteiro: ");
    scanf("%d", &n);
    if(n<0)
            printf("fat nao existe\n");
    		else { i=2;
				fat=1;
    				while(i<=n){ 
					fat=fat*i; i++;
					}	
					printf("Fatorial= %e\n", fat);
				} 
	return 0;
}
