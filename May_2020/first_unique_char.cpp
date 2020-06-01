/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,list<int>::iterator> char_map;
        list<int> index_map;
        list<int> non_unique;
        non_unique.push_back(-1);
        for(int i = 0; i < s.length(); i++){
            if(char_map.find(s[i]) == char_map.end()){
                index_map.push_front(i);
                auto it = index_map.begin();
                char_map.insert({s[i],it});
            }
            else{
                if(char_map[s[i]] == non_unique.begin())
                    continue;
                else{
                    auto it = char_map[s[i]];
                    index_map.erase(it);
                    char_map[s[i]] = non_unique.begin();
                }
            }
        }
        if(index_map.size() == 0)
            return -1;
        else
            return index_map.back();
    }
};