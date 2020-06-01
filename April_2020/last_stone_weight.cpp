/*
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/


class Solution {
public:
    void find_2largest(vector<int> &a, int *w1, int *w2){
        int i,j;
        int largest = 0;;
        for(i = 1; i < a.size(); i++){
            if(a[i] > a[largest])
                largest = i;
        }
        *w1 = largest;
        largest = 0;
        for(i = 1; i < a.size(); i++){
            if(i == w1)
                continue;
            if(a[i] > a[largest] && a[i] <= a[*w1])
                largest = i;
        }
        *w2 = largest;
        if(a[*w1] > a[*w2]){
            a[*w1] -= a[*w2];
            a[*w2] = 0;
        }
        else{
            a[*w1] = 0;
            a[*w2] = 0;
        }
    }
    
    int lastStoneWeight(vector<int>& stones) {
        int w1_pos,w2_pos;
        while(stones.size() > 1){
            find_2largest(stones,&w1_pos,&w2_pos);
            stones.erase(stones.begin() + w2_pos);
            if(stones[w1_pos] == 0)
                stones.erase(stones.begin() + w1_pos);
        }
        if(stones.size() == 0)
            return 0;
        return stones.back();
    }
};