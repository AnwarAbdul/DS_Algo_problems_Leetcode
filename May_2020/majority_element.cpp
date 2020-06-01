/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority_element = nums[0];
        unordered_map<int,int> nums_count;
        for(int i = 0; i < nums.size(); i++){
            if(nums_count.find(nums[i]) == nums_count.end())
                nums_count.insert({nums[i],1});
            else
                nums_count[nums[i]]++;
            if(nums_count[nums[i]] > nums_count[majority_element])
                majority_element = nums[i];
        }
        return majority_element;
    }
};