//26 inserir um elemento x num array ordenado (https://codeboard.io/projects/14836)

void insert(int v[],int N, int x){
    int i;
    for(i = N-1; i >= 0 && v[i] > x; i--)
        v[i+1] = v[i];
    v[i+1] = x;
}

//other solution

void insert(int v[],int N, int x){
    for(int i = 0; i < N; i++) {
        if(v[i] > x) {
            for(int j = N; j > i; j--) {
                v[j] = v[j - 1];
            }
            v[i] = x;
            break;
        }
        if(i == N - 1) {
            v[N] = x;
        }
    }
}