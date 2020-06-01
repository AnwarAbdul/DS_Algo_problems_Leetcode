/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

You may assume that both strings contain only lowercase letters.
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ransom_map;
        unordered_map<char,int> magazine_map;
        bool can = true;
        if(ransomNote.length() == 0){
            return true;
        }
        if(magazine.length() == 0){
            if(ransomNote.length() == 0)
                return true;
            else
                return false;
        }
        for(int i = 0; i < magazine.length(); i++){
            if(magazine_map.find(magazine[i]) == magazine_map.end())
                magazine_map.insert({magazine[i],1});
            else
                magazine_map[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            if(magazine_map.find(ransomNote[i]) == magazine_map.end()){
                can = false;
                break;
            }
            else{
                if(magazine_map[ransomNote[i]])
                    magazine_map[ransomNote[i]]--;
                else{
                    can = false;
                    break;
                }
            }
        }
        
        return can;
    }
};