#include "inimigos.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define QUANTIDADE_INIMIGOS 5

Inimigo *inimigos = NULL;

void adicionar_inimigo_lista(Inimigo *novo_inimigo) {
    if (inimigos == NULL) {
        inimigos = novo_inimigo;
    } else {
        Inimigo *atual = inimigos;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo_inimigo;
    }
}

Inimigo *criar_inimigo(int x, int y, char **tabuleiro, int N) {
    srand(time(NULL));

    for (int i = 0; i < QUANTIDADE_INIMIGOS; i++) {
        do {
            x = rand() % (N - 2) + 1;
            y = rand() % (N - 2) + 1;
        } while (tabuleiro[x][y] != '.');

        Inimigo *novo_inimigo = (Inimigo *)malloc(sizeof(Inimigo));
        if (novo_inimigo == NULL) {
            printf("Erro de alocação de memória para inimigo\n");
            return NULL;
        }

        novo_inimigo->x = x;
        novo_inimigo->y = y;
        novo_inimigo->vida = 60;
        novo_inimigo->prox = NULL;

        adicionar_inimigo_lista(novo_inimigo);
        tabuleiro[x][y] = '&';
    }

    return inimigos;
}


/*

void mover_inimigos(Inimigo *inimigos, char **tabuleiro) {

}*/

void remover_inimigo(Inimigo *alvo) {
    Inimigo *anterior = NULL;
    Inimigo *atual = inimigos;

    while (atual) {
        if (atual == alvo) { // encontrar o inimigo do combate
            if (anterior) {
                anterior->prox = atual->prox;
            } else { // inimigo primeiro da lista
                inimigos = atual->prox;
            }
            // atual = NULL;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

void liberar_memoria_inimigos() {
	 while (inimigos) {
	    Inimigo *temp = inimigos;
	    inimigos = inimigos->prox;
	    free(temp);
	 }
	 inimigos = NULL;
}
