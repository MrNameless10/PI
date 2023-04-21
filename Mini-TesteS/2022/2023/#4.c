#include <stdio.h>
#include <stdlib.h>

#define TAM_TURMA 40

typedef struct estudante {
    char nome[50];
    int nota;
} Estudante;

/*
A turma da professora tem uma particularidade especial: as notas de cada estudante estão diretamente relacionadas com o seu nome! Como é que isso funciona?
Bem, para saber a nota de um estudante, apenas precisamos de somar as posições no abecedário das letras minúsculas do seu nome e dividir o valor final por 20.
A nota de PI será igual ao resto dessa divisão.
Nenhum nome tem acentos, mas pode ser constituído por mais do que uma palavra. Nesses casos, deve ter em conta todas as letras minúsculas apenas do primeiro nome.
Por exemplo, uma aluna chamada "Maria da Piedade" terá uma nota a PI igual a ( 'a' + 'r' + 'i' + 'a' ) % 20 = ( 1 + 18 + 9 + 1 ) % 20 = 29 % 20 = 9.
A letra 'a' corresponde à posição 1, 'b' à posição 2, 'c' à posição 3, etc.
*/

//Função que calcula a nota de um estudante a partir do seu nome 
int calcula_nota(char nome[]) {
    int sum = 0;
    int i = 1;  
    while (nome[i] != '\0' && nome[i] != ' ') {
        if (nome[i] >= 'a' && nome[i] <= 'z') {
            sum += nome[i] - 'a' + 1;
        }
        i++;
    }
    return sum % 20;
}

void preenche_notas(Estudante turma[], int N) {
    for (int i = 0; i < N; i++) {
        turma[i].nota = calcula_nota(turma[i].nome);
    }
}


int compare(const void* a, const void* b) {
    const Estudante* estudante1 = (const Estudante*)a;
    const Estudante* estudante2 = (const Estudante*)b;
    return strcmp(estudante1->nome, estudante2->nome);
}

//Parecido ao que foi feito nas aulas
int compare2(char nome1[], char nome2[]) {
    int i = 0;
    while (nome1[i] != '\0' && nome2[i] != '\0') {
        if (nome1[i] != nome2[i]) {
            return nome1[i] - nome2[i];
        }
        i++;
    }
    return nome1[i] - nome2[i];
}


void ordena_turma(Estudante turma[], int N) {
    //por ordem alfabética de nomes
    qsort(turma, N, sizeof(Estudante), compare);
}

void ordena_preenche_turma(Estudante turma[], int N) {
    // ordena a turma por ordem alfabética de nomes
    qsort(turma, N, sizeof(Estudante), compare);

    // preenche as notas dos primeiros 12 estudantes da turma (ordem alfabética)
    int sum = 0;
    for (int i = 0; i < 12; i++) {
        sum += calcula_nota(turma[i].nome);
    }
    printf("Soma das notas dos primeiros 12 alunos: %d\n", sum);
}


int main() {

    Estudante turma[TAM_TURMA] = {
        { "Natasha Romanoff", 0 }, { "Tara Jones", 0 },
        { "Sun Bak", 0 }, { "Dipper Pines", 0 },
        { "Shirley Bennett", 0 }, { "Loki", 0 },
        { "Hank Pym", 0 }, { "Jeff Winger", 0 },
        { "Kala Dandekar", 0 }, { "Charlie Spring", 0 },
        { "Kate Bishop", 0 }, { "Will Gorski", 0 },
        { "Joy Wang", 0 }, { "Rick Grimes", 0 },
        { "Grogu", 0 }, { "Scott Lang", 0 },
        { "Nia Nal", 0 }, { "Wanda Maximoff", 0 },
        { "Elle Argent", 0 }, { "Soos", 0 },
        { "Tommy Miller", 0 }, { "Darcy Olsson", 0 },
        { "Britta Perry", 0 }, { "Mabel Pines", 0 },
        { "Amity Blight", 0 }, { "Lilith Clawthorne", 0 },
        { "Candace", 0 }, { "America Chavez", 0 },
        { "Arthur Curry", 0 }, { "Gus Porter", 0 },
        { "Ben Chang", 0 }, { "Gamora", 0 },
        { "Gollum", 0 }, { "Darth Vader", 0 },
        { "Victor Stone", 0 }, { "Waymond Wang", 0 },
        { "Leia Organa", 0 }, { "Princess Carolyn", 0 },
        { "Drax", 0 }, { "Lito Rodriguez", 0 }
    };
    // Calcula as notas de cada estudante
    preenche_notas(turma, TAM_TURMA);

    /*
    ###############################################################################
    Qual é a nota do estudante na posição 9 da turma antes de ordenar a turma? 
    ###############################################################################
    */

    // Imprime o aluno no indice 9 antes de ordenar
    printf("%s %d\n", turma[9].nome, turma[9].nota);

    // Calcula a nota de um estudante específico
    int score = calcula_nota("Charlie Spring");
    printf("%d\n", score);


    /*
    #####################################################################################################################
    Qual é a soma das notas dos primeiros 12 estudantes da turma depois de ordenar a turma por ordem alfabética de nomes?
    #####################################################################################################################
    */

    // Ordena a turma por ordem alfabética de nomes
    ordena_turma(turma, TAM_TURMA);
    for (int i = 0; i < TAM_TURMA; i++) {
        printf("%s %d\n" , turma[i].nome, turma[i].nota);
    }


    // Calcula e imprime a soma das notas dos primeiros 12 estudantes
    int sum = 0;
    for (int i = 0; i < 12; i++) {
      sum += turma[i].nota;
    }
    printf("A soma das notas dos primeiros 12 alunos é: %d\n", sum);

    // Ordena a turma por ordem alfabética de nomes e preenche as notas dos primeiros 12 estudantes
    ordena_preenche_turma(turma, TAM_TURMA);


    return 0;
}