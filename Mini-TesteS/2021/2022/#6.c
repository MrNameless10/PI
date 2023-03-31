/*
Aceda ao projecto codeboard https://codeboard.io/projects/244386 e implemente a função calcula por forma a que devolva a soma dos primeiros 7 valores em posições ímpares da lista (assuma que a lista começa na posição 0).

Quando terminar insira aqui o código que lhe foi devolvido pelo codeboard.
*/

typedef struct nodo {
    int valor;
    struct nodo * prox;
} *LInt;

int calcula(LInt l) {
    int soma = 0;
    int i = 0;
    l = l->prox;
    while (l != NULL && i < 7) {
        soma += l->valor;
        l = l->prox->prox;
        i++;
    }
    return soma;
}

/*
	
Aceda ao projecto codeboard https://codeboard.io/projects/244621 e implemente a função cria por forma a que devolva uma árvore equilibrada com tamanho 17. A árvora é equilibrada se em todos os nodos o número de elementos do lado esquerdo difere do número de elementos do lado direito no máximo numa unidade.

Quando terminar insira aqui o código que lhe foi devolvido pelo codeboard.

*/

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;


ABin aux (int n) {
    if (n < 1)
        return NULL;

    ABin r = (ABin) malloc (sizeof(struct nodo));
    
    if (r == NULL)
        return NULL;
        
    int meio = n/2;
    r->valor = meio;
    r->esq = aux (meio);
    r->dir = aux (n - meio - 1);
    
    return r;
}

ABin cria() {
    return aux(17);
}