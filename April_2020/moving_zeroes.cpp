/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/



#include <iostream>
#include <vector>
#include <fstream>

int main(){
	int n;
	std::vector<int> a;
	int i;
	int num;
	std::ifstream inf("input.txt");
	inf>>n;
	for(i = 0; i < n; i++){
		inf>>num;
		a.push_back(num);
	}
	int j;
	j = -1;
	i = 0;
	int temp;
	while(i <= n-1){
		if(a[i] != 0){
			if(j != -1){
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
				j++;
				i++;
			}
			else
				i++;
		}
		else{
			if(j == -1)
				j = i;
			i++;
		}
	}
	for(i = 0; i < n; i++)
		std::cout<<a[i]<<" ";
	return 0;
}