#include <stdio.h>

int main() {
	
	int c;
	float n, soma = 0;
	
	//Contador de 1 at� 10
	//Executa bloco de repetil�ao 10 vezes
	for(c = 1; c <= 10; c++){
	   printf("Informe um numero: ");
	   scanf("%f", &n);
	   //Soma valor digitado
	   soma = soma + n;
	   soma / 2;
	   
	}
	printf("Soma: %f", soma);
	
	return 0;
}
