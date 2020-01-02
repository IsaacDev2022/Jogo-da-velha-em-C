#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Funções
void tab (char Pos [3][3]);
void menuStart ();
void option ();

// Variáveis
char Pos [3][3];
char Casas [3][3];
char res;
int escolha, jogadas, l, c, vez = 0, i, j;


int main() {
	setlocale (LC_ALL, "Portuguese");
	
	menuStart ();
		
	option ();
	
		switch (escolha){
			case 01:{ // 
				do {
		jogadas = 1;
		
			// Limpa a matriz para inserir o X e O
			for (i = 0;i <= 2; i++){
				for (j = 0;j <= 2;j++){
					Casas [i][j] = ' ';
				}
			}
			
			do {
				
				tab (Casas);
				if (vez%2==0) {
					printf ("Jogador X\n");
				}
				
				else {
					printf ("Jogador O\n");
				}
				
				printf ("\nDigite as linha: ");
					scanf ("%d", &l);
				printf ("Digite a coluna: ");
					scanf ("%d", &c);
					system ("cls");
					
					if (l < 1 || c < 1 || c > 3){
						l = 0;
						c = 0;
					}
					
					else if (Casas [l-1] [c-1] != ' '){
						l = 0;
						c = 0;
					}
					
					else {
						if (vez%2==0){
							Casas [l-1][c-1] = 'X'; // Condição para inserir o X
						}
						else {
							Casas [l-1][c-1] = 'O'; // Condição para inserir o 0
						}
					}
					
				vez++;
				jogadas++;
				
		// Condições para o X ganhar
			if(Casas [0][0] == 'X' && Casas [0][1] == 'X' && Casas [0][2] == 'X') jogadas = 11;
			if(Casas [1][0] == 'X' && Casas [1][1] == 'X' && Casas [1][2] == 'X') jogadas = 11;
			if(Casas [2][0] == 'X' && Casas [2][1] == 'X' && Casas [2][2] == 'X') jogadas = 11;
			if(Casas [0][0] == 'X' && Casas [2][0] == 'X' && Casas [2][0] == 'X') jogadas = 11;
			if(Casas [0][2] == 'X' && Casas [1][2] == 'X' && Casas [2][2] == 'X') jogadas = 11;
			if(Casas [0][0] == 'X' && Casas [1][1] == 'X' && Casas [2][2] == 'X') jogadas = 11;
			if(Casas [0][2] == 'X' && Casas [1][1] == 'X' && Casas [2][0] == 'X') jogadas = 11;

		// Condições para o O ganhar
			if(Casas [0][0] == '0' && Casas [0][1] == '0' && Casas [0][2] == '0') jogadas = 12;
			if(Casas [1][0] == '0' && Casas [1][1] == '0' && Casas [1][2] == '0') jogadas = 12;
			if(Casas [2][0] == '0' && Casas [2][1] == '0' && Casas [2][2] == '0') jogadas = 12;
			if(Casas [0][0] == '0' && Casas [2][0] == '0' && Casas [2][0] == '0') jogadas = 12;
			if(Casas [0][2] == '0' && Casas [1][2] == '0' && Casas [2][2] == '0') jogadas = 12;
			if(Casas [0][0] == '0' && Casas [1][1] == '0' && Casas [2][2] == '0') jogadas = 12;
			if(Casas [0][2] == '0' && Casas [1][1] == '0' && Casas [2][0] == '0') jogadas = 12;

			} while (jogadas <= 9);
		
			tab (Casas);
			if (jogadas == 10) printf ("Jogo emparado\n");
			if (jogadas == 11) printf ("Vencedor X\n");
			if (jogadas == 12) printf ("Vencedor O\n");
			printf ("Deseja jogar novamente? [S - N]: "); // Retorna caso o jogador queira jogar novamente
				scanf ("%c", &res);
		} while (res == 'S');
				
				break;
			} 
			
			case 02: exit (2); // Sai do programa
		}
		
	return 0;
}

// Fubção do início
void menuStart (){
		printf ("|*******************************************|\n");
		printf ("|                            	            |\n");
		printf ("|\tBem vindo ao jogo da velha          |\n");
		printf ("|                                           |\n");
		printf ("|*******************************************|\n");
		getch ();

		system ("cls");	
}

// Função menu de opções
void option (){
		printf ("|*******************************************|\n");
		printf ("|                            	            |\n");
		printf ("|\tEscolha uma das opções:             |\n");
		printf ("|\t[1] - Jogar                         |\n");
		printf ("|\t[2] - Sair                          |\n");
		printf ("|                                           |\n");
		printf ("|*******************************************|\n");
		printf ("\nOpção: ");
			scanf ("%d", &escolha);
	
		system ("cls");	

}

// Função para montar o tabuleiro jogável
void tab (char Pos [3][3]){
		printf ("\t %c | %c | %c \n", Pos [0][0], Pos [0][1], Pos [0][2]);
		printf ("\t-----------\n");
		printf ("\t %c | %c | %c \n", Pos [1][0], Pos [1][1], Pos [1][2]);
		printf ("\t-----------\n");
		printf ("\t %c | %c | %c \n", Pos [2][0], Pos [2][1], Pos [2][2]);
}

