/*
Product of Array Except Self
Solution
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

    
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


int divide(long long int numerator, long long int denominator){
    long long int q = 0;
    int i;
    long long int temp = 0;
    for(i = 31; i >= 0; --i){
        if(temp + (denominator << i) <= numerator){
            temp += denominator << i;
            q |= 1LL << i;
        }
    }
    return q;
}


int main() {
    ifstream inf("input.txt");
    int n;
    inf>>n;
    vector<int> nums;
    int num,i;
    for(i = 0; i < n; i++){
        inf>>num;
        nums.push_back(num);
    }
    int p;
    p = 1;
    for(i = 0; i < nums.size(); i++){
        p *= nums[i];
    }
    std::cout<<p<<"\n";
    vector<int> out;
    for(i = 0; i < nums.size(); i++){
        out.push_back(divide(p,nums[i]));
    }
    for(i = 0; i < out.size(); i++)
        std::cout<<out[i]<<" ";
    return 0;
}

