#ifndef UTIL_H
#define UTIL_H

#include <SDL2/SDL.h>
#include "SDL2_gfx/SDL2_gfxPrimitives.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LARGURA 1000
#define ALTURA 600

typedef enum direcao{
    CIMA,
    BAIXO,
    ESQUERDA,
    DIREITA,
    ESQC,
    DIRC,
    ESQB,
    DIRB,
} Direcao;

typedef struct ponto{
    int x, y;
    int raio;
    Direcao d;
} Ponto;

typedef struct laterais{
    int x1, y1, x2, y2;
} Laterais;

typedef struct tijolos{
    float x1, y1, x2, y2;
    int presenca;
    int cor[3];
} Tijolos;

typedef struct raquete{
    int x1, x2, y1, y2;
} Raquete;

typedef struct ranking {
    char nome[81];
    int pontuacao;
} Ranking;

void print_SDLError ();

void comecoponto1 (Ponto *p, Raquete *ra);

void comecoponto2 (Ponto *p, Raquete *ra);

void inicia_tijolos (Tijolos** ti, int l, int c);

void colisao_tijolos (Ponto *p, Tijolos** ti, int *pontuacao);

void colisao_direcoes(Ponto *p, Laterais *lae, Laterais *lad, Laterais *te, Raquete *ra, int *pontuacao, int *tentativas, int *start);

#endif // UTIL_H
