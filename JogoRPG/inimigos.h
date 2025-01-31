#ifndef INIMIGOS_H
#define INIMIGOS_H

typedef struct Inimigo {
    int x, y, vida;
    struct Inimigo *prox;
} Inimigo;

void inicializar_inimigo(int x, int y);
Inimigo *adicionar_inimigo(int x, int y, char **tabuleiro, int N);
void mover_inimigos(Inimigo *inimigos, char **tabuleiro);
void remover_inimigo(Inimigo *inimigos, Inimigo *alvo); //
void liberar_memoria_inimigos(Inimigo *inimigos);

#endif
