#include <stdio.h>
#include "windows.h"
#include "memory.h"

#define LEN 1000

const static char table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const static int revtable[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,62,0,0,0,63,52,53,54,55,56,57,58,59,60,61,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,0,0,0,0,0,0,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};

char payload[LEN+1] = {0};

char* b64encode(){

    int length = strlen(payload) - 1;
    if (length % 3 == 1){
        length = (length + 2) / 3 * 4;
    } else if (length % 3 == 2){
        length = (length + 1) / 3 * 4;
    } else {
        length = sizeof(char) * length / 3 *4;
    }


    char *result = malloc(sizeof(char) * length + 1);
    memset(result, '\0', sizeof(char) * length + 1);

    int i,j;

    for (i = 0,j = 0; i < length - 2; i += 4,j += 3) {
        result[i] = table[payload[j] >> 2];
        result[i + 1] = table[(((payload[j] & 0x3) << 6) | ((payload[j + 1] >> 2) & 0x3C)) >> 2];
        result[i + 2] = table[((payload[j + 1] << 2) & 0x3C) | payload[j + 2] >> 6];
        result[i + 3] = table[payload[j + 2] & 0x3F];
    }

    if ((strlen(payload) - 1) % 3 == 1 ){
        result[strlen(result)-2 ] = '=';
        result[strlen(result) -1] = '=';
    } else if ((strlen(payload) - 1) % 3 == 2){
        result[strlen(result)-1] = '=';
    }


    return result;
}

char* b64decode(){

    int length = strlen(payload);

    if(payload[strlen(payload) - 3
       ] == '='){
        length = length / 4 * 3 - 2;
        payload[strlen(payload) - 3] = payload[strlen(payload) - 2] = '_';
    } else if (payload[strlen(payload) - 2] != '='){
        length = length / 4 * 3 - 1;
        payload[strlen(payload) - 2] = '_';
    }


    char *result = malloc(sizeof(char) * length +1);
    memset(result,0, sizeof(char) * length + 1);


    int i,j;
    for(i = 0 ,j = 0; i <= length; i += 4,j += 3){
        result[i] = (revtable[payload[i]] << 2 | revtable[payload[i+1]] >> 4);
        result[i+1] = ((revtable[payload[i+1]] & 0xF ) << 4 | (revtable[payload[i+2]] >> 2) & 0xF);
        result[i+2] = ((revtable[payload[i+2]] & 0x3) << 6 | revtable[payload[i+3]]);
    }

    return  result;
}

int main(int argc, char * argv) {
    fgets(payload,LEN +1,stdin);
    char *result = b64encode();
    printf("%s\n",result);

    return 0;
}
