#include <stdio.h>

int main() {
	
	int n, c;
	
	printf("Informe um numero positivo: ");
	scanf("%d", &n);
    
    //Inicializa��o; Condi��o; Incremento
    for(c = n; c >= 0; c--){
    	printf("%d ", c);
	}
	
	return 0;
}
