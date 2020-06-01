/*

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4


*/

#include <iostream>
#include <vector>
#include <unordered_set>


int singleNumber(std::vector<int>& nums) {
        std::unordered_set<int> matches;
        int i;
        matches.insert(nums[0]);
        for(i = 1; i < nums.size(); i++){
    	    if(matches.find(nums[i]) != matches.end())
    		    matches.erase(nums[i]);
    	    else
    		    matches.insert(nums[i]);
        }
        return *matches.begin();
    }

int singleNumber_XOR(std::vector<int> &nums){
	int i;
	int sum = 0;
	for(i = 0; i < nums.size(); i++)
		sum ^= nums[i];
	return sum;
}

int main(){
	int n;
	int i;
	std::vector<int> nums;
	std::cin>>n;
	int num;
	for(i = 0; i < n ;i++){
		std::cin>>num;
		nums.push_back(num);
	}
    std::cout<<singleNumber_XOR(nums);
    return 0;
}