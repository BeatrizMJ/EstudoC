#include "jogo.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h> // Captura de teclas.


void jogo() {
    int N, x, y, i;
    char **tabuleiro, direcao; // tirar daqui e fazer em sua devida classe e alterar para constante 
    Inimigo *inimigos;        // tirar daqui e fazer em sua devida classe e alterar para constante 
    Item *itens = NULL;      // tirar daqui e fazer em sua devida classe e alterar para constante 
    srand(time(NULL));


    do {
        printf("Digite o tamanho do tabuleiro (N x N): \n");
        printf("(Observacao: apenas N entre 6 a 50)\n");
        scanf("%d", &N);
    } while(N < 6 || N > 50);

    tabuleiro = inicializar_tabuleiro(N);
    Personagem *p = criar_personagem(1, 1, tabuleiro);
    inimigos = adicionar_inimigo(x, y, tabuleiro, N);
    adicionar_item(&itens, x, y, tabuleiro, N);

    imprimir_tabuleiro(N, tabuleiro);

    while (1) {
        if (kbhit()) {
            system("cls");
            direcao = getch();
            mover_personagem(p, direcao, tabuleiro, N, inimigos);
            imprimir_tabuleiro(N, tabuleiro);
        }
    }

    liberar_memoria(tabuleiro, N, inimigos, itens, p);
}

void liberar_memoria(char **tabuleiro, int N, Inimigo *inimigos, Item *itens, Personagem *p) {
    liberar_memoria_tabuleiro(tabuleiro, N);
    liberar_memoria_inimigos(inimigos);
    liberar_memoria_itens(itens);
    liberar_memoria_personagem(p);
}
