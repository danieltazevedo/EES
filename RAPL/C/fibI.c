/*
 *  Análise e Teste de Software
 *  2022-2023
 */

#include <stdio.h>
#include <stdlib.h>

long long fib(long long n)
{ 
  long long new, old; 
  for (new=1, old=1; n > 1; n--) {
    new = new + old;
    old = new - old;
  }
  return new;
}




int main (int argc, char **argv) 
{

  int v = atoi (argv[1]);

  //int v = 30;
  long long res;

  res = fib(v);
  printf("\n\n fib(%d): %lld \n\n",v,res);
  
  fflush(stdout);
    
  return 0;
}



