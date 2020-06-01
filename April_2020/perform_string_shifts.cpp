/*
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

 

Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"
Example 2:

Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
*/

class Solution {
public:
    
    void adjust_vector_left(std::vector<char> &a, int n){
        for(int i = 0; i < n; i++){
            int num = a.front();
            a.erase(a.begin());
            a.push_back(num);
        }
    }
    
    void adjust_vector_right(std::vector<char> &a, int n){
        for(int i = 0; i < n; i++){
            int num = a.back();
            a.pop_back();
            a.insert(a.begin(),num);
        }
    }
    
    string stringShift(string s, vector<vector<int>>& shift) {
        vector<char> string_char;
        int i;
        for(i = 0; i < s.length(); i++)
            string_char.push_back(s[i]);
        int j;
        for(i = 0; i < shift.size(); i++){
            if(shift[i][0] == 0)
                adjust_vector_left(string_char,shift[i][1]);
            else
                adjust_vector_right(string_char,shift[i][1]);
        }
        string out(string_char.begin(), string_char.end());
        return out;
    }
};