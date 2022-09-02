#include<stdio.h>
#include<math.h>

int main(){
    int a, b, c;
    float x1, x2;
    printf("Algoritmo para resolver equacao ax2 + bx + c = 0:");
    printf("\nInforme o valor de A :\n");
    scanf("%d",&a);
    printf("\nInforme o valor de B :\n");
    scanf("%d",&b);
    printf("\nInforme o valor de C :\n");
    scanf("%d",&c);
    raizes(a,b,c,&x1,&x2);
    return 0;
}

int raizes (int a, int b, int c, float * x1, float * x2){
    float delta;
    delta = pow(b,2) - 4 * (a*c);
    if(delta < 0){
        return 0;
    }else{
        if(delta == 0){
            printf("Duas raizes reais e iguais:");
            *x1 = ((-b) + pow(delta, 0.5))/2 * a;
            return 1;
        }else{
            printf("\n\nDuas raizes reais e distintas:");
            *x1 = ((-b) + pow(delta, 0.5))/2 * a;
            *x2 = -b - pow(delta, 0.5)/2*a;
            if(*x1 > *x2){
                delta = *x1; *x1 = *x2; *x2 = delta;
                printf("\n\nAs raizes são: [%.2f] e [%.2f]",x1,x2);
            }
        }
    }
}
