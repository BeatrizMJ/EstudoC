#ifndef JOGO_H
#define JOGO_H

#include "tabuleiro.h"
#include "personagem.h"
#include "inimigos.h"
#include "itens.h"

void jogo();
void liberar_memoria(char **tabuleiro, int N, Inimigo *inimigos, Item *itens, Personagem *p);

#endif
