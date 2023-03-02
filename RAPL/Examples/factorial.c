#include <stdio.h>
#include <stdlib.h>
#include "rapl.h"

int main (int argc, char **argv)
{ long fact = 1;
  
  
  int n = atoi (argv[1]);

  rapl_init(0);
  rapl_before(stdout,0);    
  for(int x=1;x<=n;x++)
     fact=fact*x; 
  rapl_after(stdout,0);
  printf("\nfact(%d): %ld \n",n,fact);   
  fflush(stdout);
  return 0;
}
