#include <stdio.h>

int main() {
    int age = 0;
    int factor =  12 *7;
    for (age = 0; age <= 200; age += factor){
        if (age / 4 + age / 7 + 5 + age / 2 == age -4 ){
            printf("%d",age);
        }
    }

    return 0;
}
