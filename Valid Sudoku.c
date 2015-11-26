/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
判断数独是否有效：
1. 每一行的数字在该行只能出现一次
2. 每一列的数字在该列只能出现一次
3. 每个小的九宫格里的数字只能出现一次

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
没有标识的数字为‘.’表示


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
有效的数独不代表可解；
只要判断是否有效，满足以上三个要求即可；

分别从每行，每列，每个九宫格判断

注意vecotr assign的用法；初始化vector有用；
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> count(9,0);
        
        //判断每行元素是否有重叠
        for(int row=0;row<9;row++){
            count.assign(9,0);//将count中9个数都初始化为0；
            for(int col=0;col<9;col++){
                char ch=board[row][col];
                if(ch!='.'){
                    //如果只出现一次，count为1，若再出现一样的，则说明有重复的，则为false
                    if(count[ch-'1']>0){
                        return false;
                    }
                    else{
                        count[ch-'1']++;
                    }
                }
            }
        }
        
        //判断每列元素是否有重叠
        for(int col=0;col<9;col++){
            count.assign(9,0);//将count中9个数都初始化为0；
            for(int row=0;row<9;row++){
                char ch=board[row][col];
                if(ch!='.'){
                    //如果只出现一次，count为1，若再出现一样的，则说明有重复的，则为false
                    if(count[ch-'1']>0){
                        return false;
                    }
                    else{
                        count[ch-'1']++;
                    }
                }
            }
        }
        
        //判断每个九宫格里是否有重叠
        for(int block=0;block<9;block++){
            //每个九宫格的开始的行和列；
            int start_row=(block/3)*3;
            int start_col=(block%3)*3;
            count.assign(9,0);
            for(int row=start_row;row<start_row+3;row++){
                for(int col=start_col;col<start_col+3;col++){
                    char ch=board[row][col];
                    if(ch!='.'){
                        if(count[ch-'1']>0){
                            return false;
                        }
                        else{
                            count[ch-'1']++;
                        }
                    }
                }
            }
        }
        return true;
    }
};