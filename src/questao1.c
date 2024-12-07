

int main() {
    int matriz[3][3];
    int maior, menor;

    // Leitura dos valores da matriz
    printf("Digite os 9 elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Inicializando maior e menor com o primeiro elemento da matriz
    maior = menor = matriz[0][0];

    // Percorrendo a matriz para encontrar o maior e o menor valor
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
    }

    // Exibindo os resultados
    printf("O maior elemento da matriz é: %d\n", maior);
    printf("O menor elemento da matriz é: %d\n", menor);

    return 0;
}
