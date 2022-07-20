#include <stdio.h>

int main()
{
    int nb=164,n,ind,j,k,numByte,lim,off,numLigne,max;
    unsigned char nbBin[32+3+1]; //3 espaces dans le pire des cas (32 bits) et 1 caractère NULL
    unsigned char nbBinSp[32+3+1];
    int i,format=11;

    for(i=0;i<format;i++){
        nbBin[i]=((nb>>(format-1-i))&0x01)+0x30;
    }
    nbBin[i]=0;

    n=i%8;
    if(0==n){
        max=i/8;
        numByte=0;
        ind=0;
        for(k=0;k<max;k++){
            for(j=0;j<8;j++){
                nbBinSp[j+k*8+numByte]=nbBin[ind];
                ind++;
            }
            nbBinSp[j+k*8+numByte]=' ';
            numByte++;
        }
        nbBinSp[j+k*8+numByte]=0;
    }else{
        max=i/8+1;
        numByte=0;
        ind=0;
        for(k=0,lim=n,off=0,numLigne=0;k<max;k++){
            for(j=0;j<lim;j++){
                nbBinSp[j+numLigne*8+numByte+off]=nbBin[ind];
                ind++;
            }
            nbBinSp[j+numLigne*8+numByte+off]=' ';
            if(numByte>=1)
                numLigne++;
            numByte++;
            lim=8;
            off=n;
        }
        nbBinSp[j+numLigne*8+numByte+off]=0;            
    }
    printf("%s\n%s",nbBin,nbBinSp);
    
    return 0;
}