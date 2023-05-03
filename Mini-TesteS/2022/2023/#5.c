#include <stdlib.h>
#include <string.h>


typedef struct aluno {
  char *nome;
  int nr;
  int nota;
} Aluno;


typedef struct cel {
  Aluno aluno;
  struct cel *prox;
} *Turma;


int adicionaAluno(Turma *t, char *nome, int nr, int nota) {

  Aluno novo_aluno;
  novo_aluno.nome = malloc(sizeof(char) * (strlen(nome) + 1));
  if (novo_aluno.nome == NULL) {
    return 1; 
  }
  strcpy(novo_aluno.nome, nome); 
  novo_aluno.nr = nr;
  novo_aluno.nota = nota;

  struct cel *nova_cel = malloc(sizeof(struct cel)); 
  if (nova_cel == NULL) {
    free(novo_aluno.nome);
    return 1; 
  }
  nova_cel->aluno = novo_aluno; 
 
  while (*t != NULL && (*t)->aluno.nota < nota) { 
    t = &((*t)->prox);
  }

  nova_cel->prox = *t;
  *t = nova_cel;

  return 0; 

}

void printTurma(Turma t) {
  while (t != NULL) {
    printf("Nome: %s, Nr: %d, Nota: %d\n", t->aluno.nome, t->aluno.nr, t->aluno.nota);
    t = t->prox;
  }
}

int main() {
  Turma turma = NULL;

  if (adicionaAluno(&turma, "João", 1, 80) != 0) {
    printf("Erro ao adicionar aluno.\n");
  }

  if (adicionaAluno(&turma, "Maria", 2, 85) != 0) {
    printf("Erro ao adicionar aluno.\n");
  }

  if (adicionaAluno(&turma, "Pedro", 3, 75) != 0) {
    printf("Erro ao adicionar aluno.\n");
  }

  if (adicionaAluno(&turma, "Ana", 4, 90) != 0) {
    printf("Erro ao adicionar aluno.\n");
  }

  printf("Turma ordenada por ordem crescente da nota dos alunos:\n");
  printTurma(turma);

  return 0;
}