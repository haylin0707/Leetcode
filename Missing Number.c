/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.
*/
//Solution 1:先将原数组排序，再依次对应比较数字和数组下标是否相等；
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());//先将vector中的数据排序，再依次对应比较
        int i;
        for(i=0;i<nums.size();i++){
            if(i!=nums[i]){
                return i;
            }
            else{
                continue;
            }
        }
        if(i==nums.size()) return i;//对于vector为[0,1,2]，却少数为3的情况；
    }
};

//Solution 2：若原数组不缺数的话，其和应该为(1+size)*size/2为1~size的求和公式
//若少数，则依次用和去减去vector中的数，剩余的那个就是缺少的那个数；
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (1+nums.size())*nums.size()/2;
        for (int i = 0; i < nums.size(); i++) {
            n -= nums[i];
        }
        return n;
    }
};