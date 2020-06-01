/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.
*/


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    
    int max(int a, int b, int c){
        int maxi = a;
        if(b > maxi)
            maxi = b;
        if(c > maxi)
            maxi = c;
        return maxi;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        int i,j;
        int **d = (int **)malloc(sizeof(int*)*(n1+1));
        for(i = 0; i <= n1; i++)
            d[i] = (int *)malloc(sizeof(int)*(n2+1));
        for(i = 0; i <= n1; i++)
            d[i][0] = 0;
        for(j = 0; j <= n2; j++)
            d[0][j] = 0;
        int ins, del, mis, mat;
        int l = 0;
        for(i = 1; i <= n1; i++){
            for(j = 1; j <= n2; j++){
                ins = d[i-1][j] ;
                del = d[i][j-1] ;
                mis = d[i-1][j-1] - 1;
                mat = d[i-1][j-1] + 1;
                if(text1[i-1] == text2[j-1])
                    d[i][j] = max(ins,del,mat);
                else
                    d[i][j] = max(ins,del,mis);
            }
        }
        i = n1; j = n2; 
        while(i > 0 && j > 0){
            if(d[i-1][j-1] == d[i-1][j] && d[i][j-1] == d[i-1][j-1]){
                if(d[i-1][j-1] == d[i][j] - 1)
                    l++;
                i--;
                j--;
            }
            else if(d[i-1][j] == d[i][j])
                i--;
            else
                j--;

        }
                
        
        for(i = 0; i <= n1; i++)
            free(d[i]);
        free(d);
        return l; 
    }
};



int main(){
    Solution s;
    string s1,s2;
    cin>>s1>>s2;
    cout<<s.longestCommonSubsequence(s1,s2);
    return 0;
}