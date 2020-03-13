#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024 

//Dados ----------------------------------------
typedef enum {
	VAZIO, 
	BRANCA, 
	PRETA
} CASA;

typedef struct {
	int coluna;
	int linha;
} COORDENADA;

typedef struct {
	COORDENADA jogador1;
	COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
	CASA tab[8][8];
	COORDENADA centro;
	JOGADAS jogadas;
	int num_jogadas;
	int jogador_atual;
} ESTADO;
//Main -------------------------------------------
ESTADO *inicializar_estado ();
//Interface --------------------------------------
int interpretador (ESTADO *e);
void mostrar_tabuleiro (ESTADO *e);
void printLinha (CASA linha[],int nuLinha);
void clear ();
//Logica -----------------------------------------
int jogar (ESTADO *e, COORDENADA c);
int limite (int novo,int centro);