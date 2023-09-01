//
// Created by 李力扬 on 2023/8/29.
//
#include <stdlib.h>
#include <stdio.h>
int lengthOfLongestSubstring(char * s){
    int length = strlen(s);
    int left =0, right =0, l =0;//[left, right]
    for(right = 0;right<length;right++){
        char c = s[right];
        printf("%d,%d\n",left,right);
        while(myStrchr(left,right-1,s,c)){
            printf("%d,%d\n",left,right);
            left+=1;
        }
        if(right-left+1>l){
            l = right-left+1;
        }
    }
    return l;
}

int myStrchr(int left, int right, const char* s, char c){
    //[left ,right]
    int i;
    for(i=left;i<=right;i++){
        if(s[i]==c){
            return 1;
        }
    }
    return 0;
}
