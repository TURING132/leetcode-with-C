#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 10000
bool match(char a,char b){
    if(a=='('&&b==')'||a=='['&&b==']'||a=='{'&&b=='}')return true;
    else return false;
}

bool isValid(char * s){
    char stack[MAX_SIZE] = {0};
    int len = strlen(s); int i=0;
    int top = -1;// stact = (,top]
    for(i=0;i<len;i++){
        // printf("current: %c,top: %d\n",s[i],top);
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            stack[++top]=s[i];
        }
        else{
            if(top<0||!match(stack[top],s[i])) return false;
            else top--;
        }
    }
    if(top==-1)return true;
    else return false;
}


int main(){
    char s[7] = "()[]{}";
    printf("%d",isValid(s));
}