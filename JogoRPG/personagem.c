#include "personagem.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h> // Captura de teclas.
#include <stdbool.h>

Personagem *p = NULL;

int criar_personagem(int x, int y, char **tabuleiro) {
    p = malloc(sizeof(Personagem));
    if (p == NULL) {
       printf("Erro de alocação de memória do personagem\n");
       return -1;
    } else {
        p->x = x;
        p->y = y;
        p->vida = 100;
        p->pontos = 0;
        tabuleiro[x][y] = 'P';
    }
    return 0; //
}


char direcao;
void teclado_personagem(int N, char **tabuleiro, Inimigo *inimigos) {
    while (1) {
       if (kbhit()) {
        system("cls");
        direcao = getch();
        mover_personagem(N, tabuleiro, inimigos);
        imprimir_tabuleiro(N);
        }
    }
}


void mover_personagem(int N, char **tabuleiro, Inimigo *inimigos) {

    int xNovo = p->x;
    int yNovo = p->y;

    switch (direcao)
    {
    case 'w':
        if (xNovo > 1) xNovo--;
        break;
    case 's':
        if (xNovo < N - 2) xNovo++;
        break;
    case 'a':
        if (yNovo > 1) yNovo--;
        break;
    case 'd':
        if (yNovo < N - 2) yNovo++;
        break;
    case 'e':
        printf("Jogo finalizado.\n");
        return;
    default:
        printf("Tecla invalida.\n");
        break;
    }

    Inimigo *atual = inimigos; // Começa pelo primeiro inimigo
    if (atual == NULL) {
        printf("Nenhum inimigo na lista.\n");
        return;
    }

    printf("Lista de Inimigos:\n");
    while (atual != NULL) {
        printf("Inimigo em (x: %d, y: %d), Vida: %d\n", atual->x, atual->y, atual->vida);
        atual = atual->prox; // Avança para o próximo inimigo
    }


    bool venceu = false;
    bool encontrouInimigo = false;
    Inimigo *temp = inimigos;
    while (temp != NULL) {
        if (xNovo == temp->x && yNovo == temp->y) {
            encontrouInimigo = true;
            printf("Combate! ");
            venceu = combate(temp, tabuleiro);
            //todo: sair do while caso o p ganhe
        }

        temp = temp->prox;  // Avança para o próximo inimigo na lista
    }

    if ((encontrouInimigo && venceu) || !encontrouInimigo){
        tabuleiro[p->x][p->y] = ' ';
        tabuleiro[xNovo][yNovo] = 'P';
        p->x = xNovo;
        p->y = yNovo;
    }
}


bool combate(Inimigo *inimigos, char **tabuleiro) {
    Inimigo *atual = inimigos;

    p->vida -= 10;
    atual->vida -= 20;
    printf("Vida: personagem %d e inimigo %d.\n", p->vida, atual->vida);

    if (p->vida <= 0)
    {
        printf("Voce Perdeu! Jogo finalizado.\n");
        exit(0);
        //return false;
    }

    if (atual->vida <= 0)
    {
        printf("Inimigo eliminado!\n");
        remover_inimigo(atual);
        return true;
    }

    return false;
}

void liberar_memoria_personagem() {
    free(p);
    p = NULL;
}
