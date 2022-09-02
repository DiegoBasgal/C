#include <stdio.h>

int main() {
	
	int c;
	float n, soma = 0;
	
	//Contador de 1 até 10
	//Executa bloco de repetilçao 10 vezes
	for(c = 1; c <= 10; c++){
	   printf("Informe um numero: ");
	   scanf("%f", &n);
	   //Media valor digitado
	   soma = soma + n;
	   
	}
	   

	printf("Media: %.2f", soma / 10);
	return 0;
}
