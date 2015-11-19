/*Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
这道题本来的想法是用除法，但题目明确要求不能用除法；
我们可以先遍历一遍数组，每一个位置上存之前所有数字的乘积。
那么一遍下来，最后一个位置上的数字是之前所有数字之积，是符合题目要求的，只是前面所有的数还需要在继续乘。
我们这时候再从后往前扫描，每个位置上的数在乘以后面所有数字之积，对于最后一个位置来说，
由于后面没有数字了，所以乘以1就行。

*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        //从前往后扫描，res[i]中存放的都是nums[i]之前的所有数的乘积，不包括i;
        //注意i从1开始，因为res[i]存的是i之前所有数之积
        for(int i=1;i<nums.size();i++){
            res[i]=res[i-1]*nums[i-1];
        }
        //从后往前扫描，right表示的是num[i]之后的数的乘积，和之前得到res[i]相乘，得到除i以外的乘积；
        int right=1;
        for(int j=nums.size()-1;j>=0;j--){
            res[j]=res[j]*right;
            right=right*nums[j];
        }
        return res;
    }
};

