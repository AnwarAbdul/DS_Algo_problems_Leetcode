/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
	    int running_sum = nums[0];
	    int i;
	    for (i = 1; i < nums.size(); i++) {
		    if (running_sum + nums[i] > nums[i]) {
			    if(running_sum + nums[i] > sum)
				    sum = running_sum + nums[i];
			    running_sum += nums[i];
		    }
		    else {
			    running_sum = nums[i];
			    if (nums[i] > sum)
			        sum = nums[i];
		    }
	    }
	return sum;
    }
};