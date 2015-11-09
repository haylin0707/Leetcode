/*
Rotate an array of n elements to the right by k steps.
将数组循环右移k个单位；
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II
*/

//Solution 1:
//这种方法的效率很低，当数组很大时，会超时；
void rotate(int* nums, int numsSize, int k) {
    int temp;
    for(int step=0;step<k;step++){
        temp=nums[numsSize-1];
        for(int i=numsSize-1;i>0;i--){
            nums[i]=nums[i-1];
        }
        nums[0]=temp;
    }
}

//Solution 2：
//先将5以前的数据翻转得到的数组是[4,3,2,1,5,6,7]
//再将5及以后的数据翻转得到的数组是[4,3,2,1,7,6,5]
//再将整个数组翻转即得到[5,6,7,1,2,3,4]. （即为所求）
void reverse(int* nums, int begin, int end);//翻转数组
void rotate(int* nums, int numsSize, int k) {
    k=k%numsSize;
    reverse(nums,0,numsSize-k-1);
    reverse(nums,numsSize-k,numsSize-1);
    reverse(nums,0,numsSize-1);
}

void reverse(int* nums, int begin, int end){
    int temp=0;
    while(begin<end && end>=0){
        temp=nums[begin];
        nums[begin]=nums[end];
        nums[end]=temp;
        begin++;
        end--;
    }
}