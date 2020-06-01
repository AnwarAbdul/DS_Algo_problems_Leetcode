/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> dup_strs;
        int i;
        string str;
        for(i = 0; i < strs.size(); i++){
            str = strs[i];
            sort(str.begin(), str.end());
            dup_strs.push_back(str);
        }
        vector<vector<string>> ans;
        unordered_set<string> unique_elements;
        for(i = 0; i < dup_strs.size(); i++){
            if(unique_elements.find(dup_strs[i]) != unique_elements.end())
                continue;
            else
                unique_elements.insert(dup_strs[i]);                
        }
        vector<string> unique_elements_strs(unique_elements.begin(),unique_elements.end());
        int j;
        vector<string> temp;
        for(j = 0; j < unique_elements_strs.size(); j++){
            temp.clear();
            for(i = 0; i < dup_strs.size(); i++){
                if(unique_elements_strs[j] == dup_strs[i])
                    temp.push_back(strs[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};