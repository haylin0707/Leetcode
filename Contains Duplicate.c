/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
若数组中出现两个以上相同的元素，则为true，若没有相同的元素则为false
*/
//最笨的方法就是两次循环数组，但这样会runtime error
bool containsDuplicate(int* nums, int numsSize) {
    int base;
    for(int i=0;i<numsSize;i++){
        base=nums[i];
        int count=0;
        for(int j=0;j<numsSize;j++){
            if(nums[i]==nums[j]){
                count++;
            }
            if(count==2){
                return true;
            }
        }
    }
    return false;
}

//另一种就是用C++中的sort，将数组都排序，然后比较前后两个元素是否一样
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] == nums[i]) 
                return true;
        }
    }
};