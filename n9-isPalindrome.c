#include <stdio.h>
#include <stdbool.h>
bool isPalindrome(int x){
    if(x<0)return false;
    char s[33]={0};
    int length =0;
    while(x){
        s[length++]=x%10;
        x/=10;
    }
    for(int i=0;i<length/2;i++){
        if(s[i]!=s[length-i-1]){
            return false;
        }
    }
    return true;
}