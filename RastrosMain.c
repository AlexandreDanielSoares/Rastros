#include "RastrosData.h"

int main () {
	ESTADO *e = inicializar_estado ();
	clear ();
	mostrar_tabuleiro (e);
	while (1)
	 interpretador (e);
	return 0;
}

ESTADO *inicializar_estado (){
	CASA t[8][8];
	JOGADAS j;
	COORDENADA c = {.coluna = 4,.linha = 3};
	for (int i = 0; i < 8; i++)
		for (int i1 = 0; i1 < 8; i1++)
			t[i][i1] = VAZIO;
    t[3][4] = BRANCA;
	ESTADO e = {
		tab: t,
		centro: c,
		jogadas: j,
		num_jogadas: 1,
		jogador_atual: 1
	};
	return &e; 
}