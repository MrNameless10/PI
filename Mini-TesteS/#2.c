#include <stdio.h>

/*
A seguinte função imprime os 4 últimos digitos dos primeiros n números da sequência de Fibonacci.

########################################################
# Quantos dos números impressos são impares se n = 55? #
########################################################
Answer: 36
*/
void fibonacci_impar (int n) {
  int sum = 0;
    
  int a = 0, b = 1, aux;
  for (; n > 0; n--) {
    if (a % 2 == 1) {
      sum += 1;
    }
    aux = a;
    a = b;
    b = (b + aux) % 10000;
  }
  
  printf("sum = %d", sum);
}

/*
########################################################
Quantos dos números impressos pela função anterior são potências perfeitas se n = 60?

Um número é uma potência perfeita se pode ser expresso como o produto de 2 ou mais números iguais. 
########################################################
Answer: 6

Atenção 0,1,1 € potenciaPerfeita
*/

int potenciaPerfeita(int n) {
    int temp;
    for (int i = 2; i < n; i++) {
        temp = n;
        while (temp % i == 0) {
            temp /= i;
        }
        if (temp == 1) {
            return 1;
        }
    }
    return 0;
}

void fibonacci (int n) {
  int a = 0, b = 1, aux;
  for (; n > 0; n--) {
    printf("%d\n",a);
    aux = a;
    a = b;
    b = (b + aux) % 10000;
  }
}



int main(void) {
  fibonacci_impar(55);
  printf("\n \n");
  fibonacci (60);
  
  return 0;
}
