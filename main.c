#include <stdio.h>

int main()
{
    int nb=164;
    unsigned char nbBin[33];
    int i,format=8;

    for(i=0;i<format;i++){
        nbBin[i]=((nb>>(format-1-i))&0x01)+0x30;
    }
    nbBin[i]=0;

    printf("%s",nbBin);
    
    return 0;
}