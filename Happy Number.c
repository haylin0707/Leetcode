/*Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
主要思路是先得到每步的各位的平方和，然后将和放入集合中，
若是Happy number则会有sum=1的情况
不是Happy number最终得到sum会有在集合中一样的数出现，这样可返回false
*/

class Solution {
public:
    bool isHappy(int n) {
        if(n==1) return true;
        unordered_set<int> number;//集合number用来存储每步得到的平方和
        
        number.insert(n);
        while(true){
            int sum=0;
            //各位的平方求和
            while(n>0){
                int digit=n%10;//个位数
                sum+=digit*digit;
                n=n/10;
            }
            if(sum==1){
                return true;
            }
            else{
                if(number.find(sum)==number.end()){
                    //即是sum不在集合number中
                    number.insert(sum);
                }
                else{
                    return false;
                }
            }
            n=sum;
        }
    }
};
