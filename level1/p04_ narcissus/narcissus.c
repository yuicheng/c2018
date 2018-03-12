#include <stdio.h>
#include <math.h>
#include <windows.h>
int main(){
   
    int i = 153;
    for (i;i<=999;i++) {
        double vh = i / 100 % 10;
        double vx = i / 10 % 10 ;
        double vl = i % 10;
        int powersum = (int) (pow(vh,3) + pow(vx,3) + pow(vl,3));
        if  (powersum == i){
            printf("%d", i);
        }
    }
    system("pause");
    return 0;
}
