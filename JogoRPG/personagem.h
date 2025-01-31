#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "inimigos.h"

typedef struct {
    int x, y;
    int vida;
    int pontos;
} Personagem;

Personagem *criar_personagem(int x, int y, char **tabuleiro);
void mover_personagem(Personagem *p, char direcao, char **tabuleiro, int N, Inimigo *inimigos);
void combate_PXI(Personagem *p, Inimigo *inimigos, char** tabuleiro);
void liberar_memoria_personagem(Personagem *p);

#endif
