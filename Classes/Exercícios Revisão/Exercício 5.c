#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){
    char nome [15];
    int x,y,n,r;
    printf("jogador: ");
    gets(nome);
    printf("voce quer par(1) ou impar(2)?");
    scanf("%s", &y);
    printf("digite um numero: ");
    scanf("%s", &x);
    srand(time(NULL));
    n=rand()%11;
    if (n%2==0){
        printf(" voce joga com impar a maquina com par. \n");
    }
    else{
        printf(" voce joga com par a maquina com impar. \n");
    }
    printf("a maquina escolheu o numero: \n");
    scanf("%s", &n);
    r=n+x;
    if ((r%2==0) && (x%2==0)){
        printf("jogador vence.\n");
        scanf("%d", &r);
    }
    else{
        printf("maquina vence.\n");
    }
    if ((r%2!=0)&&(x%2!=0)){
        printf("jogador vence.\n");
    }
    else{
        printf("a maquina vence.\n");
    }
    system("cls");{
        printf("placar\n\n jogador: %s- maquina: %s\n");
        scanf("%s", x);
        scanf("%s%", n);
    }
    system("PAUSE");
}
