/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //创建vector存放分割str的各个单词
        vector<string> vec;  
        int j=0;  
        for(int i=0;i<str.size();i++){  
            if(str[i]==' '){  
                string tmp =str.substr(j,i-j);//tmp为分割得到的字符串  
                vec.push_back(tmp);  
                j=i+1;  
            }  
            if(i==str.size()-1){  
                string tmp =str.substr(j,i-j+1);  
                vec.push_back(tmp);  
            }  

        }  
        //若pattern的个数和vec中的数目不相同，则为false
        if(pattern.size()!=vec.size())return false;  
        unordered_map<char,string> map;  
        unordered_map<string,char> map2;  
        for(int i=0;i<pattern.size();i++){  
            if(map.find(pattern[i])==map.end()&&map2.find(vec[i])==map2.end()){  
                //插入map的用法，insert（make_pair（））
                map.insert(make_pair(pattern[i],vec[i]));  
                map2.insert(make_pair(vec[i],pattern[i]));  
            }  
            else if(map[pattern[i]]!=vec[i]||map2[vec[i]]!=pattern[i])return false;  

        }  

        return true;  
    }
};