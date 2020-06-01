/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0

*/


#include <iostream>
using namespace std;


int rangeBitwiseAnd(int m, int n) {
    uint64_t m1 = (uint64_t)m;
    uint64_t n1 = (uint64_t)n;
    uint64_t delta = n1 - m1;
    uint64_t val_m,val_n;
    uint64_t num = 0;
    uint64_t compare = 1;
    for(uint64_t i = 0; i < 31; i++){
        compare = 1;
        val_m = m1 & 0x1;
        val_n = n1 & 0x1;
        m1 = m1 >> 1;
        n1 = n1 >> 1;
        cout<<"\nval_m = "<<val_m<<" val_n = "<<val_n<<" m1 = "<<m1<<" n1 = "<<n1;
        if(val_m == 1 && val_n == 1){
            compare = compare << i;
            cout<<"\ncompare = "<<compare;
            if(delta < compare)
                num += compare;
        }
    }
    return (int)num;
}

int main(){
    int m = 5;
    int n = 7;
    cout<<"\n";
    int num = rangeBitwiseAnd(5,7);
    cout<<"\n"<<num;
    return 0;
}