#include <stdio.h>

int main() {
	
	int n, c;
	
	printf("Informe um numero positivo: ");
	scanf("%d", &n);
	//1) Inicializar o contador
	c = 100;
	//3) Condição
	while( c <= n ){
		printf("%d ", c);
		//2) Incremetnar o contador
		c--; //c = c + 1;
	}
	
	
	
	
	return 0;
}
