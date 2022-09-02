#include <stdio.h>
#include <stdlib.h>

int main(){
    int a1, a2,x=1;
    if(1 <= a1 && a1 <= 1024){
      printf("\nO usuario1 digita o numero escondido: ");
      scanf("%d",&a1);
      system("cls");
      V:printf("\nO usuario2 digita o numero escolhido: ");
      scanf("%d",&a2);
      if(a1>a2){
        printf("\n\nO numero escolhido e MENOR que o escondido, escolha outro numero.\n");
        x=x+1;
        goto V;
       }
      else if (a1<a2){

        printf("\n\nO numero escolhido e MAIOR que o escondido, escolha outro numero.\n");
        x=x+1;
        goto V;
       }
      else{
        printf("\nParabens, voce acertou o numero escondido\n\n");
       }
    }
    else
        printf("O numero nao e permitido");
        printf("O numero de tentativas foi: %d\n",x);
    return(0);
}
