#include <SDL2/SDL.h>
#include "SDL2_gfx/SDL2_gfxPrimitives.h"
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <locale.h>
#include <windows.h>

#define LARGURA 1000
#define ALTURA 600
#define g 9.81

typedef struct ponto{
    int x, y;
    int raio;
} Ponto;

typedef struct cenario{
    int x1, y1, x2, y2;
} Cenario;

double pontoX (double x0, double v0, double a, double t){
    float an = a*M_PI/180;
    return x0+v0*cos(an)*t;
}

double pontoY (double y0, double v0, double a, double t){
    float an = a*M_PI/180;
    return y0+v0*sin(an)*t-(g*t*t)/2;
}

double ym (double v0, double a){
    float an = a*M_PI/180;
    return (v0*v0*sin(an)*sin(an))/2*g;
}

int main (int argc, char* argv[]){
    setlocale(LC_ALL, "Portuguese");
    SDL_Window* janela = NULL;
    SDL_Renderer* render = NULL;
    SDL_Event e;
    int iniciar = 1, x = 0, y = y0, ymax = y0;
    double v0 = 0, a = 0, y0 = 85, x0 = 30, t = 0;
    char caracteres[10];

    Cenario grama = {0, 535, 1000, 550};
    Cenario grama1 = {0, 533, 1000, 535};
    Cenario terra = {0, 550, 1000, 600};
    Cenario bixoc = {647, 300, 753, 600};
    Cenario bixo = {650, 300, 750, 600};
    Cenario bixoc2 = {577, 400, 683, 600};
    Cenario bixo2 = {580, 400, 680, 600};
    Cenario olho = {670, 275, 677, 295};
    Cenario olho2 = {610, 375, 617, 395};
    Cenario castelo = {5, 470, 85, 535};

    printf("Forneca um valor para a velocidade inicial: ");
    scanf("%lf", &v0);
    printf("Forneça um angulo em graus de 0 a 90(°): ");
    scanf("%lf", &a);

    SDL_Init(SDL_INIT_VIDEO) < 0;

    janela = SDL_CreateWindow("Lancamento Obliquo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGURA, ALTURA, SDL_WINDOW_SHOWN);

    render = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    while(iniciar){
        x = pontoX(x0, v0, a, t);
        y = pontoY(y0, v0, a, t);
        ymax = ym(v0, a);
        Sleep(10);
        t = t + 0.1;
        if(y <= 65){
            system("pause");
        }


        SDL_SetRenderDrawColor(render, 12, 38, 63, 0xFF);
        SDL_RenderClear(render);

        filledCircleRGBA(render, 900, 90, 40, 255, 250, 250, 0xFF);

        filledCircleRGBA(render, 20, 90, 1, 255, 255, 0, 0xFF);
        filledCircleRGBA(render, 110, 300, 3, 255, 255, 0, 0xFF);
        filledCircleRGBA(render, 150, 250, 2, 255, 255, 0, 0xFF);
        filledCircleRGBA(render, 270, 100, 1, 255, 255, 0, 0xFF);
        filledCircleRGBA(render, 380, 330, 3, 255, 255, 0, 0xFF);
        filledCircleRGBA(render, 430, 170, 2, 255, 255, 0, 0xFF);
        filledCircleRGBA(render, 550, 200, 2, 255, 255, 0, 0xFF);
        filledCircleRGBA(render, 700, 110, 2, 255, 255, 0, 0xFF);
        filledCircleRGBA(render, 790, 40, 3, 255, 255, 0, 0xFF);
        filledCircleRGBA(render, 840, 50, 2, 255, 255, 0, 0xFF);
        filledCircleRGBA(render, 910, 160, 1, 255, 255, 0, 0xFF);
        filledCircleRGBA(render, 990, 290, 2, 255, 255, 0, 0xFF);

        filledCircleRGBA(render, 700, 300, 53, 0, 0, 0, 0xFF);
        filledCircleRGBA(render, 700, 300, 50, 0, 134, 1, 0xFF);

        boxRGBA(render, bixoc.x1, bixoc.y1, bixoc.x2, bixoc.y2, 0, 0, 0, 0xFF);
        boxRGBA(render, bixo.x1, bixo.y1, bixo.x2, bixo.y2, 0, 134, 1, 0xFF);
        boxRGBA(render, olho.x1, olho.y1, olho.x2, olho.y2, 0, 0, 0, 0xFF);
        boxRGBA(render, olho.x1 + 30, olho.y1, olho.x2 + 30, olho.y2, 0, 0, 0, 0xFF);
        boxRGBA(render, olho.x1 + 4, olho.y1 + 6, olho.x2, olho.y2 - 6, 255, 255, 255, 0xFF);
        boxRGBA(render, olho.x1 + 30, olho.y1 + 6, olho.x2 + 26, olho.y2 - 6, 255, 255, 255, 0xFF);

        filledCircleRGBA(render, 630, 400, 53, 0, 0, 0, 0xFF);
        filledCircleRGBA(render, 630, 400, 50, 0, 134, 1, 0xFF);

        boxRGBA(render, bixoc2.x1, bixoc2.y1, bixoc2.x2, bixoc2.y2, 0, 0, 0, 0xFF);
        boxRGBA(render, bixo2.x1, bixo2.y1, bixo2.x2, bixo2.y2, 0, 134, 1, 0xFF);
        boxRGBA(render, olho2.x1, olho2.y1, olho2.x2, olho2.y2, 0, 0, 0, 0xFF);
        boxRGBA(render, olho2.x1 + 30, olho2.y1, olho2.x2 + 30, olho2.y2, 0, 0, 0, 0xFF);
        boxRGBA(render, olho2.x1 + 4, olho2.y1 + 6, olho2.x2, olho2.y2 - 6, 255, 255, 255, 0xFF);
        boxRGBA(render, olho2.x1 + 30, olho2.y1 + 6, olho2.x2 + 26, olho2.y2 - 6, 255, 255, 255, 0xFF);

        boxRGBA(render, grama.x1, grama.y1, grama.x2, grama.y2, 0, 201, 1, 0xFF);
        boxRGBA(render, grama1.x1, grama1.y1, grama1.x2, grama1.y2, 0, 0, 0, 0xFF);
        boxRGBA(render, terra.x1, terra.y1, terra.x2, terra.y2, 200, 152, 88, 0xFF);

        sprintf(caracteres,"Ponto X: %dm", x);
        stringRGBA (render, 6, 7, caracteres, 0xFF, 0xFF, 0xFF, 0xFF);
        sprintf(caracteres,"Ponto Y: %dm", ymax);
        stringRGBA (render, 6, 19, caracteres, 0xFF, 0xFF, 0xFF, 0xFF);
        sprintf(caracteres,"Tempo: %.2lfs", t/6);
        stringRGBA (render, 6, 31, caracteres, 0xFF, 0xFF, 0xFF, 0xFF);

        filledCircleRGBA(render, round(x), ALTURA - round(y), 7, 0x0, 0x0, 0x0, 0xFF);
        filledCircleRGBA(render, round(x), ALTURA - round(y), 5, 0xFF, 0xFF, 0xFF, 0xFF);

        boxRGBA(render, castelo.x1 + 38, castelo.y1 - 80, castelo.x2 - 38, castelo.y2, 0, 0, 0, 0xFF);
        boxRGBA(render, castelo.x1 + 38, castelo.y1 - 80, castelo.x2 - 10, castelo.y2 - 125, 0, 0, 0, 0xFF);
        boxRGBA(render, castelo.x1 + 41, castelo.y1 - 77, castelo.x2 - 13, castelo.y2 - 128, 255, 0, 0, 0xFF);
        boxRGBA(render, castelo.x1 + 20, castelo.y1 - 40, castelo.x2 - 20, castelo.y2, 0, 0, 0, 0xFF);
        boxRGBA(render, castelo.x1 + 23, castelo.y1 - 37, castelo.x2 - 23, castelo.y2 - 3, 196, 76, 22, 0xFF);
        boxRGBA(render, castelo.x1, castelo.y1, castelo.x2, castelo.y2, 0, 0, 0, 0xFF);
        boxRGBA(render, castelo.x1 + 3, castelo.y1 + 3, castelo.x2 - 3, castelo.y2 - 3, 196, 76, 22, 0xFF);
        filledCircleRGBA(render, 45, 515, 7, 0, 0, 0, 0xFF);
        boxRGBA(render, castelo.x1 + 32, castelo.y1 + 44, castelo.x2 - 32, castelo.y2, 0, 0, 0, 0xFF);


        SDL_RenderPresent(render);
        }

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(janela);
    render = NULL;
    janela = NULL;
    SDL_Quit();

    return 0;
}



