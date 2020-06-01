/*
Search in Rotated Sorted Array
Solution
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int binary_search(vector<int> nums, int low, int high, int key){
        if(low > high)
            return -1;
        int mid = low + (high - low)/2;
        if(nums[mid] == key)
            return mid;
        else if(nums[mid] > key)
            return binary_search(nums,low,mid-1,key);
        else
            return binary_search(nums,mid+1,high,key);
    }
    
    int transition_search(vector<int> &nums, int l, int low, int high){
        int mid = low + (high - low)/2;
        if(nums[mid] >= l && nums[mid+1] < nums[mid])
            return mid;
        else if(nums[mid] >= l)
            return transition_search(nums,l,mid+1,high);
        else
            return transition_search(nums,l,low,mid-1);
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int transition_index;
        if(nums[nums.size()-1] >= nums[0] || nums.size() == 1)
            transition_index = -1;
        else
            transition_index = transition_search(nums,nums[0],0,nums.size()-1);
        if(transition_index == -1)
            return binary_search(nums,0,nums.size()-1,target);
        if(transition_index){
            if(target >= nums[0])
                return binary_search(nums,0,transition_index,target);    
            else
                return binary_search(nums,transition_index+1,nums.size()-1,target);
        }
        else{
            if(target == nums[0])
                return 0;
            else if(target > nums[0])
                return -1;
            else
                return binary_search(nums,transition_index+1,nums.size()-1,target);
        }
        
    }
};