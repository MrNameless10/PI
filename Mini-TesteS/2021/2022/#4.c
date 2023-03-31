/*
Aceda ao projecto codeboard https://codeboard.io/projects/326086 e implemente a função corrige. Dada uma string só com digitos, esta função deve alterar alguns dos zeros por forma a soma de todos digitos seja 4.677. Assuma que a string tem sempre zeros suficientes para que seja possível atingir essa soma.

Por exemplo, se a string for "932010" e a soma pretendida for 17 pode alterar a string para "9322010", "932012" ou "932111".
*/

void corrige(char s[]) {
    int soma_atual = 0;
    int i, diferenca;
    char d;
    
    // calcular a soma atual de todos os dígitos na string
    for (i = 0; s[i] != '\0'; i++) {
        soma_atual += s[i] - '0';
    }
    
    // calcular a diferença entre a soma pretendida e a soma atual
    diferenca = 4677 - soma_atual;
    
    // substituir zeros pela diferença até que a soma atual seja igual à soma pretendida
    for (i = 0; s[i] != '\0'; i++) {
        if (diferenca == 0) {
            break;
        }
        if (s[i] == '0') {
            d = diferenca > 9 ? '9' : diferenca + '0';
            s[i] = d;
            diferenca -= d - '0';
        }
    }
}

//other solution
void corrige(char s[]) {
    int somaFinal = 17;
    int total = 0;
    char *ite;
    
    for (ite = s; *ite != '\0'; ite++) {
        if (*ite != '0') total += *ite - '0';
    }
    
    for(ite = s; *ite != '\0' && total != somaFinal; ite++) {
        if (*ite == '0') {
            int n = somaFinal - total;
            if (n >= 10) n = 9;
            
            total += n;
            *ite = '0' + n;
        }
    }
}


/*
Aceda ao projecto https://codeboard.io/projects/326015 e implemente a função nesimo que dado um array com N posições devolve a 105ª posição mais perto da origem.

Por exemplo, se o array tiver os pontos {4,3}, {3,2},{1,1},{0,1} a 3ª posição mais próxima da origem é a posição {3,2}.

*/

typedef struct {
    int x, y;
} Posicao;

int dist(Posicao p) {
    return (p.x*p.x + p.y*p.y);
}

void insereOrd(Posicao nums[], int N, Posicao p) {
    int i, j;
    
    for(i = 0; i < N; i++) {
        if (dist(nums[i]) > dist(p)) {
            for (j = i+1; j <= N; j++) {
                nums[j] = nums[j-1];
            }
            break;
        }
    }
    
    nums[i] = p;
}

Posicao nesimo(Posicao a[], int N) {
    int k = 2;
    Posicao nums[N];

    nums[0] = a[0];
    
    int i;
    for (i = 0; i < N; i++) {
        insereOrd(nums, i, a[i]);
    }
    
    return nums[k-1];
}

