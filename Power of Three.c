/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

//新方法：
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        //不用迭代或者递归的方法
        //若n是3的幂次，则3^x=n,则log10(n)/log10(3)=x；
        //则再用pow(3,x)=n应该成立；主要是利用了对数除法的性质
        int a=(log10(n)/log10(3));
        if(n==pow(3,a)){
            return true;
        }
        else{
            return false;
        }
    }
};

//传统方法：迭代
class Solution {  
public:  
    bool isPowerOfThree(int n) {  
        if(n <= 0) return false;  
        while(n > 1){  
            if(n %3 != 0) return false;  
             n/=3;  
        }  
        return true;  
    }  
}; 

//递归
class Solution {  
public:  
    bool isPowerOfThree(int n) {  
        if (n <= 0) return false;  
        if (n == 1) return true;  
        return n % 3 == 0 && isPowerOfThree(n / 3);  
    }  
};  
