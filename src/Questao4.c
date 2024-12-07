#include <stdio.h>

#define CIDADES 7
#define MESES 6

int main() {
   
    float indicePluviometrico[CIDADES][MESES];

   
    float mediaCidade[CIDADES];
    float mediaMes[MESES];
    
 
    for (int i = 0; i < CIDADES; i++) {
        printf("Digite os indices pluviometricos para a cidade %d (Janeiro a Junho):\n", i + 1);
        for (int j = 0; j < MESES; j++) {
            printf("Mes %d: ", j + 1);
            scanf("%f", &indicePluviometrico[i][j]);
        }
    }


    for (int i = 0; i < CIDADES; i++) {
        float somaCidade = 0;
        for (int j = 0; j < MESES; j++) {
            somaCidade += indicePluviometrico[i][j];
        }
        mediaCidade[i] = somaCidade / MESES;
    }

 
    for (int j = 0; j < MESES; j++) {
        float somaMes = 0;
        for (int i = 0; i < CIDADES; i++) {
            somaMes += indicePluviometrico[i][j];
        }
        mediaMes[j] = somaMes / CIDADES;
    }

  
    printf("\nMedia de pluviosidade mensal de cada cidade:\n");
    for (int i = 0; i < CIDADES; i++) {
        printf("Cidade %d: %.2f\n", i + 1, mediaCidade[i]);
    }

    printf("\nMedia de pluviosidade de cada mes na regiao:\n");
    for (int j = 0; j < MESES; j++) {
        printf("Mes %d: %.2f\n", j + 1, mediaMes[j]);
    }

    return 0;
}

