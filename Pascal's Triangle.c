/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
杨辉三角返回一个大的vector triangle；其中还嵌套这不同的vector，每一行都是一个vector row；
每行的第一个和最后一个元素都为1，即是j=0或是j=i的情况
其余可以发现row[i][j]=row[i-1][j-1]+row[i-1][j];

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0){
            return vector<vector<int>>(0);
        }
        vector<vector<int>> trangle;
        for(int i=0;i<numRows;i++){
            vector<int> row;
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                    row.push_back(1);//每一行的第一个和最后一个数都为1；
                }
                else{
                    int tmp=trangle[i-1][j-1]+trangle[i-1][j];
                    row.push_back(tmp);
                }
            }
            trangle.push_back(row);
        }
        return trangle;
    }
};
