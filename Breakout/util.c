#include "Util.h"

void print_SDLError (){
    printf("SDL Error: %s\n", SDL_GetError());
}

void comecoponto2 (Ponto *p, Raquete *ra){
    ra->x1 = LARGURA / 2 + 70;
    ra->x2 = LARGURA / 2 - 70;
    ra->y1 = ALTURA / 2 + 245;
    ra->y2 = ALTURA / 2 + 235;
    p->x = LARGURA / 2;
    p->raio = 5;
    p->y = LARGURA / 2 + 30;
    p->d = ESQC;
}

void comecoponto1(Ponto *p, Raquete *ra){
    ra->x1 = LARGURA / 2 + 70;
    ra->x2 = LARGURA / 2 - 70;
    ra->y1 = ALTURA / 2 + 245;
    ra->y2 = ALTURA / 2 + 235;
    p->x = LARGURA / 2;
    p->raio = 5;
    p->y = LARGURA / 2 + 30;
    p->d = DIRC;
}

void inicia_tijolos (Tijolos** ti, int l, int c){
    int i, j;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            ti[i][j].presenca = 1;
            ti[i][j].x1 = j * 90 + 50;
            ti[i][j].y1 = i * 30 + 50;
            ti[i][j].x2 = j * 90 + 140;
            ti[i][j].y2 = i * 30 + 80;
            ti[i][j].cor[0] = rand()%255;
            ti[i][j].cor[1] = rand()%255;
            ti[i][j].cor[2] = rand()%255;
        }
    }
}

void colisao_tijolos (Ponto *p, Tijolos** ti, int *pontuacao){
    int i, j;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 10; j++){
            if (p->d == ESQC){
                if (ti[i][j].presenca == 1 && p->y - p->raio == ti[i][j].y2 && p->x > ti[i][j].x1 && p->x < ti[i][j].x2){
                    p->d = ESQB;
                    ti[i][j].presenca = 0;
                    *(pontuacao) += 4;
                }
                else if (ti[i][j].presenca == 1 && p->x - p->raio == ti[i][j].x2 && p->y > ti[i][j].y1 && p->y < ti[i][j].y2){
                    p->d = DIRC;
                    ti[i][j].presenca = 0;
                    *(pontuacao) += 4;
                }
                else if (ti[i][j].presenca == 1 && p->x + p->raio == ti[i][j].x2 &&  p->y + p->raio == ti[i][j].y2){
                    p->d = DIRB;
                    ti[i][j].presenca = 0;
                    *(pontuacao) += 4;
                }
            }
            else if (p->d == DIRC){
                if (ti[i][j].presenca == 1 && p->y - p->raio == ti[i][j].y2 && p->x >= ti[i][j].x1 && p->x <= ti[i][j].x2){
                    p->d = DIRB;
                    ti[i][j].presenca = 0;
                    *(pontuacao) += 4;
                }
                else if (ti[i][j].presenca == 1 && p->x + p->raio == ti[i][j].x1 && p->y >= ti[i][j].y1 && p->y <= ti[i][j].y2){
                    p->d = ESQC;
                    ti[i][j].presenca = 0;
                    *(pontuacao) += 4;
                }
                else if (ti[i][j].presenca == 1 && p->x - p->raio == ti[i][j].x1 &&  p->y + p->raio == ti[i][j].y2){
                    p->d = ESQB;
                    ti[i][j].presenca = 0;
                    *(pontuacao) += 4;
                }
            }
            else if (p->d == DIRB){
                if (ti[i][j].presenca == 1 && p->y + p->raio == ti[i][j].y1 && p->x >= ti[i][j].x1 && p->x <= ti[i][j].x2){
                    p->d = DIRC;
                    ti[i][j].presenca = 0;
                    *(pontuacao) += 4;
                }
                else if (ti[i][j].presenca == 1 && p->x + p->raio == ti[i][j].x1 && p->y >= ti[i][j].y1 && p->y <= ti[i][j].y2){
                    p->d = ESQB;
                    ti[i][j].presenca = 0;
                    *(pontuacao) += 4;
                }
                else if (ti[i][j].presenca == 1 && p->x - p->raio == ti[i][j].x1 &&  p->y - p->raio == ti[i][j].y1){
                    p->d = ESQC;
                    ti[i][j].presenca = 0;
                    *(pontuacao) += 4;
                }
            }
            else if (p->d == ESQB){
                if (ti[i][j].presenca == 1 && p->y + p->raio == ti[i][j].y1 && p->x >= ti[i][j].x1 && p->x <= ti[i][j].x2){
                    p->d = ESQC;
                    ti[i][j].presenca = 0;
                    *(pontuacao) += 4;
                }
                else if (ti[i][j].presenca == 1 && p->x - p->raio == ti[i][j].x2 && p->y >= ti[i][j].y1 && p->y <= ti[i][j].y2){
                    p->d = DIRB;
                    ti[i][j].presenca = 0;
                    *(pontuacao) += 4;
                }
                else if (ti[i][j].presenca == 1 && p->x + p->raio == ti[i][j].x2 &&  p->y - p->raio == ti[i][j].y1){
                    p->d = DIRC;
                    ti[i][j].presenca = 0;
                    *(pontuacao)
                     += 4;
                }
            }
        }
    }
}

