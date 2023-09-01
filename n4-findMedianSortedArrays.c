#include <stdio.h>
int min(int a, int b){
    return a<b?a:b;
}

double findKth(int k,int* nums1, int nums1Size, int* nums2, int nums2Size){
    int k_th = k;//in 1-first way
    int floor1 = 0,floor2 = 0;
    while(k_th>0){
        int check_index = k_th/2-1;
        int a,b;
        if(floor1>=nums1Size) return nums2[floor2+k_th-1];
        if(floor2>=nums2Size) return nums1[floor1+k_th-1];
        if(k_th == 1) return min(nums1[floor1],nums2[floor2]);

        int idx1 = nums1Size>floor1+check_index?floor1+check_index:nums1Size-1;
        int idx2 = nums2Size>floor2+check_index?floor2+check_index:nums2Size-1;
        a = nums1[idx1];
        b = nums2[idx2];
        printf("idx1 = %d, idx2 = %d\n",idx1,idx2);
        if(a<=b){
            k_th -= idx1 - floor1 + 1;
            floor1 = idx1+1;
        }else{
            k_th -= idx2 - floor2 + 1;
            floor2 = idx2+1;
        }
    }
    return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int mid = (nums1Size+nums2Size)/2;//in 1-first way
    int is_even = !((nums1Size+nums2Size)%2);
    if(is_even){
        return (findKth(mid,nums1,nums1Size,nums2,nums2Size)+findKth(mid+1,nums1,nums1Size,nums2,nums2Size))/2;
    }else{
        return findKth(mid+1,nums1,nums1Size,nums2,nums2Size);
    }
}

int main(){
    int a[1] = {4};
    int b[3] = {1,2,3};
    printf("%f",findMedianSortedArrays(a,1,b,3));
}
