/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/
class Solution {
public:
    int titleToNumber(string s) {
        int index=0;
        for(int i=0;i<s.size();i++){
            index=index*26 + (s[i]-'A'+1);//注意以'A'而不是0开头，因此要“+1”
        }
        return index;
    }
};