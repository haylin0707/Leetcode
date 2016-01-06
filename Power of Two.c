//Given an integer, write a function to determine if it is a power of two.
//判断是否为2的幂数
//两种方法：

class Solution {
public:
    bool isPowerOfTwo(int n) {
        //判断一个数是否是2的次幂，则n和n-1化成二进制数在“与”一下，应该为0；n只有最高位为1；n-1全是1；
        if(n>0 && (n&(n-1))==0){
            //这里注意“与”的方法，直接用”&“
            return true;
        }
        else{
            return false;
        }
    }
};
//或者还可以采用计算2进制数中1的个数，若是2的幂数，则只有最高位一个1；
//但如何转换为2进制？？？？

bool isPowerOfTwo(int n) {
    int count = 0;
    while (n > 0)
    {
        count+=(n&0x01);//每次将n和二进制00001数进行判断，即是每次判断最末尾的数，不是的话，相与都为0；
        n>>=1;//每次右移一位，直到有1在最末尾和0001相与即可判断有几个1；
    }
    return count==1;
}