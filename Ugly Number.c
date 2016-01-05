/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
所谓一个数m是另一个数n的因子，是指n能被m整除，也就是n % m == 0。根据丑数的定义，丑数只能被2、3和5整除。也就是说如果一个数如果它能被2整除，我们把它连续除以2；如果能被3整除，就连续除以3；如果能被5整除，就除以连续5。如果最后我们得到的是1，那么这个数就是丑数，否则不是。
*/

class Solution {
public:
    bool isUgly(int num) {
        if(num<=0) return false;//首先保证ungly number是正数；
        //ugly num的因数只能为2,3,5，则看不断地除以2,3,5，看最后是否为1；
        while(num%2==0){
            num=num/2;
        }
        while(num%3==0){
            num=num/3;
        }
        while(num%5==0){
            num=num/5;
        }
        if(num==1){
            return true;
        }
        else{
            return false;
        }
    }
};