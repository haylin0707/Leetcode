/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/
/*
vector 的用法，
创建vector<string> result;
vector的大小：vector.size()
加入到vector尾部：vector.push_back（x）
将int x转化为string str：先创建中间char数组，char tmp[]， sprintf((char) tmp,"%d",（int）x); str=tmp即可
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int start=0;
        int end=0;
        //设置两个指针start和end，判断nums[end+1]==nums[end]+1，是的话则继续向下循环；
        std::string str;
        char tmp[100];//用来存储转换格式
        char star[100];//用来存储将start的int转化为char
        char en[100];//用来存储将end的int转化为char
        while(end<nums.size()){
            if(end+1<nums.size() && nums[end+1]==nums[end]+1){
                end++;
            }
            else{
                //若不满足nums[end+1]==nums[end]+1，
                //若start==end，表示只有单独的一个数，放入vector result中；
                if(start==end){
                    sprintf(tmp, "%d", nums[end]);
                    str=tmp;
                    result.push_back(str);
                }
                else{
                    //若start！=end，表示start->end之间都满足；
                    std::string s;
                    std::string e;
                    sprintf(star,"%d",nums[start]);
                    s=star;
                    sprintf(en,"%d",nums[end]);
                    e=en;
                    str=s+"->"+e;
                    result.push_back(str);
                }
                end++;
                start=end;
            }
        }
        return result;
    }
};