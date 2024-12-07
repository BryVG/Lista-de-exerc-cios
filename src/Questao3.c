#include <stdio.h>

#define ALUNOS 5
#define PROVAS 4

int main() {
    float notas[ALUNOS][PROVAS];
    float mediaAluno[ALUNOS]; 
    float somaTurma = 0;

  
    for (int i = 0; i < ALUNOS; i++) {
        printf("Digite as notas do aluno %d:\n", i + 1);
        for (int j = 0; j < PROVAS; j++) {
            printf("Nota da prova %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

   
    for (int i = 0; i < ALUNOS; i++) {
        float somaNotas = 0;
        for (int j = 0; j < PROVAS; j++) {
            somaNotas += notas[i][j];
        }
        mediaAluno[i] = somaNotas / PROVAS;
        somaTurma += mediaAluno[i];
    }


    for (int i = 0; i < ALUNOS; i++) {
        printf("\nMedia do aluno %d: %.2f\n", i + 1, mediaAluno[i]);
    }

 
    float mediaTurma = somaTurma / ALUNOS;
    printf("\nMedia da turma: %.2f\n", mediaTurma);

    return 0;
}

