#include <stdio.h>
#include <stdlib.h>



typedef struct {
    int numero;               
    int dia;                  
    int hora;                 
    int minuto;               
    int aeroporto_saida;      
    int aeroporto_chegada;    
    int rota;                 
    float tempo_estimado;     
    int passageiros_a_bordo;  
} Voo;


void cadastrarVoo(Voo *voos, int *count) {
    
    Voo novoVoo;

   
    printf("Digite os dados do novo voo:\n");

    printf("Numero do voo: ");
    scanf("%d", &novoVoo.numero);
    
    printf("Dia do voo (1 - seg, 2 - ter, 3 - qua, 4 - qui, 5 - sex, 6 - sab, 7 - dom, 8 - diário): ");
    scanf("%d", &novoVoo.dia);

    printf("Hora do voo (hora): ");
    scanf("%d", &novoVoo.hora);
    
    printf("Minuto do voo: ");
    scanf("%d", &novoVoo.minuto);

    printf("ID do aeroporto de saida: ");
    scanf("%d", &novoVoo.aeroporto_saida);

    printf("ID do aeroporto de chegada: ");
    scanf("%d", &novoVoo.aeroporto_chegada);

    printf("ID da rota: ");
    scanf("%d", &novoVoo.rota);

    printf("Tempo estimado de voo (em horas): ");
    scanf("%f", &novoVoo.tempo_estimado);

    printf("Numero de passageiros a bordo: ");
    scanf("%d", &novoVoo.passageiros_a_bordo);

   
    voos[*count] = novoVoo;
    (*count)++;

    printf("\nVoo cadastrado com sucesso!\n");
}


int main() {
    Voo *voos = (Voo*) malloc(sizeof(Voo)); 
    int count = 0; 
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar novo voo\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarVoo(voos, &count);
                break;
            case 2:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 2);

    free(voos); 
    return 0;
}
