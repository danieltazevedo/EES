/*
 *  Análise e Teste de Software
 *  2022-2023
 */

#include <stdio.h>
#include <stdlib.h>

long long fib(long long n)
{ if   (n <= 1 ) return 1;
  else return (fib(n-1) + fib(n-2)); 
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



