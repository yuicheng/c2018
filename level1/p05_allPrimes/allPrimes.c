#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define MAXN 10000000

bool primes[MAXN] = {false};


    


int main(){
 int i,j;
    for (i = 2;i < MAXN; i++){
        if (!primes[i]){
            printf("%d\n",i);
            for (j = 2 * i; j < MAXN; j +=i){
                primes[j] = true;
            }
        }
    }
}
