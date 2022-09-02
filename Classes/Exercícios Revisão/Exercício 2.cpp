#include <stdio.h>

int fat(int n);

int main(){
    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    printf("fat(%d)=%d\n", n, fat(n));
    return 0;
}
int fat(int n){
    if(n==0)
        return 1;
    else
        return n*fat(n-1);
}

