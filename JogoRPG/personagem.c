#include "personagem.h"
#include <stdlib.h>
#include <stdio.h>


Personagem *criar_personagem(int x, int y, char **tabuleiro) {
    Personagem *p = (Personagem *)malloc(sizeof(Personagem)); // nao precisa de malloc paa personagem
    if (p) {
        p->x = x;
        p->y = y;
        p->vida = 300;
        p->pontos = 0;
        tabuleiro[x][y] = 'P';
    }
    return p;
}

void mover_personagem(Personagem *p, char direcao, char **tabuleiro, int N, Inimigo *inimigos) {
            static char ant = ' '; //
            //tabuleiro[p->x][p->y] = ' ';
            if(ant == '&'){
                Inimigo *current = inimigos;
                while(current != NULL){
                    if(current->x == p->x && current->y == p->y){
                        ant = '&';
                        break;
                    }else{
                        ant = '.';
                    }
                    current = current->prox;
                }

            }
	        tabuleiro[p->x][p->y] = ant;
	        switch (direcao) {
	            case 'w':
	                if (p->x > 1) p->x--;
	                break;
	            case 's':
	                if (p->x < N - 2) p->x++;
	                break;
	            case 'a':
	                if (p->y > 1) p->y--;
	                break;
	            case 'd':
	                if (p->y < N - 2) p->y++;
	                break;
	            case 'e':
	                printf("Jogo finalizado.\n");
	                return;
	            default:
	                printf("Tecla invalida.\n");
	                break;
	        }


	        ant = (tabuleiro[p->x][p->y] == '.') ? ' ' : tabuleiro[p->x][p->y];

	        tabuleiro[p->x][p->y] = 'P';

	        combate_PXI(p, inimigos, tabuleiro);
}

void combate_PXI (Personagem *p, Inimigo *inimigos, char **tabuleiro) {

    Inimigo *current = inimigos;
    while(current != NULL)
    {
        if (p->x == current->x && p->y == current->y) {
            p->vida -= 10;
            current->vida -= 20;
            printf("Combate! Vida: personagem %d e inimigo %d.\n", p->vida, current->vida);
        }

        if (p->vida <= 0) {
            printf("Voce Perdeu! Jogo finalizado.\n");
        }

        if (current->vida <= 0) {
            printf("Inimigo eliminado!\n");
            remover_inimigo(inimigos, current);
            //remover_inimigas(current);
            return;
        }
        current = current->prox;
    }
}


void liberar_memoria_personagem(Personagem *p) {
	free(p);
	p = NULL;
}
