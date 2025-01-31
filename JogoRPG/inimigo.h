#ifndef INIMIGOS_H
#define JOGO_H


typedef struct {
    int x, y;
    int vida;
    int pontos;
} Personagem;

typedef struct Inimigo {
    int x, y;
    int vida;
    struct Inimigo *prox;
} Inimigo;

typedef struct Item {
    int x, y;
    int valor;
    struct Item *prox;
} Item;

typedef struct Movimento {
    char acao;
    char direcao;
    struct Movimento *prox;
} Movimento;


void inicializar_tabuleiro(int N, char **tabuleiro);
void imprimir_tabuleiro(int N, char **tabuleiro, Personagem *p, Inimigo *inimigos, Item *itens);
Personagem *criar_personagem(int x, int y);
void adicionar_inimigo(Inimigo **lista, int x, int y);
void adicionar_item(Item **lista, int x, int y, int valor);
void mover_personagem(Personagem *p, char direcao, char **tabuleiro, int N, Item *itens, Inimigo *inimigos);
void mover_inimigos(Inimigo *inimigos, char **tabuleiro);
void liberar_memoria(char **tabuleiro, int N, Inimigo *inimigos, Item *itens, Personagem *p);

#endif

