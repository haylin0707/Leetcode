/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

羅馬數字共有7個，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）。按照下述的規則可以表示任意正整數。需要注意的是罗马数字中没有“0”，與進位制無關。一般認為羅馬數字只用來記數，而不作演算。
重複數次：一個羅馬數字重複幾次，就表示這個數的幾倍。
右加左減：
在較大的羅馬數字的右邊記上較小的羅馬數字，表示大數字加小數字。
在較大的羅馬數字的左邊記上較小的羅馬數字，表示大數字减小數字。
*/

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> roman;
        roman['I']=1;
        roman['V']=5;
        roman['X']=10;
        roman['L']=50;
        roman['C']=100;
        roman['D']=500;
        roman['M']=1000;
        
        int len=s.length();
        int result=0;
        for(int i=len-1;i>=0;i--){
            if(i==len-1){
                result=result+roman[s[i]];//从最末尾开始扫描；
            }
            else{
                if(roman[s[i]]>=roman[s[i+1]]){
                    result+=roman[s[i]];//在較大的羅馬數字的右邊記上較小的羅馬數字，表示大數字加小數字
                }
                else{
                    result-=roman[s[i]];//在較大的羅馬數字的左邊記上較小的羅馬數字，表示大數字减小數字
                }
            }
            
        }
        return result;
    }
};