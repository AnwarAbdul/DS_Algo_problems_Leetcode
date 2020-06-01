/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

class Solution {
public:
    
    bool Compare(int *a, int *b){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length())
            return false;
        int p_array[26];
        int s_array[26];
        for(int i = 0; i < 26; i++){
            p_array[i] = 0;
            s_array[i] = 0;
        }
        for(int i = 0; i < s1.length(); i++){
            p_array[s1[i]-'a'] += 1;
            s_array[s2[i]-'a'] += 1;
        }
        if(Compare(p_array,s_array))
            return true;
        for(int i = s1.length(); i < s2.length(); i++){
            s_array[s2[i-s1.length()]-'a'] -= 1;
            s_array[s2[i] - 'a'] += 1;
            if(Compare(p_array,s_array))
                return true;
        }
        return false;
    }
};