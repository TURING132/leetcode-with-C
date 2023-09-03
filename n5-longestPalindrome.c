#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char * longestPalindrome(char * s){
    int l = strlen(s);
    int ** dp = (int**)malloc(l*sizeof(int *));
    int i,j,len;
    int ri=0,rj=0,rl=0;//用来返回结果
    for (i=0;i<l;i++){
        dp[i] = (int *)malloc(l*sizeof(int));
    }
    //dp(i,j)表示s[i，j]的字符串
    for(i=0;i<l;i++){
        for(j=0;j<l;j++){
            if(i==j){dp[i][j]=1;ri=i;rj=j;rl=1;}
            else dp[i][j]=0;
            //初始化
        }
    }
    //dp(i,j)=dp(i+1,j-1) & s(i)==s(j)
    
    for(len=2;len<=l;len++){

        for(i=0;i<l;i++){
            j = i+len-1;
            if(i>j||j>=l)continue;
            if(len==2)dp[i][j]=s[i]==s[j]?1:0; //其实这是初始化的部分，但是放在这里也方便
            else dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]); //如果len>2就可以使用递推式dp(i,j)=dp(i+1,j-1) & s(i)==s(j)
            if(dp[i][j]&&len>rl){
                rl = len;
                ri = i;
                rj = j;
            }
        }
    }

    char *rs = (char *)malloc(sizeof(char)*(rl+1));
    for(i=0;i<rl;i++){
        rs[i] = s[ri+i];
    }
    rs[rl]=0;
    return rs;
}

int main(){
    char* s = "cbbd";
    printf("%s",longestPalindrome(s));
}