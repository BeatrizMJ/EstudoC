#ifndef INIMIGOS_H
#define INIMIGOS_H

typedef struct Inimigo {
    int x, y, vida;
    struct Inimigo *prox;
} Inimigo;

void adicionar_inimigo_lista(Inimigo *novo_inimigo);
Inimigo *criar_inimigo(int x, int y, char **tabuleiro, int N);
//void mover_inimigos(Inimigo *inimigos, char **tabuleiro);
void remover_inimiges(Inimigo *alvo); //
void liberar_memoria_inimigos();

#endif
