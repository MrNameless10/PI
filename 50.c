/*
Defina uma fun ̧c ̃ao int bitsUm (unsigned int n) que calcula o n ́umero de bits iguais a 1
usados na representa ̧c ̃ao bin ́aria de um dado n ́umero n. (https://codeboard.io/projects/
13548)
*/
int bitsUm (unsigned int x){
    int i = 0;
    int um = 0;
    for (i = x; i>0; i/=2){
        if (i % 2 ==1){
            um++;
        }
    }
    return um;
}

/*
Defina uma fun ̧c ̃ao int trailingZ (unsigned int n) que calcula o n ́umero de bits a 0 no
final da representa ̧c ̃ao bin ́aria de um n ́umero (i.e., o expoente da maior potˆencia de 2 que  ́e
divisor desse n ́umero).
*/
int trailingZ(unsigned int n){
    int i = 0;
    int um = 0;
    if (n == 0)
        return 32;
    for (i = n; i>0; i/=2){
        if (i % 2 ==0){
            um++;
        }
    }
    return um;
}


/*
Defina uma fun ̧c ̃ao int qDig (unsigned int n) que calcula o n ́umero de d ́ıgitos necess ́arios
para escrever o inteiro n em base decimal. Por exemplo, qDig (440) deve retornar 3. (https:
//codeboard.io/projects/13583)
*/

int qDig (unsigned int n){
	int i,x = 0, resto = 1;
	for(i = 1; resto != n; i*=10) {
        print("%d",n);
		resto = n % i;
		if (resto != n)
			x++;
	}
	return x;
}

/*
Apresente uma defini ̧c ̃ao da fun ̧c ̃ao pr ́e-definida em C char *strcat (char s1[], char
s2[]) que concatena a string s2 a s1 (retornando o endere ̧co da primeira). (https://
codeboard.io/projects/14490)
*/
char *mystrcat(char s1[], char s2[]) {
	int j,i;
	for(j = 0; s1[j] != '\0'; j++);
	for (i = 0; s2[i] != '\0';i++,j++)
		s1[j] = s2[i];
	s1[j] = '\0';
	return s1;
}

/*
Apresente uma defini ̧c ̃ao da fun ̧c ̃ao pr ́e-definida em C char *strcpy (char *dest, char
source[]) que copia a string source para dest retornando o valor desta  ́ultima. (https:
//codeboard.io/projects/14491
*/

char* mystrcpy(char* dest, char source[]) {
    char* result = dest;
    while((*dest = *source)) { source++; dest++; }
    return result;
}

/*
Apresente uma defini ̧c ̃ao da fun ̧c ̃ao pr ́e-definida em C int strcmp (char s1[], char s2[])
que compara (lexicograficamente) duas strings. O resultado dever ́a ser
• 0 se as strings forem iguais
• <0 se s1 < s2
• >0 se s1 > s2
(https://codeboard.io/projects/14492)

*/

int mystrcmp(char s1[], char s2[]) {
	int i=0;
    while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
	return s1[i]-s2[i];
}