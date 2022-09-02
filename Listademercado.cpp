#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct {
	char nome[50];
	int quant;
}tquant;

tquant V[N];
int tot = 0;

int entrada() {
	printf("Informe nome do produto: ");
	fflush(stdin);
	gets(V[tot].nome);
	while (strcmpi(V[tot].nome, "fim")!=0 && tot<100){
		printf("Informe quantidade do produto(unidades): ");
		fflush(stdin);
		scanf("%d", &V[tot].quant);
		tot++;
		fflush(stdin);
		printf("Informe nome do produto: ");
		gets(V[tot].nome);
	}
	return 0;
}

void ordena1() {
	int i, j;
	tquant aux;
	for(i=0; i<tot-1; i++)
		for(j=i+1; j<tot; j++)
			if (strcmpi(V[i].nome, V[j].nome)>0){
				aux=V[i];
				V[i]=V[j];
				V[j]=aux;
			}	
}

void ordena2() {
	int i, j;
	tquant aux;
	for(i=0; i<tot-1; i++)
		for(j=i+1; j<tot; j++)
			if (V[i].quant < V[j].quant){
				aux=V[i];
				V[i]=V[j];
				V[j]=aux;
			}	
}

void mostra1() {
	int i;
	ordena1();
	system("cls");
	printf("Produto                                                Quantidade(unidades)\n\n");
	for(i=0; i<tot; i++)
		printf("%-50s         %5d\n", V[i].nome, V[i].quant);
		
	system("pause");
}

void mostra2() {
	int i;
	ordena2();
	system("cls");
	printf("Produto                                                Quantidade(unidades)\n\n");
	for(i=0; i<tot; i++)
		printf("%-50s         %5d\n", V[i].nome, V[i].quant);
		
	system("pause");
}

void procura(){
	int i, j;
	j = 0;
	printf("Digite o nome do produto que deseja procurar:");
	fflush(stdin);
	gets(V[N-1].nome);
	for(i = 0; i < tot; i++){
		if(strcmpi(V[i].nome, V[N-1].nome)==0){
			j++;
			if(j==1){
				printf("\nNome:                                                 Quantidade(unidades):\n\n");
			}	
			printf("%-50s          %5d\n", V[i].nome, V[i].quant);	
		}
	}
	if(j == 0){
		printf("Produto nao encontrado.\n");
	}
	system("pause");
}

int main() {
	int op;	
	do {
		system("cls");
		printf("\n             ---------- L I S T A   D E   M E R C A D O ----------\n\n\n");
		printf("1 - Inclui Produto\n");
		printf("2 - Mostra os produtos por ordem alfabetica\n");
		printf("3 - Mostra os produtos por ordem de quantidade\n");
		printf("4 - Procurar produto\n");
		printf("5 - Encerra\n");
		scanf("%d", &op);
		switch (op) {
			case 1: entrada(); break;
			case 2: mostra1(); break;
			case 3: mostra2(); break;
			case 4: procura(); break;
			case 5: printf("Ate Logo"); break;
			default: printf("Opcao nao encontrada\n");
		}
		
	} while (op!=5);
	return 0;
}
