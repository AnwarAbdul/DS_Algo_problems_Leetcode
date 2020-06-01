/*

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
 

Constraints:

1 <= num <= 2^31 - 1

*/

class Solution {
public:
    
    int binary_search(long long int low,long long int high, long long int num){
        if(low > high)
            return -1;
        long long int mid = low + (high-low)/2;
        long long int sq = mid * mid;
        if(sq == num)
            return (int)sq;
        else if(sq > num)
            return binary_search(low,mid-1,num);
        else
            return binary_search(mid+1,high,num);
    }
    
    bool isPerfectSquare(int num) {
        int ans = binary_search((long long int)1,(long long int)num,(long long int)num);
        if(ans == -1)
            return false;
        else 
            return true;
    }
};
