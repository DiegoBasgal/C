#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void calc_esfera(double r, double* area, double* volume){
    *area = 4 * 3.1415 * pow(r, 2);
    *volume = (4 * 3.1415 * pow(r, 3))/3;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    double area, volume, raio;
    int repeticao = 1;

    while(repeticao == 1){
        printf("Insira o raio da esfera: ");
        scanf("%lf", &raio);
        if(raio == 0){
            repeticao = 0;
        }else{
            calc_esfera(raio, &area, &volume);
            printf("Área = %.4lf\nVolume = %.4lf\n\n", area, volume);
        }
    }

    return 0;
}
