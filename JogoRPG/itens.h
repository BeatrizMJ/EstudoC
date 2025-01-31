#ifndef ITENS_H
#define ITENS_H

typedef struct Item {
    int x, y, valor;
    struct Item *prox;
} Item;

void inicializar_item(Item **itens, int x, int y, int valor);
void adicionar_item(Item **itens, int x, int y, char** tabuleiro, int N);
void liberar_memoria_itens(Item *itens);

#endif
