#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))


int maxArea(int* height, int heightSize){
    int left = 0, right = heightSize-1;
    int maxsize = 0;
    while(left<right){
        int size =  MIN(height[left],height[right])*(right-left);
        maxsize = MAX(size,maxsize);
        if(height[left]<height[right]){
            left++;
        }else{
            right--;
        }
    }
    return maxsize;
}