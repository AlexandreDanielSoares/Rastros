#include "RastrosData.h"

int jogar (ESTADO *e, COORDENADA c){
	printf("Jogar %d %d\n", c.coluna, c.linha);
	int x = e->centro.linha;
	int y = e->centro.coluna;
	if ((c.coluna == y && c.linha == x) || 
		limite (c.linha,x) || 
		limite (c.coluna,y) || 
		(e -> tab[c.linha][c.coluna] == PRETA )) return 0;
    else {
       if (e->jogador_atual == 2){
	       // Jogada anterior Caso seja jogador 2
       		e->jogador_atual = 1;
       		e->num_jogadas ++;
       }
       else{
	// Jogada anterior Caso seja jogador 1
       	e->jogador_atual ++;
       }
       e->tab[x][y] = PRETA;
       e->tab[c.linha][c.coluna] = BRANCA;
       e->centro.linha = c.linha;
       e->centro.coluna = c.coluna;
       return 1;
    }
}

int limite (int novo,int centro){
	return ((novo > (centro + 1)) || (novo < (centro - 1)) || novo < 0 || novo > 8);
}
