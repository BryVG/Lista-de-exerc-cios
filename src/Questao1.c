#include <stdio.h>

int main() {
    int matriz[3][3];
    int maior, menor;

    
    printf("Digite os nove elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

   
    maior = matriz[0][0];
    menor = matriz[0][0];


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

    printf("maior elemento da matriz: %d\n", maior);
    printf("menor elemento da matriz: %d\n", menor);

    return 0;
}
