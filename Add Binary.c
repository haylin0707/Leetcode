/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
思路：将两个数的位数补齐，有相同的长度，然后从最低位开始一一相加，注意要有进位的情况分析；
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int sizea = a.size();
        int sizeb = b.size();
        if(sizea < sizeb)
            return addBinary(b, a);
        //sizea >= sizeb
        string zeros(sizea-sizeb, '0');
        b = zeros + b;//将b的前面添上0，保证长度和a相等；
        int carry = 0;
        for(int i = sizea-1; i >= 0; i --)
        {
            int sum = (a[i]-'0') + (b[i] - '0') + carry;
            if(sum == 0)
                continue;
            else if(sum == 1)
            {
                a[i] = '1';
                carry = 0;
            }
            else if(sum == 2)
            {
                a[i] = '0';
                carry = 1;
            }
            else
            {//sum == 3 (1+1+1)
                a[i] = '1';
                carry = 1;
            }
        }
        if(carry == 1)
            a = "1" + a;
        return a;
    }
};