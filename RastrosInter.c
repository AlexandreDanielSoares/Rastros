#include "RastrosData.h"

int interpretador (ESTADO *e){
	char linha[BUF_SIZE];
	char col[2], lin[2];
    if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2){
    	COORDENADA coord = {*col -'a', '8' - *lin};
    	clear ();
    	if (!(jogar (e, coord))) printf ("Jogada nao possivel\n");
    	else if (winPlayer (e)) {
    	 	    //WinPlayer Ten der ser alterada e colocada na logica!!!
    			printf ("Parabens o jogador %d ganhou!!\n",e->jogador_atual); 
    			mostrar_tabuleiro (e);
    			exit ();
            }
    	mostrar_tabuleiro(e);
    }
    return 0;
} 

void mostrar_tabuleiro (ESTADO *e){
	printf("Tabuleiro:\n");
	for (int i = 0;i < 8;i++){
		printf("%d |",8-i);
        printLinha ((e -> tab [i]),i);
        putchar ('\n');
    }
    for (int i = 0; i < 3; ++i) putchar (' ');	
    for (int i = 0; i < 8; ++i) printf ("%c ",65 + i);
    putchar ('\n');
    printf("Jogada n%d Jogador n%d\n",e->num_jogadas,e->jogador_atual);
} 

void printLinha (CASA linha[],int n){
	for (int i = 0; i < 8;i++){
		if (n == 0 && i == 7) putchar ('2');
		if (n == 7 && i == 0) putchar ('1');
		else switch (linha[i]){ case VAZIO: putchar ('.'); break;
		                        case BRANCA: putchar ('*'); break;
		                        case PRETA: putchar ('#'); break;
		                        }
		putchar (' ');
	}
}

void clear (){
     printf("\e[1;1H\e[2J");
}