#include <stdio.h>

/*
	
Considere o seguinte excerto de uma função:

int main() {
  int i;
 
  for(i = 3; i < 42; i *=2){
     ...
  }

  return 0;
}

Quantas vezes é que o ciclo for será executado?
*/

int ex1() {
  int i;
  int j=0;
 
  for(i = 3; i < 42; i *=2){
     printf("%d\n", i);
     j++;
    
  }
  printf("é executado: %d\n", j);

  return 0;
}

/*

	
Considere o seguinte excerto de uma função:

int main() {
  int i;
 
  for(i = 3; i < 29; ???){
     ...
  }

  return 0;
}

Assumindo que i tem inicialmente o valor 3 e um valor limite inferior a 29, que comando de incremento usar no corpo do ciclo para que o ciclo faça 7 iterações?

*/

int ex2() {
  int i;
  int j=0;

  // 29 - 3 = 26 / 7 = 3.7142857142857144 -> 4
  for(i = 3; i < 29; i += 4){
     printf("%d\n", i);
     j++;
  }
  printf("é executado: %d\n", j);

  return 0;
}

int main() {
  ex1();
  ex2();
}