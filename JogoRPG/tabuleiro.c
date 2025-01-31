#include "tabuleiro.h"
#include <stdlib.h>
#include <stdio.h>

char **inicializar_tabuleiro(int N) {
    char **tabuleiro = malloc(N * sizeof(char *));
    if (tabuleiro) {

        for (int i = 0; i < N; i++) {
            tabuleiro[i] = malloc(N * sizeof(char));

            if (tabuleiro[i]) {
                for (int j = 0; j < N; j++) {
                    if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                        tabuleiro[i][j] = 'X';
                    } else {
                        tabuleiro[i][j] = '.';
                    }
                }
            }

        }

    }
    return tabuleiro;
}


void imprimir_tabuleiro(int N, char **tabuleiro) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
            printf("%c ", tabuleiro[i][j]);
		}
        printf("\n");
    }
}


void liberar_memoria_tabuleiro(char **tabuleiro, int N) {
	for (int i = 0; i < N; i++) {
	    free(tabuleiro[i]);
	}
	free(tabuleiro);
	tabuleiro = NULL; //
}

