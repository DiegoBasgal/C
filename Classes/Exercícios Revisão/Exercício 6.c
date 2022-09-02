#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int ptsjogador=0, ptscpu=0; main(){
    jokenpo();
}
int jokenpo(){
    int jogador, cpu;
    printf ("---JokenPo---\n");
    printf ("%d Jogador X CPU %d\n", ptsjogador, ptscpu);
    printf ("-------------\n");
    printf ("0. Pedra\n");
    printf ("1. Papel\n");
    printf ("2. Tesoura\n");
    printf ("3. Sair\n");
    scanf ("%d", &jogador);
    if (jogador < 0 || jogador >=3){
        exit(0);
    }
    srand(time(NULL));
    cpu = rand() % 3; //gera um numero aleatorio
    switch(cpu){
        case 0: printf ("CPU -> Pedra\n"); break;
        case 1: printf ("CPU -> Papel\n"); break;
        case 2: printf ("CPU -> Tesoura\n"); break;
    }
    if ((jogador == 0 && cpu==2) || (jogador == 1 && cpu == 0) || (jogador == 2 && cpu == 1)){ //verifica se o jogador venceu
        printf("Voce venceu!\n");
        ptsjogador++;
        jokenpo();
    }
    if (jogador == cpu){ //verifica se houve empate
        printf ("Empate!\n");
        jokenpo();
    }
    else{
        printf ("CPU venceu!\n");
        ptscpu++;
        jokenpo();
    }
    return 0;
}
