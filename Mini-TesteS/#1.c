#include <stdio.h>

/*

int func(int x) {
  int r = 0;
  while (x > 0) {
    r += 1;
    x = x - r;
  }
  return r;
}

#########################################################################
# Qual o menor valor de x que faz com que seja produzido o resultado 6? #
#########################################################################
Answer: 16
*/

int func(int x) {
  int r = 0;
  while (x > 0) {
    r += 1;
    x = x - r;
  }
  return r;
}

int main() {
    int i;
    
    for (i = 0; i < 100; i++) {
        int r = func(i);
        printf("i = %d, r = %d\n", i, r);
        if (r == 6) break;
    }
    
    printf("res = %d", i);
    
    return 0;
}

/*
########################################################

int x,y;
for (y=0;y<8;y++) {    
  for (x=0;x<8;x++) {
    if (x [A] y > [C]) putchar('#');
    else putchar('.');
  }
  putchar('\n');
}

Identify the missing code so that the program draws the following figure.

########
.#######
..######
...#####
....####
.....###
......##
.......#


########################################################
*/

int main(void) {
  int x,y;
  for (y=0;y<8;y++) {    
    for (x=0;x<8;x++) {
      if (x-y > -1) putchar('#');
      else putchar('.');
    }
    putchar('\n');
    }
}