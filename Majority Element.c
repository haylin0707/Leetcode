/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
找出数组中出现次数大于n/2的元素，且假设数组一定是非空，一定存在majority element

*/
//Moore voting algorithm--每找出两个不同的element，就成对删除即count--，最终剩下的一定就是所求的。时间复杂度：O(n)
//注意majority element出现的次数一定是大于n/2的
int majorityElement(int* nums, int numsSize) {
    int count=0;
    int candidate;
    for(int i=0;i<numsSize;i++){
        if(count==0){
            candidate=nums[i];
            count=1;
        }
        else{
            if(candidate==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
    }
    return candidate;
}

//随机挑选一个元素，检查是否是多数元素。时间复杂度：Average：O(n)。期望查找次数 <2
//这里选择随机数而不是依次将数组中的从头开始作为参考，要不要进行两次循环，为O(n^2)
class Solution {
 public:
     int majorityElement(vector<int> &num) {
 
         int count = 0;
         
         for(;;) {
             if(num.size() == 1)
                 return num[0];
             else    {
                 int i = rand() % (num.size() - 1);
                 for(int j = 0; j < num.size(); j++) {
                     if(num[j] == num[i])
                         count++;
                 }
                 if(count > (num.size() / 2))//若大于n/2，则为majority element
                     return num[i];
                 else    {
                     count = 0;
                     continue;
                 }
             }
         }
     }
　};