void colisao_direcoes(Ponto *p, Laterais *lae, Laterais *lad, Laterais *te, Raquete *ra, int *pontuacao, int *tentativas, int *start){
    if (p->d == ESQC){
        if (p->x == lae->x2 + p->raio) p->d = DIRC;
        else if (p->y == te->y2 + p->raio) p->d = ESQB;
        else{
            p->y = p->y - p->raio;
            p->x = p->x - p->raio;
        }
    }
    else if (p->d == DIRC){
        if (p->y == te->y2 + p->raio) p->d = DIRB;
        else if(p->x == lad->x1 - p->raio) p->d = ESQC;
        else{
            p->y = p->y - p->raio;
            p->x = p->x + p->raio;
        }
    }
    else if (p->d == DIRB){
        if(p->x == lad->x1 - p->raio) p->d = ESQB;
        if (p->y + p->raio + 10 == ra->y1 && p->x <= ra->x1 + 50 && p->x >= ra->x2 + 50){
            p->d = DIRC;
        }
        else if (p->y + p->raio + 10 == ra->y1 && p->x <= ra->x1 && p->x >= ra->x2){
            p->d = ESQC;
        }
        else if (p->y  == ALTURA + p->raio){
            comecoponto2 (p, ra);
            *(start) = 1;
            *(tentativas) -= 1;
            *(pontuacao) -= 10;
        }
        else{
            p->y = p->y + p->raio;
            p->x = p->x + p->raio;
        }
    }
    else if (p->d == ESQB){
        if (p->x == lae->x2 + p->raio) p->d = DIRB;
        if (p->y + p->raio == ra->y1 - 10 && p->x <= ra->x1 - 50 && p->x >= ra->x2 - 50){
            p->d = ESQC;
        }
        else if (p->y + p->raio == ra->y1 - 10 && p->x <= ra->x1 && p->x >= ra->x2){
            p->d = DIRC;
        }
        else if (p->y == ALTURA + p->raio){
            comecoponto1(p, ra);
            *(start) = 1;
            *(tentativas) -= 1;
            *(pontuacao) -= 10;
        }
        else{
            p->y = p->y + p->raio;
            p->x = p->x - p->raio;
        }
    }
}

Tijolos** aloca_m(int l, int c){
    int i;
    Tijolos** m;
    m = (Tijolos**)malloc(l*sizeof(Tijolos*));
    if(!m){
        return NULL;
    }
    for(i = 0; i < l; i++){
        m[i] = (Tijolos*) malloc(c*sizeof(Tijolos));
        if(!m[i]){
            return NULL;
        }
    }
    return m;
}

void libera_m(Tijolos** m, int l){
    int i;
    for (i = 0; i < l; i++){
        free(m[i]);
    }
    free(m);
}
