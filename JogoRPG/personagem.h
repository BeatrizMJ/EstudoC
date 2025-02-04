#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include "inimigos.h"
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    int vida;
    int pontos;
} Personagem;

int criar_personagem(int x, int y, char **tabuleiro);
void teclado_personagem (int N, char **tabuleiro, Inimigo *inimigos);
void mover_personagem(int N, char **tabuleiro, Inimigo *inimigos);
bool combate(Inimigo *inimigos, char **tabuleiro);
void liberar_memoria_personagem();

#endif
