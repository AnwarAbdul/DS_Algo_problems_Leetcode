/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/



#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;
    
int main(){
    ifstream inf("input.txt");
    int n;
    inf>>n;
    vector<int> nums;
    int num,i;
    for(i = 0; i < n; i++){
        inf>>num;
        nums.push_back(num);
    }
    unordered_map<int,int> cumsum_index;
    vector<int> sum;
    if(nums[0] == 1)
        sum.push_back(1);
    else
        sum.push_back(-1); 
    for(i = 1; i < n; i++){
        num = sum.back();
        if(nums[i] == 1)
            sum.push_back(num+1);
        else
            sum.push_back(num-1);
    }
    int max = 0;
    int temp;
    for(i = 0; i < n; i++){
        if(sum[i] == 0){
            if(i+1 > max)
                max = i+1;
        }
        else if(cumsum_index.find(sum[i]) == cumsum_index.end())
            cumsum_index.insert({sum[i],i});
        else{
            temp = i - cumsum_index.at(sum[i]);
            if(temp > max)
                max = temp;
        }
    }
    std::cout<<max;
    return 0;
}
