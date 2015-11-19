/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
给出一个整数，以数组的形式表示，例如12：[1,2]
写出该整数加一后的数
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      vector<int> ret(digits);
        reverse(ret.begin(), ret.end());
        //先将数组倒叙，即个位在最前面，然后十位，百位；
         int flag = 1;
         for(int i = 0; i < ret.size(); i++)
         {
             ret[i] += flag;
            flag = ret[i] / 10;//判断是否需要进位
             ret[i] %= 10; //判断进位；如果等于10，则该为应该为0；
         }
         
         if (flag == 1)//最后一位，例如如果是99，则会新增加以为1；
             ret.push_back(1);
        
        reverse(ret.begin(), ret.end());//再把得到的数组反过来
         return ret;

        
    }
};