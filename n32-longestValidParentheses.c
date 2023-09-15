#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX(a,b) a>b?a:b;
int longestValidParentheses(char * s){
    //dp[i] 表示s(:i)的字符串里面的最长有效列
    // ... ()
    // dp[i] = max(dp[i-1],dp[i-2]+2)  x
    // ... ))
    // if s[i−dp[i−1]−1] == (
    // dp[i] = dp[i-1]+2+dp[i-dp[i-1]-2]  把断掉的接上了，可以加上前面的
    int result = 0;
    int l = strlen(s);
    int * dp = (int *)malloc(sizeof(int)*l);
    int i;
    for(i=0;i<l;i++){
        dp[i] = 0;
    }
    for(i=1;i<l;i++){
        if(s[i]=='('){continue;}
        if(s[i-1]=='('){//s[i]==')'
            dp[i] = (i-2>=0?dp[i-2]:0) + 2;
        }else{//s[i-1]==')' && s[i]==')'
            if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                dp[i] = dp[i-1]+((i-dp[i-1]-2)>=0?dp[i-dp[i-1]-2]:0)+2;
            }//else dp[i]=0
        }
        result = MAX(dp[i],result);
    }
    free(dp);
    return result;
}

int main(){
    printf("%d",longestValidParentheses("(()())"));
    return 0;
}