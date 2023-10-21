
#define MAXSIZE 1001
int stack[MAXSIZE] = {0};
int top = -1;
int calPoints(char ** operations, int operationsSize){
    int i;
    int temp;
    top = -1;
    for(i=0;i<operationsSize;i++){
        char c = operations[i][0];
        if(c>='0'&&c<='9'||c=='-'){
            sscanf(operations[i],"%d",&temp);
            stack[++top] = temp;
        }
        else if(c=='C'){
            top--;
        }
        else if(c=='D'){
            temp = stack[top] * 2;
            stack[++top] = temp;
        }
        else if(c=='+'){
            temp = stack[top] + stack[top-1];
            stack[++top] = temp;
        }
    }
    int res = 0;
    for(i=0;i<=top;i++){
        printf("%d\n",stack[i]);
        res+=stack[i];
    }
    return res;
}