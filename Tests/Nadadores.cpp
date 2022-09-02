#include <stdio.h>

int main () {
	int idade;
	printf("Entre com a idade do nadador: ");
	scanf("%d", &idade);
	if (idade<=16)
	    printf("Nadador junior\n");
	else if (idade<=40)
	         printf("Nadador senior\n");
	    else if (idade<=100)
	         printf("Nadador veterano\n");
	        else if (idade<=200) 
	            printf("Esse cara ta morto tio, nem boia ele boia\n");
	            else
	                printf("Para de encher o meu saco cara, ele morreu, CHEGA!!!");
	return 0;
}
