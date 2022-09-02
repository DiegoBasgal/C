#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(){

    char usuario[15];
    char senha[12];
    int tentativas = 3;

    while(strcmpi(usuario, "Diego") != 0){
        printf("Login: ");
        scanf("%s", &usuario);
        if(strcmpi(usuario, "Diego")== 0){
        }
        else{
            printf("\nUsuario Inexistente\n\n");
        }
    }

    while(strcmpi(senha, "1234") != 0){
        printf("Senha:");
        scanf("%s", &senha);
        if(strcmpi(senha,"1234")== 0){
            printf("\nBem Vindo");
        }
        else{
            printf("\nSenha Incorreta\n");
            tentativas --;
        }
        if (tentativas == 0){
            printf("Usuario Bloqueado\n");
            return 0;
        }
    }
}
