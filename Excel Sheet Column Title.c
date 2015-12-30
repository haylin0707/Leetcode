/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
    string convertToTitle(int n) {
        string column="";
        char s;
        while(n){
            int mod=(n-1)%26;
            s=mod+'A';
            column=s+column;//注意string的用法，可以连接可以直接用+连接char+char或char+string都可以
            n=(n-1)/26;
        }
        return column;
    }
};