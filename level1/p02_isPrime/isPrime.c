#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define MAXN 100000000

bool primes[MAXN] = {false};

void erato(){
    int i,j;
    for (i = 2;i < MAXN; i++){
        if (!primes[i]){
            for (j = 2 * i; j < MAXN; j +=i){
                primes[j] = true;
            }
        }
    }
}

int main(){
    erato();
    int n;
    printf("Hi! Gimme a number and I\'ll check if it's a prime or not. \n");
    scanf("%d",&n);
    if (n >= MAXN || n < 0) {
        printf("Number out of range.  Try a smaller one \n");
    }
    else if (!primes[n]){
        printf("Yes, number %d is a prime! \n",n);
    } else {
        printf("No, number %d is not a prime. \n",n);
    }
}
