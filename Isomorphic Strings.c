/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
*****No two characters may map to the same character but a character may map to itself.****
是一一映射！

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

开始只考虑从s到t的映射，这样的话没有考虑一一映射，所以在case“ab”和“aa”过不去，因为a和b都对应a；不满足题意；
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,char> ch;
        for(int i=0;i<s.length();i++){
            //如果在映射中没找到s[i]，说明该映射还未出现，则把它加入到map ch中；
            if(ch.find(s[i])==ch.end()){
                ch[s[i]]=t[i];
            }
            else if(ch[s[i]]!=t[i]){
                //如果已有的映射和新出现的映射不同
                return false;
            }
        }
        
        //要做到一一对应；没有两个不同的字母映射到同一字母，所以，还要从t映射回s
        ch.clear();//清除映射，重新从t映射到s
        for(int i=0;i<t.length();i++){
            if(ch.find(t[i])==ch.end()){
                ch[t[i]]=s[i];
            }
            else if(ch[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
};