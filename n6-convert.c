#include <stdlib.h>
#include <string.h>
#include <stdio.h>
enum Direction{
    down,
    right_up
};

char * convert(char * s, int numRows){
    int sl = strlen(s);
    int l_max = sl;
    int i,j,k;
    char ** rs = (char **)malloc(sizeof(char *)*numRows);
    for(i=0;i<numRows;i++){
        rs[i]=(char *)malloc(sizeof(char)*l_max);
        for(j=0;j<l_max;j++){
            rs[i][j]=0;
        }
    }
    enum Direction flag = down;

    for(i=0,j=0,k=0;k<sl;k++){
        if(flag == down){
            rs[i++][j] = s[k];
            if(i==numRows-1) flag = right_up;
        }else if(flag == right_up){
            rs[i--][j++] = s[k];
            if(i==0) flag = down;
        }
    }
    char * res = (char *)malloc(sizeof(char)*(sl+1));
    for(i=0,k=0;i<numRows;i++){
        for(j=0;j<l_max;j++){
            if(k==sl)break;
            if(rs[i][j])res[k++]=rs[i][j];
        }
    }
    res[k]=0;
    return res;
}


int main(){
    printf("%s",convert("AB",1));
}