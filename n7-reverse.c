#include <limits.h>
#include <stdio.h>
int reverse(int x){
    int rev = 0;
    while(x!=0){
        // 不用考虑加尾数，MAX为 2...7, 尾数为0,1,2，都小于7，加了没关系
        if(rev<INT_MIN/10||rev>INT_MAX/10)return 0;
        rev = rev*10+x%10;
        x /=10;
    }
    return rev;
}

int main(){
    printf("%u",INT_MAX);
    return 0;
}