/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

class Solution {
public:
    int binary_search(vector<int> nums,int low, int high){        
       if(low == high)
           return nums[low];
        int mid = low + (high-low)/2;
        if(mid == 0){
            if(nums[mid] == nums[mid+1])
                return binary_search(nums,low+2,high);
            else
                return nums[mid];
        }
        if(mid%2 == 0){
            if(nums[mid] == nums[mid-1])
                return binary_search(nums,low,mid-1);
            else if(nums[mid] == nums[mid+1])
                return binary_search(nums,mid+1,high);
            else
                return nums[mid];
        }
        else{
            if(nums[mid] == nums[mid-1])
                return binary_search(nums,mid+1,high);
            else if(nums[mid] == nums[mid+1])
                return binary_search(nums,low,mid-1);
            else
                return nums[mid];
        }
            
    }
    int singleNonDuplicate(vector<int>& nums) {
        return binary_search(nums,0,nums.size()-1);
    }
};