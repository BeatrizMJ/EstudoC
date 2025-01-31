INSTRUCOES DO JOGO    
Objetivo:
Este Desafio combina os conceitos de ponteiros avançados, alocação dinâmica e
gerenciamento de estruturas de dados (listas, filas), simulando uma aplicação real que manipula
objetos dinâmicos e controle de fluxo.
Descrição:
Implemente um jogo simples onde o jogador controla um personagem em um tabuleiro
bidimensional, tentando coletar itens enquanto evita obstáculos. O tabuleiro será representado por
uma matriz dinamicamente alocada, e os personagens e itens serão gerenciados por uma estrutura de
lista ligada. O jogo também deve conter uma fila para armazenar os eventos de movimentação dos
personagens.

Requisitos:
1. Tabuleiro Dinâmico:
o O tabuleiro deve ser uma matriz NxN alocada dinamicamente, onde N é especificado
pelo usuário no início do jogo.
o O tabuleiro conterá:
▪ Células vazias.
▪ Obstáculos (representados por 'X').
▪ Itens (representados por 'I').
▪ O personagem do jogador (representado por 'P').
▪ Inimigos (representados por 'E').

2. Estruturas de Dados:
o Personagem: O personagem do jogador será representado por uma struct, contendo:
▪ Posição no tabuleiro (x, y).
▪ Pontuação (inicialmente 0).
▪ Vida (inicialmente 100).
o Lista de Inimigos: Crie uma lista ligada dinamicamente para armazenar a posição e
vida dos inimigos.
o Itens no Jogo: Use outra lista ligada para representar os itens no tabuleiro (posição e
valor do item).
o Fila de Movimentação: Implemente uma fila que armazene os comandos de
movimentação do jogador e dos inimigos (usando uma struct para o tipo de ação e
direção).

3. Movimentação:
o O jogador pode se mover nas direções (cima, baixo, esquerda, direita).
o A cada movimento, verifique:
▪ Se o jogador colidiu com um obstáculo (X).
▪ Se o jogador coletou um item (I). Isso aumenta a pontuação e remove o item
da lista.
▪ Se o jogador encontra um inimigo (E). Isso inicia um combate (simples redução
de vida).
o Inimigos também se movimentam a cada turno de forma aleatória.

4. Combate Simples:
o Quando o jogador encontra um inimigo, o jogo reduz a vida de ambos (por exemplo,
o jogador perde 10 pontos de vida e o inimigo perde 20 pontos de vida).
o Se a vida do jogador chegar a zero, o jogo termina.
o Se a vida de um inimigo chegar a zero, ele é removido da lista de inimigos.

5. Alocação Dinâmica:
o Use malloc e free para criar e liberar o tabuleiro, a lista de inimigos e a lista de itens.
o A memória deve ser gerenciada corretamente, evitando vazamentos.

6. Encerramento:
o O jogo termina quando:
▪ O jogador coleta todos os itens.
▪ A vida do jogador chega a zero.
▪ O jogador escolhe encerrar o jogo.

Regras de Implementação:
1. Estruturas sugeridas:
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
 char acao; // 'M' para movimento, 'A' para ataque
 char direcao; // 'W' para cima, 'S' para baixo, 'A' para esquerda, 'D'
para direita
 struct Movimento *prox;
} Movimento;

2. Funções sugeridas:
void inicializar_tabuleiro(int N, char **tabuleiro);
Personagem *criar_personagem(int x, int y);
void adicionar_inimigo(Inimigo **lista, int x, int y);
void adicionar_item(Item **lista, int x, int y, int valor);
void mover_personagem(Personagem *p, char direcao, char **tabuleiro, Item
**itens, Inimigo **inimigos);
void mover_inimigos(Inimigo *inimigos, char **tabuleiro);
void processar_comando_fila(Movimento **fila, Personagem *p, char
**tabuleiro);
void liberar_memoria(char **tabuleiro, Inimigo *inimigos, Item *itens);

