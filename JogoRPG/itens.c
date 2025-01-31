#include "itens.h"
#include <stdlib.h>
#include <stdio.h> //
#include <time.h>

// inicializacao de itens aqui e nao na classe jogo - arrumar

void inicializar_item(Item **itens, int x, int y, int valor) {
	Item *novo = (Item *)malloc(sizeof(Item));
	if (novo) {
		novo->x = x;
		novo->y = y;
	    novo->valor = valor;
	    novo->prox = *itens;
		*itens = novo;
	}
}

void adicionar_item(Item **itens, int x, int y, char **tabuleiro, int N) {
    int quantidade_itens = 6;
    for (int i = 0; i < quantidade_itens; i++) {
        do {
            x = rand() % (N - 2) + 1;
            y = rand() % (N - 2) + 1;
        } while (tabuleiro[x][y] != '.');

        inicializar_item(itens, x, y, 20);
        tabuleiro[x][y] = 'o';
    }
}

void liberar_memoria_itens(Item *itens) {
	 while (itens) {
	    Item *temp = itens;
	    itens = itens->prox;
	    free(temp);
	 }
	 itens = NULL;
}
