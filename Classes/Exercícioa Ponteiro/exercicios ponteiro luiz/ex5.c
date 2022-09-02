#include <stdio.h>
#include<math.h>
#include <locale.h>

int raizes(double a, double b, double c, double* x1, double* x2){
    int num_raizes = 0;
    double delta;

    delta = pow(b, 2)-4*a*c;

    if(delta<0){
        num_raizes = 0;
    }else{
        if(delta == 0){
            num_raizes = 1;
            *x1 = (-b +sqrt(delta))/(a*2);

        }else if(delta > 0){
            num_raizes = 2;

            *x1 = (-b +sqrt(delta))/(a*2);
            *x2 = (-b -sqrt(delta))/(a*2);

            if(*x1 < *x2){
                double aux;
                aux = *x1;
                *x1 = *x2;
                *x2 = aux;
            }
        }
    }

    return num_raizes;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int raiz;
    double a, b, c;
    double raiz1, raiz2;

    printf("Insira o valor de a: ");
    scanf("%lf", &a);
    printf("Insira o valor de b: ");
    scanf("%lf", &b);
    printf("Insira o valor de c: ");
    scanf("%lf", &c);

    raiz = raizes(a, b, c, &raiz1, &raiz2);
    printf("Número de raízes: %d\n", raiz);

    if(raiz >= 1){
        printf("1° Raíz: %.2lf\n", raiz1);
    }
    if(raiz == 2){
        printf("2° Raíz: %.2lf\n", raiz2);
    }


    return 0;
}