3. Exemplo de movimentação:
o O jogador insere comandos de movimentação, e o jogo processa os comandos
enfileirados.
o Cada comando é retirado da fila e executado na ordem, até que a fila fique vazia.

4. Extras (opcional):
o Crie um sistema de log de eventos de combate e movimentação.
o Adicione uma interface de texto para exibir o tabuleiro a cada turno.
o Inclua a possibilidade de usar “poderes” que afetam os inimigos no tabuleiro
 */


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ORGANIZACAO DO MEU CODIGO:

CLASSES:

-main.c (iniciar e chamar a classe jogo.c que chama todas as outras classe)

-jogo.c (chama todas as outras classes (como um main)

-tabuleiro.c (inicaliza, cria, manipula, e limpa a memoria de um tabueliro char)

-personagem.c (inicaliza, cria, manipula um personagem em um tabuleiro)

-inimigos.c (inicaliza, cria, manipula, e limpa a memoria de uma lista encadeada de inmigos de um tabuleiro)

-itens.c (inicaliza, cria, manipula, e limpa a memoria de uma lista de itens (ou poder ou pontos para o persoangem - ainda nao decide totalmente) de um tabuleiro


BIBLOTECAS: correspondentes para cada classe exceto o main (personagem, inimigos, itens e tabuleiro possuem structs)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ARRUMAR E MELHORAR O CODIGO:

ARRUMAR:
- aleatoriedade dos itens e dos inimigos nao sobrescrever bordas e/ou caracteres   FEITO
- mover os inimigos
- // incrementar pontos a cada pontinho que passar
- nao permitir ser muito pequene ou muito grande o tabuleiro (minmo 10)  * sera que fazer o usuario escolher entre tamanhos fixos? FEITO
- diminuir ou aumentar itens/inimigos conforme o tamanho do tabueliro
- eliminar inimigo PROBLEMA
- criar obstaculos


MUDAR:
- alterar manipulacao da lista encadeada (exemplo de como deveria ficar na ultima parte dessa classe)
- transformar EM constante inimigos, tabuleiro, itens, personagem
- fazer por partes cada metodo novo criado pelo main testar antes de continuar
- arrumar as estruturas e chamados (nao precisar chamar nos parametros o tabuleiro) ou ficar chamando coisas desnecessaria e declara-las na sua propria classe



EXTRAS:
- se comer o 'o' pode comer os inimigos por um determinado tempo regredindo gradativamento a vida do inimigo
- se comer outro item ganha vida


EXEMPLO DE LISTA ENCADEADA USADA AQUI:

adicionando:

    #include <stdio.h>
    #include <stdlib.h>

    typedef struct Inimigo {
    int x, y;
    int vida;
    struct Inimigo *prox;
    } Inimigo;

    Inimigo *inimigos = NULL; // Lista encadeada inicializada vazia

    void inicializar_inimigo(int x, int y) {
    Inimigo *novo = (Inimigo *)malloc(sizeof(Inimigo));
    if (novo) {
        novo->x = x;
        novo->y = y;
        novo->vida = 60;
        novo->prox = NULL; // Novo inimigo sempre aponta para NULL

        if (inimigos == NULL) {
            // Se a lista estiver vazia, novo inimigo será o primeiro
            inimigos = novo;
        } else {
            // Percorre até o último elemento
            Inimigo *temp = inimigos;
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novo; // Adiciona no final
        }
    }
}



remoção:

    void remover_inimigo(int x, int y) {

    if (inimigos == NULL) return; // Lista vazia, nada para remover

    Inimigo *atual = inimigos;
    Inimigo *anterior = NULL;

    // Percorre a lista procurando o inimigo com as coordenadas (x, y)
    while (atual != NULL) {
        if (atual->x == x && atual->y == y) { // Encontrou o inimigo
            if (anterior == NULL) {
                // O inimigo está no início da lista
                inimigos = atual->prox;
            } else {
                // O inimigo está no meio ou no final
                anterior->prox = atual->prox;
            }
            free(atual); // Libera a memória do inimigo removido
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    }
