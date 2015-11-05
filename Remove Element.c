/*Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

给出一个数组和一个数字，要求删除数组中出现的数字，返回新数组的长度；
（C)
*/

int removeElement(int* nums, int numsSize, int val) {
    int len=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=val){
            nums[len]=nums[i];
            len++;
        }
    }
    return len;
}
