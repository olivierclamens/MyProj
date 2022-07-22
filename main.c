#include <stdio.h>

int main()
{
    int nb=2546895232,format=32;

    unsigned char nbBin[32+3+1]; //3 espaces dans le pire des cas (32 bits) et 1 caractère NULL
    unsigned char nbBinSp[32+3+1];
    int i,ind,j,k,numByte,lim,off,numLigne,max,multiple;

    for(ind=0;ind<format;ind++){
        nbBin[ind]=((nb>>(format-1-ind))&0x01)+0x30;
    }
    nbBin[ind]=0;
    printf("nb=%d\t=> %s\n",nb,nbBin);

    multiple=ind%8;
    max=ind/8;
    numByte=0;
    ind=0;
    if(0==multiple){
        for(k=0;k<max;k++){
            for(j=0;j<8;j++){
                nbBinSp[j+k*8+numByte]=nbBin[ind];
                ind++;
            }
            if((max-k)>1)
                nbBinSp[j+k*8+numByte]=' ';
            numByte++;
        }
        nbBinSp[j+k*8+numByte]=0;
    }else{
        max+=1;
        for(k=0,lim=multiple,off=0,numLigne=0;k<max;k++){
            for(j=0;j<lim;j++){
                nbBinSp[j+numLigne*8+numByte+off]=nbBin[ind];
                ind++;
            }
            nbBinSp[j+numLigne*8+numByte+off]=' ';
            if(numByte>=1)
                numLigne++;
            numByte++;
            lim=8;
            off=multiple;
        }
        nbBinSp[j+numLigne*8+numByte+off]=0;            
    }	
    printf("nb=%d\t=> %s\n",nb,nbBinSp);
    
    return 0;
}