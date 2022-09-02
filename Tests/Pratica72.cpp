#include <stdio.h>

int main() {
	
	int n, c;
	
	printf("Informe um numero positivo: ");
	scanf("%d", &n);
    
    //Inicialização; Condição; Incremento
    for(c = n; c >= 0; c--){
    	printf("%d ", c);
	}
	
	return 0;
}
