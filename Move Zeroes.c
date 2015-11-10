/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
将数组中的0，放到数组末尾，非零的元素不变；
Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
要求不创建新的数组；且移动数目最少；
*/
void moveZeroes(int* nums, int numsSize) {
    int count=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0){
            count++;
        }
        else{
            if(count!=0){
                nums[i-count]=nums[i];
                nums[i]=0;
            }
            else
                continue;//防止出现{1,2,3}开头就是非零元素的情况
        }
    }
}