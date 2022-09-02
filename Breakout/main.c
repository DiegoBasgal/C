#include "Util.h"

int main (int argc, char* argv[]){
    SDL_Window* janela = NULL;
    SDL_Renderer* render = NULL;
    SDL_Event e;
    FILE* out;
    int i, j, tentativas = 1, fim = 0, start = 1, pontuacao = 0, n_ranking = 0, AUX;
    char game [128], breakout [128], vidas[128], pontos[128], esc[128], mostra_ranking[256], nome_jogador[81];
    Ranking rank[10];
    Tijolos** ti;
    Laterais lae = {LARGURA - 1000, ALTURA - 600, LARGURA - 980, ALTURA};
    Laterais lad = {LARGURA - 20, ALTURA - 600, LARGURA, ALTURA};
    Laterais te = {LARGURA - 1000, ALTURA - 600, LARGURA, ALTURA - 580};
    Ponto p = { LARGURA / 2, ALTURA / 2 + 230, 4};
    Raquete ra = { LARGURA / 2 + 70, LARGURA / 2 - 70, ALTURA / 2 + 245, ALTURA / 2 + 235};
    int grava_arquivo = 1;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("Nao foi possivel inicializar a SDL!\n");
        print_SDLError();
        return 1;
    }
    janela = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGURA, ALTURA, SDL_WINDOW_SHOWN);
    if (janela == NULL){
        printf("Nao foi possivel criar a janela!\n");
        print_SDLError();
        return 2;
    }
    render = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (render == NULL){
        SDL_DestroyWindow(janela);
        printf("Nao foi possivel criar o renderizador!\n");
        print_SDLError();
        return 3;
    }
    ti = aloca_m(6, 10);
    if (ti == NULL) {
        printf("Erro ao alocar matriz de tijolos!\n");
        return 500;
    }
    inicia_tijolos(ti, 6, 10);
    if (argc != 2) {
        printf("Informe o nome do jogador!\n");
        return 10;
    }
    strcpy(nome_jogador, argv[1]);
    printf("nome_jogador = %s\n", nome_jogador);
    out = fopen("ranking.txt", "r");
    if(!out){
        printf("Erro ao abrir ranking.txt\n");
        return 0;
    }
    while (fscanf(out, "%s %d", rank[n_ranking].nome, &rank[n_ranking].pontuacao) == 2) {
        n_ranking ++;
    }
    fclose(out);
    printf("%d", n_ranking);
    while (!fim){
        while (SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT ||
                    (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))fim = 1;
            if (e.type == SDL_KEYDOWN){
                if (e.key.keysym.sym == SDLK_LEFT && ra.x1 > 180){
                    ra.x2 = ra.x2 - 35;
                    ra.x1 = ra.x1 - 35;
                    if (start == 1 && tentativas > 0){
                        comecoponto2(&p, &ra);
                        start = 0;
                    }
                }
                else if (e.key.keysym.sym == SDLK_RIGHT && ra.x2 < 820){
                    ra.x1 = ra.x1 + 35;
                    ra.x2 = ra.x2 + 35;
                    if (start == 1 && tentativas > 0){
                        comecoponto1(&p, &ra);
                        start = 0;
                    }
                }
                else if (e.key.keysym.sym == SDLK_p){
                    start = 2;
                }
                else if (e.key.keysym.sym == SDLK_SPACE){
                    start = 0;
                }
            }
        }
        if (start == 0){
            colisao_tijolos (&p, ti, &pontuacao);
            colisao_direcoes(&p, &lae, &lad, &te, &ra, &pontuacao, &tentativas, &start);
        }
        if (tentativas > 0){
            SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderClear(render);
            filledCircleRGBA(render, p.x, p.y, p.raio, 0xFF, 0xFF, 0xFF, 0xFF);
            for(i = 0; i < 6; i++){
                for(j = 0; j < 10; j++){
                    if (ti[i][j].presenca == 1){
                        boxRGBA(render, ti[i][j].x1, ti[i][j].y1, ti[i][j].x2, ti[i][j].y2, ti[i][j].cor[0], ti[i][j].cor[1], ti[i][j].cor[2], 0xFF);
                    }
                }
            }
            boxRGBA(render, ra.x1, ra.y1, ra.x2, ra.y2, 0x00, 0x00, 0xFF, 0xFF);
            boxRGBA(render, lae.x1, lae.y1, lae.x2, lae.y2, 0xD1, 0x00, 0x00, 0xFF);
            boxRGBA(render, lad.x1, lad.y1, lad.x2, lad.y2, 0xD1, 0x00, 0x00, 0xFF);
            boxRGBA(render, te.x1, te.y1, te.x2, te.y2, 0xD1, 0x00, 0x00, 0xFF);
            SDL_Rect boxvida = {3, 4, 69, 13};
            SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderFillRect(render, &boxvida);
            SDL_Rect boxpts = {904, 4, 93, 13};
            SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderFillRect(render, &boxpts);
            SDL_Rect boxbreak = {465, 4, 67, 13};
            SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderFillRect(render, &boxbreak);
            sprintf(vidas, "Vidas: %d", tentativas);
            stringRGBA (render, 6, 7, vidas, 0xFF, 0xFF, 0xFF, 0xFF);
            sprintf(pontos, "Pontos: %d", pontuacao);
            stringRGBA (render, 907, 7, pontos, 0xFF, 0xFF, 0xFF, 0xFF);
            sprintf(breakout, "BREAKOUT");
            stringRGBA (render, 467, 7, breakout, 0xFF, 0xFF, 0xFF, 0xFF);
            stringRGBA (render, 395, 590, "Aperte P para pausar o jogo.", 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderPresent(render);
        }
        else{
            SDL_SetRenderDrawColor(render, 0xD1, 0x00, 0x00, 0xFF);
            SDL_RenderClear(render);
            SDL_Rect rect = {0, 0, 1000, 20};
            SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0xFF );
            SDL_RenderFillRect(render, &rect);
            SDL_Rect rect2 = {0, 0, 20, 1000};
            SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0xFF );
            SDL_RenderFillRect(render, &rect2);
            SDL_Rect rect3 = {980, 0, 20, 1000};
            SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0xFF );
            SDL_RenderFillRect(render, &rect3);
            SDL_Rect rect4 = {0, 580, 1000, 20};
            SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderFillRect(render, &rect4);
            sprintf(game, "GAME OVER");
            stringRGBA (render, 459, 176, game, 0xFF, 0xFF, 0xFF, 0xFF);
            stringRGBA (render, 465, 235, "Ranking:", 0xFF, 0xFF, 0xFF, 0xFF);
            if (grava_arquivo) {
                if (pontuacao > 0){
                    for(i = 0; i < 5; i++){
                        if(pontuacao > rank[i].pontuacao){
                            n_ranking = i;
                            break;
                        }
                    }
                    for (j = 5 - 1; j > n_ranking; j--){
                        rank[j].pontuacao = rank[j - 1].pontuacao;
                        strcpy(rank[j].nome, rank[j - 1].nome);
                    }
                    rank[n_ranking].pontuacao = pontuacao;
                    strcpy(rank[n_ranking].nome, nome_jogador);
                    out = fopen("ranking.txt", "w");
                    if(!out){
                        printf("Erro ao abrir ranking.txt\n");
                        return 30;
                    }
                    for (i=0; i < 5; i++) {
                        fprintf(out, "%s %d\n", rank[i].nome, rank[i].pontuacao);
                    }
                }
                fclose(out);
                grava_arquivo = 0;
            }
            for (i=0; i < 5; i++) {
                sprintf(mostra_ranking, "%s %d", rank[i].nome, rank[i].pontuacao);
                stringRGBA (render, 465, 265 + (i * 10), mostra_ranking, 0xFF, 0xFF, 0xFF, 0xFF);
            }
            sprintf(esc, "<Pressione esc para sair>"); // posicao e cor do contador de vidas
            stringRGBA (render, 395, 525, esc, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderPresent(render);
        }
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(janela);
    libera_m(ti, 6);
    SDL_Quit();
    return 0;
}
