/*
Jump Game
Solution
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5
*/

class Solution {
public:
    
    int maxi(int a, int b){
        int maxi = a;
        if(b > maxi)
            maxi = b;
        return maxi;
    }
    
    bool union_indexes(int i, int j, vector<int> &rank){
        if(j > rank[i])
            return false;
        else{
            rank[j] = maxi(rank[i],rank[j]);
            rank[i] = rank[j];
            return true;
        }
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> rank;
        int i;
        for(i = 0; i < nums.size(); i++){
            rank.push_back(i+nums[i]);
        }
        for(i = 0; i < nums.size() - 1; i++){
            if(union_indexes(i,i+1,rank)){
                if(rank[i+1] >= nums.size() - 1)
                    return true;
                else
                    continue;
            }
            else
                return false;
        }
        return true;
    }
};