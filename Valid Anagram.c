/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

/*
Solution 1:
分别将两个字符串，若得到两个字符串一样，则返回true；
采用sort！
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){
            return true;
        }
    }
};

/*
Solution 2:
运用Hash Table，key是每个在s和t中出现的字母，value是出现次数；
若在s中出现，count+1；若在t中出现，count-1；
最后count中的值为0，则表示两个string是一样的；
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()==0 && t.length()==0)
            return true;
        if(s.length()!=t.length())
            return false;
        unordered_map<char, int> count;//建立一个Hash table，分别是两个string中出现的字母，和其对应出现的次数
        for(int i=0;i<s.length();i++){
            count[s[i]]+=1;
            count[t[i]]-=1;
            //即当在s中出现的字母，则对于count中的次数+1；若在t中出现的字母，则对于count中的次数-1；
        }
        for(auto c:count){//c相当于是简化的迭代器
            //返回count中的第二个值，若为0，表示在s中该字母出现的次数和t中出现的次数一样；
            if(c.second!=0)
                return false;
                //这里不能判断c.second==0，返回true，这样不能判断所有的是否都是0；
        }
    }
};