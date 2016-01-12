/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {
        //罗列出可能运用到的罗马符号；但要注意这里有IV这种小号数字在前的特殊情况也要罗列出来，900,400,90,40,9等；
        string symbol[20]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[20]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s;
        for (int i=0;num!=0;i++){
            while(num>=value[i]){
                num-=value[i];
                s+=symbol[i];
            }
        }
        return s;
    }
};