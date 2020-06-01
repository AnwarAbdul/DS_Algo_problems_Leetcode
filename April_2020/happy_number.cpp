/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

class Solution {
public:
    bool isHappy(int n) {
        
        int temp,sum,sum_check;
        int flag = 0;
        std::unordered_set<int> map;
	    while(1){
            sum = 0;
	        while (n >= 10) {
		        temp = n % 10;
		        sum += temp * temp;
		        n = n / 10;
	        }
            sum += n*n;
            n = sum;
            sum_check = 0;
            while (n >= 10) {
		        temp = n % 10;
		        sum_check += temp * temp;
		        n = n / 10;
	        }
            sum_check += n*n;
            if (sum_check == 1) {
		    	flag = 1;
    			break;
	    	}
		    if (map.find(sum) != map.end()) {
			    flag = 0;
			    break;
		    }
		    else
			    map.insert(sum);
            n = sum;
        }
        if(flag == 1)
            return true;
        else
            return false;
    }