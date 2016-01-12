/*
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/
/*对于第2盏灯，1*2,2*1的两次开关，最终为灭；
  对于第4盏灯，1*4，2*2,4*1的三次开关，最终为开；
  对于第6盏灯，1*6，2*3,3*2,6*1的四次开关，最终为灭；
  我们可以发现，当两个不同整数相乘时，有n*m出现，则必有m*n出现；其分解的因数最终为偶数个，灯最终为灭的。而对于可以被拆分成n*n形式的整数，这可能出现这一次n*n，所以其分解的因数最终为奇数个，灯为亮；
  所以就求n盏灯包含多少个平方数即可；
  int(sqrt(n));
*/
class Solution {
public:
    int bulbSwitch(int n) {
        int result=sqrt(n);
        return result;
    }
};