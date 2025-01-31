#include "inimigos.h"
#include <stdlib.h>
#include <stdio.h> //
#include <time.h>

Inimigo *inimigos = NULL; // deveria ser constante, para os outros tambem

void inicializar_inimigo(int x, int y) {
    Inimigo *novo = (Inimigo *)malloc(sizeof(Inimigo));
    if (novo) {
        novo->x = x;
        novo->y = y;
        novo->vida = 60;
        novo->prox = inimigos; // novo->prox = NULL;
        inimigos = novo;
    }
}

Inimigo *adicionar_inimigo(int x, int y, char **tabuleiro, int N) {
    int quantidade_inimigos = 5;
    for (int i = 0; i < quantidade_inimigos; i++) {
        do {
            x = rand() % (N - 2) + 1;
            y = rand() % (N - 2) + 1;
        } while (tabuleiro[x][y] != '.');
        inicializar_inimigo(x, y);
        tabuleiro[x][y] = '&';
    }
    return inimigos;
}



void mover_inimigos(Inimigo *inimigos, char **tabuleiro) {

}

// NULL [&] [&] [&] [&]
void remover_inimigo(Inimigo *inimigos, Inimigo *alvo) {
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


/*
void remover_inimigas(Inimigo *alvo)
{
    Inimigo *current = inimigos;
    Inimigo *toDelete = NULL;

    while(current != NULL){
        if(current == alvo){
            //cabeça da lista
            toDelete = current;
            current = current->prox;
        }else{
            //demais
            if(current->prox == alvo){
                toDelete = current->prox;
                current->prox = toDelete->prox;
            }
        }

        if(toDelete != NULL){
            free(toDelete);
            return;
        }
        current = current->prox;
    }
}
*/

void liberar_memoria_inimigos(Inimigo *inimigos) {
	 while (inimigos) {
	    Inimigo *temp = inimigos;
	    inimigos = inimigos->prox;
	    free(temp);
	 }
	 inimigos = NULL;
}
