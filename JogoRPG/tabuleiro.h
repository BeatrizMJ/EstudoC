#ifndef TABULEIRO_H
#define TABULEIRO_H

char **inicializar_tabuleiro(int N);
void imprimir_tabuleiro(int N, char **tabuleiro);
void liberar_memoria_tabuleiro(char **tabuleiro, int N);

#endif
