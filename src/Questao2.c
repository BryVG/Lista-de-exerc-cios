#include <stdio.h>

char tabuleiro[3][3]; 
char jogadorAtual = 'X'; 

void comecarTabuleiro() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' '; 
        }
    }
}

void imprimirTabuleiro() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}


int verificarVitoria() {
   
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return 1; 
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return 1;
        }
    }

   
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return 1;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return 1; 
    }

    return 0;
}

int verificarEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1; 
}


void fazerJogada() {
    int linha, coluna;
    while (1) {
        printf("Jogador %c, digite a linha e a coluna (0, 1 ou 2) para a sua jogada: ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        
        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ') {
            tabuleiro[linha][coluna] = jogadorAtual; 
            break;
        } else {
            printf("Posicao invalida. Tente novamente.\n");
        }
    }
}


void alternarJogador() {
    if (jogadorAtual == 'X') {
        jogadorAtual = 'O';
    } else {
        jogadorAtual = 'X';
    }
}

int main() {
    comecarTabuleiro();
    int vitoria = 0;

    while (1) {
        imprimirTabuleiro();
        fazerJogada();
        vitoria = verificarVitoria();

        if (vitoria) {
            imprimirTabuleiro();
            printf("Jogador %c venceu!\n", jogadorAtual);
            break;
        }

        if (verificarEmpate()) {
            imprimirTabuleiro();
            printf("Empate! O jogo acabou sem vencedor.\n");
            break;
        }

        alternarJogador(); 
    }

    return 0;
}

