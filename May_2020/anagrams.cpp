/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
class Solution {
public:
    
    #define MAX 26
    
    bool Compare(int *a, int *b){
        for(int i = 0; i < MAX; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
    
    int maxi(int a, int b){
        if(a > b)
            return a;
        else
            return b;
    }
    
    vector<int> findAnagrams(string s, string p) {
        if(p.length() > s.length())
            return {};
        vector<int> out;
        int p_array[MAX];
        int s_array[MAX];
        for(int i = 0; i < MAX; i++){
            p_array[i] = 0;
            s_array[i] = 0;
        }
        int max_length = maxi(s.length(),p.length());
        for(int i = 0; i < p.length(); i++){
            p_array[p[i]-'a'] += 1;
            s_array[s[i]-'a'] += 1;
        }
        if(Compare(p_array,s_array))
                out.push_back(0);
        for(int i = p.length(); i < s.length(); i++){
            s_array[s[i-p.length()]-'a'] -= 1;
            s_array[s[i] - 'a'] += 1;
            if(Compare(p_array,s_array))
                out.push_back(i - p.length()+1);
        }
        return out;
    }
};