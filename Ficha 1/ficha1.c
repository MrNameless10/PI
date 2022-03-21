#include <stdio.h>
#include <math.h>
/*
int main() {
    char a, b, c;
    a = 'A'; b = ' '; c = '0';
    printf ("%c %d\n", a, a);
    a = a+1; c = c+2;
    printf ("%c %d %c %d\n", a, a, c, c);
    c = a + b;
    printf ("%c %d\n", c, c);

}
*/

void quadrado(int size){
  int i,j;
  for(i=0;i<size;i++){
    for (j=0;j<size;j++)
      printf("#");
    printf("\n");
  }
}

void xadrez(int size){
  int i,j;
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      if((i+j)%2) printf("*");
      else printf("_");
    }
  printf("\n");
  }
}

void triangulo_horizontal(int size){
  int i,j;
  for(i=0;i<size;i++){
    for(j=0;j<i;j++){
      printf("*");
    }
    printf("\n");
  }
  for(i=size;i>0;i--){
    for(j=0;j<i;j++){
      printf("*");
    }
    printf("\n");
  }
}

void triangulo_vertical(int size){
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1 - i; j++) putchar(' ');
        for(int j = 0; j < 1 + 2 * i; j++) putchar('*');
        putchar('\n');
    }
}  

int circulo(int raio) {
    int num = 0;
    for (int i =  0; i < raio*2+1; i++) {
        for (int j = 0; j < raio*2+1; j++) {
            float x = raio - i;
            float y = raio - j;
            float dist = sqrt(x*x + y*y);
            if (dist <= raio) {
                putchar('*');
                num++;
            }
            else putchar(' ');
        }
        putchar('\n');
    }

    return num;
}



int main(){
  quadrado(5);
  printf("\n");
  xadrez(5);
  printf("\n");
  triangulo_horizontal(5);
  printf("\n");
  triangulo_vertical(5);
  printf("\n");
  circulo(4);
  
  return 0;
}

