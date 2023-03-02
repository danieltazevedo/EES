#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char*argv[]){
    srand(time(NULL));   // Initialization, should only be called once.
    for(int i=0;i<atoi(argv[1]);i++) {
        int r =  rand () % 10000;
        printf("%d,",r);
    }
}

