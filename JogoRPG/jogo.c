#include "jogo.h"
#include <stdlib.h>
#include <stdio.h>
#include "inimigos.h"

void jogo() {
    int N, x, y;

    do {
        printf("Digite o tamanho do tabuleiro (N x N): \n");
        printf("(Observacao: apenas N entre 10 a 40)\n");
        scanf("%d", &N);
    } while(N < 10 || N > 40);

    char **tabuleiro = inicializar_tabuleiro(N);
    criar_personagem(1, 1, tabuleiro);

    Inimigo *inimigos = criar_inimigo(x, y, tabuleiro, N);

    //adicionar_item(&itens, x, y, tabuleiro, N);

    imprimir_tabuleiro(N);
    teclado_personagem(N, tabuleiro, inimigos);


    liberar_memoria(N);
}

void liberar_memoria(int N) {
    liberar_memoria_tabuleiro(N);
    liberar_memoria_personagem();
    liberar_memoria_inimigos();
    //liberar_memoria_itens();
}
