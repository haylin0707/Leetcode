/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
这是之前contain Duplicate的改进；我们要hash表，创造一个数组和位置一一映射的表m；
需找m中和nums[i]相同的数的位置，并判断两者位置之差是否小于等于k；若没找到的话，说明只有一个数；
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) {
                return true;
            }
            else m[nums[i]] = i;
        }
        return false;
    }
};