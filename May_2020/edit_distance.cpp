/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
class Solution {
public:
    
    int mini(int a, int b, int c){
        int mini = a;
        if(b < mini)
            mini = b;
        if(c < mini)
            mini = c;
        return mini;
    }
    
    int minDistance(string word1, string word2) {
        int **dp = (int **)malloc(sizeof(int *)*(word1.length() + 1));
        for(int i = 0; i <= word1.length(); i++)
            dp[i] = (int *)malloc(sizeof(int)*(word2.length() + 1));
        for(int i = 0; i <= word2.length(); i++)
            dp[0][i] = i;
        for(int i = 0; i <= word1.length(); i++)
            dp[i][0] = i;
        for(int i = 1; i <= word1.length(); i++){
            for(int j = 1; j <= word2.length(); j++){
                int ins = dp[i-1][j] + 1;
                int del = dp[i][j-1] + 1;
                int mat = dp[i-1][j-1];
                int mis = dp[i-1][j-1] + 1;
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = mini(ins,del,mat);
                else
                    dp[i][j] = mini(ins,del,mis);
            }
        }
        return dp[word1.length()][word2.length()];
    }
};