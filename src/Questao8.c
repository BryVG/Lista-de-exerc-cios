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

void consultaVoo(Voo *voos, int count, int numeroVoo) {
    int encontrado = 0;
    for (int i = 0; i < count; i++) {
        if (voos[i].numero == numeroVoo) {
        	printf("\nDetalhes do voo %d:\n", voos[i].numero);
            printf("Dia: %d\n", voos[i].dia);
            printf("Hora: %02d:%02d\n", voos[i].hora, voos[i].minuto);
            printf("Aeroporto de saida ID: %d\n", voos[i].aeroporto_saida);
            printf("Aeroporto de chegada ID: %d\n", voos[i].aeroporto_chegada);
            printf("Rota ID: %d\n", voos[i].rota);
            printf("Tempo estimado de voo: %.2f horas\n", voos[i].tempo_estimado);
            printf("Passageiros a bordo: %d\n", voos[i].passageiros_a_bordo);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("\nVoo nao encontrado!\n");
    }
}


int main() {
    Voo *voos = (Voo*) malloc(sizeof(Voo)); 
    int count = 0; 
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar novo voo\n");
        printf("2. Consultar voo pelo numero\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarVoo(voos, &count);
                break;
            case 2:
                {
                    int numeroVoo;
                    printf("Digite o numero do voo que deseja consultar: ");
                    scanf("%d", &numeroVoo);
                    consultaVoo(voos, count, numeroVoo);
                }
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
            
        }
    } while(opcao != 3);

    free(voos); 
    return 0;
}
