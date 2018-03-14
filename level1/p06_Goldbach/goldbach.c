#include <stdio.h>
#include "stdbool.h"
#include "stdlib.h"

int primes[100];
int count = 0;


int main() {
    bool seq[100] = {false};

    int i,j,k;

    // All primes
    for(i = 2;i < 100; i++){
        if(!seq[i]){
            printf("%d ",i);
            primes[count] = i;
            count++;
            for(j = 2 * i; j < 100; j += i){
                seq[j] = true;
            }
        }
    }

    printf("\n");

    for(i = 2; i < 100; i += 2){
        for (j = 0; j < count - 1; j++){
            for(k = 0;k < count - 1; k++){
                if( i == primes[j] + primes[k]){
                    printf("Number %d is equal to %d + %d \n",i,primes[j],primes[k]);
                }
            }
        }
    }
    printf("flag");
    return 0;
}

