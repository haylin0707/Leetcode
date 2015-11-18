/*Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
每次从后往前推，从每行的最后一个数开始依次计算前面的数；
*/
class Solution {
 public:
     vector<int> getRow(int rowIndex) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         vector<int> a(rowIndex + 1);//第k行，有k+1个数
         
         a[0] = 1;
         for(int i = 1; i <= rowIndex; i++){
             //从该行的最后一个数往前推
             for(int j = i; j >= 0; j--){
                 if (j == i)
                     a[j] = a[j-1];
                 else if (j == 0)
                     a[j] = a[j];
                 else
                     a[j] = a[j-1] + a[j];//此时a[j-1]和a[j]还是上一行的值，a[j]的值还没有改变；
             } 
         }
         return a;                    
     }
 };
