/*
Given an array of integers, every element appears twice except for one. Find that single one.
数组中都是俩俩出现，找出单独出现的那个数；
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
采用的方法是先排序，再每三个一比较；
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //所有数从小到大排序
       std::sort(nums.begin(),nums.end());
       //如果第一个和第二个不相等，说明第一个数为单个数
       if(nums[0]!=nums[1]){
           return nums[0];
       }
       //判断nums[i]和前一个和后一个比较，如果都不想等，则是nums[i]为单个数；
        for (int i = 1; i < nums.size()-1; i++) {
            if ((nums[i-1] != nums[i]) && (nums[i]!=nums[i+1])){ 
                return nums[i];
            }
            else{
                continue;
            }
        }
        //如果最后一个数和前一个数不相等，则为最后一个数为单个数；
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
    }
};