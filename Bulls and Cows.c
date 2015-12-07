/*
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/

//这道题主要注意的地方有
//String的用法，int转换为string
using namespace std;
void main()
{
    // int 转 string
    stringstream ss;
    int n = 123;
    string str;
    ss<<n;
    ss>>str;
    // string 转 int
    str = "456";
    n = atoi(str.c_str());
}

class Solution {
public:
    string getHint(string secret, string guess) {
        int len=secret.size();
        vector<int> p1(10,0);//用来存储secret里面数字0~9出现的次数
        vector<int> p2(10,0);//用来存储guess里面数字0~9出现的次数
        int bulls=0;
        int total=0;
        for(int i=0;i<len;i++){
            if(secret[i]==guess[i]){
                bulls++;//两者相等，说明数字相同，位置也相同
            }
            //同时，相应的secret和guess里面的数字出现的次数加一；
            p1[secret[i]-'0']++;
            p2[guess[i]-'0']++;
        }
        
        //比较p1和p2相同数字出现的次数，取两者的最小值为总共guess和secret有多少个数字是相同的；
        //其中也包含了在相同位置的数字
        for(int j=0;j<10;j++){
            total+=min(p1[j],p2[j]);
        }
        //所以，用total-bulls即是cows，不同位置相同数字
        int cows=total-bulls;
        //注意string的用法！！！将int转换成string
        std::stringstream ss;
        ss<<bulls<<'A'<<cows<<'B';
        return ss.str();
    }
};